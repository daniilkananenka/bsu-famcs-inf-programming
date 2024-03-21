.586
.model flat

public _IsSemit

.code

_IsSemit proc

mov eax, [esp+4]
mov ebx, 10
mov ecx, 0
_revert_number:
	cmp eax,0
	je _continue
	imul ecx, ebx
	cdq
	idiv ebx
	add ecx, edx
	jmp _revert_number
_continue:
	mov eax, ecx
	mov ecx, [esp+4]
	cmp eax, ecx
	je _equals
	jne _not_equals
	_equals:
		mov eax, 1
		jmp _return
	_not_equals:
		mov eax,0
	_return:
		ret 
_IsSemit endp

end