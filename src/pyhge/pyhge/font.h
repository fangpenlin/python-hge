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
};


#endif // FONT_H_INCLUDED