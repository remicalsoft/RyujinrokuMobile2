package net.dixq.ryujinrokumobile

import android.app.NativeActivity
import android.util.Log
import net.dixq.ryujinrokumobile.common.Lg
import net.dixq.ryujinrokumobile.dxlib.Dx
import java.util.*
import kotlin.system.measureTimeMillis

class MainActivity : NativeActivity() {
    fun start() {
        val handle = IntArray(8)
        Dx.LoadDivGraph("bullet2.png", 8, 8, 1, 62, 62, handle)
        val list = LinkedList<Bullet>()
        for (i in 0..10000) {
            val b = Bullet(handle[0])
            b.x = (Define.WIN_W / 2).toFloat()
            b.y = (Define.WIN_H / 2).toFloat()
            b.ang = Util.randf2(Math.PI.toFloat())
            b.v = 1 + Util.randf2(0.99F)
            list.push(b)
        }
        Dx.SetDrawMode(Dx.DX_DRAWMODE_BILINEAR)
        while(Dx.ScreenFlip()==0 && Dx.ProcessMessage()==0 && Dx.ClearDrawScreen()==0){
            val elapsed = measureTimeMillis {
                val it = list.iterator()
                while (it.hasNext()) {
                    val b = it.next()
                    if (!b.update()) {
                        it.remove()
                    } else {
                        b.draw()
                    }
                }
            }
            Lg.e("time:$elapsed")
        }
        Dx.SetDrawMode(Dx.DX_DRAWMODE_NEAREST)
    }
}