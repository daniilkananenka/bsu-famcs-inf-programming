.586
.model flat

public _NOD

.code

_NOD proc

mov eax, [esp+4]
mov ebx, [esp+8]
mov ecx, eax
loop_start :
    cmp eax, ebx
    je loop_end
    jg num_greater
    sub ebx, eax
    jmp loop_start
num_greater :
    sub eax, ebx
    jmp loop_start
loop_end :
    ret
    
_NOD endp

end