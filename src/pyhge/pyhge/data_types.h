#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED

#include "headers.h"

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
    PyHgeTriple(boost::python::tuple v, HTEXTURE tex, int blend) {
        assert(boost::python::len(v)==3);
        for(size_t i = 0; i < 3; ++i) {
            this->v[i] = boost::python::extract<PyHgeVertex>(v[i]);
        }
        this->tex = tex;
        this->blend = blend;
    }

    PyHgeVertex &getV0() {
        return getV(0);
    }

    PyHgeVertex &getV1() {
        return getV(1);
    }

    PyHgeVertex &getV2() {
        return getV(2);
    }

    PyHgeVertex &getV(size_t i) {
        assert(i >= 0 && i < 3);
        return static_cast<PyHgeVertex&>(this->v[i]);
    }

    void setV(size_t i, const PyHgeVertex &v) {
        assert(i >= 0 && i < 3);
        this->v[i] = v;
    }

};

class PyHgeQuad : public hgeQuad {
public:
    PyHgeQuad(boost::python::tuple v, HTEXTURE tex, int blend) {
        assert(boost::python::len(v)==4);
        for(size_t i = 0; i < 4; ++i) {
            this->v[i] = boost::python::extract<PyHgeVertex>(v[i]);
        }
        this->tex = tex;
        this->blend = blend;
    }

    PyHgeVertex &getV(size_t i) {
        assert(i >= 0 && i < 4);
        return static_cast<PyHgeVertex&>(this->v[i]);
    }

    void setV(size_t i, const PyHgeVertex &v) {
        assert(i >= 0 && i < 4);
        this->v[i] = v;
    }

};

#endif // DATA_TYPES_H_INCLUDED