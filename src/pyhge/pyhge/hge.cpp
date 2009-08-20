#include "stdafx.h"
#include "pyhge.h"

void exportHge() {
    using namespace boost::python;

    class_<PyHGE>("HGE", init<int>())
        .def("Release", &PyHGE::Release)
        .def("System_Initiate", &PyHGE::System_Initiate)
        .def("System_Shutdown", &PyHGE::System_Shutdown)
        .def("System_Start", &PyHGE::System_Start)
        .def("System_GetErrorMessage", &PyHGE::System_GetErrorMessage)
        .def("System_SetStateBool", &PyHGE::System_SetStateBool)
    ;
}