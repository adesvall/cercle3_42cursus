segment .text
	global ft_strcmp

ft_strcmp:									; dst = rdi, src = rsi
			xor		rcx, rcx				; i = 0
			xor		rdx, rdx				; tmp = 0
			xor		rax, rax
			jmp		compare
compare:
			mov     dl, BYTE [rsi + rcx]
			cmp		dl, 0
			je		return
			cmp		dl, BYTE [rdi + rcx]
			jne		return
			inc		rcx
			jmp		compare
return:
			mov		al, BYTE [rdi + rcx]			; return dst
			sub		rax, rdx
			ret