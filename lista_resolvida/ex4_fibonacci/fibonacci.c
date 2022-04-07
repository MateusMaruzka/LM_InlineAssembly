#include <stdlib.h>
#include <stdio.h>

int fibonacci(int n){
	
	register int fn1 asm("r8") = 1, fn2 asm ("r9") = 1;
	register int res asm("r10") = 0;

	asm goto("cmp %[n], 0;"
		 "je %l[f0];"
		 "cmp %[n], 2;"
		 "jle %l[f1];"
		
		 "initFor:"
		 "mov ecx, %[n];"
		 "dec ecx; dec ecx;" 
		 // f1 e f2 sao valores definidos entao nao é preciso que o laço percorra esses valores
		 "loopFor:" 
		 "cmp ecx, 0;"
		 "jle saidaFor;"
	
		 "add r8, r9;"
		 "mov r10, r8;"
		 "mov r8, r9;"
		 "mov r9, r10;"

		 "dec ecx;"
		 "jmp loopFor;"

		 "saidaFor:"
		 "jmp %l[fn];"
		: /* Com asm goto não podemos ter operandos de saída */
		: [n] "m" (n), "r" (fn1), "r" (fn2)
		: "cc", "memory"
		: f1, f0, fn);

f0: return 0;
f1: return 1;
fn: return res;
	
}


int main(){


	printf("N=%d\n", fibonacci(0));
	printf("N=%d\n", fibonacci(1));
	printf("N=%d\n", fibonacci(10));

	return 0;
}
