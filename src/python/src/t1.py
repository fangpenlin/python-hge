import _hge

def main():
    hge = _hge.HGE(_hge.HGE_VERSION)
    
    def frameFunc():
        if hge.Input_GetKeyState(_hge.HGEK_ESCAPE):
            return True;
        return False
    
    hge.System_SetStateFunc(_hge.HGE_FRAMEFUNC, frameFunc);
    
    hge.System_SetStateString(
        _hge.HGE_TITLE, "HGE Tutorial 01 - Minimal HGE application")
    
    hge.System_SetStateBool(_hge.HGE_WINDOWED, True);
	
    if hge.System_Initiate():
        if not hge.System_Start():
            print hge.System_GetErrorMessage()
    else:
        print hge.System_GetErrorMessage()
    	
    hge.System_Shutdown()
    hge.Release()
	
if __name__ == '__main__':
    main()