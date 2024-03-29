section .text
	global _ft_strtoupper
	extern _ft_toupper

_ft_strtoupper:
	xor rax, rax
	xor rbx, rbx
	mov rbx, rdi
	cmp rdi, 0x0
	je return

	xor rcx, rcx
	xor rdi, rdi
	jmp toupper

toupper:
	mov dil, byte [rbx + rcx]

	cmp dil, 0x0
	je return
	call _ft_toupper

	mov byte [rbx + rcx], al
	inc rcx

	jmp toupper
	

return:
	mov rax, rbx
	ret