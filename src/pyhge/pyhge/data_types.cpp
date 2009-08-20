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
    
    class_<PyHgeTriple>("hgeTriple", init<boost::python::tuple, HTEXTURE, int>())
        //.add_property("v0", &PyHgeTriple::getV0)
        //.add_property("v1", &PyHgeTriple::getV1, return_value_policy<copy_non_const_reference>())
        //.add_property("v2", &PyHgeTriple::getV2, return_value_policy<reference_existing_object>())
        .def_readwrite("tex", &PyHgeTriple::tex)
        .def_readwrite("blend", &PyHgeTriple::blend)
        .def("getV", &PyHgeTriple::getV, return_value_policy<reference_existing_object>())
        .def("setV", &PyHgeTriple::setV)
    ;

    class_<PyHgeQuad>("hgeQuad", init<boost::python::tuple, HTEXTURE, int>())
        .def_readwrite("tex", &PyHgeQuad::tex)
        .def_readwrite("blend", &PyHgeQuad::blend)
        .def("getV", &PyHgeQuad::getV, return_value_policy<reference_existing_object>())
        .def("setV", &PyHgeQuad::setV)
    ;
    
}