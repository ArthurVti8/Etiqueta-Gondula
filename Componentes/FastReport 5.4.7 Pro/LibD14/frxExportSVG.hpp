// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexportsvg.pas' rev: 21.00

#ifndef FrxexportsvgHPP
#define FrxexportsvgHPP

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

//-- user supplied -----------------------------------------------------------

namespace Frxexportsvg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxSVGExportDialog;
class PASCALIMPLEMENTATION TfrxSVGExportDialog : public Forms::TForm
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
	/* TCustomForm.Create */ inline __fastcall virtual TfrxSVGExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxSVGExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxSVGExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxSVGExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TfrxSVGExport;
class PASCALIMPLEMENTATION TfrxSVGExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	typedef DynamicArray<Frxexporthelpers::TfrxExportHandler> _TfrxSVGExport__1;
	
	
private:
	bool FOpenAfterExport;
	bool FMultiPage;
	bool FFormatted;
	bool FUnifiedPictures;
	Frxexporthelpers::TfrxPictureFormat FPicFormat;
	Frxexporthelpers::TfrxCSSStyle* FShadowStyle;
	bool FEmbeddedPictures;
	bool FEmbeddedCSS;
	Classes::TStream* FCurrentSVGFile;
	int FCurrentPage;
	Frxexporthelpers::TfrxCSS* FCSS;
	Frxexporthelpers::TfrxPictureStorage* FPictures;
	_TfrxSVGExport__1 FHandlers;
	void __fastcall SetPicFormat(Frxexporthelpers::TfrxPictureFormat Fmt);
	Frxexporthelpers::TfrxCSSStyle* __fastcall GetShadowStyle(void);
	System::UnicodeString __fastcall GetCSSFileName(void);
	System::UnicodeString __fastcall GetCSSFilePath(void);
	void __fastcall SaveCSS(const System::UnicodeString FileName);
	void __fastcall PutsRaw(const System::AnsiString s);
	void __fastcall PutImage(Frxclass::TfrxView* Obj, Graphics::TGraphic* Pic);
	void __fastcall RunExportsChain(Frxclass::TfrxView* Obj);
	void __fastcall StartSVG(double Width, double Height);
	void __fastcall FinishSVG(void);
	bool __fastcall ExportShape(Frxclass::TfrxView* Obj);
	bool __fastcall ExportLine(Frxclass::TfrxView* Obj);
	bool __fastcall ExportGradient(Frxclass::TfrxView* Obj);
	bool __fastcall ExportPicture(Frxclass::TfrxView* Obj);
	bool __fastcall ExportRich(Frxclass::TfrxView* Obj);
	bool __fastcall ExportAsPicture(Frxclass::TfrxView* Obj);
	bool __fastcall ExportMemo(Frxclass::TfrxView* Obj);
	
protected:
	double FGlobalPageY;
	System::UnicodeString FPageRect;
	int FDefineCount;
	void __fastcall PutsA(const System::AnsiString s);
	void __fastcall Puts(const System::UnicodeString s)/* overload */;
	void __fastcall Puts(const System::UnicodeString Fmt, System::TVarRec const *Args, const int Args_Size)/* overload */;
	System::UnicodeString __fastcall LockStyle(Frxexporthelpers::TfrxCSSStyle* Style);
	void __fastcall DoGradient(Frxclass::TfrxView* Obj, System::UnicodeString BeginValue, System::UnicodeString EndValue, Frxgradient::TfrxGradientStyle Style);
	void __fastcall DoFrameLine(double x1, double y1, double x2, double y2, Frxclass::TfrxFrameLine* frxFrameLine);
	void __fastcall DoFill(Frxclass::TfrxView* Obj);
	void __fastcall DoFrame(Frxclass::TfrxView* Obj);
	void __fastcall DoFilledRect(Frxclass::TfrxView* Obj, System::UnicodeString FillValue);
	void __fastcall DoBackground(Frxclass::TfrxView* Obj);
	bool __fastcall DoHyperLink(Frxclass::TfrxView* Obj);
	void __fastcall DoExportAsPicture(Frxclass::TfrxView* Obj, bool Transparent, Graphics::TColor TransparentColor = (Graphics::TColor)(0x1fffffff));
	System::UnicodeString __fastcall WrapByCrLf(const System::UnicodeString Text, /* out */ int &BreakCount, const double x, const double dy);
	System::UnicodeString __fastcall EscapeTextAndAttribute(const System::UnicodeString s);
	
public:
	__fastcall virtual TfrxSVGExport(Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxSVGExport(void);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall Finish(void);
	void __fastcall AttachHandler(Frxexporthelpers::TfrxExportHandler Handler);
	__property Frxexporthelpers::TfrxCSSStyle* ShadowStyle = {read=GetShadowStyle};
	
__published:
	__property OverwritePrompt;
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, nodefault};
	__property bool MultiPage = {read=FMultiPage, write=FMultiPage, nodefault};
	__property bool Formatted = {read=FFormatted, write=FFormatted, nodefault};
	__property Frxexporthelpers::TfrxPictureFormat PictureFormat = {read=FPicFormat, write=SetPicFormat, nodefault};
	__property bool UnifiedPictures = {read=FUnifiedPictures, write=FUnifiedPictures, nodefault};
	__property bool EmbeddedPictures = {read=FEmbeddedPictures, write=FEmbeddedPictures, nodefault};
	__property bool EmbeddedCSS = {read=FEmbeddedCSS, write=FEmbeddedCSS, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxSVGExport(void) : Frxclass::TfrxCustomExportFilter() { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexportsvg */
using namespace Frxexportsvg;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportsvgHPP
