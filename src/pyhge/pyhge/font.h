#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include "headers.h"

#include "hgefont.h"

class PyHgeFont : public hgeFont {
public:
    PyHgeFont(const char *filename, bool bMipmap=false) 
        : hgeFont(filename, bMipmap)
    {}   

    // TODO
    /*
	hgeSprite *GetSprite(char chr) {
		return NULL;
	}*/

    /**
        There is already string % operation in Python, so we don't need
        C style string format
    **/
    void printf(float x, float y, int align, const char *string) {
        hgeFont::printf(x, y, align, string);
    }

    void printfb(float x, float y, float w, float, float h, int align, const char *string) {
        hgeFont::printfb(x, y, w, h, align, string);
    }
};


#endif // FONT_H_INCLUDED