// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxexporttxtprn.pas' rev: 21.00

#ifndef FrxexporttxtprnHPP
#define FrxexporttxtprnHPP

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
#include <Extctrls.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Checklst.hpp>	// Pascal unit
#include <Frxexporttxt.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Mask.hpp>	// Pascal unit
#include <Frxres.hpp>	// Pascal unit
#include <Frxrcexports.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxexporttxtprn
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxPrnInit;
class PASCALIMPLEMENTATION TfrxPrnInit : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OK;
	Stdctrls::TButton* Cancel;
	Dialogs::TOpenDialog* OpenDialog1;
	Dialogs::TSaveDialog* SaveDialog1;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label4;
	Extctrls::TImage* Image1;
	Stdctrls::TComboBox* CB1;
	Stdctrls::TButton* PropButton;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TLabel* Label2;
	Extctrls::TPanel* Panel2;
	Stdctrls::TGroupBox* GroupBox2;
	Checklst::TCheckListBox* CheckListBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TComboBox* ComboBox1;
	Buttons::TSpeedButton* Button1;
	Buttons::TSpeedButton* Button2;
	Mask::TMaskEdit* E1;
	Comctrls::TUpDown* UpDown1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ComboBox1Change(System::TObject* Sender);
	void __fastcall CheckListBox1ClickCheck(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall FormDeactivate(System::TObject* Sender);
	void __fastcall PropButtonClick(System::TObject* Sender);
	void __fastcall CB1Click(System::TObject* Sender);
	void __fastcall CB1DrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &ARect, Windows::TOwnerDrawState State);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
	
private:
	Frxexporttxt::TfrxTXTExport* exp;
	int OldIndex;
	void __fastcall Localize(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxPrnInit(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxPrnInit(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxPrnInit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxPrnInit(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TfrxPrnInit* frxPrnInit;

}	/* namespace Frxexporttxtprn */
using namespace Frxexporttxtprn;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporttxtprnHPP
