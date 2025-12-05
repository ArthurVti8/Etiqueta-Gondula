// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbarcode2dbase.pas' rev: 21.00

#ifndef Frxbarcode2dbaseHPP
#define Frxbarcode2dbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Frxprinter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbarcode2dbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxBarcode2DBase;
class PASCALIMPLEMENTATION TfrxBarcode2DBase : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef DynamicArray<System::Byte> _TfrxBarcode2DBase__1;
	
	
protected:
	_TfrxBarcode2DBase__1 FImage;
	int FHeight;
	int FWidth;
	int FPixelWidth;
	int FPixelHeight;
	bool FShowText;
	int FRotation;
	System::UnicodeString FText;
	System::Extended FZoom;
	bool FFontScaled;
	Graphics::TFont* FFont;
	Graphics::TColor FColor;
	Graphics::TColor FColorBar;
	System::UnicodeString FErrorText;
	int FQuietZone;
	virtual void __fastcall SetShowText(bool v);
	virtual void __fastcall SetRotation(int v);
	virtual void __fastcall SetText(System::UnicodeString v);
	virtual void __fastcall SetZoom(System::Extended v);
	virtual void __fastcall SetFontScaled(bool v);
	virtual void __fastcall SetFont(Graphics::TFont* v);
	virtual void __fastcall SetColor(Graphics::TColor v);
	virtual void __fastcall SetColorBar(Graphics::TColor v);
	virtual void __fastcall SetErrorText(System::UnicodeString v);
	virtual int __fastcall GetWidth(void);
	virtual int __fastcall GetHeight(void);
	
public:
	__fastcall virtual TfrxBarcode2DBase(void);
	__fastcall virtual ~TfrxBarcode2DBase(void);
	virtual void __fastcall Assign(TfrxBarcode2DBase* src);
	virtual int __fastcall GetFooterHeight(void);
	virtual void __fastcall Draw2DBarcode(Graphics::TCanvas* &g, System::Extended scalex, System::Extended scaley, int x, int y);
	__property bool ShowText = {read=FShowText, write=SetShowText, nodefault};
	__property int Rotation = {read=FRotation, write=SetRotation, nodefault};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property System::Extended Zoom = {read=FZoom, write=SetZoom};
	__property bool FontScaled = {read=FFontScaled, write=SetFontScaled, nodefault};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property Graphics::TColor ColorBar = {read=FColorBar, write=SetColorBar, nodefault};
	__property System::UnicodeString ErrorText = {read=FErrorText, write=SetErrorText};
	__property int Width = {read=GetWidth, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int PixelWidth = {read=FPixelWidth, write=FPixelWidth, nodefault};
	__property int PixelHeight = {read=FPixelHeight, write=FPixelHeight, nodefault};
	__property int QuietZone = {read=FQuietZone, write=FQuietZone, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
#define cbDefaultText L"12345678"

}	/* namespace Frxbarcode2dbase */
using namespace Frxbarcode2dbase;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frxbarcode2dbaseHPP
