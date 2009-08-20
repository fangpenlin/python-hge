import _hge

def main():
    hge = _hge.HGE(0x180)
    
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
    #main()
    v = _hge.hgeVertex(1, 2, 3, 0, 1, 2)
    print v.x
    print v.y
    print v.x