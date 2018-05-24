global _ft_islower

section .text
	global _ft_islower

_ft_islower:
	cmp rdi, 97
	jl no
	cmp rdi, 122
	jg no
	mov rax, 1
	ret

no:
	mov rax, 0
	ret