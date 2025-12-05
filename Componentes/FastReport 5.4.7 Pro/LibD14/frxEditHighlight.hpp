// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxedithighlight.pas' rev: 21.00

#ifndef FrxedithighlightHPP
#define FrxedithighlightHPP

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
#include <Frxclass.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Frxctrls.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxedithighlight
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxHighlightEditorForm;
class PASCALIMPLEMENTATION TfrxHighlightEditorForm : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OKB;
	Stdctrls::TButton* CancelB;
	Stdctrls::TGroupBox* ConditionsGB;
	Stdctrls::TListBox* HighlightsLB;
	Stdctrls::TButton* AddB;
	Stdctrls::TButton* DeleteB;
	Stdctrls::TButton* EditB;
	Stdctrls::TGroupBox* StyleGB;
	Buttons::TSpeedButton* FrameB;
	Stdctrls::TCheckBox* FrameCB;
	Stdctrls::TCheckBox* FillCB;
	Buttons::TSpeedButton* FillB;
	Stdctrls::TCheckBox* FontCB;
	Buttons::TSpeedButton* FontB;
	Stdctrls::TCheckBox* VisibleCB;
	Buttons::TSpeedButton* UpB;
	Buttons::TSpeedButton* DownB;
	Dialogs::TFontDialog* FontDialog1;
	Extctrls::TPaintBox* PaintBox1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormHide(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
	void __fastcall AddBClick(System::TObject* Sender);
	void __fastcall EditBClick(System::TObject* Sender);
	void __fastcall DeleteBClick(System::TObject* Sender);
	void __fastcall HighlightsLBClick(System::TObject* Sender);
	void __fastcall FrameCBClick(System::TObject* Sender);
	void __fastcall FillCBClick(System::TObject* Sender);
	void __fastcall FontCBClick(System::TObject* Sender);
	void __fastcall VisibleCBClick(System::TObject* Sender);
	void __fastcall FrameBClick(System::TObject* Sender);
	void __fastcall FillBClick(System::TObject* Sender);
	void __fastcall FontBClick(System::TObject* Sender);
	void __fastcall PaintBox1Paint(System::TObject* Sender);
	void __fastcall UpBClick(System::TObject* Sender);
	void __fastcall DownBClick(System::TObject* Sender);
	
private:
	Frxclass::TfrxCustomMemoView* FMemoView;
	Frxclass::TfrxHighlightCollection* FHighlights;
	Frxclass::TfrxHighlight* FCurHighlight;
	void __fastcall UpdateHighlights(void);
	void __fastcall UpdateControls(void);
	void __fastcall Change(void);
	
public:
	__fastcall virtual TfrxHighlightEditorForm(Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxHighlightEditorForm(void);
	void __fastcall HostControls(Controls::TWinControl* Host);
	void __fastcall UnhostControls(Controls::TModalResult AModalResult);
	__property Frxclass::TfrxCustomMemoView* MemoView = {read=FMemoView, write=FMemoView};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxHighlightEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxHighlightEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxedithighlight */
using namespace Frxedithighlight;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxedithighlightHPP
