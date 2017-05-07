#include"cn_com_reformer_license_util_SysInfo.h"
#include   <stdio.h> 
#include   <sys/ioctl.h> 
#include   <sys/socket.h> 
#include   <netinet/in.h> 
#include   <net/if.h> 
#include   <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <linux/hdreg.h>
#include <sys/fcntl.h>
unsigned int veax;
unsigned int vebx;
unsigned int vedx;
unsigned int vecx;

void cpuid(unsigned int veax1)
{
	//asm("cpuid"
	//    :"=a"(veax),
	//    "=b"(vebx),
	//    "=c"(vecx),
	//    "=d"(vedx)
	//    :"a"(veax));
	//x64  
	//"xchgq\t%%rbx, %q1\n\t"    
	//  "cpuid\n\t"                  
	//  "xchgq\t%%rbx, %q1\n\t"
	asm(
		"xchgl\t%%ebx, %k1\n\t"
		"cpuid\n\t"
		"xchgl\t%%ebx, %k1\n\t"

		: "=a"(veax), "=&r"(vebx), "=c"(vecx), "=d"(vedx)
		: "a"(veax));
}
void LM(int var, uint32_t *vx)
{
	int i;
	for (i = 0; i<3; i++)
	{
		var = (var >> i);
		vx[i] = var;
	}
}

static void getcpuid(char *id)
{
	uint32_t ax[3], cx[3], dx[3];
	cpuid(1);
	LM(veax, ax);
	cpuid(3);
	LM(vecx, cx);
	LM(vedx, dx);
	sprintf(id, "%u%u%u%u%u%u%u%u%u", ax[0], ax[1], ax[2], cx[0], cx[1], cx[2], dx[0], dx[1], dx[2]);
}

jstring   CharTojstring(JNIEnv*   env, char*   str)
{
	jsize   len = strlen(str);

	jclass   clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring   strencode = (*env)->NewStringUTF(env, "GB2312");

	jmethodID   mid = (*env)->GetMethodID(env, clsstring, "<init>", "([BLjava/lang/String;)V");
	jbyteArray   barr = (*env)->NewByteArray(env, len);

	(*env)->SetByteArrayRegion(env, barr, 0, len, (jbyte*)str);
	return (jstring)(*env)->NewObject(env, clsstring, mid, barr, strencode);
}
JNIEXPORT jstring JNICALL Java_cn_com_reformer_license_util_SysInfo_getmid
(JNIEnv *env, jobject o){
	struct   ifreq   ifreq;
	int   sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	strcpy(ifreq.ifr_name, "eth0");
	ioctl(sock, SIOCGIFHWADDR, &ifreq);
	char mac[6];
	sprintf(mac, "%02x%02x%02x%02x%02x%02x",
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[0],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[1],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[2],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[3],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[4],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[5]);
	return CharTojstring(env, mac);
}

JNIEXPORT jstring JNICALL Java_cn_com_reformer_license_util_SysInfo_getcid
(JNIEnv *env, jobject o){
	char cpuid[100];
	getcpuid(cpuid);
	return CharTojstring(env, cpuid);
}

JNIEXPORT jstring JNICALL Java_cn_com_reformer_license_util_SysInfo_getdid
(JNIEnv *env, jobject o){

	struct hd_driveid id;
	int fd = open("/dev/sda", O_RDONLY | O_NONBLOCK);
	ioctl(fd, HDIO_GET_IDENTITY, &id);
	return CharTojstring(env, id.serial_no);
}
