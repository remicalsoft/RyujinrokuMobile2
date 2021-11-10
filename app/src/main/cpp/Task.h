#pragma once

#include "Drawable.h"

class Task : public Drawable {
public:
    virtual ~Task() = default;
    virtual bool update() = 0;
};
