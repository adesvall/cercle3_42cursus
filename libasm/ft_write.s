segment .text
	global ft_write
	extern __errno_location

; ft_write (rdi, rsi, rdx)
ft_write:
	mov rax, 1		; set rax to write
    syscall					; call rax (write)
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
