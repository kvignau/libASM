section .text
	global _ft_strcat
	extern _ft_strlen
	extern _ft_memcpy

_ft_strcat:
	xor rax, rax
	cmp rdi, 0x0
	je return_str2
	cmp rsi, 0x0
	je return_str1

	xor rdx, rdx
	
	mov rbx, rdi

	call _ft_strlen
	
	push rax
	mov rdi, rsi

	call _ft_strlen
	mov rdx, rax
	add rdx, 1

	mov rdi, rbx
	pop rax

	add rdi, rax

	call _ft_memcpy

	mov rax, rbx
	ret

return_str2:
	cmp rsi, 0x0
	je return_null
	lea rax, [rsi]
	ret

return_str1:
	mov rax, rdi
	ret

return_null:
	mov rax, 0x0
	ret