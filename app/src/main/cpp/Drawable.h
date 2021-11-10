#pragma once

#include "DxLib.h"

class Drawable {

public:
    virtual ~Drawable() = default;
    virtual void draw(){
        printfDx("super draw()");
        DrawRotaGraph(x, y, size, ang, imgHandle, TRUE);
    };

    int imgHandle;
    float x = 0, y = 0;
    int z = 0;
    float size = 1.f;
    float ang = 0;

};
