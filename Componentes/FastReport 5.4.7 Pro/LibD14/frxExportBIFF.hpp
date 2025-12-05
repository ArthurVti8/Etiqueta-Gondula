// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexportbiff.pas' rev: 21.00

#ifndef FrxexportbiffHPP
#define FrxexportbiffHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Shellapi.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxexportmatrix.hpp>	// Pascal unit
#include <Frxprogress.hpp>	// Pascal unit
#include <Frxstorage.hpp>	// Pascal unit
#include <Frxbiff.hpp>	// Pascal unit
#include <Frxoleps.hpp>	// Pascal unit
#include <Frxescher.hpp>	// Pascal unit
#include <Frxdraftpool.hpp>	// Pascal unit
#include <Frxbiffconverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexportbiff
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxDraftSheet;
class PASCALIMPLEMENTATION TfrxDraftSheet : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Frxbiffconverter::TfrxBiffPageOptions Options;
public:
	/* TObject.Create */ inline __fastcall TfrxDraftSheet(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxDraftSheet(void) { }
	
};


class DELPHICLASS TfrxBIFFExportDialog;
class PASCALIMPLEMENTATION TfrxBIFFExportDialog : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkB;
	Stdctrls::TButton* CancelB;
	Comctrls::TPageControl* pc1;
	Comctrls::TTabSheet* tsGeneral;
	Stdctrls::TGroupBox* GroupPageRange;
	Stdctrls::TLabel* DescrL;
	Stdctrls::TRadioButton* AllRB;
	Stdctrls::TRadioButton* CurPageRB;
	Stdctrls::TRadioButton* PageNumbersRB;
	Stdctrls::TEdit* PageNumbersE;
	Stdctrls::TGroupBox* gbGroup;
	Stdctrls::TRadioButton* rbOriginal;
	Stdctrls::TRadioButton* rbSingle;
	Stdctrls::TRadioButton* rbChunks;
	Stdctrls::TEdit* edChunk;
	Dialogs::TSaveDialog* sd;
	Comctrls::TTabSheet* tsInfo;
	Stdctrls::TLabel* lbTitle;
	Stdctrls::TEdit* edTitle;
	Stdctrls::TLabel* lbAuthor;
	Stdctrls::TEdit* edAuthor;
	Stdctrls::TLabel* lbKeywords;
	Stdctrls::TEdit* edKeywords;
	Stdctrls::TLabel* lbRevision;
	Stdctrls::TEdit* edRevision;
	Stdctrls::TLabel* lbAppName;
	Stdctrls::TEdit* edAppName;
	Stdctrls::TLabel* lbSubject;
	Stdctrls::TEdit* edSubject;
	Stdctrls::TLabel* lbCategory;
	Stdctrls::TEdit* edCategory;
	Stdctrls::TLabel* lbCompany;
	Stdctrls::TEdit* edCompany;
	Stdctrls::TLabel* lbManager;
	Stdctrls::TEdit* edManager;
	Stdctrls::TLabel* lbComment;
	Stdctrls::TMemo* edComment;
	Comctrls::TTabSheet* tsProt;
	Stdctrls::TLabel* lbPass;
	Stdctrls::TEdit* edPass1;
	Stdctrls::TLabel* lbPassInfo;
	Stdctrls::TLabel* lbPassConf;
	Stdctrls::TEdit* edPass2;
	Stdctrls::TCheckBox* OpenCB;
	Stdctrls::TCheckBox* cbAutoCreateFile;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TCheckBox* cbPreciseQuality;
	Stdctrls::TCheckBox* cbPictures;
	Stdctrls::TCheckBox* cbGridLines;
	Stdctrls::TCheckBox* cbFit;
	Stdctrls::TCheckBox* cbDelEmptyRows;
	Stdctrls::TCheckBox* cbFormulas;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxBIFFExportDialog(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxBIFFExportDialog(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxBIFFExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxBIFFExportDialog(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TfrxBIFFExport;
class PASCALIMPLEMENTATION TfrxBIFFExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FOpenAfterExport;
	int FParallelPages;
	Frxprogress::TfrxProgress* FProgress;
	bool FSingleSheet;
	bool FDeleteEmptyRows;
	int FChunkSize;
	bool FGridLines;
	System::Extended FInaccuracy;
	bool FFitPages;
	bool FPictures;
	System::Extended FRowHeightScale;
	bool FExportFormulas;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	Frxbiff::TBiffWorkbook* FWB;
	int FZCW;
	int FTSW;
	Frxbiffconverter::TfrxPageInfo FLastPage;
	Frxdraftpool::TDpDraftPool* FDraftPool;
	System::AnsiString FAuthor;
	System::AnsiString FComment;
	System::AnsiString FKeywords;
	System::AnsiString FRevision;
	System::AnsiString FAppName;
	System::AnsiString FSubject;
	System::AnsiString FCategory;
	System::AnsiString FCompany;
	System::AnsiString FTitle;
	unsigned FAccess;
	System::AnsiString FManager;
	System::WideString FPassword;
	void __fastcall SetChunkSize(int Value);
	void __fastcall SetPassword(const System::WideString s);
	void __fastcall SetParallelPages(int Count);
	void __fastcall SetRowHeightScale(System::Extended Value);
	Frxbiffconverter::TfrxBiffPageOptions __fastcall GetExportOptionsDraft(void);
	void __fastcall SaveWorkbook(Classes::TStream* s);
	void __fastcall SaveSI(Classes::TStream* s);
	void __fastcall SaveDSI(Classes::TStream* s);
	void __fastcall InitProgressBar(int Steps, System::UnicodeString Text);
	void __fastcall StepProgressBar(void);
	void __fastcall FreeProgressBar(void);
	
public:
	__fastcall virtual TfrxBIFFExport(Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual Controls::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	bool __fastcall UseParallelPages(void);
	Frxexportmatrix::TfrxIEMatrix* __fastcall CreateMatrix(void);
	void __fastcall ExportPage(System::TObject* Draft);
	
__published:
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property OverwritePrompt;
	__property bool SingleSheet = {read=FSingleSheet, write=FSingleSheet, default=0};
	__property bool DeleteEmptyRows = {read=FDeleteEmptyRows, write=FDeleteEmptyRows, default=0};
	__property System::Extended RowHeightScale = {read=FRowHeightScale, write=SetRowHeightScale};
	__property int ChunkSize = {read=FChunkSize, write=SetChunkSize, nodefault};
	__property bool GridLines = {read=FGridLines, write=FGridLines, default=1};
	__property System::Extended Inaccuracy = {read=FInaccuracy, write=FInaccuracy};
	__property bool FitPages = {read=FFitPages, write=FFitPages, nodefault};
	__property bool Pictures = {read=FPictures, write=FPictures, nodefault};
	__property System::AnsiString Author = {read=FAuthor, write=FAuthor};
	__property System::AnsiString Comment = {read=FComment, write=FComment};
	__property System::AnsiString Keywords = {read=FKeywords, write=FKeywords};
	__property System::AnsiString Revision = {read=FRevision, write=FRevision};
	__property System::AnsiString AppName = {read=FAppName, write=FAppName};
	__property System::AnsiString Subject = {read=FSubject, write=FSubject};
	__property System::AnsiString Category = {read=FCategory, write=FCategory};
	__property System::AnsiString Company = {read=FCompany, write=FCompany};
	__property System::AnsiString Title = {read=FTitle, write=FTitle};
	__property System::AnsiString Manager = {read=FManager, write=FManager};
	__property System::WideString Password = {read=FPassword, write=SetPassword};
	__property int ParallelPages = {read=FParallelPages, write=SetParallelPages, nodefault};
	__property bool ExportFormulas = {read=FExportFormulas, write=FExportFormulas, default=1};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxBIFFExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxBIFFExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxexportbiff */
using namespace Frxexportbiff;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportbiffHPP
