// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxbarcodepdf417.pas' rev: 21.00

#ifndef Frxbarcodepdf417HPP
#define Frxbarcodepdf417HPP

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
#include <Frxprinter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxbarcodepdf417
{
//-- type declarations -------------------------------------------------------
typedef DynamicArray<int> TInt;

typedef TInt *PInt;

#pragma option push -b-
enum PDF417ErrorCorrection { AutoCorr, Level0, Level1, Level2, Level3, Level4, Level5, Level6, Level7, Level8 };
#pragma option pop

#pragma option push -b-
enum PDF417CompactionMode { AutoCompaction, TextComp, Numeric, Binary };
#pragma option pop

class DELPHICLASS Segment;
class PASCALIMPLEMENTATION Segment : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::WideChar _type;
	int _start;
	int _end;
	__fastcall Segment(System::WideChar _t, int _s, int _e);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~Segment(void) { }
	
};


class DELPHICLASS TSegmentList;
class PASCALIMPLEMENTATION TSegmentList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Classes::TList* List;
	__fastcall TSegmentList(void);
	__fastcall virtual ~TSegmentList(void);
	void __fastcall Add(System::WideChar _type, int _start, int _end);
	Segment* __fastcall Get(int idx);
	void __fastcall Remove(int idx);
	int __fastcall Size(void);
};


class DELPHICLASS TfrxBarcodePDF417;
class PASCALIMPLEMENTATION TfrxBarcodePDF417 : public Frxbarcode2dbase::TfrxBarcode2DBase
{
	typedef Frxbarcode2dbase::TfrxBarcode2DBase inherited;
	
private:
	typedef DynamicArray<System::Byte> _TfrxBarcodePDF417__1;
	
	
private:
	int codeColumns;
	int FRows;
	int FColumns;
	StaticArray<int, 928> codewords;
	int lenCodewords;
	int errorLevel;
	PDF417ErrorCorrection FErrorCorrection;
	PDF417CompactionMode FCompactionMode;
	_TfrxBarcodePDF417__1 bytes;
	System::Extended FAspectRatio;
	int FCodePage;
	int bitPtr;
	int cwPtr;
	TSegmentList* segmentList;
	bool __fastcall CheckSegmentType(Segment* &segm, System::WideChar typ);
	int __fastcall GetSegmentLength(Segment* &segm);
	void __fastcall OutCodeword17(int codeword);
	void __fastcall OutCodeword18(int codeword);
	void __fastcall OutCodeword(int codeword);
	void __fastcall OutStopPattern(void);
	void __fastcall OutStartPattern(void);
	void __fastcall OutPaintCode(void);
	void __fastcall CalculateErrorCorrection(int dest);
	int __fastcall GetTextTypeAndValue(System::Byte *input, const int input_Size, int maxLength, int idx)/* overload */;
	int __fastcall GetTextTypeAndValue(int maxLength, int idx)/* overload */;
	void __fastcall TextCompaction(System::Byte *input, const int input_Size, int start, int length)/* overload */;
	void __fastcall TextCompaction(int start, int length)/* overload */;
	void __fastcall BasicNumberCompaction(System::Byte *input, const int input_Size, int start, int length)/* overload */;
	void __fastcall NumberCompaction(System::Byte *input, const int input_Size, int start, int length)/* overload */;
	void __fastcall NumberCompaction(int start, int length)/* overload */;
	void __fastcall ByteCompaction6(int start);
	void __fastcall ByteCompaction(int start, int length);
	void __fastcall BreakString(void);
	void __fastcall Assemble(void);
	int __fastcall MaxPossibleErrorLevel(int remain);
	int __fastcall GetMaxSquare(void);
	void __fastcall PaintCode(void);
	void __fastcall Initialize(void);
	void __fastcall SetAspectRatio(System::Extended v);
	void __fastcall SetColumns(int v);
	void __fastcall SetRows(int v);
	void __fastcall SetErrorCorrection(PDF417ErrorCorrection v);
	void __fastcall SetCodePage(int v);
	void __fastcall SetCompactionMode(PDF417CompactionMode v);
	
protected:
	virtual void __fastcall SetText(System::UnicodeString v);
	
public:
	__fastcall virtual TfrxBarcodePDF417(void);
	__fastcall virtual ~TfrxBarcodePDF417(void);
	virtual void __fastcall Assign(Frxbarcode2dbase::TfrxBarcode2DBase* source);
	
__published:
	__property System::Extended AspectRatio = {read=FAspectRatio, write=SetAspectRatio};
	__property int Columns = {read=FColumns, write=SetColumns, nodefault};
	__property int Rows = {read=FRows, write=SetRows, nodefault};
	__property PDF417ErrorCorrection ErrorCorrection = {read=FErrorCorrection, write=SetErrorCorrection, nodefault};
	__property int CodePage = {read=FCodePage, write=SetCodePage, nodefault};
	__property PDF417CompactionMode CompactionMode = {read=FCompactionMode, write=SetCompactionMode, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const int START_PATTERN = 0x1fea8;
static const int STOP_PATTERN = 0x3fa29;
static const ShortInt START_CODE_SIZE = 0x11;
static const ShortInt STOP_SIZE = 0x12;
static const Word _MOD = 0x3a1;
static const int ALPHA = 0x10000;
static const int LOWER = 0x20000;
static const int MIXED = 0x40000;
static const int PUNCTUATION = 0x80000;
static const int ISBYTE = 0x100000;
static const Word BYTESHIFT = 0x391;
static const ShortInt PL = 0x19;
static const ShortInt LL = 0x1b;
static const ShortInt _AS = 0x1b;
static const ShortInt ML = 0x1c;
static const ShortInt AL = 0x1c;
static const ShortInt PS = 0x1d;
static const ShortInt PAL = 0x1d;
static const ShortInt SPACE = 0x1a;
static const Word TEXT_MODE = 0x384;
static const Word BYTE_MODE_6 = 0x39c;
static const Word BYTE_MODE = 0x385;
static const Word NUMERIC_MODE = 0x386;
static const Word ABSOLUTE_MAX_TEXT_SIZE = 0x152c;
static const Word MAX_DATA_CODEWORDS = 0x39e;
static const Word MACRO_SEGMENT_ID = 0x3a0;
static const Word MACRO_LAST_SEGMENT = 0x39a;
#define MIXED_SET L"0123456789&\r\t,:#-.$/+%*=^"
#define PUNCTUATION_SET L";<>@[\\]_`~!\r\t,:\n-.$/\"|*()?{}'"
extern PACKAGE StaticArray<StaticArray<int, 929>, 3> CLUSTERS;
extern PACKAGE StaticArray<int, 2> ERRLVL0;
extern PACKAGE StaticArray<int, 4> ERRLVL1;
extern PACKAGE StaticArray<int, 8> ERRLVL2;
extern PACKAGE StaticArray<int, 16> ERRLVL3;
extern PACKAGE StaticArray<int, 32> ERRLVL4;
extern PACKAGE StaticArray<int, 64> ERRLVL5;
extern PACKAGE StaticArray<int, 128> ERRLVL6;
extern PACKAGE StaticArray<int, 256> ERRLVL7;
extern PACKAGE StaticArray<int, 512> ERRLVL8;
extern PACKAGE StaticArray<PInt, 9> ERROR_LEVEL;

}	/* namespace Frxbarcodepdf417 */
using namespace Frxbarcodepdf417;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frxbarcodepdf417HPP
