global _ft_isupper

section .text
	global _ft_isupper

_ft_isupper:
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jg no
	mov rax, 1
	ret

no:
	mov rax, 0
	ret