segment .text
    global ft_strcpy

ft_strcpy:                                    ; dst = rdi, src = rsi
			xor			rcx, rcx                ; i = 0
			xor			rdx, rdx                ; tmp = 0
			cmp			rsi, 0                    ; if !rsi
				je		return
			jmp			copy
copy:
            mov         dl, BYTE [rsi + rcx]
            mov         BYTE [rdi + rcx], dl
            cmp         dl, 0
                je      return
            inc         rcx
            jmp         copy
return:
            mov         rax, rdi                ; return dst
            ret