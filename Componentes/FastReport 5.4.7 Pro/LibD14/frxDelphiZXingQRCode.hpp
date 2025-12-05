// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxdelphizxingqrcode.pas' rev: 21.00

#ifndef FrxdelphizxingqrcodeHPP
#define FrxdelphizxingqrcodeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxdelphizxingqrcode
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TQRCodeEncoding { qrAuto, qrNumeric, qrAlphanumeric, qrISO88591, qrUTF8NoBOM, qrUTF8BOM, qrShift_JIS };
#pragma option pop

#pragma option push -b-
enum TQRErrorLevels { ecL, ecM, ecQ, ecH };
#pragma option pop

typedef DynamicArray<bool> Frxdelphizxingqrcode__1;

typedef DynamicArray<DynamicArray<bool> > T2DBooleanArray;

class DELPHICLASS TErrorCorrectionLevel;
class PASCALIMPLEMENTATION TErrorCorrectionLevel : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FBits;
	int FOrdinal;
	
public:
	void __fastcall Assign(TErrorCorrectionLevel* Source);
	__property int Bits = {read=FBits, write=FBits, nodefault};
	__property int Ordinal = {read=FOrdinal, write=FOrdinal, nodefault};
public:
	/* TObject.Create */ inline __fastcall TErrorCorrectionLevel(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TErrorCorrectionLevel(void) { }
	
};


class DELPHICLASS TDelphiZXingQRCode;
class PASCALIMPLEMENTATION TDelphiZXingQRCode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void __fastcall SetErrorLevels(const TQRErrorLevels Value);
	void __fastcall SetCodePage(const int Value);
	
protected:
	System::WideString FData;
	int FRows;
	int FColumns;
	TQRCodeEncoding FEncoding;
	int FQuietZone;
	T2DBooleanArray FElements;
	TQRErrorLevels FErrorLevels;
	TErrorCorrectionLevel* FLevel;
	int FCodePage;
	void __fastcall SetEncoding(TQRCodeEncoding NewEncoding);
	void __fastcall SetData(const System::WideString NewData);
	void __fastcall SetQuietZone(int NewQuietZone);
	bool __fastcall GetIsBlack(int Row, int Column);
	void __fastcall Update(void);
	
public:
	__fastcall TDelphiZXingQRCode(void);
	__fastcall virtual ~TDelphiZXingQRCode(void);
	__property System::WideString Data = {read=FData, write=SetData};
	__property TQRCodeEncoding Encoding = {read=FEncoding, write=SetEncoding, nodefault};
	__property int QuietZone = {read=FQuietZone, write=SetQuietZone, nodefault};
	__property int Rows = {read=FRows, nodefault};
	__property int Columns = {read=FColumns, nodefault};
	__property bool IsBlack[int Row][int Column] = {read=GetIsBlack};
	__property TQRErrorLevels ErrorLevels = {read=FErrorLevels, write=SetErrorLevels, nodefault};
	__property int CodePage = {read=FCodePage, write=SetCodePage, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxdelphizxingqrcode */
using namespace Frxdelphizxingqrcode;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxdelphizxingqrcodeHPP
