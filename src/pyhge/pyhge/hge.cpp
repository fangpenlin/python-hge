#include "stdafx.h"
#include "pyhge.h"

void exposeHge() {
    using namespace boost::python;

    class_<PyHGE, boost::noncopyable>("HGE", init<int>())
        .def("Release", &PyHGE::Release)

        .def("System_Initiate", &PyHGE::System_Initiate)
        .def("System_Shutdown", &PyHGE::System_Shutdown)
        .def("System_Start", &PyHGE::System_Start)
        .def("System_GetErrorMessage", &PyHGE::System_GetErrorMessage)
        .def("System_SetStateBool", &PyHGE::System_SetStateBool)
        .def("System_SetStateFunc", &PyHGE::System_SetStateFunc)
        .def("System_SetStateHwnd", &PyHGE::System_SetStateHwnd)
        .def("System_SetStateInt", &PyHGE::System_SetStateInt)
        .def("System_SetStateString", &PyHGE::System_SetStateString)

        .def("Ini_SetInt", &PyHGE::Ini_SetInt)
        .def("Ini_GetInt", &PyHGE::Ini_GetInt)
        .def("Ini_SetFloat", &PyHGE::Ini_SetFloat)
        .def("Ini_GetFloat", &PyHGE::Ini_GetFloat)
        .def("Ini_SetString", &PyHGE::Ini_SetString)
        .def("Ini_GetString", &PyHGE::Ini_GetString)

        .def("Random_Seed", &PyHGE::Random_Seed)
        .def("Random_Int", &PyHGE::Random_Int)
        .def("Random_Float", &PyHGE::Random_Float)

        .def("Timer_GetTime", &PyHGE::Timer_GetTime)
        .def("Timer_GetDelta", &PyHGE::Timer_GetDelta)
        .def("Timer_GetFPS", &PyHGE::Timer_GetFPS)

        .def("Effect_Load", &PyHGE::Effect_Load)
        .def("Effect_Free", &PyHGE::Effect_Free)
        .def("Effect_Play", &PyHGE::Effect_Play)
        .def("Effect_PlayEx", &PyHGE::Effect_PlayEx)

        .def("Music_Load", &PyHGE::Music_Load)
        .def("Music_Free", &PyHGE::Music_Free)
        .def("Music_Play", &PyHGE::Music_Play)
        .def("Music_SetAmplification", &PyHGE::Music_SetAmplification)
        .def("Music_GetAmplification", &PyHGE::Music_GetAmplification)
        .def("Music_GetLength", &PyHGE::Music_GetLength)
        .def("Music_SetPos", &PyHGE::Music_SetPos)
        .def("Music_GetPos", &PyHGE::Music_GetPos)
        .def("Music_SetInstrVolume", &PyHGE::Music_SetInstrVolume)
        .def("Music_GetInstrVolume", &PyHGE::Music_GetInstrVolume)
        .def("Music_SetChannelVolume", &PyHGE::Music_SetChannelVolume)
        .def("Music_GetChannelVolume", &PyHGE::Music_GetChannelVolume)

        .def("Stream_Load", &PyHGE::Stream_Load)
        .def("Stream_Free", &PyHGE::Stream_Free)
        .def("Stream_Play", &PyHGE::Stream_Play)
        .def("Channel_SetPanning", &PyHGE::Channel_SetPanning)
        .def("Channel_SetVolume", &PyHGE::Channel_SetVolume)
        .def("Channel_SetPitch", &PyHGE::Channel_SetPitch)
        .def("Channel_Pause", &PyHGE::Channel_Pause)
        .def("Channel_Resume", &PyHGE::Channel_Resume)
        .def("Channel_Stop", &PyHGE::Channel_Stop)
        .def("Channel_PauseAll", &PyHGE::Channel_PauseAll)
        .def("Channel_ResumeAll", &PyHGE::Channel_ResumeAll)
        .def("Channel_StopAll", &PyHGE::Channel_StopAll)
        .def("Channel_IsPlaying", &PyHGE::Channel_IsPlaying)
        .def("Channel_GetLength", &PyHGE::Channel_GetLength)
        .def("Channel_GetPos", &PyHGE::Channel_GetPos)
        .def("Channel_SetPos", &PyHGE::Channel_SetPos)
        .def("Channel_SlideTo", &PyHGE::Channel_SlideTo)
        .def("Channel_IsSliding", &PyHGE::Channel_IsSliding)
        
        .def("Input_GetMousePos", &PyHGE::Input_GetMousePos)
        .def("Input_SetMousePos", &PyHGE::Input_SetMousePos)
        .def("Input_GetMouseWheel", &PyHGE::Input_GetMouseWheel)
        .def("Input_IsMouseOver", &PyHGE::Input_IsMouseOver)
        .def("Input_KeyDown", &PyHGE::Input_KeyDown)
        .def("Input_KeyUp", &PyHGE::Input_KeyUp)
        .def("Input_GetKeyState", &PyHGE::Input_GetKeyState)
        .def("Input_GetKeyName", &PyHGE::Input_GetKeyName)
        .def("Input_GetKey", &PyHGE::Input_GetKey)
        .def("Input_GetChar", &PyHGE::Input_GetChar)

        .def("Texture_Create", &PyHGE::Texture_Create)
        .def("Texture_Load", &PyHGE::Texture_Load)
        .def("Texture_Free", &PyHGE::Texture_Free)
        .def("Texture_GetWidth", &PyHGE::Texture_GetWidth)
        .def("Texture_GetHeight", &PyHGE::Texture_GetHeight)
        
    ;
}
