[Setup]
AppName=StudentSorter
AppVersion=3.0
DefaultDirName={commonpf}\VU\StudentSorter
OutputDir=.\dist
OutputBaseFilename=StudentSorterSetup
PrivilegesRequired=admin
Compression=lzma
SolidCompression=yes

[Files]
Source: ".\v3.0.exe"; DestDir: "{app}"; Flags: ignoreversion

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Icons]
Name: "{group}\StudentSorter"; Filename: "{app}\v3.0.exe"
Name: "{commondesktop}\StudentSorter"; Filename: "{app}\v3.0.exe"; Tasks: desktopicon


[Run]
Filename: "{app}\v3.0.exe"; Description: "Launch StudentSorter Program"; Flags: nowait postinstall skipifsilent
