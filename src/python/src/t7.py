'''
Created on 2009/8/21

@author: Stubborn
'''

import math
import os

import _hge

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
MIN_OBJECTS = 100
MAX_OBJECTS = 2000

tex = None
bgTex = None
spr = None
bgSpr = None
hge = None
objects = []
nObjects = 1000
nBlend = 0

class SprObject(object):
    
    def __init__(
        self, x=0, y=0, dx=0, dy=0, scale=0, rot=0, dscale=0, drot=0, color=0
    ):
        self.x = x
        self.y = y
        self.dx = dx
        self.dy = dy
        self.scale = scale
        self.rot = rot
        self.dscale = dscale
        self.drot = drot
        self.color = color
        
def SetBlend(blend):
    sprBlend= [
        _hge.BLEND_COLORMUL | _hge.BLEND_ALPHABLEND | _hge.BLEND_NOZWRITE,
        _hge.BLEND_COLORADD | _hge.BLEND_ALPHABLEND | _hge.BLEND_NOZWRITE,
        _hge.BLEND_COLORMUL | _hge.BLEND_ALPHABLEND | _hge.BLEND_NOZWRITE,
        _hge.BLEND_COLORMUL | _hge.BLEND_ALPHAADD   | _hge.BLEND_NOZWRITE,
        _hge.BLEND_COLORMUL | _hge.BLEND_ALPHABLEND | _hge.BLEND_NOZWRITE
    ]

    sprColors = [
        [ 0xFFFFFFFF, 0xFFFFE080, 0xFF80A0FF, 0xFFA0FF80, 0xFFFF80A0 ],
        [ 0xFF000000, 0xFF303000, 0xFF000060, 0xFF006000, 0xFF600000 ],
        [ 0x80FFFFFF, 0x80FFE080, 0x8080A0FF, 0x80A0FF80, 0x80FF80A0 ],
        [ 0x80FFFFFF, 0x80FFE080, 0x8080A0FF, 0x80A0FF80, 0x80FF80A0 ],
        [ 0x40202020, 0x40302010, 0x40102030, 0x40203010, 0x40102030 ]
    ]

    if blend > 4:
        blend = 0
    
    global nBlend
    nBlend = blend
    spr.SetBlendMode(sprBlend[blend])
    for obj in objects:
        obj.color = sprColors[blend][hge.Random_Int(0, 4)]
    
fpsElipsed = 0
def frameFunc():
    global nBlend, nObjects
    key = hge.Input_GetKey()
    if key == _hge.HGEK_ESCAPE:
        return True
    elif key == _hge.HGEK_SPACE:
        nBlend += 1
        SetBlend(nBlend)
    elif key == _hge.HGEK_UP:
        if nObjects < MAX_OBJECTS:
            nObjects += 100
    elif key == _hge.HGEK_DOWN:
        if nObjects > MIN_OBJECTS:
            nObjects -= 100
    
    dt = hge.Timer_GetDelta()
    
    def update(obj):
        obj.x += obj.dx * dt
        if obj.x > SCREEN_WIDTH or obj.x < 0:
            obj.dx = -obj.dx
            
        obj.y += obj.dy*dt
        if obj.y > SCREEN_HEIGHT or obj.y < 0:
            obj.dy = -obj.dy
            
        obj.scale += obj.dscale * dt
        if obj.scale > 2 or obj.scale < 0.5:
            obj.dscale = -obj.dscale
            
        obj.rot += obj.drot*dt
    
    for i in xrange(nObjects):
        update(objects[i])
    
    global fpsElipsed
    fpsElipsed += dt
    if fpsElipsed >= 3:
        print 'FPS:', hge.Timer_GetFPS()
        fpsElipsed = 0
    return False

def renderFunc():
    hge.Gfx_BeginScene(0)
    bgSpr.Render(0,0)
    
    def render(obj):
        spr.SetColor(obj.color, -1)
        spr.RenderEx(obj.x, obj.y, obj.rot, obj.scale, 0.0)
        
    for i in range(nObjects):
        render(objects[i])
        
    hge.Gfx_EndScene()
    return False

def main():
    global hge, spr, bgSpr
    
    hge = _hge.HGE(_hge.HGE_VERSION);

    hge.System_SetStateFunc(_hge.HGE_FRAMEFUNC, frameFunc)
    hge.System_SetStateFunc(_hge.HGE_RENDERFUNC, renderFunc)
    hge.System_SetStateString(
        _hge.HGE_TITLE, "HGE Tutorial 07 - Thousand of Hares")
    hge.System_SetStateBool(_hge.HGE_USESOUND, False)
    hge.System_SetStateBool(_hge.HGE_WINDOWED, True)
    hge.System_SetStateInt(_hge.HGE_SCREENWIDTH, SCREEN_WIDTH)
    hge.System_SetStateInt(_hge.HGE_SCREENHEIGHT, SCREEN_HEIGHT)
    hge.System_SetStateInt(_hge.HGE_SCREENBPP, 32)

    if hge.System_Initiate():
        # Load textures
        bgtex = hge.Texture_Load(os.path.abspath("bg2.png"), 0, False)
        tex = hge.Texture_Load(os.path.abspath("zazaka.png"), 0, False)
        if not bgtex or not tex:
            # If one of the data files is not found,
            # display an error message and shutdown
            print "Can't load BG2.PNG or ZAZAKA.PNG"
            hge.System_Shutdown()
            hge.Release()
            return

        # Load font, create sprites

        spr = _hge.hgeSprite(tex, 0, 0, 64, 64)
        spr.SetHotSpot(32, 32)

        bgSpr = _hge.hgeSprite(bgtex, 0, 0, 800, 600)
        bgSpr.SetBlendMode(
            _hge.BLEND_COLORADD | _hge.BLEND_ALPHABLEND | _hge.BLEND_NOZWRITE)
        bgSpr.SetColor(0xFF000000, 0)
        bgSpr.SetColor(0xFF000000, 1)
        bgSpr.SetColor(0xFF000040, 2)
        bgSpr.SetColor(0xFF000040, 3)

        # Initialize objects list
        for i in range(MAX_OBJECTS):
            objects.append(SprObject())
            objects[i].x = hge.Random_Float(0, SCREEN_WIDTH)
            objects[i].y = hge.Random_Float(0, SCREEN_HEIGHT)
            objects[i].dx = hge.Random_Float(-200, 200)
            objects[i].dy = hge.Random_Float(-200, 200)
            objects[i].scale = hge.Random_Float(0.5, 2.0)
            objects[i].dscale = hge.Random_Float(-1.0, 1.0)
            objects[i].rot = hge.Random_Float(0, math.pi*2)
            objects[i].drot = hge.Random_Float(-1.0, 1.0)
        
        SetBlend(0)

        # Let's rock now!
        hge.System_Start()

        # Delete created objects and free loaded resources
        hge.Texture_Free(tex)
        hge.Texture_Free(bgtex)

    # Clean up and shutdown
    hge.System_Shutdown()
    hge.Release()
    
if __name__ == '__main__':
    main()