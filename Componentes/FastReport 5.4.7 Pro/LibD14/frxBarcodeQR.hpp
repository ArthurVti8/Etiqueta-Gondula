// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbarcodeqr.pas' rev: 21.00

#ifndef FrxbarcodeqrHPP
#define FrxbarcodeqrHPP

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
#include <Types.hpp>	// Pascal unit
#include <Strutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Frxbarcode2dbase.hpp>	// Pascal unit
#include <Frxdelphizxingqrcode.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbarcodeqr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrxBarcodeQR;
class PASCALIMPLEMENTATION TfrxBarcodeQR : public Frxbarcode2dbase::TfrxBarcode2DBase
{
	typedef Frxbarcode2dbase::TfrxBarcode2DBase inherited;
	
private:
	Frxdelphizxingqrcode::TDelphiZXingQRCode* FDelphiZXingQRCode;
	void __fastcall Generate(void);
	Frxdelphizxingqrcode::TQRCodeEncoding __fastcall GetEncoding(void);
	int __fastcall GetQuietZone(void);
	void __fastcall SetEncoding(const Frxdelphizxingqrcode::TQRCodeEncoding Value);
	void __fastcall SetQuietZone(const int Value);
	Frxdelphizxingqrcode::TQRErrorLevels __fastcall GetErrorLevels(void);
	void __fastcall SetErrorLevels(const Frxdelphizxingqrcode::TQRErrorLevels Value);
	int __fastcall GetPixelSize(void);
	void __fastcall SetPixelSize(int v);
	int __fastcall GetCodepage(void);
	void __fastcall SetCodepage(const int Value);
	
protected:
	virtual void __fastcall SetText(System::UnicodeString v);
	
public:
	__fastcall virtual TfrxBarcodeQR(void);
	__fastcall virtual ~TfrxBarcodeQR(void);
	virtual void __fastcall Assign(Frxbarcode2dbase::TfrxBarcode2DBase* src);
	
__published:
	__property Frxdelphizxingqrcode::TQRCodeEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
	__property int QuietZone = {read=GetQuietZone, write=SetQuietZone, nodefault};
	__property Frxdelphizxingqrcode::TQRErrorLevels ErrorLevels = {read=GetErrorLevels, write=SetErrorLevels, nodefault};
	__property int PixelSize = {read=GetPixelSize, write=SetPixelSize, nodefault};
	__property int Codepage = {read=GetCodepage, write=SetCodepage, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxbarcodeqr */
using namespace Frxbarcodeqr;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbarcodeqrHPP
