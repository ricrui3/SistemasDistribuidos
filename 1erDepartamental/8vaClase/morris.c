#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, const char *argv[])
{
	char aux[4];
	char *cadenota=NULL;
	int j,i,l=0, pos=4, cont=0;
	char empatar[] = "IPN";
	for(i=0;i<17576;i++){
		for(j=0;j<3;j++){
			aux[j]=(rand()%25)+65;
		}
		aux[3]=' ';
		cadenota=(char *)realloc(cadenota,pos);
		memcpy(cadenota+pos-4,aux,4);
		pos+=4;
	}
	for (i = 0; cadenota[i+2]; i+=4)
	{
		
		if (cadenota[i]=='I' && cadenota[i+1]=='P' && cadenota[i+2]=='N')
		{
			cont++;
		}
	}
	printf("%d veces\n",cont);
	return 0;
}
