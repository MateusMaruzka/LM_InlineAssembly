#include <stdio.h>

int par(int n){
	
	asm goto
	      ( "and %[n], 1;"
	        "jz %l[par];"
		"jmp %l[impar];"	
	      :
	      : [n] "rm" (n)
	      :"cc", "memory"
	      :par, impar);

par:return 1;
impar: return 0;
}



int main(){
	int a = 5, b = 10;
	printf("%d par? %d\n", a, par(a));
	printf("%d par? %d\n", b, par(b));
	return 0;
}
