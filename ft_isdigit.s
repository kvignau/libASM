global _ft_isdigit

section .text
	global _ft_isdigit

_ft_isdigit:
	cmp rdi, 48
	jl no
	cmp rdi, 58
	jl yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
