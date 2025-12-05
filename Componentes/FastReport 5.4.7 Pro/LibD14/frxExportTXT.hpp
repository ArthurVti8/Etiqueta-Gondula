// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexporttxt.pas' rev: 21.00

#ifndef FrxexporttxtHPP
#define FrxexporttxtHPP

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
#include <Frxprogress.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexporttxt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxTXTExportDialog;
class DELPHICLASS TfrxTXTExport;
class PASCALIMPLEMENTATION TfrxTXTExportDialog : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OK;
	Stdctrls::TButton* Cancel;
	Extctrls::TPanel* Panel1;
	Stdctrls::TGroupBox* GroupCellProp;
	Stdctrls::TGroupBox* GroupPageRange;
	Stdctrls::TLabel* Pages;
	Stdctrls::TLabel* Descr;
	Stdctrls::TEdit* E_Range;
	Stdctrls::TGroupBox* GroupScaleSettings;
	Stdctrls::TLabel* ScX;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* ScY;
	Stdctrls::TLabel* Label9;
	Stdctrls::TEdit* E_ScaleX;
	Stdctrls::TCheckBox* CB_PageBreaks;
	Stdctrls::TGroupBox* GroupFramesSettings;
	Stdctrls::TRadioButton* RB_NoneFrames;
	Stdctrls::TRadioButton* RB_Simple;
	Stdctrls::TRadioButton* RB_Graph;
	Stdctrls::TCheckBox* CB_OEM;
	Stdctrls::TCheckBox* CB_EmptyLines;
	Stdctrls::TCheckBox* CB_LeadSpaces;
	Stdctrls::TCheckBox* CB_PrintAfter;
	Extctrls::TPanel* Panel2;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* PgHeight;
	Stdctrls::TLabel* PgWidth;
	Stdctrls::TMemo* Preview;
	Stdctrls::TEdit* EPage;
	Comctrls::TUpDown* PageUpDown;
	Stdctrls::TLabel* LBPage;
	Buttons::TSpeedButton* ToolButton1;
	Buttons::TSpeedButton* ToolButton2;
	Buttons::TSpeedButton* BtnPreview;
	Dialogs::TSaveDialog* SaveDialog1;
	Comctrls::TUpDown* UpDown1;
	Comctrls::TUpDown* UpDown2;
	Stdctrls::TEdit* E_ScaleY;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CB_OEMClick(System::TObject* Sender);
	void __fastcall RefreshClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall E_ScaleXChange(System::TObject* Sender);
	void __fastcall BtnPreviewClick(System::TObject* Sender);
	void __fastcall ToolButton1Click(System::TObject* Sender);
	void __fastcall ToolButton2Click(System::TObject* Sender);
	void __fastcall UpDown1Changing(System::TObject* Sender, bool &AllowChange);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
	
private:
	TfrxTXTExport* TxtExp;
	bool Flag;
	bool created;
	bool MakeInit;
	bool running;
	int printer;
	
public:
	int PagesCount;
	TfrxTXTExport* Exporter;
	bool PreviewActive;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxTXTExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxTXTExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxTXTExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxTXTExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


struct TfrxTXTStyle;
typedef TfrxTXTStyle *PfrxTXTStyle;

#pragma pack(push,1)
struct TfrxTXTStyle
{
	
public:
	Graphics::TFont* Font;
	Frxclass::TfrxVAlign VAlignment;
	Frxclass::TfrxHAlign HAlignment;
	Frxclass::TfrxFrameTypes FrameTyp;
	float FrameWidth;
	Graphics::TColor FrameColor;
	Frxclass::TfrxFrameStyle FrameStyle;
	Graphics::TColor FillColor;
	bool IsText;
};
#pragma pack(pop)


struct TfrxTXTPrinterCommand
{
	
public:
	System::UnicodeString Name;
	System::UnicodeString SwitchOn;
	System::UnicodeString SwitchOff;
	bool Trigger;
};


struct TfrxTXTPrinterType
{
	
private:
	typedef StaticArray<TfrxTXTPrinterCommand, 32> _TfrxTXTPrinterType__1;
	
	
public:
	System::UnicodeString name;
	int CommCount;
	_TfrxTXTPrinterType__1 Commands;
};


class PASCALIMPLEMENTATION TfrxTXTExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	typedef DynamicArray<System::WideChar> _TfrxTXTExport__1;
	
	typedef StaticArray<TfrxTXTPrinterType, 16> _TfrxTXTExport__2;
	
	
private:
	int CurrentPage;
	bool FirstPage;
	int CurY;
	Classes::TList* RX;
	Classes::TList* RY;
	Classes::TList* ObjectPos;
	Classes::TList* PageObj;
	Classes::TList* StyleList;
	System::Extended CY;
	System::Extended LastY;
	TfrxTXTExportDialog* frExportSet;
	Classes::TStringList* pgBreakList;
	bool expBorders;
	bool expBordersGraph;
	bool expPrintAfter;
	bool expUseSavedProps;
	bool expPrinterDialog;
	bool expPageBreaks;
	bool expOEM;
	bool expEmptyLines;
	bool expLeadSpaces;
	System::UnicodeString expCustomFrameSet;
	System::Extended expScaleX;
	System::Extended expScaleY;
	System::Extended MaxWidth;
	_TfrxTXTExport__1 Scr;
	int ScrWidth;
	int ScrHeight;
	System::UnicodeString PrinterInitString;
	Classes::TFileStream* Stream;
	bool FStripHTMLTags;
	void __fastcall WriteExpLn(const System::UnicodeString str);
	void __fastcall WriteExp(const System::UnicodeString str);
	void __fastcall ObjCellAdd(Classes::TList* Vector, System::Extended Value);
	void __fastcall ObjPosAdd(Classes::TList* Vector, int x, int y, int dx, int dy, int obj);
	bool __fastcall CompareStyles(PfrxTXTStyle Style1, PfrxTXTStyle Style2);
	int __fastcall FindStyle(PfrxTXTStyle Style);
	void __fastcall MakeStyleList(void);
	void __fastcall ClearLastPage(void);
	void __fastcall OrderObjectByCells(void);
	void __fastcall ExportPage(void);
	System::UnicodeString __fastcall ChangeReturns(const System::UnicodeString Str);
	System::UnicodeString __fastcall TruncReturns(const System::UnicodeString Str);
	void __fastcall AfterExport(const System::UnicodeString FileName);
	void __fastcall PrepareExportPage(void);
	void __fastcall DrawMemo(int x, int y, int dx, int dy, System::UnicodeString text, int st);
	void __fastcall FlushScr(void);
	void __fastcall CreateScr(int dx, int dy);
	void __fastcall FreeScr(void);
	void __fastcall ScrType(int x, int y, System::WideChar c);
	System::WideChar __fastcall ScrGet(int x, int y);
	void __fastcall ScrString(int x, int y, const System::UnicodeString s);
	void __fastcall FormFeed(void);
	System::UnicodeString __fastcall MakeInitString(void);
	
public:
	int PrintersCount;
	_TfrxTXTExport__2 PrinterTypes;
	int SelectedPrinterType;
	int PageWidth;
	int PageHeight;
	bool IsPreview;
	int Copys;
	__fastcall virtual TfrxTXTExport(Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxTXTExport(void);
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	int __fastcall RegisterPrinterType(const System::UnicodeString Name);
	void __fastcall RegisterPrinterCommand(int PrinterIndex, const System::UnicodeString Name, const System::UnicodeString switch_on, const System::UnicodeString switch_off);
	void __fastcall LoadPrinterInit(const System::UnicodeString FName);
	void __fastcall SavePrinterInit(const System::UnicodeString FName);
	void __fastcall SpoolFile(const System::UnicodeString FileName);
	
__published:
	__property System::Extended ScaleWidth = {read=expScaleX, write=expScaleX};
	__property System::Extended ScaleHeight = {read=expScaleY, write=expScaleY};
	__property bool Borders = {read=expBorders, write=expBorders, nodefault};
	__property bool Pseudogrpahic = {read=expBordersGraph, write=expBordersGraph, nodefault};
	__property bool PageBreaks = {read=expPageBreaks, write=expPageBreaks, nodefault};
	__property bool OEMCodepage = {read=expOEM, write=expOEM, nodefault};
	__property bool EmptyLines = {read=expEmptyLines, write=expEmptyLines, nodefault};
	__property bool LeadSpaces = {read=expLeadSpaces, write=expLeadSpaces, nodefault};
	__property bool PrintAfter = {read=expPrintAfter, write=expPrintAfter, nodefault};
	__property bool PrinterDialog = {read=expPrinterDialog, write=expPrinterDialog, nodefault};
	__property bool UseSavedProps = {read=expUseSavedProps, write=expUseSavedProps, nodefault};
	__property System::UnicodeString InitString = {read=PrinterInitString, write=PrinterInitString};
	__property System::UnicodeString CustomFrameSet = {read=expCustomFrameSet, write=expCustomFrameSet};
	__property bool StripHTMLTags = {read=FStripHTMLTags, write=FStripHTMLTags, default=0};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxTXTExport(void) : Frxclass::TfrxCustomExportFilter() { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexporttxt */
using namespace Frxexporttxt;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporttxtHPP
