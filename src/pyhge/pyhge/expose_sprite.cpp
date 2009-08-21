#include "headers.h"
#include "sprite.h"

void exposeSprite() {
    using namespace boost::python;

    class_<PyHgeSprite>("hgeSprite", init<HTEXTURE, float, float, float, float>())
        .def("Render", &PyHgeSprite::Render)
        .def("RenderEx", &PyHgeSprite::RenderEx)
        .def("RenderStretch", &PyHgeSprite::RenderStretch)
        .def("Render4V", &PyHgeSprite::Render4V)

        .def("SetTexture", &PyHgeSprite::SetTexture)
        .def("SetTextureRect", &PyHgeSprite::SetTextureRect)
        .def("SetColor", &PyHgeSprite::SetColor)
        .def("SetZ", &PyHgeSprite::SetZ)
        .def("SetBlendMode", &PyHgeSprite::SetBlendMode)
        .def("SetHotSpot", &PyHgeSprite::SetHotSpot)
        .def("SetFlip", &PyHgeSprite::SetFlip)

        .def("GetTexture", &PyHgeSprite::GetTexture)
        .def("GetTextureRect", &PyHgeSprite::GetTextureRectTuple)
        .def("GetColor", &PyHgeSprite::GetColor)
        .def("GetZ", &PyHgeSprite::GetZ)
        .def("GetBlendMode", &PyHgeSprite::GetBlendMode)
        .def("GetHotSpot", &PyHgeSprite::GetHotSpotTuple)
        .def("GetFlip", &PyHgeSprite::GetFlipTuple)

        .def("GetWidth", &PyHgeSprite::GetWidth)
        .def("GetHeight", &PyHgeSprite::GetHeight)

        .def("GetBoundingBox", &PyHgeSprite::GetBoundingBoxTuple)
        .def("GetBoundingExBox", &PyHgeSprite::GetBoundingBoxExTuple)
    ;
}