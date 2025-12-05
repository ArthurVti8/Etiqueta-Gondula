// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxedithyperlink.pas' rev: 21.00

#ifndef FrxedithyperlinkHPP
#define FrxedithyperlinkHPP

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
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxctrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxedithyperlink
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxHyperlinkEditorForm;
class PASCALIMPLEMENTATION TfrxHyperlinkEditorForm : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKB;
	Stdctrls::TButton* CancelB;
	Stdctrls::TGroupBox* KindGB;
	Stdctrls::TRadioButton* UrlRB;
	Stdctrls::TRadioButton* PageNumberRB;
	Stdctrls::TRadioButton* AnchorRB;
	Stdctrls::TRadioButton* ReportRB;
	Stdctrls::TRadioButton* ReportPageRB;
	Stdctrls::TRadioButton* CustomRB;
	Stdctrls::TGroupBox* PropertiesGB;
	Extctrls::TPanel* UrlP;
	Stdctrls::TLabel* UrlL;
	Stdctrls::TEdit* UrlE;
	Stdctrls::TLabel* UrlExprL;
	Frxctrls::TfrxComboEdit* UrlExprE;
	Stdctrls::TLabel* Hint1L;
	Stdctrls::TLabel* Hint2L;
	Extctrls::TPanel* PageNumberP;
	Stdctrls::TLabel* PageNumberL;
	Stdctrls::TLabel* PageNumberExprL;
	Stdctrls::TEdit* PageNumberE;
	Frxctrls::TfrxComboEdit* PageNumberExprE;
	Extctrls::TPanel* AnchorP;
	Stdctrls::TLabel* AnchorL;
	Stdctrls::TLabel* AnchorExprL;
	Stdctrls::TEdit* AnchorE;
	Frxctrls::TfrxComboEdit* AnchorExprE;
	Extctrls::TPanel* CustomP;
	Stdctrls::TLabel* CustomL;
	Stdctrls::TLabel* CustomExprL;
	Stdctrls::TEdit* CustomE;
	Frxctrls::TfrxComboEdit* CustomExprE;
	Extctrls::TPanel* ReportP;
	Stdctrls::TLabel* ReportValueL;
	Stdctrls::TLabel* ReportExprL;
	Stdctrls::TEdit* ReportValueE;
	Frxctrls::TfrxComboEdit* ReportExprE;
	Stdctrls::TLabel* ReportNameL;
	Frxctrls::TfrxComboEdit* ReportNameE;
	Stdctrls::TLabel* ReportParamL;
	Stdctrls::TComboBox* ReportParamCB;
	Extctrls::TPanel* ReportPageP;
	Stdctrls::TLabel* ReportPageValueL;
	Stdctrls::TLabel* ReportPageExprL;
	Stdctrls::TLabel* ReportPageL;
	Stdctrls::TLabel* ReportPageParamL;
	Stdctrls::TEdit* ReportPageValueE;
	Frxctrls::TfrxComboEdit* ReportPageExprE;
	Stdctrls::TComboBox* ReportPageParamCB;
	Stdctrls::TComboBox* ReportPageCB;
	Dialogs::TOpenDialog* OpenDialog;
	Stdctrls::TCheckBox* ModifyAppearanceCB;
	void __fastcall UrlRBClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ExprClick(System::TObject* Sender);
	void __fastcall FormHide(System::TObject* Sender);
	void __fastcall ReportNameEButtonClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	void __fastcall FillVariablesList(Frxclass::TfrxReport* Report, Classes::TStrings* List)/* overload */;
	void __fastcall FillVariablesList(const System::UnicodeString FileName, Classes::TStrings* List)/* overload */;
	void __fastcall FillPagesList(void);
	
public:
	Frxclass::TfrxView* View;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxHyperlinkEditorForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxHyperlinkEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxHyperlinkEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxHyperlinkEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxedithyperlink */
using namespace Frxedithyperlink;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxedithyperlinkHPP
