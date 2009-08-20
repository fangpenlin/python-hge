#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED

#include "stdafx.h"

class PyHgeVertex : public hgeVertex {
public:
    PyHgeVertex(float x, float y, float z, DWORD col, float tx, float ty) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->col = col;
        this->tx = tx;
        this->ty = ty;
    }

    PyHgeVertex(const PyHgeVertex &rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->col = rhs.col;
        this->tx = rhs.tx;
        this->ty = rhs.ty;        
    }

    PyHgeVertex &operator=(const PyHgeVertex &rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        this->col = rhs.col;
        this->tx = rhs.tx;
        this->ty = rhs.ty;
        return *this;
    }
};

class PyHgeTriple : public hgeTriple {
public:
    PyHgeTriple(boost::python::list v, HTEXTURE tex, int blend) {
        assert(boost::python::len(v)==3);
        for(size_t i = 0; i < 3; ++i) {
            this->v[i] = boost::python::extract<PyHgeVertex>(v[i]);
        }
        this->tex = tex;
        this->blend = blend;
    }
};

#endif // DATA_TYPES_H_INCLUDED