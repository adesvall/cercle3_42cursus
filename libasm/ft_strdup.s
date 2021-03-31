segment .text
    global  ft_strdup
	extern  ft_strlen
	extern  ft_strcpy
    extern  malloc

ft_strdup:
			call	ft_strlen
			inc		rax
			push	rdi
			mov		rdi, rax
			call	malloc
			cmp		rax, 0      ;if malloc ret = 0: 
				je		malloc_fail
			mov		rdi, rax
			pop		rsi
			call	ft_strcpy
			ret

malloc_fail:
			ret