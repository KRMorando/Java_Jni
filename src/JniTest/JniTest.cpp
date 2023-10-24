#include <jni.h>
#include <stdio.h>
#include <windows.h>
#include "JniTest_JniTest.h"

JNIEXPORT void JNICALL Java_JniTest_JniTest_PrintHelloWorld(JNIEnv *env, jobject obj) {
     printf("Hello World!");
     return;
}
