// pyhge.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern void exposeEnums();
extern void exposeConstants();
extern void exposeDataTypes();
extern void exposeHge();

BOOST_PYTHON_MODULE(_hge) {
    using namespace boost::python;

    exposeEnums();
    exposeConstants();
    exposeDataTypes();
    exposeHge();
}
