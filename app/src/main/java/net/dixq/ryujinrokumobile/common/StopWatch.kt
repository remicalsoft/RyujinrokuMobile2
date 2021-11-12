package net.dixq.ryujinrokumobile.common

class StopWatch {
    var startTime:Long = System.currentTimeMillis()
    fun start(){
        startTime = System.currentTimeMillis()
    }
    fun getDiff(): Int {
        return (System.currentTimeMillis()-startTime).toInt()
    }
}