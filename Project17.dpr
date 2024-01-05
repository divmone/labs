program Project17;

uses
  Vcl.Forms,
  ss in '..\Documents\Embarcadero\Studio\Projects\ss.pas' {MainForm},
  Vcl.Themes,
  Vcl.Styles,
  Unit3 in '..\Documents\Embarcadero\Studio\Projects\Unit3.pas' {Form3},
  Unit4 in '..\Documents\Embarcadero\Studio\Projects\Unit4.pas' {Form4};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  TStyleManager.TrySetStyle('Windows10 Dark');
  Application.CreateForm(TMainForm, MainForm);
  Application.CreateForm(TForm3, Form3);
  Application.CreateForm(TForm4, Form4);
  Application.Run;
end.
