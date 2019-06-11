/*
 * file main.c
 * 
 
* 
* Author: Aleksandr Barunin
* email: aabzel@yandex.ru
* 
* Data: 2019
*/

#include "fifo_node.h"
#include "unit_test.h"
#include <stdio.h>
#include <string.h>	
#include <stdlib.h>	
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>	 
#include <unistd.h>	 
#include <pthread.h>  

 
int main (int argc , char *argv[])
{	
    uint32_t ret;
    printf("\n start");
	ret = run_unit_test ();
    printf("\n run_unit_test %d", ret);
	if(ret){
		printf("\n Error %d", ret);
		printf("\n ");
		return 1;
	}
	
	printf("\n finish");
	printf("\n Done!");
	
	return 0;
}

 

 
 

 
