// pyhge.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern void exportEnums();
extern void exportHge();

BOOST_PYTHON_MODULE(_hge) {
    using namespace boost::python;

    exportEnums();
    exportHge();
}
