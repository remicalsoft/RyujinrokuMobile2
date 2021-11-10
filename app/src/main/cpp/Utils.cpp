//
// Created by dixq on 2021/11/09.
//

#include "Utils.h"
#include "DxLib.h"

/*
* @brief 0~valまでの乱数を返す
*/
float randf(float val) {
    return GetRand(1000000) / 1000000.f * val;
}

/*
* @brief -val~valまでの乱数を返す
*/
float randf2(float val) {
    return GetRand(1000000) / 500000.f * val - val;
}

