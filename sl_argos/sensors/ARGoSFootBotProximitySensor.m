classdef ARGoSFootBotProximitySensor < matlab.System ...
        & coder.ExternalDependency ... 
        & matlab.system.mixin.Propagates ...
        & matlab.system.mixin.CustomIcon
 % MATLAB interface to ARGoS FootBot Proximity Sensor
 
    properties (Access=protected)
        sensPtr; % Pointer to ARGoS sensor
    end
    
    properties (Access=public, Nontunable)
        numReadings = 100; % Number of range readings
    end
    
    methods
        % Constructor
        function obj = ARGoSFootBotProximitySensor(varargin)
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
                coder.cinclude('ARGoSFootBotProximitySensorWrapper.h');
                coder.cinclude('<argos3/core/control_interface/ci_controller.h>');
                % Call the wrapper initialization function
                obj.sensPtr = coder.opaque('argostype','HeaderFile','ARGoSFootBotProximitySensorWrapper.h');
                obj.sensPtr = coder.ceval('footBotProximitySensor_constructor',coder.opaque('CCI_Controller','controller'));
            end
        end
        
        % CONTROL STEP
        function [angles,ranges] = stepImpl(obj)
            angles = zeros(obj.numReadings,1);
            ranges = zeros(obj.numReadings,1);
            if isempty(coder.target)
                % Simulation step code
            else
                % Call C-function implementing device output
                coder.ceval('footBotProximitySensor_getReadings',obj.sensPtr,coder.ref(angles),coder.ref(ranges));
            end
        end
        
        % TERMINATE
        function releaseImpl(obj)
            if isempty(coder.target)
                % Simulation termination code
            else
                % Code generation termination code
                coder.ceval('footBotProximitySensor_destructor',obj.sensPtr);
            end
        end
        
        function icon = getIconImpl(~)
            % Define icon for System block
            icon = {'ARGoS','FootBot','Proximity'};
            %icon = matlab.system.display.Icon('my_icon.png');
        end
        
        
        function [flag1,flag2] = isOutputFixedSizeImpl(~)
            % Define fixed-size outputs
            flag1 = true;
            flag2 = true;
        end
        
        function [n1,n2] = getOutputSizeImpl(obj)
            % Define output sizes
            n1 = obj.numReadings;
            n2 = obj.numReadings;
        end
        
        function [t1,t2] = getOutputDataTypeImpl(~)
            % Define output data types
            t1 = "double";
            t2 = "double";
        end
          
        function [c1,c2] = isOutputComplexImpl(~)
            % Define output complexity
            c1 = false;
            c2 = false;
        end      
        
    end
    
    
    methods (Static)
        
        function name = getDescriptiveName()
            name = 'ARGoS FootBot Proximity Sensor';
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
                addSourceFiles(buildInfo,'ARGoSFootBotProximitySensorWrapper.cpp', srcDir);
            end
        end
        
    end
end