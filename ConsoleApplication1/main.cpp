#include <sys/utsname.h>
#include <iostream>
#include <cstdio>
#include "sys/socket.h"
int main()
{
	//auto start = chrono::high_resolution_clock::now();
	utsname names;
	if (uname(&names) != 0) {
		std::perror("cannot get unames");
	}
	printf("数入");
	std::cout << "Linux kernel version: " << names.release << std::endl;
	printf("9999\n");
	return 0;
}