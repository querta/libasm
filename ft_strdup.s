section .text
	extern ___error
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	global _ft_strdup

_ft_strdup:
		push	rdi			; Сохраняю 0аргумент в стек
		call	_ft_strlen	; принимает в rdi строку, возвращает в rax размер
		inc	rax				; для \0
		mov	rdi, rax		; Записываем размер строки в rdi
		call	_malloc		; Возвращает в rax указательно на новую строку
		jz	error			; или 0
		pop	rdi				
		mov	rsi, rdi		; Строку из стека во 2 аргумент
		mov	rdi, rax		; указатель от маллока в 1
		call	_ft_strcpy
		ret

error:
	call ___error
	mov rdi, 12
	mov [rax], rdi
	pop rdi
	mov rax, 0
	ret