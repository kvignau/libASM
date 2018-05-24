%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4
%define READ				3
%define BUFF_SIZE			100

section .bss
	buffer resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rdi
	lea rsi, [rel buffer]
	mov rdx, BUFF_SIZE
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc exit

	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	cmp rax, 0x0
	jg _ft_cat
	ret

exit:
	pop rdi
	ret
