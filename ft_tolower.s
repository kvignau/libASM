global _ft_tolower

section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jg no
	add rdi, 32
	mov rax, rdi
	ret

no:
	mov rax, rdi
	ret