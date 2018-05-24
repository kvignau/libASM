section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	mov rbx, rdi
	xor rax, rax

	cmp rdi, 0x0
	je exit_failure

	call _ft_strlen
	add rax, 1
	mov rdi, rax
	push rax

	call _malloc
	cmp rax, 0x0
	je exit_failure

	mov rdi, rax
	pop rdx
	mov rsi, rbx

	call _ft_memcpy
	ret

exit_failure:
	ret
