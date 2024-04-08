.586
.model flat

public _FirstIn
.data
_STR dd 0
_SUBSTR dd 0
_STR_SIZE dd 0
_SUBSTR_SIZE dd 0
_START dd 0

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

; XOR
xor edx, edx
xor eax, eax
xor ebx, ebx
xor ecx, ecx
xor edi, edi
xor esi, esi
xor esp, esp
xor ebp, ebp

; Register init
mov ecx, _STR_SIZE ; ecx - counter for string
mov ebx, _SUBSTR_SIZE ; ebx - counter for substring
mov esi, _STR ; esi - str
mov edi, _SUBSTR ; edi - substr
mov esp, -1 ; esp - index of first in of substr
mov ebp, -1


str_iterate:
	mov al, [esi][ecx] ; al - current string char
	mov ah, [edi][ebx] ; ah - current substring char
	cmp al, ah
	jne _not_equal_char
	; str[i] == substr[j]
	inc ecx ; next char of string
	inc ebx ; next char of substring
	jmp _continue

	_not_equal_char: ; str[i] != substr[j]
		
		
	_continue:
		cmp ebx, _SUBSTR_SIZE ; if end of substring
		je _end
		cmp ecx, _STR_SIZE ; if end of string
		je _end
		jmp str_iterate
		
	

_zero_index_ret:
	mov eax,0
	jmp _ret
_end:
	mov eax, esp
_ret:
	ret
_FirstIn endp

end