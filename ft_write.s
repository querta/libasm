section .text
	extern ___error
	global _ft_write

; rdi - fd, rsi - text, rdx - nbytes

_ft_write:
	mov rax, 0x2000004
	syscall
	jc error
	ret

error:
	push r8
	mov r8, rax
	call ___error
	mov [rax], r8
	pop r8
	mov rax, -1
	ret
