classdef ARGoSDifferentialSteering < matlab.System ...
        & coder.ExternalDependency ... 
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon
 % MATLAB interface to ARGoS Differential Steering Actuator
 
    properties (Access=protected)
        actPtr; % Pointer to ARGoS actuator
    end
    
    methods
        % Constructor
        function obj = ARGoSDifferentialSteering(varargin)
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
        
    end
    
    methods (Access=protected)
        
        % SETUP
        function setupImpl(obj)
            if isempty(coder.target)
                % Simulation setup
            else
                % Code generation setup
                % Include the wrapper class
                coder.cinclude('ARGoSDifferentialSteeringWrapper.h');
                coder.cinclude('<argos3/core/control_interface/ci_controller.h>');
                % Call the wrapper initialization function
                obj.actPtr = coder.opaque('argostype','HeaderFile','ARGoSDifferentialSteeringWrapper.h');
                obj.actPtr = coder.ceval('argosDifferentialSteering_constructor',coder.opaque('CCI_Controller','controller'));
            end
        end
        
        % CONTROL STEP
        function stepImpl(obj,wl,wr)
            if isempty(coder.target)
                % Simulation step code
            else
                % Call C-function implementing device output
                coder.ceval('argosDifferentialSteering_setLinearVelocity',obj.actPtr,wl,wr);
            end
        end
        
        % TERMINATE
        function releaseImpl(obj)
            if isempty(coder.target)
                % Simulation termination code
            else
                % Code generation termination code
                coder.ceval('argosDifferentialSteering_destructor',obj.actPtr);
            end
        end
        
        function icon = getIconImpl(~)
            % Define icon for System block
            icon = {'ARGoS','Differential','Steering'};
            %icon = matlab.system.display.Icon('my_icon.png');
        end
        
    end
    
    
    methods (Static)
        
        function name = getDescriptiveName()
            name = 'ARGoS Differential Steering Actuator';
        end
        
        function tf = isSupportedContext(context)
            tf = context.isCodeGenTarget('rtw');
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src');
                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);
                % Add include files, sources and linker flags
                addSourceFiles(buildInfo,'ARGoSDifferentialSteeringWrapper.cpp', srcDir);
            end
        end
        
    end
end