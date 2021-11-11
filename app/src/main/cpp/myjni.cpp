#include "DxLib.h"
#include <string>

std::string jstring2string(JNIEnv *env, jstring jStr) {

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

extern "C" JNIEXPORT void JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_DrawRotaGraph(JNIEnv *env, jobject thiz, jfloat x, jfloat y, jfloat size, jfloat ang, jint img_handle) {
    DrawRotaGraphF(x, y, size, ang, img_handle, TRUE);
}

extern "C" JNIEXPORT void JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_ScreenFlip(JNIEnv *env, jobject thiz) {
    ScreenFlip();
    ProcessMessage();
    ClearDrawScreen();
}

extern "C" JNIEXPORT jint JNICALL
Java_net_dixq_ryujinrokumobile_dxlib_Dx_LoadGraph(JNIEnv *env, jobject thiz, jstring path) {
    return LoadGraph(jstring2string(env, path).c_str());
}
