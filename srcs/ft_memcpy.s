section .text
	global _ft_memcpy

_ft_memcpy:
	push rdi

	cmp rdi, 0x0
	je exit
	cmp rsi, 0x0
	je exit
	cmp rdx, 0
	jle exit

	xor rcx, rcx
	mov rcx, rdx
	cld
	rep movsb
	jmp exit

exit:
	pop rax
	ret