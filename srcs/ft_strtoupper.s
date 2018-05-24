section .text
	global _ft_strtoupper
	extern _ft_toupper

_ft_strtoupper:
	xor rax, rax
	mov rbx, rdi				; char * str2
	cmp rdi, 0x0
	je return

	mov rcx, 0					; int i = 0
	jmp toupper

toupper:
	mov rdi, [rbx + rcx]		;  while (str2[i])
	mov rax, rdi
	ret
	; cmp byte [rbx + rcx], 0
	; je return
	call _ft_toupper
	ret

	mov [rbx + rcx], rax
	inc rcx						;  i++;
	; mov [rdi], rax
	; mov rax, rdi
	; pop rdi
	; ret
	jmp toupper
	

return:
	mov rax, rbx
	; mov rax, 0x0
	ret