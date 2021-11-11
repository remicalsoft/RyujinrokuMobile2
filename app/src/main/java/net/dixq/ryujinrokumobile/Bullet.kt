package net.dixq.ryujinrokumobile

import kotlin.math.*

class Bullet(handle:Int) : Task() {

    var v = 0f;
    var range = 0f;
    init {
        imgHandle = handle
    }

    override fun update(): Boolean {
        x += cos(ang) * v
        y += sin(ang) * v
        return true
    }

}