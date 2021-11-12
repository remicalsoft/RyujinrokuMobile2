package net.dixq.ryujinrokumobile

import net.dixq.ryujinrokumobile.dxlib.Dx

open class Drawable {
    var imgHandle:Int = 0
    var x:Float = 0f
    var y:Float = 0f
    var z:Int = 0
    var size:Float = 1f
    var ang:Float = 0f

    fun draw(){
        Dx.DrawRotaGraph(x, y, size, ang, imgHandle)
    }
}