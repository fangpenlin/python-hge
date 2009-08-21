#include "headers.h"

void exposeConstants() {
    using namespace boost::python;
    
    scope().attr("HGE_VERSION") = 0x180;

    scope().attr("BLEND_COLORADD") = BLEND_COLORADD;
    scope().attr("BLEND_COLORMUL") = BLEND_COLORMUL;
    scope().attr("BLEND_ALPHABLEND") = BLEND_ALPHABLEND;
    scope().attr("BLEND_ALPHAADD") = BLEND_ALPHAADD;
    scope().attr("BLEND_ZWRITE") = BLEND_ZWRITE;
    scope().attr("BLEND_NOZWRITE") = BLEND_NOZWRITE;

    scope().attr("BLEND_DEFAULT") = BLEND_DEFAULT;
    scope().attr("BLEND_DEFAULT_Z") = BLEND_DEFAULT_Z;
    
    scope().attr("HGEK_LBUTTON") = 0x01;
    scope().attr("HGEK_RBUTTON") = 0x02;
    scope().attr("HGEK_MBUTTON") = 0x04;

    scope().attr("HGEK_ESCAPE") = 0x1B;
    scope().attr("HGEK_BACKSPACE") = 0x08;
    scope().attr("HGEK_TAB") = 0x09;
    scope().attr("HGEK_ENTER") = 0x0D;
    scope().attr("HGEK_SPACE") = 0x20;

    scope().attr("HGEK_SHIFT") = 0x10;
    scope().attr("HGEK_CTRL") = 0x11;
    scope().attr("HGEK_ALT") = 0x12;

    scope().attr("HGEK_LWIN") = 0x5B;
    scope().attr("HGEK_RWIN") = 0x5C;
    scope().attr("HGEK_APPS") = 0x5D;

    scope().attr("HGEK_PAUSE") = 0x13;
    scope().attr("HGEK_CAPSLOCK") = 0x14;
    scope().attr("HGEK_NUMLOCK") = 0x90;
    scope().attr("HGEK_SCROLLLOCK") = 0x91;

    scope().attr("HGEK_PGUP") = 0x21;
    scope().attr("HGEK_PGDN") = 0x22;
    scope().attr("HGEK_HOME") = 0x24;
    scope().attr("HGEK_END") = 0x23;
    scope().attr("HGEK_INSERT") = 0x2D;
    scope().attr("HGEK_DELETE") = 0x2E;

    scope().attr("HGEK_LEFT") = 0x25;
    scope().attr("HGEK_UP") = 0x26;
    scope().attr("HGEK_RIGHT") = 0x27;
    scope().attr("HGEK_DOWN") = 0x28;

    scope().attr("HGEK_0") = 0x30;
    scope().attr("HGEK_1") = 0x31;
    scope().attr("HGEK_2") = 0x32;
    scope().attr("HGEK_3") = 0x33;
    scope().attr("HGEK_4") = 0x34;
    scope().attr("HGEK_5") = 0x35;
    scope().attr("HGEK_6") = 0x36;
    scope().attr("HGEK_7") = 0x37;
    scope().attr("HGEK_8") = 0x38;
    scope().attr("HGEK_9") = 0x39;

    scope().attr("HGEK_A") = 0x41;
    scope().attr("HGEK_B") = 0x42;
    scope().attr("HGEK_C") = 0x43;
    scope().attr("HGEK_D") = 0x44;
    scope().attr("HGEK_E") = 0x45;
    scope().attr("HGEK_F") = 0x46;
    scope().attr("HGEK_G") = 0x47;
    scope().attr("HGEK_H") = 0x48;
    scope().attr("HGEK_I") = 0x49;
    scope().attr("HGEK_J") = 0x4A;
    scope().attr("HGEK_K") = 0x4B;
    scope().attr("HGEK_L") = 0x4C;
    scope().attr("HGEK_M") = 0x4D;
    scope().attr("HGEK_N") = 0x4E;
    scope().attr("HGEK_O") = 0x4F;
    scope().attr("HGEK_P") = 0x50;
    scope().attr("HGEK_Q") = 0x51;
    scope().attr("HGEK_R") = 0x52;
    scope().attr("HGEK_S") = 0x53;
    scope().attr("HGEK_T") = 0x54;
    scope().attr("HGEK_U") = 0x55;
    scope().attr("HGEK_V") = 0x56;
    scope().attr("HGEK_W") = 0x57;
    scope().attr("HGEK_X") = 0x58;
    scope().attr("HGEK_Y") = 0x59;
    scope().attr("HGEK_Z") = 0x5A;

    scope().attr("HGEK_GRAVE") = 0xC0;
    scope().attr("HGEK_MINUS") = 0xBD;
    scope().attr("HGEK_EQUALS") = 0xBB;
    scope().attr("HGEK_BACKSLASH") = 0xDC;
    scope().attr("HGEK_LBRACKET") = 0xDB;
    scope().attr("HGEK_RBRACKET") = 0xDD;
    scope().attr("HGEK_SEMICOLON") = 0xBA;
    scope().attr("HGEK_APOSTROPHE") = 0xDE;
    scope().attr("HGEK_COMMA") = 0xBC;
    scope().attr("HGEK_PERIOD") = 0xBE;
    scope().attr("HGEK_SLASH") = 0xBF;

    scope().attr("HGEK_NUMPAD0") = 0x60;
    scope().attr("HGEK_NUMPAD1") = 0x61;
    scope().attr("HGEK_NUMPAD2") = 0x62;
    scope().attr("HGEK_NUMPAD3") = 0x63;
    scope().attr("HGEK_NUMPAD4") = 0x64;
    scope().attr("HGEK_NUMPAD5") = 0x65;
    scope().attr("HGEK_NUMPAD6") = 0x66;
    scope().attr("HGEK_NUMPAD7") = 0x67;
    scope().attr("HGEK_NUMPAD8") = 0x68;
    scope().attr("HGEK_NUMPAD9") = 0x69;

    scope().attr("HGEK_MULTIPLY") = 0x6A;
    scope().attr("HGEK_DIVIDE") = 0x6F;
    scope().attr("HGEK_ADD") = 0x6B;
    scope().attr("HGEK_SUBTRACT") = 0x6D;
    scope().attr("HGEK_DECIMAL") = 0x6E;

    scope().attr("HGEK_F1") = 0x70;
    scope().attr("HGEK_F2") = 0x71;
    scope().attr("HGEK_F3") = 0x72;
    scope().attr("HGEK_F4") = 0x73;
    scope().attr("HGEK_F5") = 0x74;
    scope().attr("HGEK_F6") = 0x75;
    scope().attr("HGEK_F7") = 0x76;
    scope().attr("HGEK_F8") = 0x77;
    scope().attr("HGEK_F9") = 0x78;
    scope().attr("HGEK_F10") = 0x79;
    scope().attr("HGEK_F11") = 0x7A;
    scope().attr("HGEK_F12") = 0x7B;
}