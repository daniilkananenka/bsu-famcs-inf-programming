.586
.model flat

public _SmallWordSize
.data
CUR_SIZE dd 0
STR_SIZE dd 0

.code

_SmallWordSize proc
mov esi, [esp + 8]
mov STR_SIZE, esi; size
mov ecx, dword ptr[esp+4]; string
mov ebx, [esp+8]; min size
mov al, ' '; space
mov esi, 0

; _cycle - begin
_cycle:
	cmp esi, STR_SIZE
	jge _end_cycle
	mov ah, [ecx][esi]
	cmp ah, al
	jne _not_space
	cmp ebx, CUR_SIZE
	jle _not_bigger_size
	mov ebx, CUR_SIZE
	
_not_bigger_size:
	mov CUR_SIZE, 0
	jmp _next_iteration

_not_space:
	inc CUR_SIZE

_next_iteration:
	inc esi
	jmp _cycle
_end_cycle:
; _cycle - end


cmp ebx, CUR_SIZE
jge _cur_greater
mov eax,ebx
jmp _end

_cur_greater:
	mov eax, CUR_SIZE
	jmp _end
	
_end:
	ret
    
_SmallWordSize endp

end