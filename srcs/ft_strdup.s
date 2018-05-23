section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	push rdi
	xor rdx, rdx
	xor rsi, rsi

	cmp rdi, 0x0
	je exit_failure

	call _ft_strlen
	xor rdi, rdi	; useless or not?
	mov rdi, rax

	push rdi

	call _malloc
	xor rdi, rdi	; useless or not?
	mov rdi, rax

	pop rdx
	pop rsi

	call _ft_memcpy
	ret

exit_failure:
	pop rax
	ret
