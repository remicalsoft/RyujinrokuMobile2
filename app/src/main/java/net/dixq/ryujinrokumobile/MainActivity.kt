package net.dixq.ryujinrokumobile

import net.dixq.ryujinrokumobile.dxlib.Dx.LoadGraph
import android.app.NativeActivity
import android.util.Log
import net.dixq.ryujinrokumobile.dxlib.Dx
import net.dixq.ryujinrokumobile.Bullet
import java.util.*
import kotlin.system.measureTimeMillis

class MainActivity : NativeActivity() {
    fun start() {
        val handle = LoadGraph("bullet.png")
        val list = LinkedList<Bullet>()
        for (i in 0..10000) {
            val b = Bullet(handle)
            b.x = (Define.WIN_W / 2).toFloat()
            b.y = (Define.WIN_H / 2).toFloat()
            b.ang = Utils.Companion.randf2(Math.PI.toFloat())
            b.v = 1 + Utils.Companion.randf2(0.99F)
            list.push(b)
        }
        while(true){
            Dx.ScreenFlip()
            val elapsed = measureTimeMillis {
                var i = 0
                while(i < list.size){
                    if(!list[i].update()){
                        list.removeAt(i)
                    } else {
                        list[i].draw()
                        i++
                    }
                }
            }
            Log.e("rm", "time:$elapsed")
        }
    }
}