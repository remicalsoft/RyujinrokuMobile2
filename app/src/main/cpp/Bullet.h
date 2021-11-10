#pragma once

#include <math.h>
#include "DxLib.h"
#include "Task.h"

class Bullet : public Task {

public:
    float v = 0;
    float range = 0;

    Bullet(int handle)
    {
        imgHandle = handle;
    }

    ~Bullet() = default;

    bool update() override {
        x += cos(ang) * v;
        y += sin(ang) * v;
        return true;
    }

    void draw() override {
        DrawRotaGraphF(x, y, size, ang, imgHandle, TRUE);
    }

};
