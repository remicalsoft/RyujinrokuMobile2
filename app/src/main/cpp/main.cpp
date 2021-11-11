#include "DxLib.h"
#include <memory>
#include <list>

using namespace std;

#include "android/log.h"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "TAG", __VA_ARGS__)

// プログラムは android_main から始まります
int android_main( )
{
    SetGraphMode(1080, 2280, 32);

    if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
    {
        return -1;			// エラーが起きたら直ちに終了
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

    WaitKey() ;				// キー入力待ち

    DxLib_End() ;				// ＤＸライブラリ使用の終了処理

    return 0;
}