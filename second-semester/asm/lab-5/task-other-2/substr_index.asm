.586
.model flat

public _FirstIn
.data
_STR dd 0
_SUBSTR dd 0
_STR_SIZE dd 0
_SUBSTR_SIZE dd 0
temp dd 1

.code 
_FirstIn proc
; XOR
xor eax,eax
xor ebx,ebx
xor esi,esi
xor edi,edi
xor ecx,ecx

; Setup data
mov eax, dword ptr[esp + 4] ; str
mov _STR, eax
mov eax, [esp + 8] ; str_size
mov _STR_SIZE, eax
mov eax, dword ptr[esp + 12] ; substr
mov _SUBSTR, eax
mov eax, [esp + 16] ; substr_size
mov _SUBSTR_SIZE, eax

mov eax, _STR
cmp eax, _SUBSTR ; equal address
jl _zero_index_ret

mov ebx, _STR
sub ebx, _SUBSTR
mov ecx, ebx
inc ecx


_zero_index_ret:
	mov eax,0
	jmp _ret
_endOne:
	mov eax,1
_ret:
	ret
_FirstIn endp

end