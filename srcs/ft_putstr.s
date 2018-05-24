%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .data
string:
	.null db "(null)"
	.len equ $ - string.null

section .text
	global _ft_putstr

_ft_putstr:
	mov rax, 0
	xor rsi, rsi
	xor rdx, rdx
	mov rsi, rdi
	mov rdi, STDOUT
	cmp rsi, 0x0
	je exit
	jmp choice

choice:
	mov al, [rsi + rdx]
	cmp al, 0x0
	jne plus
	cmp rdx, 0
	je return
	lea rsi, [rel rsi]
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp return

plus:
	add rdx, 1
	jmp choice

return:
	mov rax, 10
	ret

exit:
	xor rsi, rsi
	mov rax, MACH_SYSCALL(WRITE)
	lea rsi, [rel string.null]
	mov rdx, string.len
	syscall
	xor rax, rax
	ret