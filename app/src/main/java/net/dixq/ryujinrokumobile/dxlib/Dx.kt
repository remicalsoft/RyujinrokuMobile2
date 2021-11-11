package net.dixq.ryujinrokumobile.dxlib

import android.util.Log

object Dx {

    external fun DxLibInit()

    init {
        Log.e("rm","loadlibrary")
        System.loadLibrary("ryujinrokumobile")
    }

    fun initialize(){
        Log.e("rm", "initialize")
        DxLibInit()
    }

}