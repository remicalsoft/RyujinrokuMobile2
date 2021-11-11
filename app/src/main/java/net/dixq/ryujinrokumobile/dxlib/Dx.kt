package net.dixq.ryujinrokumobile.dxlib

object Dx {

    external fun DrawRotaGraph(x:Float, y:Float, size:Float, ang:Float, imgHandle:Int)
    external fun ScreenFlip()
    external fun LoadGraph(path:String): Int

    fun drawRotaGraph(x:Float, y:Float, size:Float, ang:Float, imgHandle:Int){
        DrawRotaGraph(x, y, size, ang, imgHandle)
    }

    fun screenFlip(){
        ScreenFlip()
    }

    fun loadGraph(path:String): Int {
        return LoadGraph(path)
    }

    init {
        System.loadLibrary("ryujinrokumobile")
    }

}