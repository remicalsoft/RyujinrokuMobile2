#include "DxLib.h"

int android_main( )
{
    SetGraphMode(1080, 2280, 32);
    if( DxLib_Init() == -1 ){
        return -1;
    }
    SetDrawScreen( DX_SCREEN_BACK );

    if(1) {
        JNIEnv *env;
        const ANativeActivity *NativeActivity = GetNativeActivity();
        if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, NULL) != JNI_OK) {
            return -1;
        }
        jclass jclass_MainActivity = env->GetObjectClass(NativeActivity->clazz);
        jmethodID jmethodID_PopupWindowTest = env->GetMethodID(jclass_MainActivity, "start","()V");
        env->CallVoidMethod(NativeActivity->clazz, jmethodID_PopupWindowTest);
        env->DeleteLocalRef(jclass_MainActivity);
        NativeActivity->vm->DetachCurrentThread();
    }

    DxLib_End() ;
    return 0;
}
