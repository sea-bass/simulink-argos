%% Generate code
mdlName = 'testArgosModel';
rtwbuild(mdlName);

%% Pack the files in a ZIP file
load([mdlName '_ert_rtw/buildInfo.mat'])
warning off
packNGo(buildInfo,{'packType','flat','ignoreFileMissing',true})
warning on

%% Move and extract the ZIP to target folder
targetDir = '/home/sebastian/Workspace/matlab_argos/examples/controllers/matlab_test';
filename = [mdlName '.zip'];
movefile(fullfile(filename),fullfile(targetDir,filename));

% Remove the folder if it already exists
if isfolder(fullfile(targetDir,mdlName))
   rmdir(fullfile(targetDir,mdlName),'s');
   mkdir(fullfile(targetDir,mdlName));
end

% Change folder and unzip
curDir = pwd;
cd(targetDir);
mkdir(mdlName);
unzip(filename,mdlName);
delete(filename);

%% TODO: Modify the generated code
headerFile = fullfile(mdlName,[mdlName '.h']);
sourceFile = fullfile(mdlName,[mdlName '.cpp']);

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

%% TODO: Modify the CMakeLists.txt to include all cpp files

%% TODO: Compile the generated code