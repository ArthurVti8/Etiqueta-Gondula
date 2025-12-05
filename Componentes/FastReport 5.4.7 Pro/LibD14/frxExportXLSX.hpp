// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexportxlsx.pas' rev: 21.00

#ifndef FrxexportxlsxHPP
#define FrxexportxlsxHPP

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
#include <Types.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxexportmatrix.hpp>	// Pascal unit
#include <Shellapi.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Frxzip.hpp>	// Pascal unit
#include <Frxofficeopen.hpp>	// Pascal unit
#include <Frximageconverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexportxlsx
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxXLSXExportDialog;
class PASCALIMPLEMENTATION TfrxXLSXExportDialog : public Forms::TForm
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
	Stdctrls::TGroupBox* GroupOptions;
	Stdctrls::TCheckBox* ContinuousCB;
	Stdctrls::TGroupBox* SplitToSheetGB;
	Stdctrls::TRadioButton* RPagesRB;
	Stdctrls::TRadioButton* NotSplitRB;
	Stdctrls::TRadioButton* RowsCountRB;
	Stdctrls::TEdit* edChunk;
	Stdctrls::TCheckBox* OpenCB;
	Stdctrls::TCheckBox* PageBreaksCB;
	Stdctrls::TCheckBox* WCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxXLSXExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxXLSXExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxXLSXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxXLSXExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TfrxXLSXExport;
class PASCALIMPLEMENTATION TfrxXLSXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FExportPageBreaks;
	bool FEmptyLines;
	bool FOpenAfterExport;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	System::UnicodeString FDocFolder;
	Classes::TStream* FContentTypes;
	Classes::TStream* FRels;
	Classes::TStream* FStyles;
	Classes::TStream* FWorkbook;
	Classes::TStream* FSharedStrings;
	Classes::TStream* FWorkbookRels;
	Classes::TStrings* FFonts;
	Classes::TStrings* FFills;
	Classes::TStrings* FBorders;
	Classes::TStrings* FCellStyleXfs;
	Classes::TStrings* FCellXfs;
	Classes::TList* FColors;
	Classes::TStrings* FNumFmts;
	Classes::TStrings* FStrings;
	int FStringsCount;
	bool FSingleSheet;
	int FChunkSize;
	Frxofficeopen::TfrxMap FLastPage;
	bool FWysiwyg;
	Frximageconverter::TfrxPictureType FPictureType;
	int __fastcall AddString(System::UnicodeString s);
	int __fastcall AddColor(Graphics::TColor c);
	void __fastcall AddColors(Graphics::TColor const *c, const int c_Size);
	void __fastcall AddSheet(const Frxofficeopen::TfrxMap &m);
	void __fastcall ExportFormats(Classes::TStrings* FNumFmts);
	void __fastcall UpdateStyles(void);
	
public:
	__fastcall virtual TfrxXLSXExport(Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property int ChunkSize = {read=FChunkSize, write=FChunkSize, nodefault};
	__property bool EmptyLines = {read=FEmptyLines, write=FEmptyLines, default=1};
	__property bool ExportPageBreaks = {read=FExportPageBreaks, write=FExportPageBreaks, default=1};
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
	__property bool SingleSheet = {read=FSingleSheet, write=FSingleSheet, default=1};
	__property bool Wysiwyg = {read=FWysiwyg, write=FWysiwyg, default=1};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxXLSXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxXLSXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexportxlsx */
using namespace Frxexportxlsx;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportxlsxHPP
