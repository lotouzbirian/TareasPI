#include <stdio.h>

enum estados {
	INICIO,
	ESPACIO,
	DOSPUNTOS,     // :
	DOSPUNTOS_A,   // :)
	DOSPUNTOS_B,   // :(
	DOSPUNTOS_C,   // :D
	DOSPUNTOS_D,   // :P
	DOSPUNTOS_AP_A, // :’
	DOSPUNTOS_AP_B, // :’(
	ASOMBRO_A,		// o
	ASOMBRO_B,      // o.
	ASOMBRO_C,		// o.O
	TRISTE_A,		// u
	TRISTE_B,		// u.
	TRISTE_C,		// u.U
	GUINO_A,		// ;
	GUINO_B,		// ;)
};

int
main(void){

	int c, estado = INICIO;
	int p = 0, n = 0, d = 0;

	while((c = getchar()) != '\n' && c != EOF){
		switch(estado){

			case INICIO:	
							if(c == ' ')
								estado = ESPACIO;
							putchar(c);

							break;

			case ESPACIO: 
							if(c == ':'){
								estado = DOSPUNTOS;
							}
							else if(c == 'o'){
								estado = ASOMBRO_A;
							}
							else if(c == 'u'){
								estado = TRISTE_A;
							}
							else if(c == ';'){
								estado = GUINO_A;
							}
							else if(!(c == ' ')){
								estado = INICIO;
								putchar(c);
							}
							break;

			case DOSPUNTOS:
							if(c == ')')
								estado = DOSPUNTOS_A;
							else if(c == '(')
								estado = DOSPUNTOS_B;
							else if(c == 'D')
								estado = DOSPUNTOS_C;
							else if(c == 'P')
								estado = DOSPUNTOS_D;
							else if(c == '’')
								estado = DOSPUNTOS_AP_A;
							else{
								estado = INICIO;
								putchar(c);
								}
							break;

		    case DOSPUNTOS_A: 
		    				if(c == ' '){
		    					printf("(SONRISA)");
		    					p++;
		    				}
		    				else{
		    					printf(":)");
		    					putchar(c);
		    				}
		    				estado = ESPACIO;
	

		    				break;

		   	case DOSPUNTOS_B: 
		    				if(c == ' '){
		    					printf("(TRISTEZA)");
		    					n++;
		    				}else{
		    					printf(":(");
		    					putchar(c);
		    				}
		    				
		    				
		    				estado = ESPACIO;
		    				

		    				break;

		    case DOSPUNTOS_C: 
		    				if(c == ' '){
		    					printf("(RISA)");
		    					p++;
		    				}
		    				else{
		    					printf(":D");
		    					putchar(c);
		    				}
		    				
		    				estado = ESPACIO;
		    				

		    				break;

		    case DOSPUNTOS_D: 
		    				if(c == ' '){
		    					printf("(BROMA)");
		    					d++;
		    				}
		    				else{
		    					printf(":P\n");
		    					putchar(c);
		    				}
		    				
		    				estado = ESPACIO;
		    				

		    				break;

		    case DOSPUNTOS_AP_A:
		    				if(c == '('){
		    					estado = DOSPUNTOS_AP_B;
		    				}
		    				else{
		    					printf(":’");
		    					putchar(c);
		    					estado = INICIO;
		    				}
		    				break;

		    case DOSPUNTOS_AP_B: 
		    				if(c == ' '){
		    					printf("(LLANTO)");
		    					n++;
		    				}else{
		    					printf(":’(");
		    					putchar(c);
		    				}
		    				
		    				estado = ESPACIO;
		    				

		    				break;
		    case ASOMBRO_A:
		    				if(c == '.'){
		    					estado = ASOMBRO_B;
		    				}
		    				else{
		    					printf("o\n");
		    					putchar(c);
		    					estado = INICIO;
		    					}
		    				break;

		    case ASOMBRO_B:
		    				if(c == 'O'){
		    					estado = ASOMBRO_C;
		    				}
		    				else{
		    					printf("o.\n");
		    					putchar(c);
		    					estado = INICIO;
		    					}
		    				break;

		    case ASOMBRO_C:
		    				if(c == ' '){
		    					printf("(ASOMBRO)");
		    				 	d++;
		    				}else{
		    					printf("o.O\n");
		    					putchar(c);
		    				}
		    				
		    				estado = ESPACIO;
		    				
							
							break;
			case TRISTE_A:
		    				if(c == '.'){
		    					estado = TRISTE_B;
		    				}
		    				else{
		    					printf("u\n");
		    					putchar(c);
		    					estado = INICIO;
		    					}
		    				break;

		    case TRISTE_B:
		    				if(c == 'u'){
		    					estado = TRISTE_C;
		    				}
		    				else{
		    					printf("u.\n");
		    					putchar(c);
		    					estado = INICIO;
		    					}
		    				break;

		    case TRISTE_C:
		    				if(c == ' '){
		    					printf("(TRISTE)");
		    					n++;
		    				}
		    				else{
		    					printf("u.U\n");
		    					putchar(c);
		    				}
		    				
		    				estado = ESPACIO;
		    		

		    				break;
		   	case GUINO_A:
		    				if(c == ')'){
		    					estado = GUINO_B;
		    				}
		    				else{
		    					printf(";");
		    					putchar(c);
		    					estado = INICIO;
		    					}
		    				break;

		    case GUINO_B:
		    				if(c == ' '){
		    					printf("(GUIÑO)");
		    					p++;
		    				}
		    				else{
		    					printf(";)");
		    					putchar(c);
		    				}
		    				estado = ESPACIO;
		    				
		
							break;

		}
	}

printf("\nHubo %d mensajes positivos, %d negativo y %d neutro\n", p, n, d);

}