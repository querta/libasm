section .text
	global _ft_strlen

_ft_strlen: 
	mov rax, 0
	jmp loop

loop:
	cmp byte[rdi + rax], 0
	jz return
	inc rax
	jmp loop

return:
	ret