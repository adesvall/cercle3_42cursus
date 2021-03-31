segment .text
	global ft_read
	extern __errno_location

; ft_read (rdi, rsi, rdx)
ft_read:
	mov rax, 0		; set rax to read
    syscall					; call rax (read)
	cmp rax, 0
		jl exit_error
	ret

exit_error:
	neg rax
	push rax
	call __errno_location
	pop qword[rax]
	mov rax, -1
	ret
