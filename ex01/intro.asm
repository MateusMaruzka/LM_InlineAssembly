	.file	"intro.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
	endbr64
	push	rbp
	mov	rbp, rsp
#APP
# 8 "intro.c" 1
	MEU_ASSEMBLY:
	mov rax, 0x5
	inc rax
	
# 0 "" 2
# 13 "intro.c" 1
	mov rax, 0x0; inc rax;
# 0 "" 2
#NO_APP
	mov	eax, 0
	pop	rbp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
