#include "headers.h"

extern void exposeEnums();
extern void exposeConstants();
extern void exposeDataTypes();
extern void exposeHge();
extern void exposeSprite();

BOOST_PYTHON_MODULE(_hge) {
    using namespace boost::python;

    exposeEnums();
    exposeConstants();
    exposeDataTypes();
    exposeHge();
    exposeSprite();
}
