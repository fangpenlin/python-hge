#include "headers.h"

void exposeEnums() {
    using namespace boost::python;
    
    // hgeBoolState
    scope().attr("HGE_WINDOWED") = int(HGE_WINDOWED);
    scope().attr("HGE_ZBUFFER") = int(HGE_ZBUFFER);
    scope().attr("HGE_TEXTUREFILTER") = int(HGE_TEXTUREFILTER);
    scope().attr("HGE_USESOUND") = int(HGE_USESOUND);
    scope().attr("HGE_DONTSUSPEND") = int(HGE_DONTSUSPEND);
    scope().attr("HGE_HIDEMOUSE") = int(HGE_HIDEMOUSE);
    scope().attr("HGE_SHOWSPLASH") = int(HGE_SHOWSPLASH);
    scope().attr("HGEBOOLSTATE_FORCE_DWORD") = int(HGEBOOLSTATE_FORCE_DWORD);

    // hgeFuncState
    scope().attr("HGE_FRAMEFUNC") = int(HGE_FRAMEFUNC);
    scope().attr("HGE_RENDERFUNC") = int(HGE_RENDERFUNC);
    scope().attr("HGE_FOCUSLOSTFUNC") = int(HGE_FOCUSLOSTFUNC);
    scope().attr("HGE_FOCUSGAINFUNC") = int(HGE_FOCUSGAINFUNC);
    scope().attr("HGE_GFXRESTOREFUNC") = int(HGE_GFXRESTOREFUNC);
    scope().attr("HGE_EXITFUNC") = int(HGE_EXITFUNC);
    scope().attr("HGEFUNCSTATE_FORCE_DWORD") = int(HGEFUNCSTATE_FORCE_DWORD);

    // hgeHwndState
    scope().attr("HGE_HWND") = int(HGE_HWND);
    scope().attr("HGE_HWNDPARENT") = int(HGE_HWNDPARENT);
    scope().attr("HGEHWNDSTATE_FORCE_DWORD") = int(HGEHWNDSTATE_FORCE_DWORD);

    // hgeIntState
    scope().attr("HGE_SCREENWIDTH") = int(HGE_SCREENWIDTH);
    scope().attr("HGE_SCREENHEIGHT") = int(HGE_SCREENHEIGHT);
    scope().attr("HGE_SCREENBPP") = int(HGE_SCREENBPP);
    scope().attr("HGE_SAMPLERATE") = int(HGE_SAMPLERATE);
    scope().attr("HGE_FXVOLUME") = int(HGE_FXVOLUME);
    scope().attr("HGE_MUSVOLUME") = int(HGE_MUSVOLUME);
    scope().attr("HGE_STREAMVOLUME") = int(HGE_STREAMVOLUME);
    scope().attr("HGE_FPS") = int(HGE_FPS);
    scope().attr("HGE_POWERSTATUS") = int(HGE_POWERSTATUS);
    scope().attr("HGEINTSTATE_FORCE_DWORD") = int(HGEINTSTATE_FORCE_DWORD);

    // hgeStringState
    scope().attr("HGE_ICON") = int(HGE_ICON);
    scope().attr("HGE_TITLE") = int(HGE_TITLE);
    scope().attr("HGE_INIFILE") = int(HGE_INIFILE);
    scope().attr("HGE_LOGFILE") = int(HGE_LOGFILE);
    scope().attr("HGESTRINGSTATE_FORCE_DWORD") = int(HGESTRINGSTATE_FORCE_DWORD);
}