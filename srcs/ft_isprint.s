global _ft_isprint

section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 32
	jl no
	cmp rdi, 126
	jg no
	mov rax, 1
	ret

no:
	mov rax, 0
	ret