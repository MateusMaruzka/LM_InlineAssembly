#include <stdio.h>
#include <stdlib.h>

/* Introdução ao Assembly Inline
 * Compilar com gcc -g intro.c -o intro -masm=intel
 * Código apenas coloca um valor literal no registrador RAX e o incrementa
*/
int main(){

// 
	asm(
       	    "MEU_ASSEMBLY:\n\t"
	    "mov rax, 0x5\n\t"
	    "inc rax\n\t"
	);


	asm("label2:" 
	    "mov rax, 0x0; inc rax;");

	//__asm__("nop");
	//__asm__("nop");

	return 0;
}
