section .text
	extern ___error
	global _ft_read

; rdi - fd, rsi - buf, rdx - nbytes

_ft_read:
	mov rax, 0x2000003
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
