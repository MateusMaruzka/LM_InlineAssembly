#include <stdio.h>

/*
 * Ex3: Implementar uma função que retorne 1 se o número for par e 0 caso o número seja impar, utilizando
 * a intrução IDIV
 *
 * Para compilar: gcc par_idiv.c -o par_idiv -masm=intel
 */
 int par(int a){

	asm goto ("mov edx, 0;"
	    "mov eax, %[a];" // nosso quociente
	    "mov ebx, 2;" // nosso divisor
	    "idiv ebx;"
	    "cmp dx, 0;"
	    "je %l[par];"
	    "jmp %l[impar]"
		:
	    	: [a] "m" (a)
		: "cc", "memory"
   		:par, impar);

par: return 1;
impar: return 0;

}

#define trueOrFalse(n) n ? "Verdadeiro" : "Falso"

int main(){

	int a = 8, b = 1, c = 2;

	printf("%d é par? %s\n", a, trueOrFalse(par(a)));
	printf("%d é par? %s\n", b, trueOrFalse(par(b)));
	printf("%d é par? %s\n", c, trueOrFalse(par(c)));


return 0;
}
