#include <stdio.h>
#include <string.h>

#define EXITO 1
#define ERROR -1

void insertaDesde(char *, char *, char);

void insertaDesde(char *s1, char *s2, char c){

	char *pos = strchr(s1, c);

	if(pos != NULL){
		strcpy(pos, s2);
	}
}

int main(){

	char c = 'j';

	char str1[20] = "manuel";
	char str2[] = "javi";

	insertaDesde(str1, str2, c);

	printf("%s\n", str1);

	return 0;
}