#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "headers.h"

#include "hgesprite.h"

class PyHgeSprite : public hgeSprite {
public:
    PyHgeSprite(
        HTEXTURE tex,
        float x,
        float y,
        float w,
        float h
    ) 
        : hgeSprite(tex, x, y, w, h)
    {}

    PyHgeSprite(const PyHgeSprite &sprite) 
        : hgeSprite(sprite)
    {}

    boost::python::tuple GetTextureRectTuple() {
        float x;
        float y;
        float w;
        float h;
        GetTextureRect(&x, &y, &w, &h);
        return boost::python::make_tuple(x, y, w, h);
    }

    boost::python::tuple GetHotSpotTuple() {
        float x;
        float y;
        GetHotSpot(&x, &y);
        return boost::python::make_tuple(x, y);
    }

    boost::python::tuple GetFlipTuple() {
        bool bX;
        bool bY;
        GetFlip(&bX, &bY);
        return boost::python::make_tuple(bX, bY);
    }
};


#endif // SPRITE_H_INCLUDED