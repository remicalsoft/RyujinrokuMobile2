#include "DxLib.h"

extern "C" JNIEXPORT void JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_DxLibInit(JNIEnv* env, jobject thisj) {
    ScreenFlip();
    ProcessMessage();
    ClearDrawScreen();
}

void callStaticVoidMethod(JNIEnv* env, const char* className, const char* methodName) {
    auto clazz = env->FindClass(className);
    auto methodID = env->GetStaticMethodID(clazz, methodName, "()V");
    if (methodID != nullptr) {
        env->CallStaticVoidMethod(clazz, methodID);
    }
    env->DeleteLocalRef(clazz);
}
