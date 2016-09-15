#include <stdio.h>
#include <ctype.h>

char reverse(char);

enum bases{
	DECIMAL = 10,		
	OCTAL = 8,			 
	HEXADECIMAL = 16,	
	MAX_OCTAL = 63		/* Máximo número octal de 2 cifras */
};

char reverse(char letter){

	return (islower(letter) ? toupper(letter) : tolower(letter));
}

int
main(){

	char a, b, ahexa, bhexa;
	int num, numOctal;

	a = getchar();
	b = getchar();

  	if(isdigit(a) && isdigit(b)){
  		
  		num = (a - '0') * DECIMAL + (b - '0');
  		
  		printf("Se convierte a num = %d\n", num);

  		if(num > MAX_OCTAL){
  		
  		numOctal = ((num / OCTAL) / OCTAL) * 100 + ((num / OCTAL) % OCTAL) * 10 + ((num % OCTAL)); /* Para números octales de 3 cifras */
  	    
  	    }
  	    else{
  		
  		numOctal = ((num / OCTAL) % OCTAL) * 10 + ((num % OCTAL)); /* Para números octales de 2 cifras */
  		
  		}
  		
  		printf("Se convierte a numOctal: %d\n", numOctal);
  		
  		ahexa = num / 16;
  		bhexa = num % 16;

  		if(ahexa >= DECIMAL){
  			
  			ahexa = ahexa - 10 + 'A';
  		}
  		else{
  			
  			ahexa = ahexa + '0';
  		}
  		if(bhexa >= DECIMAL){
  			
  			bhexa = bhexa - 10 + 'A';
  		}
  		else{
  			
  			bhexa = bhexa + '0';
  		}

		printf("Se convierte a ahexa = %c y bhexa = %c\n", ahexa, bhexa);
  	}
  	else if(isalpha(a) && isalpha(b)){

  		printf("Se convierte %c a %c y %c a %c\n", a, reverse(a), b, reverse(b));
  	}
  	else{
  		
  		printf("Error en los datos.\n");
  	}

  	return 0;
}