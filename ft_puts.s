%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .data
endl:
	.string db 10

section .text
	global _ft_puts

_ft_puts:
	mov rax, 0
	mov rsi, rdi
	mov rdi, STDOUT
	jmp choice

choice:
	mov al, [rsi + rdx] ; [rsi + rdx] == *(rsi + rdx)
	cmp al, 0x0
	jne plus
	lea rsi, [rel rsi]	; lea rsi, [rel rsi] == rsi = &rsi
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	mov rax, MACH_SYSCALL(WRITE)
	mov	rdi, 1
	lea rsi, [rel endl.string]
	mov rdx, 1
	syscall
	ret

plus:
	add rdx, 1
	jmp choice