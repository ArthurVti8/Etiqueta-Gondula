// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxeditfill.pas' rev: 21.00

#ifndef FrxeditfillHPP
#define FrxeditfillHPP

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
#include <Comctrls.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxdesgnctrls.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxeditfill
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxFillEditorForm;
class PASCALIMPLEMENTATION TfrxFillEditorForm : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Comctrls::TPageControl* PageControl;
	Comctrls::TTabSheet* BrushTS;
	Comctrls::TTabSheet* GradientTS;
	Comctrls::TTabSheet* GlassTS;
	Stdctrls::TLabel* BrushBackColorL;
	Stdctrls::TLabel* BrushForeColorL;
	Stdctrls::TLabel* BrushStyleL;
	Stdctrls::TComboBox* BrushStyleCB;
	Stdctrls::TLabel* GradientStyleL;
	Stdctrls::TComboBox* GradientStyleCB;
	Stdctrls::TComboBox* ComboBox5;
	Stdctrls::TLabel* GradientStartColorL;
	Stdctrls::TLabel* GradientEndColorL;
	Stdctrls::TComboBox* ComboBox6;
	Stdctrls::TLabel* GlassOrientationL;
	Stdctrls::TComboBox* GlassOrientationCB;
	Stdctrls::TLabel* GlassColorL;
	Stdctrls::TLabel* GlassBlendL;
	Stdctrls::TCheckBox* GlassHatchCB;
	Stdctrls::TButton* OKB;
	Stdctrls::TButton* CancelB;
	Extctrls::TPanel* SampleP;
	Stdctrls::TEdit* GlassBlendE;
	Extctrls::TPaintBox* PaintBox1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PaintBox1Paint(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall BrushStyleCBDrawItem(Controls::TWinControl* Control, int Index, const Types::TRect &ARect, Windows::TOwnerDrawState State);
	void __fastcall PageControlChange(System::TObject* Sender);
	void __fastcall BrushStyleCBChange(System::TObject* Sender);
	void __fastcall GradientStyleCBChange(System::TObject* Sender);
	void __fastcall GlassOrientationCBChange(System::TObject* Sender);
	void __fastcall GlassHatchCBClick(System::TObject* Sender);
	void __fastcall GlassBlendEExit(System::TObject* Sender);
	
private:
	Frxclass::TfrxBrushFill* FBrushFill;
	Frxclass::TfrxGradientFill* FGradientFill;
	Frxclass::TfrxGlassFill* FGlassFill;
	bool FIsSimpleFill;
	Frxdesgnctrls::TfrxColorComboBox* BrushBackColorCB;
	Frxdesgnctrls::TfrxColorComboBox* BrushForeColorCB;
	Frxdesgnctrls::TfrxColorComboBox* GradientStartColorCB;
	Frxdesgnctrls::TfrxColorComboBox* GradientEndColorCB;
	Frxdesgnctrls::TfrxColorComboBox* GlassColorCB;
	Frxclass::TfrxCustomFill* __fastcall GetFill(void);
	void __fastcall SetFill(Frxclass::TfrxCustomFill* Value);
	void __fastcall SetIsSimpleFill(bool Value);
	void __fastcall UpdateControls(void);
	void __fastcall Change(void);
	void __fastcall BrushBackColorChanged(System::TObject* Sender);
	void __fastcall BrushForeColorChanged(System::TObject* Sender);
	void __fastcall GradientStartColorChanged(System::TObject* Sender);
	void __fastcall GradientEndColorChanged(System::TObject* Sender);
	void __fastcall GlassColorChanged(System::TObject* Sender);
	
public:
	__property Frxclass::TfrxCustomFill* Fill = {read=GetFill, write=SetFill};
	__property bool IsSimpleFill = {read=FIsSimpleFill, write=SetIsSimpleFill, nodefault};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxFillEditorForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxFillEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxFillEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxFillEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxeditfill */
using namespace Frxeditfill;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxeditfillHPP
