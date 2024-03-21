.586
.model flat

public _ChangeLastAndMax
.data
MAX dd 0
MAX_INDEX dd 0
LAST dd 0

.code
_ChangeLastAndMax proc
mov edi, [esp+4]
mov ecx, 15         ; Array length
mov edx, 0          ; Iteration index
mov eax, dword ptr[edi][14 * 4]
mov LAST, eax
iterate :
    mov eax, dword ptr[edi][edx * 4]
    cmp eax, MAX
    jl continue_
    mov MAX, eax
    mov MAX_INDEX, edx
continue_ :
    inc edx
    loop iterate
mov eax, MAX
mov [edi][14*4], eax
mov eax, LAST
mov edx, MAX_INDEX
mov [edi][edx*4], eax

ret
_ChangeLastAndMax endp

end