section .text
	global _ft_strtolower
	extern _ft_tolower

_ft_strtolower:
	xor rax, rax
	xor rbx, rbx
	mov rbx, rdi
	cmp rdi, 0x0
	je return

	xor rcx, rcx
	xor rdi, rdi
	jmp tolower

tolower:
	mov dil, byte [rbx + rcx]

	cmp dil, 0x0
	je return
	call _ft_tolower

	mov byte [rbx + rcx], al
	inc rcx

	jmp tolower
	

return:
	mov rax, rbx
	ret