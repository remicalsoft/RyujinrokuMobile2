package net.dixq.ryujinrokumobile

import net.dixq.ryujinrokumobile.dxlib.Dx

open class Drawable {
    var imgHandle = 0
    public var x = 0f
    var y = 0f
    var z = 0
    var size = 1f
    var ang = 0f

    fun draw(){
        Dx.drawRotaGraph(x, y, size, ang, imgHandle)
    }
}