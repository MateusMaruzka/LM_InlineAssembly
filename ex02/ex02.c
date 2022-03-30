#include <stdio.h>
#include <stdlib.h>



int main() {
	
	int resultado = 5;
	asm("add %0, 0x5;"
			: [result] "+m" (resultado) );
	
	int resultado2 = 1;
	asm("add %[r2], 0xFF;"
			: [r2] "+m" (resultado2) );
	
	int a = 1, b = 3;
	
	asm(	"mov eax, %[b];"
		"add %[a], eax;"
			: [a] "+m" (a), [b] "+m" (b));


	int c = 7;
	int d = 5;
	asm (
	     "mov eax, 0x0;"
	     "mov eax, %[d];"
	     "sub %[c], eax"
     		: [c] "+m" (c)
   		: [d] "m" (d)
		: "cc");

	printf("Resultado: %d\n", resultado);
	printf("Resultado2: %d\n", resultado2);
	printf("a=%d b=%d\n", a,b);
	printf("c=%d d=%d\n", c,d);
	return 0;
}

