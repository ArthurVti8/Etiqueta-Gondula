// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexportpptx.pas' rev: 21.00

#ifndef FrxexportpptxHPP
#define FrxexportpptxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Shellapi.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Frxzip.hpp>	// Pascal unit
#include <Frximageconverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexportpptx
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxPPTXExportDialog;
class PASCALIMPLEMENTATION TfrxPPTXExportDialog : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkB;
	Stdctrls::TButton* CancelB;
	Dialogs::TSaveDialog* sd;
	Stdctrls::TGroupBox* GroupPageRange;
	Stdctrls::TLabel* DescrL;
	Stdctrls::TRadioButton* AllRB;
	Stdctrls::TRadioButton* CurPageRB;
	Stdctrls::TRadioButton* PageNumbersRB;
	Stdctrls::TEdit* PageNumbersE;
	Stdctrls::TCheckBox* OpenCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxPPTXExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxPPTXExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxPPTXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxPPTXExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TfrxPPTXExport;
class PASCALIMPLEMENTATION TfrxPPTXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FDocFolder;
	Classes::TStream* FContentTypes;
	Classes::TStream* FPresentation;
	Classes::TStream* FPresentationRels;
	Classes::TStream* FRels;
	Classes::TStream* FSlide;
	Classes::TStream* FSlideRels;
	int FSlideId;
	int FObjectId;
	Frxclass::TfrxReportPage* FPage;
	int FWidth;
	int FHeight;
	Frximageconverter::TfrxPictureType FPictureType;
	System::UnicodeString __fastcall SubPath(const System::UnicodeString s);
	void __fastcall AddTextBox(Frxclass::TfrxCustomMemoView* Obj);
	void __fastcall AddLine(Frxclass::TfrxFrameLine* Line, int x, int y, int dx, int dy);
	void __fastcall AddPicture(Frxclass::TfrxView* Obj);
	Types::TRect __fastcall GetObjRect(Frxclass::TfrxView* Obj);
	
public:
	__fastcall virtual TfrxPPTXExport(Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxPPTXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxPPTXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexportpptx */
using namespace Frxexportpptx;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportpptxHPP
