// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frxtruetypefont.pas' rev: 21.00

#ifndef FrxtruetypefontHPP
#define FrxtruetypefontHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Ttfhelpers.hpp>	// Pascal unit
#include <Frxcmaptableclass.hpp>	// Pascal unit
#include <Frxfontheaderclass.hpp>	// Pascal unit
#include <Frxglyphtableclass.hpp>	// Pascal unit
#include <Frxglyphsubstitutionclass.hpp>	// Pascal unit
#include <Frxhorizontalheaderclass.hpp>	// Pascal unit
#include <Frxhorizontalmetrixclass.hpp>	// Pascal unit
#include <Frxindextolocationclass.hpp>	// Pascal unit
#include <Frxkerningtableclass.hpp>	// Pascal unit
#include <Frxnametableclass.hpp>	// Pascal unit
#include <Frxpostscriptclass.hpp>	// Pascal unit
#include <Frxmaximumprofileclass.hpp>	// Pascal unit
#include <Frxos2windowsmetricsclass.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Frxtruetypetable.hpp>	// Pascal unit
#include <Frxpreprogramclass.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frxtruetypefont
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum ChecksumFaultAction { ChecksumFaultAction_IgnoreChecksum, ChecksumFaultAction_ThrowException, ChecksumFaultAction_Warn };
#pragma option pop

#pragma option push -b
enum TablesID { TablesID_CMAP = 1885433187, TablesID_ControlValueTable = 544503395, TablesID_DigitalSignature = 1195987780, TablesID_EmbedBitmapLocation = 1129071173, TablesID_EmbededBitmapData = 1413759557, TablesID_FontHeader = 1684104552, TablesID_FontProgram = 1835495526, TablesID_Glyph = 1719233639, TablesID_GlyphDefinition = 1178944583, TablesID_GlyphPosition = 1397706823, TablesID_GlyphSubstitution = 1112888135, TablesID_GridFittingAndScanConversion = 1886609767, TablesID_HorizontakDeviceMetrix = 2020435048, TablesID_HorizontalHeader = 1634035816, TablesID_HorizontalMetrix = 2020896104, TablesID_IndexToLocation = 1633906540, TablesID_Justification = 1179931466, TablesID_KerningTable = 1852990827, TablesID_LinearThreshold = 1213420620, TablesID_MaximumProfile = 1886937453, TablesID_Name = 1701667182, TablesID_OS2Table = 841962319, TablesID_PCL5Table = 1414284112, TablesID_Postscript = 1953722224, TablesID_PreProgram = 1885696624, TablesID_VerticalDeviceMetrix = 1481458774, TablesID_VerticalMetrix
	 = 2020896118, TablesID_VertivalMetrixHeader = 1634035830 };
#pragma option pop

typedef DynamicArray<System::Byte> TByteArray;

typedef Classes::TList TTagList;

struct TTableSortHelper
{
	
public:
	unsigned Offset;
	unsigned TAG;
};


typedef TTableSortHelper *PTableSortHelper;

#pragma pack(push,1)
struct TableDirectory
{
	
public:
	unsigned sfntversion;
	System::Word numTables;
	System::Word searchRange;
	System::Word entrySelector;
	System::Word rangeShift;
};
#pragma pack(pop)


class DELPHICLASS TrueTypeFont;
class PASCALIMPLEMENTATION TrueTypeFont : public Ttfhelpers::TTF_Helpers
{
	typedef Ttfhelpers::TTF_Helpers inherited;
	
private:
	void *beginfile_ptr;
	
public:
	ChecksumFaultAction checksum_action;
	
private:
	Frxcmaptableclass::CmapTableClass* cmap_table;
	TableDirectory dir;
	Frxfontheaderclass::FontHeaderClass* font_header;
	Frxglyphtableclass::GlyphTableClass* glyph_table;
	Frxglyphsubstitutionclass::GlyphSubstitutionClass* gsub_table;
	Frxhorizontalheaderclass::HorizontalHeaderClass* horizontal_header;
	Frxhorizontalmetrixclass::HorizontalMetrixClass* horizontal_metrix_table;
	Frxindextolocationclass::IndexToLocationClass* index_to_location;
	Frxkerningtableclass::KerningTableClass* kerning_table;
	Frxnametableclass::NameTableClass* name_table;
	Frxpostscriptclass::PostScriptClass* postscript;
	Frxmaximumprofileclass::MaximumProfileClass* profile;
	void *selector_ptr;
	Frxos2windowsmetricsclass::OS2WindowsMetricsClass* windows_metrix;
	Frxpreprogramclass::PreProgramClass* preprogram_table;
	Classes::TList* ListOfTables;
	Classes::TList* ListOfUsedGlyphs;
	Classes::TList* GlyphWidths;
	Classes::TList* Indices;
	System::UnicodeString FSubstitutionName;
	
public:
	__fastcall TrueTypeFont(void * bgn, void * font, ChecksumFaultAction action);
	__fastcall virtual ~TrueTypeFont(void);
	void __fastcall AddCharacterToKeepList(System::WideChar ch);
	void __fastcall ParseSingleGlyph(System::Word idx);
	
private:
	void __fastcall BuildGlyphIndexList(Classes::TList* used_glyphs, bool uniscribe, bool decompose, bool collate, bool use_kerning);
	unsigned __fastcall CalcTableChecksum(void * font, Frxtruetypetable::TrueTypeTable* entry, bool debug);
	void __fastcall CalculateFontChecksum(void * start_offset, unsigned font_length);
	void __fastcall ChangeEndian(void);
	void __fastcall CheckTablesChecksum(void);
	Classes::TList* __fastcall GetTablesOrder(void);
	void __fastcall LoadCoreTables(void);
	void __fastcall LoadDescriptors(Classes::TList* skip_array);
	
public:
	TByteArray __fastcall PackFont(Frxfontheaderclass::FontType translate_to, bool uniscribe);
	void __fastcall PrepareFont(Classes::TList* skip_list);
	
private:
	void __fastcall ReorderGlyphTable(void * position, bool uniscribe);
	void __fastcall SaveDescriptors(void * position);
	void __fastcall set_UsedGlyphs(Classes::TList* dict);
	unsigned __fastcall get_GlyphWidth(int glph);
	unsigned __fastcall get_Glyph(int idx);
	System::UnicodeString __fastcall GetFamilyName(void);
	
public:
	__property Frxnametableclass::NameTableClass* Names = {read=name_table};
	__property Classes::TList* UsedGlyphs = {write=set_UsedGlyphs};
	__property Classes::TList* Widths = {read=GlyphWidths};
	__property unsigned Width[int glph] = {read=get_GlyphWidth};
	__property unsigned Glyph[int idx] = {read=get_Glyph};
	__property System::UnicodeString SubstitutionName = {read=FSubstitutionName, write=FSubstitutionName};
	__property System::UnicodeString FamilyName = {read=GetFamilyName};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frxtruetypefont */
using namespace Frxtruetypefont;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxtruetypefontHPP
