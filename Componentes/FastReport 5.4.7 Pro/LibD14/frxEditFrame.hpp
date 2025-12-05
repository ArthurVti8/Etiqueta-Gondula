// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxeditframe.pas' rev: 21.00

#ifndef FrxeditframeHPP
#define FrxeditframeHPP

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
#include <Imglist.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Toolwin.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Frxctrls.hpp>	// Pascal unit
#include <Frxdock.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Frxdesgnctrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxeditframe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxFrameEditorForm;
class PASCALIMPLEMENTATION TfrxFrameEditorForm : public Forms::TForm
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkB;
	Stdctrls::TButton* CancelB;
	Stdctrls::TGroupBox* FrameGB;
	Buttons::TSpeedButton* FrameAllB;
	Buttons::TSpeedButton* FrameNoB;
	Buttons::TSpeedButton* FrameTopB;
	Buttons::TSpeedButton* FrameBottomB;
	Buttons::TSpeedButton* FrameLeftB;
	Buttons::TSpeedButton* FrameRightB;
	Stdctrls::TCheckBox* ShadowCB;
	Stdctrls::TLabel* ShadowWidthL;
	Stdctrls::TComboBox* ShadowWidthCB;
	Stdctrls::TLabel* ShadowColorL;
	Stdctrls::TGroupBox* LineGB;
	Stdctrls::TLabel* LineStyleL;
	Stdctrls::TLabel* LineWidthL;
	Stdctrls::TComboBox* LineWidthCB;
	Stdctrls::TLabel* LineColorL;
	Stdctrls::TLabel* HintL;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, Classes::TShiftState Shift);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FrameAllBClick(System::TObject* Sender);
	void __fastcall FrameNoBClick(System::TObject* Sender);
	void __fastcall FrameLineClick(System::TObject* Sender);
	void __fastcall ShadowCBClick(System::TObject* Sender);
	void __fastcall ShadowWidthCBChange(System::TObject* Sender);
	
private:
	Frxclass::TfrxFrame* FFrame;
	Frxdesgnctrls::TfrxFrameSampleControl* SampleC;
	Frxdesgnctrls::TfrxLineStyleControl* LineStyleC;
	Frxdesgnctrls::TfrxColorComboBox* ShadowColorCB;
	Frxdesgnctrls::TfrxColorComboBox* LineColorCB;
	void __fastcall SetFrame(const Frxclass::TfrxFrame* Value);
	void __fastcall FrameLineClicked(Frxclass::TfrxFrameType Line, bool state);
	void __fastcall ShadowColorChanged(System::TObject* Sender);
	Frxclass::TfrxFrameStyle __fastcall LineStyle(void);
	System::Extended __fastcall LineWidth(void);
	Graphics::TColor __fastcall LineColor(void);
	void __fastcall UpdateControls(void);
	void __fastcall Change(void);
	
public:
	__property Frxclass::TfrxFrame* Frame = {read=FFrame, write=SetFrame};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxFrameEditorForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxFrameEditorForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxFrameEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxFrameEditorForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxeditframe */
using namespace Frxeditframe;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxeditframeHPP
