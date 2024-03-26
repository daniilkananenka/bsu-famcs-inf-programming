xor edx,edx
xor eax,eax



beginProbel:
	mov ah,[esi]
	mov al,' '
	cmp ah,al ; является ли элемент пробелом?
		je proverkaSlowa
	cmp temp,1
		je prygaem
	inc esi
	inc temp
	mov edx,_str
	cmp temp, edx
		jg _endZero
	jmp beginProbel

proverkaSlowa:
	inc esi
	inc temp
	
	prygaem:

	mov edx,_str
	cmp temp, edx
		jg _endZero

	mov ecx, temp
	mov ebx, _str
	sub ebx, ecx
	add ebx,1
	cmp ebx,_word
		jl _endZero
	xor ebx,ebx
	mov edx,0
	mov ecx, _word
	cykl:
		xor ebx,ebx
		mov ebx,[esi][edx*1]
		cmp bl,[edi][edx*1]
			jne konecCykl
		add edx,1
	loop cykl
	jmp _lastCheck
	konecCykl:
		inc esi
		inc temp
		jmp beginProbel

_lastCheck:
	add temp, edx
	dec temp
	mov eax,_str
	cmp temp, eax
		je _endOne
	xor eax,eax
	mov ah,[esi][edx*1]
	mov al,' '
	cmp ah,al 
		je _endOne