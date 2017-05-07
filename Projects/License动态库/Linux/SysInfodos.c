#include   <stdio.h> 
#include   <sys/ioctl.h> 
#include   <sys/socket.h> 
#include   <netinet/in.h> 
#include   <net/if.h> 
#include   <string.h> 
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include "stdbool.h"

unsigned int veax;
unsigned int vebx;
unsigned int vedx;
unsigned int vecx;
void cpuid(unsigned int veax1)
{
	asm("cpuid"
		:"=a"(veax),
		"=b"(vebx),
		"=c"(vecx),
		"=d"(vedx)
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

bool func(uint8_t *mac)
{
	struct   ifreq   ifreq;
	int   sock;
	int i;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
		perror("socket ");
		return   2;
	}
	strcpy(ifreq.ifr_name, "eth0");
	if (ioctl(sock, SIOCGIFHWADDR, &ifreq) <0)
	{
		perror("ioctl ");
		return   3;
	}

	mac[0] = ifreq.ifr_hwaddr.sa_data[0];
	mac[1] = ifreq.ifr_hwaddr.sa_data[1];
	mac[2] = ifreq.ifr_hwaddr.sa_data[2];
	mac[3] = ifreq.ifr_hwaddr.sa_data[3];
	mac[4] = ifreq.ifr_hwaddr.sa_data[4];
	mac[5] = ifreq.ifr_hwaddr.sa_data[5];

	return true;
}




int   main(int   argc, char   *argv[])
{

	struct   ifreq   ifreq;
	int   sock;
	int i;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) <0)
	{
		perror("socket ");
		return   2;
	}
	strcpy(ifreq.ifr_name, "eth0");
	if (ioctl(sock, SIOCGIFHWADDR, &ifreq) <0)
	{
		perror("ioctl ");
		return   3;
	}
	char mac[6];

	//	sprintf(mac, "%02x%02x%02x%02x%02x%02x",
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[0],
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[1],
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[2],
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[3],
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[4],
	//		(unsigned   char)ifreq.ifr_hwaddr.sa_data[5]);

	printf("MAC = ");
	printf("%02x:%02x:%02x:%02x:%02x:%02x",
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[0],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[1],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[2],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[3],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[4],
		(unsigned   char)ifreq.ifr_hwaddr.sa_data[5]);

	printf("\n\r");
	//mac[0] = ifreq.ifr_hwaddr.sa_data[0];
	//mac[1] = ifreq.ifr_hwaddr.sa_data[1];
	//mac[2] = ifreq.ifr_hwaddr.sa_data[2];
	//mac[3] = ifreq.ifr_hwaddr.sa_data[3];
	//mac[4] = ifreq.ifr_hwaddr.sa_data[4];
	//mac[5] = ifreq.ifr_hwaddr.sa_data[5];

	//printf("%02x:%02x:%02x:%02x:%02x:%02x\n ",
	//	(unsigned   char)mac[0],
	//	(unsigned   char)mac[1],
	//	(unsigned   char)mac[2],
	//	(unsigned   char)mac[3],
	//	(unsigned   char)mac[4],
	//	(unsigned   char)mac[5]);

	//printf("mem:");
	//for (i = 0; i < 6; i++){
	//	printf("%02x-", ifreq.ifr_hwaddr.sa_data[i]);
	//}
	//printf("\n\r");

	//printf("mac:");
	//for (i = 0; i < 6; i++){
	//	printf("%02x-",mac[i]);
	//}
	//printf("\n\r");printf("\n\r");

	struct hd_driveid id;
	int fd = open("/dev/sda", O_RDONLY | O_NONBLOCK);
	if (fd < 0) {
		perror("/dev/sda");
		return 1;
	}
	if (!ioctl(fd, HDIO_GET_IDENTITY, &id))
	{
		printf("HDD Serial Number=%s", id.serial_no);
	}
	printf("\n\r");
	char cpuid[100];
	getcpuid(cpuid);
	printf("CPU SN = %s", cpuid);
	printf("\n\r");
	return 0;
}
