// CodeGear C++Builder
// Copyright (c) 1995, 2009 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frximageconverter.pas' rev: 21.00

#ifndef FrximageconverterHPP
#define FrximageconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frximageconverter
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TfrxPictureType { gpPNG, gpBMP, gpEMF, gpWMF, gpJPG, gpGIF };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall GetPicFileExtension(TfrxPictureType PicType);
extern PACKAGE void __fastcall SaveGraphicAs(Graphics::TGraphic* Graphic, System::UnicodeString Path, TfrxPictureType PicType)/* overload */;
extern PACKAGE void __fastcall SaveGraphicAs(Graphics::TGraphic* Graphic, Classes::TStream* Stream, TfrxPictureType PicType)/* overload */;

}	/* namespace Frximageconverter */
using namespace Frximageconverter;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrximageconverterHPP
