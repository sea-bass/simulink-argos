function exportARGoSCode(modelName,buildInfo)
% Post code-generation command for models that target the ARGoS simulator

%% Pack the generated code in a ZIP file
warning off
packNGo(buildInfo,{'packType','flat','ignoreFileMissing',true})
warning on

%% Move and extract the ZIP to target folder
controllerName = [modelName 'Ctrl'];
targetDir = fullfile(fileparts(which(modelName)), ... 
                     '..','controllers',controllerName);
filename = [modelName '.zip'];
if ~exist(targetDir,'dir')
   mkdir(targetDir);
end
movefile(which(filename),fullfile(targetDir,filename));

% Remove the folder if it already exists
if isfolder(fullfile(targetDir,modelName))
   rmdir(fullfile(targetDir,modelName),'s');
   mkdir(fullfile(targetDir,modelName));
end

% Change folder and unzip
curDir = pwd;
cd(targetDir);
mkdir(modelName);
unzip(filename,modelName);
delete(filename);

%% Modify the generated code 
% This will add the controller pointer in the initialize function so the
% right sensor and actuator objects can be created at initialization
headerFile = fullfile(modelName,[modelName '.h']);
sourceFile = fullfile(modelName,[modelName '.cpp']);

fid  = fopen(headerFile,'r');
f = fread(fid,'*char')';
fclose(fid);
f = strrep(f,'initialize()','initialize(CCI_Controller *controller)');
fid  = fopen(headerFile,'w');
fprintf(fid,'%s',f);
fclose(fid);

fid  = fopen(sourceFile,'r');
f = fread(fid,'*char')';
fclose(fid);
f = strrep(f,'initialize()','initialize(CCI_Controller *controller)');
fid  = fopen(sourceFile,'w');
fprintf(fid,'%s',f);
fclose(fid);

cd(curDir);

%% Create controller source/header files from template
ctrlHeaderFileTemplate = which('argos_ctrl_template.h');
ctrlHeaderFile = fullfile(targetDir,[controllerName '.h']);
ctrlSrcFileTemplate = which('argos_ctrl_template.cpp');
ctrlSrcFile = fullfile(targetDir,[controllerName '.cpp']);
copyfile(ctrlHeaderFileTemplate,ctrlHeaderFile);
copyfile(ctrlSrcFileTemplate,ctrlSrcFile);

ctrlHeaderText = fileread(ctrlHeaderFile);
ctrlHeaderText = strrep(ctrlHeaderText,'$MDL_NAME$',modelName);
ctrlHeaderText = strrep(ctrlHeaderText,'$CTRL_NAME$',controllerName);
ctrlHeaderText = strrep(ctrlHeaderText,'$CTRL_HEADER_NAME$',upper(controllerName));
f = fopen(ctrlHeaderFile,'w');
fprintf(f,'%s',ctrlHeaderText);
fclose(f);

ctrlSrcText = fileread(ctrlSrcFile);
ctrlSrcText = strrep(ctrlSrcText,'$MDL_NAME$',modelName);
ctrlSrcText = strrep(ctrlSrcText,'$CTRL_NAME$',controllerName);
ctrlSrcText = strrep(ctrlSrcText,'$CTRL_HEADER_NAME$',upper(controllerName));
f = fopen(ctrlSrcFile,'w');
fprintf(f,'%s',ctrlSrcText);
fclose(f);

%% Create CMakeLists.txt from template
cMakeListsTemplate = which('argos_cmakelists_template.txt');
cMakeListsFile = fullfile(targetDir,'CMakeLists.txt');
copyfile(cMakeListsTemplate,cMakeListsFile);

srcList = '';
numSrc = numel(buildInfo.Src.Paths);
for idx = 1:numSrc
    srcFileName = buildInfo.Src.Files(idx).FileName;
    if ~strcmp(srcFileName,'ert_main.cpp')
        srcList = [srcList newline '            ' fullfile(modelName,srcFileName)];
    end
end

cMakeListsText = fileread(cMakeListsFile);
cMakeListsText = strrep(cMakeListsText,'$MDL_NAME$',modelName);
cMakeListsText = strrep(cMakeListsText,'$CTRL_NAME$',controllerName);
cMakeListsText = strrep(cMakeListsText,'$SRC_LIST$',srcList);
f = fopen(cMakeListsFile,'w');
fprintf(f,'%s',cMakeListsText);
fclose(f);

% Plus the controllerName .cpp and .h files

%% TODO: Compile the generated code
% System calls:
% Go to the top folder, then do
% cmake -DCMAKE_BUILD_TYPE=Release ..
% make