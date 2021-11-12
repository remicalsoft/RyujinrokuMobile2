#include "DxLib.h"
#include <string>
#include "Utils.h"

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jLoadGraph(JNIEnv *env, jclass thiz, jstring path) {
    return LoadGraph(jstring2string(env, path).c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jDrawRotaGraph(JNIEnv *env, jclass thiz, jfloat x, jfloat y, jfloat size, jfloat ang, jint img_handle) {
    return DrawRotaGraphF(x, y, size, ang, img_handle, TRUE);
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jProcessMessage(JNIEnv *env, jclass thiz) {
    return ProcessMessage();
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jClearDrawScreen(JNIEnv *env, jclass thiz) {
    return ClearDrawScreen();
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jScreenFlip(JNIEnv *env, jclass thiz) {
    return ScreenFlip();
}

extern "C"
JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_DxSendCommand(JNIEnv *env, jclass thiz, jintArray command, jint len) {
//  jsize len = (*env)->GetArrayLength(env, command);
    jint *array = (env)->GetIntArrayElements(command, 0);
    for (int i=0; i<len; i+=3) {
        DrawGraph(array[i+0],array[i+1],array[i+2],TRUE);
    }
    (env)->ReleaseIntArrayElements(command, array, 0);
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jSetDrawMode(JNIEnv *env, jclass thiz, jint draw_mode) {
    return SetDrawMode(draw_mode);
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jSetDrawBlendMode(JNIEnv *env, jclass thiz, jint blend_mode, jint value) {
    return SetDrawBlendMode(blend_mode, value);
}

extern "C"
JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jLoadDivGraph(JNIEnv *env, jclass thiz, jstring file_name,
                                                     jint all_num, jint xnum, jint ynum, jint xsize,
                                                     jint ysize, jintArray handle_buf) {
    jboolean isCopy = false;
    jint *array = (env)->GetIntArrayElements(handle_buf, &isCopy);
    if(array == nullptr){
        return -1;
    }
    int ret = LoadDivGraph(jstring2string(env, file_name).c_str(),
            all_num, xnum, ynum, xsize, ysize, array);
    (env)->ReleaseIntArrayElements(handle_buf, array, JNI_COMMIT);
    return ret;
}

extern "C"
JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_jText(JNIEnv *jenv, jclass clazz, jintArray jvalues) {
    // 配列数取得
    jsize length = jenv->GetArrayLength(jvalues);

    // 配列への値設定
    jint * intArray = jenv->GetIntArrayElements(jvalues, NULL);
    intArray[0] = 10;
    jenv->ReleaseIntArrayElements(jvalues, intArray, 0);
}