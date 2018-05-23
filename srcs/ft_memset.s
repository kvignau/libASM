section .text
	global _ft_memset

_ft_memset:
	push rdi
	cmp rdi, 0x0
	je exit
	cmp rdx, 0
	jle exit
	xor rcx, rcx
	xor rax, rax
	mov rax, rsi
	mov rcx, rdx
	cld
	rep stosb
	jmp exit

exit:
	pop rax
	ret