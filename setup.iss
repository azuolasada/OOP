[Setup]
AppName=StudentSorter
AppVersion=3.0
DefaultDirName={pf}\VU\StudentSorter
OutputDir=.\dist
OutputBaseFilename=setup
PrivilegesRequired=admin
Compression=lzma
SolidCompression=yes

[Files]
Source: ".\v3.0"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\StudentSorter"; Filename: "{app}\v3.0"
Name: "{commondesktop}\StudentSorter"; Filename: "{app}\v3.0"; Tasks: desktopicon

[Run]
Filename: "{app}\v3.0"; Description: "Launch StudentSorter"; Flags: nowait postinstall skipifsilent

