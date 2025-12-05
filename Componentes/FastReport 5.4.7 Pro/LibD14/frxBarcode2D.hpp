// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbarcode2d.pas' rev: 21.00

#ifndef Frxbarcode2dHPP
#define Frxbarcode2dHPP

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
#include <Types.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Frxclass.hpp>	// Pascal unit
#include <Extctrls.hpp>	// Pascal unit
#include <Frxdesgn.hpp>	// Pascal unit
#include <Frxbarcodepdf417.hpp>	// Pascal unit
#include <Frxbarcodedatamatrix.hpp>	// Pascal unit
#include <Frxbarcodeqr.hpp>	// Pascal unit
#include <Frxbarcode2dbase.hpp>	// Pascal unit
#include <Frxbarcodeproperties.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbarcode2d
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TfrxBarcode2DType { bcCodePDF417, bcCodeDataMatrix, bcCodeQR };
#pragma option pop

class DELPHICLASS TfrxBarcode2DView;
class PASCALIMPLEMENTATION TfrxBarcode2DView : public Frxclass::TfrxView
{
	typedef Frxclass::TfrxView inherited;
	
private:
	Frxbarcode2dbase::TfrxBarcode2DBase* FBarCode;
	TfrxBarcode2DType FBarType;
	Frxclass::TfrxHAlign FHAlign;
	Frxbarcodeproperties::TfrxBarcode2DProperties* FProp;
	System::UnicodeString FExpression;
	void __fastcall SetZoom(System::Extended z);
	System::Extended __fastcall GetZoom(void);
	void __fastcall SetRotation(int v);
	int __fastcall GetRotation(void);
	void __fastcall SetShowText(bool v);
	bool __fastcall GetShowText(void);
	void __fastcall SetText(System::UnicodeString v);
	System::UnicodeString __fastcall GetText(void);
	void __fastcall SetFontScaled(bool v);
	bool __fastcall GetFontScaled(void);
	void __fastcall SetErrorText(System::UnicodeString v);
	System::UnicodeString __fastcall GetErrorText(void);
	void __fastcall SetQuietZone(int v);
	int __fastcall GetQuietZone(void);
	void __fastcall SetProp(Frxbarcodeproperties::TfrxBarcode2DProperties* v);
	void __fastcall SetBarType(TfrxBarcode2DType v);
	
public:
	__fastcall virtual TfrxBarcode2DView(Classes::TComponent* AOwner);
	__fastcall virtual TfrxBarcode2DView(Classes::TComponent* AOwner, System::Word Flags);
	__fastcall virtual ~TfrxBarcode2DView(void);
	virtual void __fastcall Draw(Graphics::TCanvas* Canvas, System::Extended ScaleX, System::Extended ScaleY, System::Extended OffsetX, System::Extended OffsetY);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual void __fastcall GetData(void);
	virtual Frxclass::TfrxRect __fastcall GetRealBounds(void);
	
__published:
	__property System::UnicodeString Expression = {read=FExpression, write=FExpression};
	__property TfrxBarcode2DType BarType = {read=FBarType, write=SetBarType, nodefault};
	__property Frxbarcodeproperties::TfrxBarcode2DProperties* BarProperties = {read=FProp, write=SetProp};
	__property BrushStyle;
	__property Color;
	__property Cursor = {default=0};
	__property DataField;
	__property DataSet;
	__property DataSetName;
	__property Frame;
	__property Frxclass::TfrxHAlign HAlign = {read=FHAlign, write=FHAlign, default=0};
	__property int Rotation = {read=GetRotation, write=SetRotation, nodefault};
	__property bool ShowText = {read=GetShowText, write=SetShowText, nodefault};
	__property TagStr;
	__property System::UnicodeString Text = {read=GetText, write=SetText};
	__property URL;
	__property System::Extended Zoom = {read=GetZoom, write=SetZoom};
	__property Font;
	__property bool FontScaled = {read=GetFontScaled, write=SetFontScaled, nodefault};
	__property System::UnicodeString ErrorText = {read=GetErrorText, write=SetErrorText};
	__property int QuietZone = {read=GetQuietZone, write=SetQuietZone, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxbarcode2d */
using namespace Frxbarcode2d;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frxbarcode2dHPP
