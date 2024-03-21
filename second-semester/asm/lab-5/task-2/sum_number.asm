.586
.model flat

public _SumNumber

.code

_SumNumber proc

mov eax, [esp+4]
mov ebx, 10
mov ecx, 0
_sum:
	cmp eax,0
	je _return
	cdq
	idiv ebx
	add ecx, edx
	jmp _sum
	_return:
		mov eax, ecx
		ret 
_SumNumber endp

end