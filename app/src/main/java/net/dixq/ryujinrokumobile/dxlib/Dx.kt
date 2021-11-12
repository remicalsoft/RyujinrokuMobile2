package net.dixq.ryujinrokumobile.dxlib

object Dx {

    private external fun jLoadGraph(FileName:String): Int
    private external fun jLoadDivGraph(FileName:String, AllNum:Int, XNum:Int, YNum:Int, XSize:Int, YSize:Int, HandleBuf:IntArray): Int

    private external fun jDrawRotaGraph(x:Float, y:Float, size:Float, ang:Float, imgHandle:Int): Int

    private external fun jSetDrawMode(DrawMode:Int): Int
    private external fun jSetDrawBlendMode(BlendMode:Int, value:Int): Int

    private external fun jProcessMessage(): Int
    private external fun jClearDrawScreen(): Int
    private external fun jScreenFlip(): Int

    fun LoadGraph(path:String): Int {
        return jLoadGraph(path)
    }

    fun LoadDivGraph(FileName:String, AllNum:Int, XNum:Int, YNum:Int, XSize:Int, YSize:Int, HandleBuf:IntArray): Int {
        return jLoadDivGraph(FileName, AllNum, XNum, YNum, XSize, YSize, HandleBuf)
    }

    fun DrawRotaGraph(x:Float, y:Float, size:Float, ang:Float, imgHandle:Int): Int {
        return jDrawRotaGraph(x, y, size, ang, imgHandle)
    }

    fun SetDrawMode(drawMode:Int): Int {
        return jSetDrawMode(drawMode)
    }

    fun ProcessMessage(): Int {
        return jProcessMessage()
    }

    fun ClearDrawScreen(): Int {
        return jClearDrawScreen()
    }

    fun ScreenFlip(): Int {
        return jScreenFlip()
    }

    init {
        System.loadLibrary("ryujinrokumobile")
    }

    const val DX_DRAWMODE_NEAREST = 0	// ネアレストネイバー法で描画
    const val DX_DRAWMODE_BILINEAR = 1 // バイリニア法で描画する

    const val DX_BLENDMODE_NOBLEND = 0 // ノーブレンド
    const val DX_BLENDMODE_ALPHA = 1 // αブレンド
    const val DX_BLENDMODE_ADD = 2 // 加算ブレンド
    const val DX_BLENDMODE_SUB = 3 // 減算ブレンド
    const val DX_BLENDMODE_MUL = 4 // 乗算ブレンド

}
