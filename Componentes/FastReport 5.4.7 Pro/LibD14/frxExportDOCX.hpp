// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexportdocx.pas' rev: 21.00

#ifndef FrxexportdocxHPP
#define FrxexportdocxHPP

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
#include <Frxexportmatrix.hpp>	// Pascal unit
#include <Frximageconverter.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexportdocx
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxDOCXExportDialog;
class PASCALIMPLEMENTATION TfrxDOCXExportDialog : public Forms::TForm
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
	/* TCustomForm.Create */ inline __fastcall virtual TfrxDOCXExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxDOCXExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxDOCXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxDOCXExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


struct TfrxDocxPage
{
	
public:
	int Width;
	int Height;
	Types::TRect Margins;
};


class DELPHICLASS TfrxDOCXExport;
class PASCALIMPLEMENTATION TfrxDOCXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FDocFolder;
	Classes::TStream* FDocument;
	Classes::TStream* FDocRels;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	TfrxDocxPage FLastPage;
	int FPicNum;
	bool FFirstPage;
	Frximageconverter::TfrxPictureType FPictureType;
	System::UnicodeString __fastcall SubPath(const System::UnicodeString s);
	System::UnicodeString __fastcall SecPr(void);
	
public:
	__fastcall virtual TfrxDOCXExport(Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, nodefault};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxDOCXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxDOCXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexportdocx */
using namespace Frxexportdocx;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportdocxHPP
