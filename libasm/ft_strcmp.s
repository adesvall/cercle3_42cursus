segment .text
	global _ft_strcmp
	extern _ft_strlen

_ft_strcmp:
	push	rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rcx, rax
	pop 	rdi
	cld
	rep		cmpsb
	mov		BYTE [rdi], 0
	jmp		exit

exit:
	ret
