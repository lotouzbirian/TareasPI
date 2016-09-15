#include <stdio.h>
#include <ctype.h>
#define espacio(c) ((c) == '\t' || (c) == ' ' || (c) == '\n')

enum estados{
	INICIO,
	ESPACIO,
	PALABRA,
	NUMERO,
	PUNTO,
	ERROR
};

int main(){

	int c, estado = INICIO;
	int pal = 0, num = 0;

	while((c = getchar()) != EOF && estado != ERROR){

		switch(estado){

			case INICIO:
							if(espacio(c))
								estado = ESPACIO;
							else if(isalpha(c))
								estado = PALABRA;
							else if(isdigit(c))
								estado = NUMERO;
							else if(c == '.')
								estado = PUNTO;
							else
								estado = ERROR;

							break;

			case ESPACIO:
							if(espacio(c))
								estado = ESPACIO;
							else if(isalpha(c))
								estado = PALABRA;
							else if(isdigit(c))
								estado = NUMERO;
							else if(c == '.')
								estado = PUNTO;
							else
								estado = ERROR;

							break;

			case PALABRA:
							if(espacio(c)){
								estado = ESPACIO;
								pal++;
							}
							else if(!(isalpha(c))){
								estado = ERROR;
							}

							break;
		

			case NUMERO:
							if(espacio(c)){
								estado = ESPACIO;
								num++;
							}
							else if(!(isdigit(c))){
								estado = ERROR;
							}

							break;

			case PUNTO:	
							if(espacio(c)){
								estado = ERROR;
							}

							break;

		}

		}

		if(estado != ERROR){
			printf("Cantidad de palabras: %d.\n", pal);
			printf("Cantidad de números: %d.\n", num);
		}
		else{
			printf("Ocurrió un error.\n");
		}

		return 0;

}