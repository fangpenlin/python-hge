#include "stdafx.h"

class PyHGE {
private:
    HGE *m_pHGE;
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
    virtual ~PyHGE() {
    
    }

	virtual	void Release() {
        m_pHGE->Release();
    }

	virtual bool System_Initiate() {
        return m_pHGE->System_Initiate();
    }

	virtual void System_Shutdown() {
        m_pHGE->System_Shutdown();
    }

	virtual bool System_Start() {
        return m_pHGE->System_Start();
    }

    virtual boost::python::str System_GetErrorMessage() {
        return boost::python::str(static_cast<const char *>(m_pHGE->System_GetErrorMessage()));
    }

	virtual	void System_Log(const char *format, ...) {

    }

	virtual bool System_Launch(const char *url) {
        return m_pHGE->System_Launch(url);
    }

	virtual void System_Snapshot(const char *filename=0) {
        m_pHGE->System_Snapshot(filename);
    }

	virtual void CALL System_SetStateBool(hgeBoolState state, bool value) {

    }

	virtual void CALL System_SetStateFunc(hgeFuncState state, hgeCallback value) {

    }

	virtual void		CALL	System_SetStateHwnd  (hgeHwndState   state, HWND        value) {

    }

	virtual void		CALL	System_SetStateInt   (hgeIntState    state, int         value) {

    }

	virtual void		CALL	System_SetStateString(hgeStringState state, const char *value) {
    }

	virtual bool		CALL	System_GetStateBool  (hgeBoolState   state) {
        return false;
    }

	virtual hgeCallback	CALL	System_GetStateFunc  (hgeFuncState   state) {
        return NULL;
    }

	virtual HWND		CALL	System_GetStateHwnd  (hgeHwndState   state) {
        return 0;
    }

	virtual int			CALL	System_GetStateInt   (hgeIntState    state) {
        return 0;
    }

	virtual const char*	CALL	System_GetStateString(hgeStringState state) {
        return NULL;
    }
	
	virtual void*		CALL	Resource_Load(const char *filename, DWORD *size=0) {
        return NULL;
    }

	virtual void		CALL	Resource_Free(void *res) {
    }

	virtual bool		CALL	Resource_AttachPack(const char *filename, const char *password=0) {
        return false;
    }

	virtual void		CALL	Resource_RemovePack(const char *filename) {
    }

	virtual void		CALL	Resource_RemoveAllPacks() {

    }

	virtual char*		CALL	Resource_MakePath(const char *filename=0) {
        return NULL;
    }

	virtual char*		CALL	Resource_EnumFiles(const char *wildcard=0) {
        return NULL;
    }

	virtual char*		CALL	Resource_EnumFolders(const char *wildcard=0) {
        return NULL;
    }

	virtual	void		CALL	Ini_SetInt(const char *section, const char *name, int value) {
    }

	virtual	int			CALL	Ini_GetInt(const char *section, const char *name, int def_val) {
        return 0;
    }

	virtual	void		CALL	Ini_SetFloat(const char *section, const char *name, float value) {

    }

	virtual	float		CALL	Ini_GetFloat(const char *section, const char *name, float def_val) {
        return 0;
    }

	virtual	void		CALL	Ini_SetString(const char *section, const char *name, const char *value) {

    }

	virtual	char*		CALL	Ini_GetString(const char *section, const char *name, const char *def_val) {
        return NULL;
    }

	virtual void		CALL	Random_Seed(int seed=0) {

    }

	virtual int			CALL	Random_Int(int min, int max) {
        return 0;
    }

	virtual float		CALL	Random_Float(float min, float max) {
        return 0;
    }

	virtual float		CALL	Timer_GetTime() {
        return 0;
    }

	virtual float		CALL	Timer_GetDelta() {
        return 0;
    }

	virtual int			CALL	Timer_GetFPS() {
        return 0;
    }

	virtual HEFFECT		CALL	Effect_Load(const char *filename, DWORD size=0) {
        return 0;
    }

	virtual void		CALL	Effect_Free(HEFFECT eff) {

    }

	virtual HCHANNEL	CALL 	Effect_Play(HEFFECT eff) {
        return 0;
    }

	virtual HCHANNEL	CALL	Effect_PlayEx(HEFFECT eff, int volume=100, int pan=0, float pitch=1.0f, bool loop=false) {
        return 0;
    }

	virtual HMUSIC		CALL	Music_Load(const char *filename, DWORD size=0) {
        return 0;
    }

	virtual void		CALL	Music_Free(HMUSIC mus) {

    }

	virtual HCHANNEL	CALL	Music_Play(HMUSIC mus, bool loop, int volume = 100, int order = -1, int row = -1) {
        return 0;
    }

	virtual void		CALL	Music_SetAmplification(HMUSIC music, int ampl) {

    }

	virtual int			CALL	Music_GetAmplification(HMUSIC music) {
        return 0;
    }

	virtual int			CALL	Music_GetLength(HMUSIC music) {
        return 0;
    }

	virtual void		CALL	Music_SetPos(HMUSIC music, int order, int row) {

    }

	virtual bool		CALL	Music_GetPos(HMUSIC music, int *order, int *row) {
        return false;
    }

	virtual void		CALL	Music_SetInstrVolume(HMUSIC music, int instr, int volume) {

    }

	virtual int			CALL	Music_GetInstrVolume(HMUSIC music, int instr) {
        return 0;
    }

	virtual void		CALL	Music_SetChannelVolume(HMUSIC music, int channel, int volume) {
        
    }

	virtual int			CALL	Music_GetChannelVolume(HMUSIC music, int channel) {
        return 0;
    }

	virtual HSTREAM		CALL	Stream_Load(const char *filename, DWORD size=0) {
        return 0;
    }

	virtual void		CALL	Stream_Free(HSTREAM stream) {
       
    }
	
    virtual HCHANNEL	CALL	Stream_Play(HSTREAM stream, bool loop, int volume = 100) {
        return 0;
    }

	virtual void		CALL	Channel_SetPanning(HCHANNEL chn, int pan) {
        
    }

	virtual void		CALL 	Channel_SetVolume(HCHANNEL chn, int volume) {
    
    }

	virtual void		CALL 	Channel_SetPitch(HCHANNEL chn, float pitch) {
    
    }

	virtual void		CALL 	Channel_Pause(HCHANNEL chn) {
    
    }

	virtual void		CALL 	Channel_Resume(HCHANNEL chn) {
    
    }

	virtual void		CALL 	Channel_Stop(HCHANNEL chn) {
    
    }

	virtual void		CALL 	Channel_PauseAll() {
    
    }

	virtual void		CALL 	Channel_ResumeAll() {
    
    }

	virtual void		CALL 	Channel_StopAll() {
    
    }

	virtual bool		CALL	Channel_IsPlaying(HCHANNEL chn) {
        return false;
    }

	virtual float		CALL	Channel_GetLength(HCHANNEL chn) {
        return 0;
    }

	virtual float		CALL	Channel_GetPos(HCHANNEL chn) {
        return 0;
    }
	
    virtual void		CALL	Channel_SetPos(HCHANNEL chn, float fSeconds) {
    
    }

	virtual void		CALL	Channel_SlideTo(HCHANNEL channel, float time, int volume, int pan = -101, float pitch = -1) {
        
    }

	virtual bool		CALL	Channel_IsSliding(HCHANNEL channel) {
        return false;
    }

	virtual void		CALL	Input_GetMousePos(float *x, float *y) {
    
    }

	virtual void		CALL	Input_SetMousePos(float x, float y) {
    
    }

	virtual int			CALL	Input_GetMouseWheel() {
        return 0;
    }

	virtual bool		CALL	Input_IsMouseOver() {
        return false;
    }

	virtual bool		CALL	Input_KeyDown(int key) {
        return false;
    }

	virtual bool		CALL	Input_KeyUp(int key) {
        return false;
    }

	virtual bool		CALL	Input_GetKeyState(int key) {
        return false;
    }

	virtual char*		CALL	Input_GetKeyName(int key) {
        return NULL;
    }

	virtual int			CALL	Input_GetKey() {
        return 0;
    }

	virtual int			CALL	Input_GetChar() {
        return 0;
    }

	virtual bool		CALL	Input_GetEvent(hgeInputEvent *event) {
        return false;
    }

	virtual bool		CALL	Gfx_BeginScene(HTARGET target=0) {
        return false;
    }

	virtual void		CALL	Gfx_EndScene() {
    
    }

	virtual void		CALL	Gfx_Clear(DWORD color) {
    
    }

	virtual void		CALL	Gfx_RenderLine(float x1, float y1, float x2, float y2, DWORD color=0xFFFFFFFF, float z=0.5f) {
    
    }

	virtual void		CALL	Gfx_RenderTriple(const hgeTriple *triple) {
        
    }

	virtual void		CALL	Gfx_RenderQuad(const hgeQuad *quad) {
    
    }
	
    virtual hgeVertex*	CALL	Gfx_StartBatch(int prim_type, HTEXTURE tex, int blend, int *max_prim) {
        return NULL;
    }

	virtual void		CALL	Gfx_FinishBatch(int nprim) {
        
    }

	virtual void		CALL	Gfx_SetClipping(int x=0, int y=0, int w=0, int h=0) {
    
    }

	virtual void		CALL	Gfx_SetTransform(float x=0, float y=0, float dx=0, float dy=0, float rot=0, float hscale=0, float vscale=0) {
    
    }

	virtual HTARGET		CALL	Target_Create(int width, int height, bool zbuffer) {
        return 0;
    }

	virtual void		CALL	Target_Free(HTARGET target) {
    
    }

	virtual HTEXTURE	CALL	Target_GetTexture(HTARGET target) {
        return 0;
    }

	virtual HTEXTURE	CALL	Texture_Create(int width, int height) {
        return 0;
    }

	virtual HTEXTURE	CALL	Texture_Load(const char *filename, DWORD size=0, bool bMipmap=false) {
        return 0;
    }

	virtual void		CALL	Texture_Free(HTEXTURE tex) {
    
    }

	virtual int			CALL	Texture_GetWidth(HTEXTURE tex, bool bOriginal=false) {
        return 0;
    }

	virtual int			CALL	Texture_GetHeight(HTEXTURE tex, bool bOriginal=false) {
        return 0;
    }

	virtual DWORD*		CALL	Texture_Lock(HTEXTURE tex, bool bReadOnly=true, int left=0, int top=0, int width=0, int height=0) {
        return NULL;
    }

	virtual void		CALL	Texture_Unlock(HTEXTURE tex) {
    
    }
};