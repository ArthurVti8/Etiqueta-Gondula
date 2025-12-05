// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexporthtmldiv.pas' rev: 21.00

#ifndef FrxexporthtmldivHPP
#define FrxexporthtmldivHPP

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
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Shellapi.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxcrypto.hpp>	// Pascal unit
#include <Frxstorage.hpp>	// Pascal unit
#include <Frxgradient.hpp>	// Pascal unit
#include <Frxexporthelpers.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexporthtmldiv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxHTMLDivExportDialog;
class PASCALIMPLEMENTATION TfrxHTMLDivExportDialog : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkB;
	Stdctrls::TButton* CancelB;
	Stdctrls::TGroupBox* GroupPageRange;
	Stdctrls::TLabel* DescrL;
	Stdctrls::TRadioButton* AllRB;
	Stdctrls::TRadioButton* CurPageRB;
	Stdctrls::TRadioButton* PageNumbersRB;
	Stdctrls::TEdit* PageNumbersE;
	Stdctrls::TGroupBox* gbOptions;
	Stdctrls::TCheckBox* OpenCB;
	Dialogs::TSaveDialog* sd;
	Stdctrls::TGroupBox* GroupQuality;
	Stdctrls::TLabel* PicturesL;
	Stdctrls::TCheckBox* StylesCB;
	Stdctrls::TCheckBox* UnifiedPicturesCB;
	Stdctrls::TCheckBox* PicturesCB;
	Stdctrls::TCheckBox* MultipageCB;
	Stdctrls::TComboBox* PFormatCB;
	Stdctrls::TCheckBox* FormattedCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxHTMLDivExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxHTMLDivExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxHTMLDivExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxHTMLDivExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TfrxHTMLItem;
class PASCALIMPLEMENTATION TfrxHTMLItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString operator[](System::UnicodeString Index) { return Prop[Index]; }
	
private:
	System::UnicodeString FName;
	Classes::TStrings* FKeys;
	Classes::TStrings* FValues;
	System::UnicodeString FValue;
	Frxstorage::TObjList* FChildren;
	System::Extended FLeft;
	System::Extended FTop;
	System::Extended FWidth;
	System::Extended FHeight;
	bool FLeftSet;
	bool FTopSet;
	bool FWidthSet;
	bool FHeightSet;
	Frxexporthelpers::TfrxCSSStyle* FStyle;
	System::UnicodeString FClass;
	void __fastcall SetProp(System::UnicodeString Index, const System::UnicodeString Value);
	Frxexporthelpers::TfrxCSSStyle* __fastcall GetStyle(void);
	void __fastcall SetLeft(System::Extended a);
	void __fastcall SetTop(System::Extended a);
	void __fastcall SetWidth(System::Extended a);
	void __fastcall SetHeight(System::Extended a);
	System::UnicodeString __fastcall GetProp(System::UnicodeString Index);
	
public:
	__fastcall TfrxHTMLItem(const System::UnicodeString Name);
	__fastcall virtual ~TfrxHTMLItem(void);
	TfrxHTMLItem* __fastcall This(void);
	System::UnicodeString __fastcall EscapeAttribute(const System::UnicodeString s);
	void __fastcall Save(Classes::TStream* Stream, bool Formatted);
	TfrxHTMLItem* __fastcall Add(const System::UnicodeString Tag)/* overload */;
	TfrxHTMLItem* __fastcall Add(TfrxHTMLItem* Item)/* overload */;
	void __fastcall AddCSSClass(const System::UnicodeString s);
	__property System::UnicodeString Prop[System::UnicodeString Index] = {read=GetProp, write=SetProp/*, default*/};
	__property System::UnicodeString Value = {write=FValue};
	__property System::UnicodeString Name = {write=FName};
	__property Frxexporthelpers::TfrxCSSStyle* Style = {read=GetStyle};
	__property System::Extended Left = {read=FLeft, write=SetLeft};
	__property System::Extended Top = {read=FTop, write=SetTop};
	__property System::Extended Width = {read=FWidth, write=SetWidth};
	__property System::Extended Height = {read=FHeight, write=SetHeight};
};


class DELPHICLASS TfrxHTMLItemQueue;
class PASCALIMPLEMENTATION TfrxHTMLItemQueue : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<TfrxHTMLItem*> _TfrxHTMLItemQueue__1;
	
	
private:
	_TfrxHTMLItemQueue__1 FQueue;
	int FUsed;
	Classes::TStream* FStream;
	bool FFormatted;
	
protected:
	void __fastcall Flush(void);
	
public:
	__fastcall TfrxHTMLItemQueue(Classes::TStream* Stream, bool Formatted);
	__fastcall virtual ~TfrxHTMLItemQueue(void);
	void __fastcall Push(TfrxHTMLItem* Item);
	void __fastcall SetQueueLength(int n);
};


class DELPHICLASS TfrxBoundsGauge;
class PASCALIMPLEMENTATION TfrxBoundsGauge : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Frxclass::TfrxView* FObj;
	bool FBoundsSet;
	Types::TRect FBounds;
	Types::TRect FBorders;
	int FX;
	int FY;
	int FX1;
	int FY1;
	int FDX;
	int FDY;
	int FFrameWidth;
	void __fastcall SetObj(Frxclass::TfrxView* Obj);
	void __fastcall AddBounds(const Types::TRect &r);
	int __fastcall GetInnerWidth(void);
	int __fastcall GetInnerHeight(void);
	
protected:
	void __fastcall BeginDraw(void);
	void __fastcall DrawBackground(void);
	void __fastcall DrawFrame(void);
	void __fastcall DrawLine(int x1, int y1, int x2, int y2, int w, Frxclass::TfrxFrameType Side);
	
public:
	__property Frxclass::TfrxView* Obj = {read=FObj, write=SetObj};
	__property Types::TRect Bounds = {read=FBounds};
	__property Types::TRect Borders = {read=FBorders};
	__property int InnerWidth = {read=GetInnerWidth, nodefault};
	__property int InnerHeight = {read=GetInnerHeight, nodefault};
public:
	/* TObject.Create */ inline __fastcall TfrxBoundsGauge(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxBoundsGauge(void) { }
	
};


class DELPHICLASS TfrxHTMLDivExport;
class PASCALIMPLEMENTATION TfrxHTMLDivExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	typedef DynamicArray<Frxexporthelpers::TfrxExportHandler> _TfrxHTMLDivExport__1;
	
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FTitle;
	bool FHTML5;
	bool FMultiPage;
	bool FFormatted;
	Frxexporthelpers::TfrxPictureFormat FPicFormat;
	bool FAllPictures;
	bool FUnifiedPictures;
	Frxexporthelpers::TfrxCSSStyle* FPageStyle;
	bool FNavigation;
	bool FExportAnchors;
	bool FEmbeddedPictures;
	bool FEmbeddedCSS;
	int FPictureTag;
	Classes::TStream* FCurrentHTMLFile;
	int FCurrentPage;
	Frxexporthelpers::TfrxCSS* FCSS;
	TfrxHTMLItemQueue* FQueue;
	Frxexporthelpers::TfrxPictureStorage* FPictures;
	_TfrxHTMLDivExport__1 FHandlers;
	TfrxBoundsGauge* FGauge;
	System::UnicodeString FPictureFolder;
	void __fastcall SetPicFormat(Frxexporthelpers::TfrxPictureFormat Fmt);
	Frxexporthelpers::TfrxCSSStyle* __fastcall GetPageStyle(void);
	bool __fastcall GetAnchor(System::UnicodeString &Page, const System::UnicodeString Name);
	System::UnicodeString __fastcall GetHRef(const System::UnicodeString URL);
	System::UnicodeString __fastcall GetCSSFileName(void);
	System::UnicodeString __fastcall GetCSSFilePath(void);
	void __fastcall SaveCSS(const System::UnicodeString FileName);
	void __fastcall PutsRaw(const System::AnsiString s);
	void __fastcall PutImg(Frxclass::TfrxView* Obj, Graphics::TGraphic* Pic, bool WriteSize);
	void __fastcall RunExportsChain(Frxclass::TfrxView* Obj);
	void __fastcall StartHTML(void);
	void __fastcall EndHTML(void);
	bool __fastcall ExportTaggedView(Frxclass::TfrxView* Obj);
	bool __fastcall ExportAllPictures(Frxclass::TfrxView* Obj);
	bool __fastcall ExportMemo(Frxclass::TfrxView* Obj);
	bool __fastcall ExportPicture(Frxclass::TfrxView* Obj);
	bool __fastcall ExportRectangle(Frxclass::TfrxView* Obj);
	bool __fastcall ExportLine(Frxclass::TfrxView* Obj);
	bool __fastcall ExportShape(Frxclass::TfrxView* Obj);
	bool __fastcall ExportGradient(Frxclass::TfrxView* Obj);
	bool __fastcall ExportRich(Frxclass::TfrxView* Obj);
	bool __fastcall ExportAsPicture(Frxclass::TfrxView* Obj);
	void __fastcall SetPictureFolder(const System::UnicodeString Value);
	
protected:
	void __fastcall PutsA(const System::AnsiString s);
	void __fastcall Puts(const System::UnicodeString s)/* overload */;
	void __fastcall Puts(const System::UnicodeString Fmt, System::TVarRec const *Args, const int Args_Size)/* overload */;
	TfrxHTMLItem* __fastcall AddTag(const System::UnicodeString Name);
	System::UnicodeString __fastcall LockStyle(Frxexporthelpers::TfrxCSSStyle* Style);
	TfrxHTMLItem* __fastcall CreateDiv(Frxclass::TfrxView* Obj, bool DrawFrame = true);
	TfrxHTMLItem* __fastcall CreateFrameDiv(Frxclass::TfrxView* Obj, bool DrawFrame = true);
	TfrxHTMLItem* __fastcall CreateFillDiv(Frxclass::TfrxView* Obj);
	void __fastcall FillFrameProps(Frxexporthelpers::TfrxCSSStyle* Style, Frxclass::TfrxFrame* Frame);
	void __fastcall FillGraduienProps(Frxexporthelpers::TfrxCSSStyle* Style, Graphics::TColor BeginColor, Graphics::TColor EndColor, Frxgradient::TfrxGradientStyle GradientStyle);
	System::UnicodeString __fastcall FilterHTML(const System::UnicodeString Text);
	System::UnicodeString __fastcall EscapeText(const System::UnicodeString s);
	System::UnicodeString __fastcall DoHyperLink(System::UnicodeString Text, Frxclass::TfrxView* Obj);
	void __fastcall DoExportAsPicture(Frxclass::TfrxView* Obj, bool Transparent, Graphics::TColor TransparentColor = (Graphics::TColor)(0x1fffffff));
	
public:
	__fastcall virtual TfrxHTMLDivExport(Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxHTMLDivExport(void);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall Finish(void);
	void __fastcall AttachHandler(Frxexporthelpers::TfrxExportHandler Handler);
	__property Frxexporthelpers::TfrxCSSStyle* PageStyle = {read=GetPageStyle};
	__property System::UnicodeString PictureFolder = {read=FPictureFolder, write=SetPictureFolder};
	
__published:
	__property OverwritePrompt;
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, nodefault};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	__property bool HTML5 = {read=FHTML5, write=FHTML5, nodefault};
	__property bool MultiPage = {read=FMultiPage, write=FMultiPage, nodefault};
	__property bool Formatted = {read=FFormatted, write=FFormatted, nodefault};
	__property Frxexporthelpers::TfrxPictureFormat PictureFormat = {read=FPicFormat, write=SetPicFormat, nodefault};
	__property bool AllPictures = {read=FAllPictures, write=FAllPictures, nodefault};
	__property bool UnifiedPictures = {read=FUnifiedPictures, write=FUnifiedPictures, nodefault};
	__property bool EmbeddedPictures = {read=FEmbeddedPictures, write=FEmbeddedPictures, nodefault};
	__property bool Navigation = {read=FNavigation, write=FNavigation, nodefault};
	__property bool ExportAnchors = {read=FExportAnchors, write=FExportAnchors, nodefault};
	__property bool EmbeddedCSS = {read=FEmbeddedCSS, write=FEmbeddedCSS, nodefault};
	__property int PictureTag = {read=FPictureTag, write=FPictureTag, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTMLDivExport(void) : Frxclass::TfrxCustomExportFilter() { }
	
};


class DELPHICLASS TfrxHTML5DivExport;
class PASCALIMPLEMENTATION TfrxHTML5DivExport : public TfrxHTMLDivExport
{
	typedef TfrxHTMLDivExport inherited;
	
public:
	__fastcall virtual TfrxHTML5DivExport(Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
public:
	/* TfrxHTMLDivExport.Destroy */ inline __fastcall virtual ~TfrxHTML5DivExport(void) { }
	
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTML5DivExport(void) : TfrxHTMLDivExport() { }
	
};


class DELPHICLASS TfrxHTML4DivExport;
class PASCALIMPLEMENTATION TfrxHTML4DivExport : public TfrxHTMLDivExport
{
	typedef TfrxHTMLDivExport inherited;
	
public:
	__fastcall virtual TfrxHTML4DivExport(Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
public:
	/* TfrxHTMLDivExport.Destroy */ inline __fastcall virtual ~TfrxHTML4DivExport(void) { }
	
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTML4DivExport(void) : TfrxHTMLDivExport() { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexporthtmldiv */
using namespace Frxexporthtmldiv;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporthtmldivHPP
