global _ft_toupper

section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 97
	jl no
	cmp rdi, 122
	jg no
	sub rdi, 32
	mov rax, rdi
	ret

no:
	mov rax, rdi
	ret