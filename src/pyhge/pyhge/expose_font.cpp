#include "headers.h"
#include "font.h"

void exposeFont() {
    using namespace boost::python;

    class_<PyHgeFont, boost::noncopyable>("hgeFont", init<const char *, bool>())
		.def("Render", &PyHgeFont::Render)

        // TODO
		//.def("printf", &PyHgeFont::printf)
		//.def("printfb", &PyHgeFont::printfb)
        
		.def("SetColor", &PyHgeFont::SetColor)
		.def("SetZ", &PyHgeFont::SetZ)
		.def("SetBlendMode", &PyHgeFont::SetBlendMode)
		.def("SetScale", &PyHgeFont::SetScale)
		.def("SetProportion", &PyHgeFont::SetProportion)
		.def("SetRotation", &PyHgeFont::SetRotation)
		.def("SetTacking", &PyHgeFont::SetTracking)
		.def("SetSpacing", &PyHgeFont::SetSpacing)

		.def("GetColor", &PyHgeFont::GetColor)
		.def("GetZ", &PyHgeFont::GetZ)
		.def("GetBlendMode", &PyHgeFont::GetBlendMode)
		.def("GetScale", &PyHgeFont::GetScale)
		.def("GetProprotion", &PyHgeFont::GetProportion)
		.def("GetRotation", &PyHgeFont::GetRotation)
		.def("GetTracking", &PyHgeFont::GetTracking)
		.def("GetSpacing", &PyHgeFont::GetSpacing)

        // TODO
		//.def("GetSprite", &PyHgeFont::GetSprite)
		.def("GetPreWidth", &PyHgeFont::GetPreWidth)
		.def("GetPostWidth", &PyHgeFont::GetPostWidth)
		.def("GetStringWidth", &PyHgeFont::GetStringWidth)
		.def("GetHeight", &PyHgeFont::GetHeight)
    ;
}