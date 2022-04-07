#include <stdio.h>

/*
 * Ex1: Escrever uma função que calcule 2^N utilizando deslocamento binário
 *
 * Para compilar: gcc pot2.c -o pot2 -masm=intel
 * 
 * O parâmetro -masm=intel é utilizada para dizer ao compilador que 
 * estamos utilizando a sintaxe intel
 */

int pot2(int n){

	register int res asm("eax") =  1;
	
	asm(
		"mov ecx, %[n];"
		"shl eax, cl;"
		:
		: [n] "m" (n)
		: "cc" );
		
	return res;
	
}

int main(){

	int n = 10;
	
	register int res asm("eax") = 1;
	
	asm("mov ecx, %[n];"
		"shl eax, cl;"
		:
		: [n] "m" (n)
		: "cc" );
		
		
	printf("2^%d = %d\n", n, pot2(n));


	return 0;
}
