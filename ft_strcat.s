section .text
	global _ft_strcat

_ft_strcat:
	mov rdx, 0
	mov al, [rdi + rdx]
	cmp al, 0x0
	jne plus
	mov rcx, 0
	jmp s2

plus:
	add rdx, 1
	jmp choice

s2:
	mov si, [rsi + rcx]
	cmp si, 0x0
	jne inc_s2
	ret

inc_s2:
	mov [rdi + rdx + rcx], [rsi + rcx]
	add rcx, 1
	jmp s2