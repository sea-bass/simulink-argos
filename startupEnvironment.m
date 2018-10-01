% Simulink-ARGoS Startup script

% Add the following folders to the MATLAB path. You can alternatively run
% this in a startup.m script or permanently save these folders to the path.
addpath(genpath('sl_argos'))
addpath(fullfile('examples','models'))

% Open the example model
open_system('testArgosModel.slx')