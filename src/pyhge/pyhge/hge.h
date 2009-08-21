#ifndef PYHGE_H_INCLUDED
#define PYHGE_H_INCLUDED

#include "headers.h"
#include "callback.h"
#include "data_types.h"

class PyHGE {
private:
    HGE *m_pHGE;
    Callback m_Callback;
public:
    /**
        @brief init hge
        @param version: version of hge to initialize
    **/
    PyHGE(int version) {
        m_pHGE = hgeCreate(version);
        if(!m_pHGE) {
            // throw
        }
    }
    ~PyHGE() {
    
    }

	void Release() {
        m_pHGE->Release();
        m_pHGE = NULL;
    }

	bool System_Initiate() {
        return m_pHGE->System_Initiate();
    }

	void System_Shutdown() {
        m_pHGE->System_Shutdown();
    }

	bool System_Start() {
        Callback::m_pCallback = &m_Callback;
        return m_pHGE->System_Start();
    }

    boost::python::str System_GetErrorMessage() {
        return boost::python::str(static_cast<const char *>(m_pHGE->System_GetErrorMessage()));
    }

    // TODO
	void System_Log(const char *format, ...) {

    }

	bool System_Launch(const char *url) {
        return m_pHGE->System_Launch(url);
    }

	void System_Snapshot(const char *filename=0) {
        m_pHGE->System_Snapshot(filename);
    }

	void System_SetStateBool(int state, bool value) {
        m_pHGE->System_SetState(static_cast<hgeBoolState>(state), value);
    }

    void System_SetStateFunc(int state, boost::python::object value) {
        hgeFuncState funcState = static_cast<hgeFuncState>(state);
        switch(funcState) {
            case HGE_FRAMEFUNC:
                m_Callback.m_FrameFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::frameFunc);
                break;
            case HGE_RENDERFUNC:
                m_Callback.m_RenderFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::renderFunc);
                break;
            case HGE_FOCUSLOSTFUNC:
                m_Callback.m_FocusLostFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::focusLostFunc);
                break;
            case HGE_FOCUSGAINFUNC:
                m_Callback.m_FocusGainFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::focusGainFunc);
                break;
            case HGE_GFXRESTOREFUNC:
                m_Callback.m_GfxRestoreFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::gfxRestoreFunc);
                break;
            case HGE_EXITFUNC:
                m_Callback.m_ExitFunc = value;
                m_pHGE->System_SetState(funcState, &Callback::exitFunc);
                break;
        }
    }

	void System_SetStateHwnd(int state, HWND value) {
        m_pHGE->System_SetState(static_cast<hgeHwndState>(state), value);
    }

	void System_SetStateInt(int state, int value) {
        m_pHGE->System_SetState(static_cast<hgeIntState>(state), value);
    }

	void System_SetStateString(int state, const char *value) {
        m_pHGE->System_SetState(static_cast<hgeStringState>(state), value);
    }

	bool System_GetStateBool(hgeBoolState   state) {
        return m_pHGE->System_GetState(state);
    }

	hgeCallback	System_GetStateFunc(hgeFuncState state) {
        return NULL;
    }

	HWND System_GetStateHwnd(hgeHwndState state) {
        return m_pHGE->System_GetState(state);
    }

	int	System_GetStateInt(hgeIntState state) {
        return m_pHGE->System_GetState(state);
    }

    boost::python::str System_GetStateString(hgeStringState state) {
        return boost::python::str(m_pHGE->System_GetState(state));
    }
	
    // TODO
	void* Resource_Load(const char *filename, DWORD *size=0) {
        return NULL;
    }

    // TODO
	void Resource_Free(void *res) {
    }

	bool Resource_AttachPack(const char *filename, const char *password=0) {
        return m_pHGE->Resource_AttachPack(filename, password);
    }

	void Resource_RemovePack(const char *filename) {
        m_pHGE->Resource_RemovePack(filename);
    }

	void Resource_RemoveAllPacks() {
        m_pHGE->Resource_RemoveAllPacks();
    }

    boost::python::str Resource_MakePath(const char *filename=0) {
        return boost::python::str(static_cast<const char*>(m_pHGE->Resource_MakePath(filename)));
    }

	boost::python::str Resource_EnumFiles(const char *wildcard=0) {
        return boost::python::str(static_cast<const char*>(m_pHGE->Resource_EnumFiles(wildcard)));
    }

	boost::python::str Resource_EnumFolders(const char *wildcard=0) {
        return boost::python::str(static_cast<const char*>(m_pHGE->Resource_EnumFolders(wildcard)));
    }

	void Ini_SetInt(const char *section, const char *name, int value) {
        m_pHGE->Ini_SetInt(section, name, value);
    }

	int	Ini_GetInt(const char *section, const char *name, int def_val) {
        return m_pHGE->Ini_GetInt(section, name, def_val);
    }

	void Ini_SetFloat(const char *section, const char *name, float value) {
        m_pHGE->Ini_SetFloat(section, name, value);
    }

	float Ini_GetFloat(const char *section, const char *name, float def_val) {
        return m_pHGE->Ini_GetFloat(section, name, def_val);
    }

	void Ini_SetString(const char *section, const char *name, const char *value) {
        return m_pHGE->Ini_SetString(section, name, value);
    }

    boost::python::str Ini_GetString(const char *section, const char *name, const char *def_val) {
        return boost::python::str(static_cast<const char*>(m_pHGE->Ini_GetString(section, name, def_val)));
    }

	void Random_Seed(int seed=0) {
        m_pHGE->Random_Seed(seed);
    }

	int Random_Int(int min, int max) {
        return m_pHGE->Random_Int(min, max);
    }

	float Random_Float(float min, float max) {
        return m_pHGE->Random_Float(min, max);
    }

	float Timer_GetTime() {
        return m_pHGE->Timer_GetTime();
    }

	float Timer_GetDelta() {
        return m_pHGE->Timer_GetDelta();
    }

	int Timer_GetFPS() {
        return m_pHGE->Timer_GetFPS();
    }

	HEFFECT Effect_Load(const char *filename, DWORD size=0) {
        return m_pHGE->Effect_Load(filename, size);
    }

	void Effect_Free(HEFFECT eff) {
        m_pHGE->Effect_Free(eff);
    }

	HCHANNEL Effect_Play(HEFFECT eff) {
        return m_pHGE->Effect_Play(eff);
    }

	HCHANNEL Effect_PlayEx(HEFFECT eff, int volume=100, int pan=0, float pitch=1.0f, bool loop=false) {
        return m_pHGE->Effect_PlayEx(eff, volume, pan, pitch, loop);
    }

	HMUSIC Music_Load(const char *filename, DWORD size=0) {
        return m_pHGE->Music_Load(filename, size);
    }

	void Music_Free(HMUSIC mus) {
        m_pHGE->Music_Free(mus);
    }

	HCHANNEL Music_Play(HMUSIC mus, bool loop, int volume = 100, int order = -1, int row = -1) {
        return m_pHGE->Music_Play(mus, loop, volume, order, row);
    }

	void Music_SetAmplification(HMUSIC music, int ampl) {
        m_pHGE->Music_SetAmplification(music, ampl);
    }

	int	Music_GetAmplification(HMUSIC music) {
        return m_pHGE->Music_GetAmplification(music);
    }

	int	Music_GetLength(HMUSIC music) {
        return m_pHGE->Music_GetLength(music);
    }

	void Music_SetPos(HMUSIC music, int order, int row) {
        m_pHGE->Music_SetPos(music, order, row);
    }

    boost::python::tuple Music_GetPos(HMUSIC music) {
        int order;
        int row;
        bool result =  m_pHGE->Music_GetPos(music, &order, &row);
        return boost::python::make_tuple(result, order, row);
    }

	void Music_SetInstrVolume(HMUSIC music, int instr, int volume) {
        m_pHGE->Music_SetInstrVolume(music, instr, volume);
    }

	int Music_GetInstrVolume(HMUSIC music, int instr) {
        return m_pHGE->Music_GetInstrVolume(music, instr);
    }

	void Music_SetChannelVolume(HMUSIC music, int channel, int volume) {
        m_pHGE->Music_SetChannelVolume(music, channel, volume);
    }

	int Music_GetChannelVolume(HMUSIC music, int channel) {
        return m_pHGE->Music_GetChannelVolume(music, channel);
    }

	HSTREAM	Stream_Load(const char *filename, DWORD size=0) {
        return m_pHGE->Stream_Load(filename, size);
    }

	void Stream_Free(HSTREAM stream) {
       m_pHGE->Stream_Free(stream);
    }
	
    HCHANNEL Stream_Play(HSTREAM stream, bool loop, int volume = 100) {
        return m_pHGE->Stream_Play(stream, loop, volume);
    }

	void Channel_SetPanning(HCHANNEL chn, int pan) {
        m_pHGE->Channel_SetPanning(chn, pan);
    }

	void Channel_SetVolume(HCHANNEL chn, int volume) {
        m_pHGE->Channel_SetVolume(chn, volume);
    }

	void Channel_SetPitch(HCHANNEL chn, float pitch) {
        m_pHGE->Channel_SetPitch(chn, pitch);
    }

	void Channel_Pause(HCHANNEL chn) {
         m_pHGE->Channel_Pause(chn);
    }

	void Channel_Resume(HCHANNEL chn) {
        m_pHGE->Channel_Resume(chn);
    }

	void Channel_Stop(HCHANNEL chn) {
        m_pHGE->Channel_Stop(chn);
    }

	void Channel_PauseAll() {
        m_pHGE->Channel_PauseAll();
    }

	void Channel_ResumeAll() {
        m_pHGE->Channel_ResumeAll();
    }

	void Channel_StopAll() {
        m_pHGE->Channel_StopAll();
    }

	bool Channel_IsPlaying(HCHANNEL chn) {
        return m_pHGE->Channel_IsPlaying(chn);
    }

	float Channel_GetLength(HCHANNEL chn) {
        return m_pHGE->Channel_GetLength(chn);
    }

	float Channel_GetPos(HCHANNEL chn) {
        return m_pHGE->Channel_GetPos(chn);
    }
	
    void Channel_SetPos(HCHANNEL chn, float fSeconds) {
        m_pHGE->Channel_SetPos(chn, fSeconds);
    }

	void Channel_SlideTo(HCHANNEL channel, float time, int volume, int pan = -101, float pitch = -1) {
        m_pHGE->Channel_SlideTo(channel, time, volume, pan, pitch);
    }

	bool Channel_IsSliding(HCHANNEL channel) {
        return m_pHGE->Channel_IsSliding(channel);
    }

    boost::python::tuple Input_GetMousePos() {
        float x;
        float y;
        m_pHGE->Input_GetMousePos(&x, &y);
        return boost::python::make_tuple(x, y);
    }

	void Input_SetMousePos(float x, float y) {
        m_pHGE->Input_SetMousePos(x, y);
    }

	int Input_GetMouseWheel() {
        return m_pHGE->Input_GetMouseWheel();
    }

	bool Input_IsMouseOver() {
        return m_pHGE->Input_IsMouseOver();
    }

	bool Input_KeyDown(int key) {
        return m_pHGE->Input_KeyDown(key);
    }

	bool Input_KeyUp(int key) {
        return m_pHGE->Input_KeyUp(key);
    }

	bool Input_GetKeyState(int key) {
        return m_pHGE->Input_GetKeyState(key);
    }

    boost::python::str Input_GetKeyName(int key) {
        return boost::python::str(static_cast<const char*>(m_pHGE->Input_GetKeyName(key)));
    }

	int	Input_GetKey() {
        return m_pHGE->Input_GetKey();
    }

	int Input_GetChar() {
        return m_pHGE->Input_GetChar();
    }

    boost::python::object Input_GetEvent() {
        hgeInputEvent event;
        if(m_pHGE->Input_GetEvent(&event)) {
            boost::python::dict result;
            result["type"] = event.type;
            result["key"] = event.key;
            result["flags"] = event.flags;
            result["chr"] = event.chr;
            result["wheel"] = event.wheel;
            result["x"] = event.x;
            result["y"] = event.y;
            return result;
        }
        // return None
        return boost::python::object();
    }

	bool Gfx_BeginScene(HTARGET target=0) {
        return m_pHGE->Gfx_BeginScene(target);
    }

	void Gfx_EndScene() {
        m_pHGE->Gfx_EndScene();
    }

	void Gfx_Clear(DWORD color) {
        m_pHGE->Gfx_Clear(color);
    }

	void Gfx_RenderLine(float x1, float y1, float x2, float y2, DWORD color=0xFFFFFFFF, float z=0.5f) {
        m_pHGE->Gfx_RenderLine(x1, y1, x2, y2, color, z);
    }


	void Gfx_RenderTriple(const PyHgeTriple triple) {
       m_pHGE->Gfx_RenderTriple(&triple);
    }

	void Gfx_RenderQuad(const PyHgeQuad quad) {
       m_pHGE->Gfx_RenderQuad(&quad); 
    }
	
    // TODO
    hgeVertex*	CALL	Gfx_StartBatch(int prim_type, HTEXTURE tex, int blend, int *max_prim) {
        return NULL;
    }

	void Gfx_FinishBatch(int nprim) {
        m_pHGE->Gfx_FinishBatch(nprim); 
    }

	void Gfx_SetClipping(int x=0, int y=0, int w=0, int h=0) {
        m_pHGE->Gfx_SetClipping(x, y, w, h); 
    }

	void Gfx_SetTransform(float x=0, float y=0, float dx=0, float dy=0, float rot=0, float hscale=0, float vscale=0) {
        m_pHGE->Gfx_SetTransform(x, y, dx, dy, rot, hscale, vscale); 
    }

	HTARGET	Target_Create(int width, int height, bool zbuffer) {
        return m_pHGE->Target_Create(width, height, zbuffer); 
    }

	void Target_Free(HTARGET target) {
        return m_pHGE->Target_Free(target); 
    }

	HTEXTURE Target_GetTexture(HTARGET target) {
        return m_pHGE->Target_GetTexture(target); 
    }

	HTEXTURE Texture_Create(int width, int height) {
        return m_pHGE->Texture_Create(width, height);
    }

	HTEXTURE Texture_Load(const char *filename, DWORD size=0, bool bMipmap=false) {
        return m_pHGE->Texture_Load(filename, size, bMipmap);
    }

	void Texture_Free(HTEXTURE tex) {
        m_pHGE->Texture_Free(tex);
    }

	int	Texture_GetWidth(HTEXTURE tex, bool bOriginal=false) {
        return m_pHGE->Texture_GetWidth(tex, bOriginal);
    }

	int	Texture_GetHeight(HTEXTURE tex, bool bOriginal=false) {
        return m_pHGE->Texture_GetHeight(tex, bOriginal);
    }

    // TODO
	DWORD* Texture_Lock(HTEXTURE tex, bool bReadOnly=true, int left=0, int top=0, int width=0, int height=0) {
        return NULL;
    }

	void Texture_Unlock(HTEXTURE tex) {
        return m_pHGE->Texture_Unlock(tex);
    }
};

#endif // PYHGE_H_INCLUDED