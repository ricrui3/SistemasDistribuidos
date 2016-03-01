#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char *argv[])
{
	char aux[3];
	char *cadenota=NULL;
	int j,i,l=0;
	char empatar[] = "IPN";
	for(i=0;i<17576;i++){
		for(j=0;j<3;j++){
			aux[j]=(rand()%25)+65;
		}
		cadenota=(char *)realloc(cadenota,4);
		memcpy(cadenota,aux,4);
		if(strstr(cadenota,empatar))	
			l++;
	}
	printf("%d veces\n",l);
	return 0;
}
