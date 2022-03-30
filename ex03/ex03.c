#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int foo(int count)
{
	  asm goto ("dec %0;"
		    "jb %l[stop]"
		     	:
		        : "r" (count)
		        : "memory"
		        : stop);
	  return count;
stop:
	  return 0;
}


bool par(int a){
// Para referenciar a label em que sera realizado o salto, usa-se %ln, onde n é a posicao em que foi colocada 
// nos parametros do assembly estendido, levando em conta os operadores de entrada e saida


	asm goto ("mov eax, %[a];"
		  "and eax, 0x1;"
		  "jz %[par];"
		  "jmp %[impar];"
		  :
		  : [a] "rm" (a)
		  : "cc", "memory"
		  : par, impar
			);

par:
	return 1;
impar:
	return 0;

}


int main(){
	int num = 4;
	printf("%d é par? ", num);
	printf(par(num) ? "true\n": "false\n");
	return 0;
}
