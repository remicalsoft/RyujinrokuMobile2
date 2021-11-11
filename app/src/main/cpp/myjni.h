#pragma once

#include <jni.h>

void callStaticVoidMethod(JNIEnv* env, const char* className, const char* methodName);
