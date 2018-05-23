global _ft_isalnum

section .text
	global _ft_isalnum
	extern _ft_isdigit
	extern _ft_isalpha

_ft_isalnum:
	call _ft_isalpha
	cmp rax, 1
	jge yes
	call _ft_isdigit
	cmp rax, 1
	jge yes
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret