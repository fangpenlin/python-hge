#ifndef CALLBACK_H_INCLUDED
#define CALLBACK_H_INCLUDED

#include "headers.h"

class Callback;


/**
    Callback functions of HGE
**/
class Callback {
public:
    static Callback *m_pCallback;
    boost::python::object m_FrameFunc;
    boost::python::object m_RenderFunc;
    boost::python::object m_GfxRestoreFunc;
    boost::python::object m_FocusLostFunc;
    boost::python::object m_FocusGainFunc;
    boost::python::object m_ExitFunc;
public:
    Callback() {
        
    }
    ~Callback() {

    }

    static bool frameFunc() {
        return boost::python::extract<bool>(m_pCallback->m_FrameFunc());
    }

    static bool renderFunc() {
        return boost::python::extract<bool>(m_pCallback->m_RenderFunc());
    }

    static bool gfxRestoreFunc() {
        return boost::python::extract<bool>(m_pCallback->m_GfxRestoreFunc());
    }

    static bool focusLostFunc() {
        return boost::python::extract<bool>(m_pCallback->m_FocusLostFunc());
    }

    static bool focusGainFunc() {
        return boost::python::extract<bool>(m_pCallback->m_FocusGainFunc());
    }

    static bool exitFunc() {
        return boost::python::extract<bool>(m_pCallback->m_ExitFunc());
    }
};

#endif // CALLBACK_H_INCLUDED