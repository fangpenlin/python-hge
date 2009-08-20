#include "stdafx.h"
#include "data_types.h"

void exposeDataTypes() {
    using namespace boost::python;

    class_<PyHgeVertex>("hgeVertex", init<float, float, float, DWORD, float, float>())
        .def_readwrite("x", &PyHgeVertex::x)
        .def_readwrite("y", &PyHgeVertex::y)
        .def_readwrite("z", &PyHgeVertex::z)
        .def_readwrite("col", &PyHgeVertex::col)
        .def_readwrite("tx", &PyHgeVertex::tx)
        .def_readwrite("ty", &PyHgeVertex::ty)
    ;

    /*
    class_<PyHgeTriple>("hgeTriple", init<boost::python::list, HTEXTURE, int>())
        .def_readwrite("v", &PyHgeTriple::v)
        .def_readwrite("tex", &PyHgeTriple::tex)
        .def_readwrite("blend", &PyHgeTriple::blend)
    ;
*/
    
}