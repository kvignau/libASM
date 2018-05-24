section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	enter 16, 0
	push rdi

	cmp rdi, 0x0
	je exit

	call _ft_strlen
	add rax, 1
	mov rdi, rax

	push rax

	call _malloc
	cmp rax, 0x0
	je exit
	mov rdi, rax

	pop rdx
	pop rsi

	call _ft_memcpy
	leave
	ret

exit:
	leave
	ret

; exit_failure:
; 	pop rax
; 	ret
