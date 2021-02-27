	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"%5d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -144(%rbp)
	movl	$2, -140(%rbp)
	movl	$3, -136(%rbp)
	movl	$4, -132(%rbp)
	movl	$5, -128(%rbp)
	movl	$6, -124(%rbp)
	movl	$7, -120(%rbp)
	movl	$8, -116(%rbp)
	movl	$9, -112(%rbp)
	movl	$1, -96(%rbp)
	movl	$2, -92(%rbp)
	movl	$3, -88(%rbp)
	movl	$4, -84(%rbp)
	movl	$5, -80(%rbp)
	movl	$6, -76(%rbp)
	movl	$7, -72(%rbp)
	movl	$8, -68(%rbp)
	movl	$9, -64(%rbp)
	movl	$0, -156(%rbp)
	jmp	.L2
.L7:
	movl	$0, -152(%rbp)
	jmp	.L3
.L6:
	movl	-152(%rbp), %eax
	movslq	%eax, %rcx
	movl	-156(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	$0, -48(%rbp,%rax,4)
	movl	$0, -148(%rbp)
	jmp	.L4
.L5:
	movl	-152(%rbp), %eax
	movslq	%eax, %rcx
	movl	-156(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-48(%rbp,%rax,4), %ecx
	movl	-148(%rbp), %eax
	movslq	%eax, %rsi
	movl	-156(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	movl	-144(%rbp,%rax,4), %esi
	movl	-152(%rbp), %eax
	movslq	%eax, %rdi
	movl	-148(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rdi, %rax
	movl	-96(%rbp,%rax,4), %eax
	imull	%esi, %eax
	addl	%eax, %ecx
	movl	-152(%rbp), %eax
	movslq	%eax, %rsi
	movl	-156(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	movl	%ecx, -48(%rbp,%rax,4)
	addl	$1, -148(%rbp)
.L4:
	cmpl	$2, -148(%rbp)
	jle	.L5
	movl	-152(%rbp), %eax
	movslq	%eax, %rcx
	movl	-156(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-48(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -152(%rbp)
.L3:
	cmpl	$2, -152(%rbp)
	jle	.L6
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -156(%rbp)
.L2:
	cmpl	$2, -156(%rbp)
	jle	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
