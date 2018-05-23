global _ft_isalpha

section .text
	global _ft_isalpha

_ft_isalpha:
	cmp rdi, 65
	jl no
	cmp rdi, 91
	jl yes
	cmp rdi, 97
	jl no
	cmp rdi, 123
	jl yes
	jmp no

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
