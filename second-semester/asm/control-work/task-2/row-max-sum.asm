.586
.model flat

public _RowMaxSum
.data ; Data
MAX_SUM dd 0
MAX_SUM_ROW dd 0
CUR_ROW dd 0

; DIMENSIONS
ROWS dd 0
COLS dd 0

.code ; Code
_RowMaxSum proc ; BEGIN - extern "C" int _cdecl RowMaxSum(int nums[ROWS][COLS], int rows, int cols);
	mov eax, [esp + 8] ; rows 
	mov ROWS, eax 
	mov eax, [esp + 12] ; cols 
	mov COLS, eax 
	mov ebx, [esp + 4] ; MATRIX - EBX
	; XOR
	xor edx, edx 
	xor ecx, ecx 
	xor edi, edi 
	mov edx, 0 ; EDX - ROW COUNTER

	rows_cycle: ; CYCLE FOR ITERATING THROUGH ROWS
		mov ecx, 0 ; CUR_COLUMN INDEX
		; COUNT FIRST INDEX OF ROW
		mov CUR_ROW, edx ; buffer
		mov eax, edx
		mul COLS
		mov edi, eax ; EDI - FIRST INDEX OF ROW 
		mov eax, 0 ; EAX - CURRENT ROW SUM
		mov edx, CUR_ROW
		cols_cycle: ; CYCLE FOR ITERATING THROUGH COLS
			; COUNT CURRENT ELEMENT INDEX
			mov esi, edi
			add esi, ecx
			;
			add eax, [ebx][esi*4] ; ADD CUR ELEMENT IN ROW TO EAX
			inc ecx
			cmp ecx, COLS
			jl cols_cycle
		cmp MAX_SUM, eax ; IF CURRENT ROW SUM > MAX_SUM
		jl _cur_bigger
		inc edx
		cmp edx, ROWS 
		jl rows_cycle
		jmp _end
		_cur_bigger:
			mov MAX_SUM, eax
			mov MAX_SUM_ROW, edx
			inc edx
			jmp rows_cycle
	_end:
		mov edx, MAX_SUM_ROW
		mov eax, MAX_SUM
		ret

_RowMaxSum endp ; END _RowMaxSum
end ; END MODULE
