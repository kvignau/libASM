global _ft_bzero

section .text
	global _ft_bzero

_ft_bzero:
	mov rcx, rsi
	mov rax, 0x0
	rep stosb
	ret