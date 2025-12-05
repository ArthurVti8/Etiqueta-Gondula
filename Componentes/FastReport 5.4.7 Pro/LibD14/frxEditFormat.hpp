// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxeditformat.pas' rev: 21.00

#ifndef FrxeditformatHPP
#define FrxeditformatHPP

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
#include <Variants.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxeditformat
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxFormatEditorForm;
class PASCALIMPLEMENTATION TfrxFormatEditorForm : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkB;
	Stdctrls::TButton* CancelB;
	Stdctrls::TListBox* CategoryLB;
	Stdctrls::TListBox* FormatLB;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* FormatStrL;
	Stdctrls::TLabel* SeparatorL;
	Stdctrls::TEdit* FormatE;
	Stdctrls::TEdit* SeparatorE;
	Stdctrls::TComboBox* ComboBox1;
	Stdctrls::TLabel* ExpressionL;
	Stdctrls::TLabel* CategoryL;
	Stdctrls::TLabel* FormatL;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CategoryLBClick(System::TObject* Sender);
	void __fastcall FormatLBDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &ARect, Windows::TOwnerDrawState State);
	void __fastcall FormatLBClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormHide(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	
private:
	Frxclass::TfrxCustomMemoView* FMemo;
	System::WideString FMemoText;
	Frxclass::TfrxFormatCollection* FFormats;
	Frxclass::TfrxFormat* FCurFormat;
	void __fastcall FillFormats(void);
	void __fastcall SetMemo(Frxclass::TfrxCustomMemoView* Value);
	void __fastcall UpdateCurFormat(void);
	void __fastcall UpdateControls(void);
	
public:
	__fastcall virtual TfrxFormatEditorForm(Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxFormatEditorForm(void);
	void __fastcall HostControls(Controls::TWinControl* Host);
	void __fastcall UnhostControls(Controls::TModalResult AModalResult);
	__property Frxclass::TfrxCustomMemoView* Memo = {read=FMemo, write=SetMemo};
	__property System::WideString MemoText = {read=FMemoText, write=FMemoText};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxFormatEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxFormatEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxeditformat */
using namespace Frxeditformat;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxeditformatHPP
