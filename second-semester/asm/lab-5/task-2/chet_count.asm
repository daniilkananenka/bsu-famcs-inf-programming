.586
.model flat

public _ChetCount

.data
RESULT dd 0
NUM dd 0
TWO dd 0

.code

_ChetCount proc

mov eax, [esp+4]
mov NUM, eax
mov ebx, 10
mov ecx, 0
mov TWO, 2

_count:
	cmp NUM, 0
	je _return
	mov eax, NUM
	cdq
	idiv ebx
	mov ecx, edx
	mov NUM, eax
	mov eax, ecx
	cdq
	idiv TWO
	cmp edx, 0
	jne _continue
	inc RESULT
	
	_continue:
	jmp _count
	_return:
		mov eax, RESULT
		ret 
_ChetCount endp

end