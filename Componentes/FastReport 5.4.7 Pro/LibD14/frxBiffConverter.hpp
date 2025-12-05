// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbiffconverter.pas' rev: 21.00

#ifndef FrxbiffconverterHPP
#define FrxbiffconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxexportmatrix.hpp>	// Pascal unit
#include <Frxbiff.hpp>	// Pascal unit
#include <Frxprogress.hpp>	// Pascal unit
#include <Frxgraphicutils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbiffconverter
{
//-- type declarations -------------------------------------------------------
typedef int TfrxPrintOrient;

struct TfrxPageInfo
{
	
public:
	System::Extended PaperWidth;
	System::Extended PaperHeight;
	System::Extended LeftMargin;
	System::Extended RightMargin;
	System::Extended TopMargin;
	System::Extended BottomMargin;
	int Orientation;
	int PageCount;
	int PaperSize;
	System::UnicodeString Name;
};


struct TfrxBiffPageOptions
{
	
public:
	Frxexportmatrix::TfrxIEMatrix* Matrix;
	Frxbiff::TBiffSheet* Sheet;
	TfrxPageInfo Page;
	int PageId;
	Types::TPoint Source;
	Types::TPoint Dest;
	Types::TPoint Size;
	Classes::TList* Images;
	bool Surr;
	bool Pictures;
	bool PageBreaks;
	Frxbiff::TBiffWorkbook* WorkBook;
	bool FitPages;
	int TSW;
	int ZCW;
	bool GridLines;
	System::Extended RHScale;
	bool Formulas;
};


class DELPHICLASS TfrxBiffStyles;
class PASCALIMPLEMENTATION TfrxBiffStyles : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<int> _TfrxBiffStyles__1;
	
	typedef DynamicArray<int> _TfrxBiffStyles__2;
	
	typedef DynamicArray<Graphics::TFont*> _TfrxBiffStyles__3;
	
	
private:
	_TfrxBiffStyles__1 FXFi;
	_TfrxBiffStyles__2 FFonti;
	_TfrxBiffStyles__3 FFonts;
	Frxbiff::TBiffWorkbook* FWorkbook;
	int FTSW;
	int __fastcall CreateStyle(Frxexportmatrix::TfrxIEMStyle* s, bool BgPattern, bool RTL);
	int __fastcall GetEntryIndex(int StyleIndex, bool Background, bool RTL);
	bool __fastcall IsValidStyleIndex(int StyleIndex);
	
public:
	__fastcall TfrxBiffStyles(int StylesCount, Frxbiff::TBiffWorkbook* Workbook, int TSW);
	int __fastcall AddStyle(int StyleIndex, Frxexportmatrix::TfrxIEMStyle* Style, bool Background, bool RTL);
	int __fastcall GetStyle(int StyleIndex, bool Background, bool RTL);
	int __fastcall CreateFont(Graphics::TFont* f, Frxgraphicutils::TSubStyle ss = (Frxgraphicutils::TSubStyle)(0x0));
	int __fastcall AddFont(Graphics::TFont* Font);
	int __fastcall GetFont(Graphics::TFont* Font);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxBiffStyles(void) { }
	
};


class DELPHICLASS TfrxBiffConverter;
class PASCALIMPLEMENTATION TfrxBiffConverter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxBiffPageOptions po;
	bool FShowprogress;
	Frxprogress::TfrxProgress* FProgressBar;
	void __fastcall Convert(Frxbiff::TBiffSheet* Sheet);
	void __fastcall InitProgressBar(int Steps, System::UnicodeString Text);
	void __fastcall StepProgressBarIf(bool Condition);
	void __fastcall FreeProgressBar(void);
	void __fastcall BreakIfTerminated(void);
	void __fastcall SuppressEndingTrash(System::WideString &s);
	Frxbiff::TBiffCell* __fastcall CreateFormulaCell(Frxexportmatrix::TfrxIEMObject* Obj);
	Frxbiff::TBiffTextCell* __fastcall CreateHTMLCell(Frxexportmatrix::TfrxIEMObject* obj, TfrxBiffStyles* Styles);
	Frxbiff::TBiffCell* __fastcall CreateTextCell(Frxexportmatrix::TfrxIEMObject* obj);
	Frxbiff::TBiffCell* __fastcall CreateNumberCell(Frxexportmatrix::TfrxIEMObject* obj);
	Frxbiff::TBiffCell* __fastcall CreateDateCell(Frxexportmatrix::TfrxIEMObject* obj);
	Frxbiff::TBiffCell* __fastcall CreateCell(int r, int c, Frxexportmatrix::TfrxIEMObject* obj, TfrxBiffStyles* Styles);
	bool __fastcall IsFormula(Frxexportmatrix::TfrxIEMObject* Obj);
	void __fastcall SetColWidths(Frxbiff::TBiffSheet* s);
	void __fastcall SetRowHeights(Frxbiff::TBiffSheet* s);
	void __fastcall SetMargin(Frxbiff::TBiffMargin &m);
	void __fastcall SetPageSetup(Frxbiff::TBiffPageSetup* ps);
	void __fastcall AddImage(Frxbiff::TBiffSheet* Sheet, int ObjId);
	void __fastcall MergeCells(Frxbiff::TBiffSheet* Sheet, int ObjId);
	double __fastcall GetColWidthFactor(void);
	double __fastcall GetRowHeightFactor(void);
	double __fastcall GetColWidth(int Col);
	double __fastcall GetRowHeight(int Row);
	
public:
	Frxbiff::TBiffSheet* __fastcall GetSheet(void);
	__property TfrxBiffPageOptions Options = {write=po};
	__property bool ShowProgress = {read=FShowprogress, write=FShowprogress, nodefault};
public:
	/* TObject.Create */ inline __fastcall TfrxBiffConverter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxBiffConverter(void) { }
	
};


class DELPHICLASS ETerminated;
class PASCALIMPLEMENTATION ETerminated : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall ETerminated(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~ETerminated(void) { }
	
};


class DELPHICLASS EInvalidFRFormat;
class PASCALIMPLEMENTATION EInvalidFRFormat : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	/* TObject.Create */ inline __fastcall EInvalidFRFormat(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidFRFormat(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const ShortInt frxPoPortrait = 0x0;
static const ShortInt frxPoLandscape = 0x1;
extern PACKAGE Frxbiff::TBiffSheet* __fastcall frxConvertMatrixToBiffSheet(const TfrxBiffPageOptions &po, bool ShowProgress);

}	/* namespace Frxbiffconverter */
using namespace Frxbiffconverter;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbiffconverterHPP
