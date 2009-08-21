'''
Created on 2009/8/21

@author: Stubborn
'''
import math

import _hge

def main():
    hge = _hge.HGE(_hge.HGE_VERSION)
    
    quad = None
    sprite = None
    
    # use list, because scope problem
    radians = [0]
    x = [100]
    y = [100]

    def frameFunc():
        if hge.Input_GetKeyState(_hge.HGEK_ESCAPE):
            return True
        
        v = 0.5
        if hge.Input_GetKeyState(_hge.HGEK_UP):
            for i in range(4):
                y[0] -= v
        if hge.Input_GetKeyState(_hge.HGEK_DOWN):
            for i in range(4):
                y[0] += v
        if hge.Input_GetKeyState(_hge.HGEK_LEFT):
            for i in range(4):
                x[0] -= v
        if hge.Input_GetKeyState(_hge.HGEK_RIGHT):
            for i in range(4):
                x[0] += v
        
        radians[0] += math.pi/720
                
        return False
    
    def renderFunc():
        # Begin rendering quads.
        # This function must be called
        # before any actual rendering.
        hge.Gfx_BeginScene(0);
    
        # Clear screen with black color
        hge.Gfx_Clear(0);
    
        # Render quads here. This time just
        # one of them will serve our needs.
        hge.Gfx_RenderQuad(quad);
        
        sprite.RenderEx(x[0], y[0], radians[0], 1.0, 0.0)
    
        # End rendering and update the screen
        hge.Gfx_EndScene();
        return False
    
    hge.System_SetStateFunc(_hge.HGE_FRAMEFUNC, frameFunc);
    
    hge.System_SetStateFunc(_hge.HGE_RENDERFUNC, renderFunc);
    
    hge.System_SetStateString(
        _hge.HGE_TITLE, "TEST")
    
    hge.System_SetStateBool(_hge.HGE_WINDOWED, True);
    
    if hge.System_Initiate():
        # load texture
        import os
        texture = hge.Texture_Load(os.path.abspath("yuki.jpg"), 0, False)
        if not texture:
            print hge.System_GetErrorMessage()
        
        blend = _hge.BLEND_ALPHAADD | _hge.BLEND_COLORMUL | _hge.BLEND_ZWRITE
        
        v0 = _hge.hgeVertex(0, 0, 0, 0xFFFFA000, 0, 0)
        v1 = _hge.hgeVertex(200, 0, 0, 0xFFFFA000, 1, 0)
        v2 = _hge.hgeVertex(200, 200, 0, 0xFFFFA000, 1, 1)
        v3 = _hge.hgeVertex(0, 200, 0, 0xFFFFA000, 0, 1)
        
        quad = _hge.hgeQuad((v0, v1, v2, v3), texture, blend)
    
        w = hge.Texture_GetWidth(texture, False)
        h = hge.Texture_GetHeight(texture, False)
        sprite = _hge.hgeSprite(texture, 0, 0, w, h)
        sprite.SetHotSpot(w*0.5, h*0.5)
    
        if not hge.System_Start():
            print hge.System_GetErrorMessage()
    else:
        print hge.System_GetErrorMessage()
        
    hge.System_Shutdown()
    hge.Release()
    
if __name__ == '__main__':
    main()