section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax
	cmp rdi, 0x0
	je return
	xor rcx, rcx
	not rcx				; START AT -1 SAME AS "mov rcx, -1"
	cld					; NOT MANDATORY BECAUSE IT'S THE DEFAULT VALUE
	repne scasb
	not rcx
	dec rcx
	mov rax, rcx
	ret

return:
	mov rax, rdi
	ret