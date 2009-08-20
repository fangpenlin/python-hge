import _hge

def main():
    hge = _hge.HGE(0x180)
    
    hge.System_SetState(_hge.HGE_WINDOWED, True);
	
    if hge.System_Initiate():
        hge.System_Start()
    else:
        print hge.System_GetErrorMessage()
    	
    hge.System_Shutdown()
    hge.Release()
	
if __name__ == '__main__':
    main()