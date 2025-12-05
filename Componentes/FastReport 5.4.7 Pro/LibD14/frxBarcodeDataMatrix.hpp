// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbarcodedatamatrix.pas' rev: 21.00

#ifndef FrxbarcodedatamatrixHPP
#define FrxbarcodedatamatrixHPP

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
#include <Frxunicodeutils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbarcodedatamatrix
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum DatamatrixEncoding { Auto, Ascii, C40, Txt, Base256, X12, Edifact };
#pragma option pop

#pragma option push -b-
enum DatamatrixSymbolSize { AutoSize, Size10x10, Size12x12, Size8x18, Size14x14, Size8x32, Size16x16, Size12x26, Size18x18, Size20x20, Size12x36, Size22x22, Size16x36, Size24x24, Size26x26, Size16x48, Size32x32, Size36x36, Size40x40, Size44x44, Size48x48, Size52x52, Size64x64, Size72x72, Size80x80, Size88x88, Size96x96, Size104x104, Size120x120, Size132x132, Size144x144 };
#pragma option pop

struct DmParams
{
	
public:
	int height;
	int width;
	int heightSection;
	int widthSection;
	int dataSize;
	int dataBlock;
	int errorBlock;
};


struct SizeF
{
	
public:
	System::Extended height;
	System::Extended width;
};


typedef DynamicArray<int> TInts;

class DELPHICLASS TfrxBarcodeDataMatrix;
class PASCALIMPLEMENTATION TfrxBarcodeDataMatrix : public Frxbarcode2dbase::TfrxBarcode2DBase
{
	typedef Frxbarcode2dbase::TfrxBarcode2DBase inherited;
	
private:
	TInts FPlace;
	DatamatrixSymbolSize FSymbolSize;
	DatamatrixEncoding FEncoding;
	int FCodePage;
	void __fastcall SetBit(int x, int y, int xByte);
	void __fastcall Generate(System::UnicodeString &text)/* overload */;
	void __fastcall Generate(System::Byte *text, const int text_Size, int textOffset, int textSize)/* overload */;
	int __fastcall GetEncodation(System::Byte *Text, const int Text_Size, int textOffset, int textSize, System::Byte *data, const int data_Size, int dataOffset, int dataSize, bool firstMatch);
	void __fastcall Draw(System::Byte *data, const int data_Size, int dataSize, const DmParams &dm);
	void __fastcall SetCodePage(int cp);
	void __fastcall SetEncoding(DatamatrixEncoding v);
	void __fastcall Ecc200(void);
	void __fastcall SetSymbolSize(DatamatrixSymbolSize s);
	int __fastcall GetPixelSize(void);
	void __fastcall SetPixelSize(int v);
	
protected:
	virtual void __fastcall SetText(System::UnicodeString v);
	
public:
	__fastcall virtual TfrxBarcodeDataMatrix(void);
	__fastcall virtual ~TfrxBarcodeDataMatrix(void);
	virtual void __fastcall Assign(Frxbarcode2dbase::TfrxBarcode2DBase* src);
	
__published:
	__property DatamatrixSymbolSize SymbolSize = {read=FSymbolSize, write=SetSymbolSize, nodefault};
	__property DatamatrixEncoding Encoding = {read=FEncoding, write=SetEncoding, nodefault};
	__property int CodePage = {read=FCodePage, write=SetCodePage, nodefault};
	__property int PixelSize = {read=GetPixelSize, write=SetPixelSize, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE StaticArray<DmParams, 30> dmSizes;
extern PACKAGE StaticArray<int, 256> log;
extern PACKAGE StaticArray<int, 256> alog;
extern PACKAGE StaticArray<int, 5> poly5;
extern PACKAGE StaticArray<int, 7> poly7;
extern PACKAGE StaticArray<int, 10> poly10;
extern PACKAGE StaticArray<int, 11> poly11;
extern PACKAGE StaticArray<int, 12> poly12;
extern PACKAGE StaticArray<int, 14> poly14;
extern PACKAGE StaticArray<int, 18> poly18;
extern PACKAGE StaticArray<int, 20> poly20;
extern PACKAGE StaticArray<int, 24> poly24;
extern PACKAGE StaticArray<int, 28> poly28;
extern PACKAGE StaticArray<int, 36> poly36;
extern PACKAGE StaticArray<int, 42> poly42;
extern PACKAGE StaticArray<int, 48> poly48;
extern PACKAGE StaticArray<int, 56> poly56;
extern PACKAGE StaticArray<int, 62> poly62;
extern PACKAGE StaticArray<int, 68> poly68;
#define _x12 L"\r*> 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define cbDefaultText L"12345678"
extern PACKAGE void __fastcall GenerateECC(System::Byte *wd, const int wd_Size, int nd, int datablock, int nc);

}	/* namespace Frxbarcodedatamatrix */
using namespace Frxbarcodedatamatrix;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbarcodedatamatrixHPP
