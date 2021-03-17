section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, 0
	jmp loop

loop:
	cmp byte[rsi + rax], 0
	jz return
	mov dl, byte[rsi + rax]
	mov byte[rdi + rax], dl
	inc rax
	jmp loop

return:
	mov byte[rdi + rax], 0
	mov rax, rdi
	ret