#include"cn_com_reformer_communication_security_SecretKeyKeeper.h"
#include <string.h>
#include<stdlib.h>
/*
* Class:     cn_com_reformer_communication_security_SecretKeyKeeper
* Method:    getSECRETKEYC
* Signature: ([B)[B
*/
typedef unsigned   char u8;
static const int ROLLDATAS[] = { 3, 7, 5, 1 };
//设备主动请求时使用的原始密钥
 jbyte  jbDevice[16] = { (jbyte)0x98, 0x39, 0x05, 0x75, 0x7D, 0x67, (jbyte)0x9D, 0x48, (jbyte)0x90, 0x6A, (jbyte)0x93, 0x52, 0x6C, (jbyte)0xA8, (jbyte)0xCA, (jbyte)0xAD };
//服务器主动请求时使用的原始密钥
 jbyte  jbServer[16] = { 0x12, 0x34, 0x56, 0x78, (jbyte)0x9A, (jbyte)0xBC, (jbyte)0xDE, (jbyte)0xF0, 0x21, 0x43, 0x65, (jbyte)0x87, (jbyte)0xA9, (jbyte)0xCB, (jbyte)0xED, 0x0F };
//查找配置设备使用的密钥
 jbyte  jbFindDevice[16] = { 0x1D, 0x3A, 0x4B, (jbyte)0xA6, 0x20, (jbyte)0xA9, (jbyte)0xCC, (jbyte)0xD2, 0x4D, (jbyte)0x94, 0x46, 0x4E, 0x7C, (jbyte)0x9A, (jbyte)0xF3, (jbyte)0xF4 };


JNIEXPORT jbyteArray JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_getSECRETKEYC
(JNIEnv *env, jobject, jbyteArray bytes){
	//取得jbyteArray长度
	int len = env->GetArrayLength(bytes);
	//声明jbyteArray
	jbyteArray b = env->NewByteArray(len);
	jbyte*   ba = env->GetByteArrayElements(bytes, JNI_FALSE);
	env->SetByteArrayRegion(b, 0, len, ba);
	env->ReleaseByteArrayElements(bytes, ba, JNI_FALSE);
	return b;
}

/*
* Class:     cn_com_reformer_communication_security_SecretKeyKeeper
* Method:    rollSecretKeyC
* Signature: ([B)[B
*/
JNIEXPORT void JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_rollSecretKeyC
(JNIEnv *env, jobject, jbyteArray bytes){
	int temp;
	//jbyteArray 转jbyte数组
	jbyte*   ba = env->GetByteArrayElements(bytes, JNI_FALSE);
	for (int i = 0; i < 4; i++)
	{
		temp = ((ba[i * 4] & 0xFF) << 24) + ((ba[i * 4 + 1] & 0xFF) << 16) + ((ba[i * 4 + 2] & 0xFF) << 8) + (ba[i * 4 + 3] & 0xFF);
		temp += ROLLDATAS[i];
		ba[i * 4] = (jbyte)((temp >> 24) & 0xFF);
		ba[i * 4 + 1] = (jbyte)((temp >> 16) & 0xFF);
		ba[i * 4 + 2] = (jbyte)((temp >> 8) & 0xFF);
		ba[i * 4 + 3] = (jbyte)(temp & 0xFF);
	}
	env->ReleaseByteArrayElements(bytes, ba, JNI_FALSE);
}

/*
* Class:     cn_com_reformer_communication_security_SecretKeyKeeper
* Method:    syncSecretKey
* Signature: ([B[B[B)[B
*/
JNIEXPORT void JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_syncSecretKeyC
(JNIEnv *env, jobject, jbyteArray jbyte1, jbyteArray jbyte2, jbyteArray jbyte3){

	int len = env->GetArrayLength(jbyte3);
	jbyte*   ba3 = env->GetByteArrayElements(jbyte3, JNI_FALSE);//ORIGINALSECRETKEY
	env->SetByteArrayRegion(jbyte2, 0, len, ba3);
	jbyte*   ba1 = env->GetByteArrayElements(jbyte1, JNI_FALSE);//randDatas
	jbyte*   ba2 = env->GetByteArrayElements(jbyte2, JNI_FALSE);//SECRETKEY
	int i, loc;
	for (i = 0; i < 4; i++)
	{
		loc = i * 4 + (ba1[i] & 0XFF) % 4;
		ba2[loc] = (u8)((ba3[loc] ^ ba1[i]) & 0xFF);
	}
	//释放指针
	env->ReleaseByteArrayElements(jbyte1, ba1, JNI_FALSE);
	env->ReleaseByteArrayElements(jbyte2, ba2, JNI_FALSE);
	env->ReleaseByteArrayElements(jbyte3, ba3, JNI_FALSE);
}

JNIEXPORT jbyteArray JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_getDEVICE_1ORIGINAL_1SECRETKEYSC
(JNIEnv *env, jclass){
	jbyteArray jbarray = env->NewByteArray(16);
	//jbDevice 复制到 jbarray，从0开始，长度16
	env->SetByteArrayRegion(jbarray, 0, 16, jbDevice);
	return jbarray;
}

/*
* Class:     cn_com_reformer_communication_security_SecretKeyKeeper
* Method:    getSERVER_ORIGINAL_SECRETKEYS
* Signature: ()[B
*/
JNIEXPORT jbyteArray JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_getSERVER_1ORIGINAL_1SECRETKEYSC
(JNIEnv *env, jclass){
	jbyteArray jbarray = env->NewByteArray(16);
	env->SetByteArrayRegion(jbarray, 0, 16, jbServer);
	return jbarray;
}

/*
* Class:     cn_com_reformer_communication_security_SecretKeyKeeper
* Method:    getCONFIG_ORIGINAL_SECRETKEYS
* Signature: ()[B
*/
JNIEXPORT jbyteArray JNICALL Java_cn_com_reformer_communication_security_SecretKeyKeeper_getCONFIG_1ORIGINAL_1SECRETKEYSC
(JNIEnv *env, jclass){
	jbyteArray jbarray = env->NewByteArray(16);
	env->SetByteArrayRegion(jbarray, 0, 16, jbFindDevice);
	return jbarray;
}