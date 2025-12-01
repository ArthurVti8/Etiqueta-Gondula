program Project1;

uses
  Vcl.Forms,
  UnitPrincipal in 'UnitPrincipal.pas' {GeradorEtiquetas};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TGeradorEtiquetas, GeradorEtiquetas);
  Application.CreateForm(TGeradorEtiquetas, GeradorEtiquetas);
  Application.Run;
end.
