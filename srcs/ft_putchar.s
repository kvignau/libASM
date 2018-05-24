%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .text
	global _ft_putchar

_ft_putchar:
	push rbp
	mov rbp, rsp	
	add rsp, 16
	mov [rsp], rdi
	mov rsi, rsp
	mov rdi, 1
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	leave
	ret
