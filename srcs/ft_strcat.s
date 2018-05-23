section .text
	global _ft_strcat

_ft_strcat:
	xor rax, rax
	cmp rdi, 0x0
	je return_str2
	cmp rsi, 0x0
	je return_str1

	xor rdx, rdx
	mov rdx, 0
	jmp continue
	
continue:
	mov al, [rdi + rdx]
	cmp al, 0x0
	jne plus

	xor rcx, rcx
	mov rcx, 0
	jmp s2

plus:
	add rdx, 1
	jmp continue

s2:
	mov si, [rsi + rcx]
	cmp si, 0x0
	jne inc_s2
	; ADD \0 AT THE END OF str
	; mov rax, rdi
	ret

inc_s2:
	add rdx, rcx
	mov al, [rdi + rdx]
	mov al, [rsi + rcx]
	add rcx, 1
	jmp s2

return_str2:
	cmp rsi, 0x0
	je return_null
	mov rax, rsi
	ret

return_str1:
	mov rax, rdi
	ret

return_null:
	mov rax, 0x0
	ret