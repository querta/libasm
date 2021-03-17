section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0
	mov rax, 0
	mov rbx, 0
	jmp compare

compare:
	mov al, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]

	cmp al, 0
	jz return
	cmp bl, 0
	jz return

	inc rcx
	cmp al, bl
	je compare
	jmp return

return:
	sub rax, rbx
	ret
