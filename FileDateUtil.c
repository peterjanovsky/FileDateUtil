#include <jni.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include "FileDateUtil.h"

JNIEXPORT jstring JNICALL Java_com_pjanof_cache_utilities_FileDateUtil_getLastAccessDate (JNIEnv *env, jobject obj, jstring fileName) {

    // convert to native string
    const char *nativeString = (*env)->GetStringUTFChars(env, fileName, 0);

    struct tm * timeinfo;  // time structure
    struct stat attrib;    // file attribute structure
    stat(nativeString, &attrib);

    char buffer[80];
    timeinfo = gmtime(&(attrib.st_atime));
    strftime(buffer, 256, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);

    // cleanup
    (*env)->ReleaseStringUTFChars(env, fileName, nativeString);

    return (*env)->NewStringUTF(env, buffer);
}

JNIEXPORT jstring JNICALL Java_com_pjanof_cache_utilities_FileDateUtil_getLastModifiedDate (JNIEnv *env, jobject obj, jstring fileName) {

    // convert to native string
    const char *nativeString = (*env)->GetStringUTFChars(env, fileName, 0);

    struct tm * timeinfo;  // time structure
    struct stat attrib;    // file attribute structure
    stat(nativeString, &attrib);

    char buffer[80];
    timeinfo = gmtime(&(attrib.st_mtime));
    strftime(buffer, 256, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);

    // cleanup
    (*env)->ReleaseStringUTFChars(env, fileName, nativeString);

    return (*env)->NewStringUTF(env, buffer);
}

JNIEXPORT jstring JNICALL Java_com_pjanof_cache_utilities_FileDateUtil_getLastStatusChangedDate (JNIEnv *env, jobject obj, jstring fileName) {

    // convert to native string
    const char *nativeString = (*env)->GetStringUTFChars(env, fileName, 0);

    struct tm * timeinfo;  // time structure
    struct stat attrib;    // file attribute structure
    stat(nativeString, &attrib);

    char buffer[80];
    timeinfo = gmtime(&(attrib.st_ctime));
    strftime(buffer, 256, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);

    // cleanup
    (*env)->ReleaseStringUTFChars(env, fileName, nativeString);

    return (*env)->NewStringUTF(env, buffer);
}
