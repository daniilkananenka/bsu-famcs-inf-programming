.586
.model flat

public _FindMaxLine
.data ; Data
MAX_LINE dd 0 ; MAX LINE LENGTH
MAX_LINE_ROW dd 0 ; INDEX OF ROW WITH MAX LINE
CUR_ROW dd 0 ; BUFFER FOR STORING CURRENT ROW INDEX
CUR_LINE dd 0 ; LENGTH OF CURRENT LINE

; DIMENSIONS
ROWS dd 0
COLS dd 0

.code ; Code
_FindMaxLine proc ; BEGIN - extern "C" int _cdecl FindMaxLine(int nums[ROWS][COLS], int rows, int cols);
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
		mov CUR_LINE, 0
		; -------INIT OF ROW------- ;
		mov ecx, 0 ; CUR_COLUMN INDEX
		; COUNT FIRST INDEX OF ROW
		mov CUR_ROW, edx ; buffer
		mov eax, edx
		mul COLS
		mov edi, eax ; EDI - FIRST INDEX OF ROW 
		mov eax, 0 ; EAX - CURRENT ROW SUM
		mov edx, CUR_ROW

		cols_cycle: ; CYCLE FOR ITERATING THROUGH COLS
			; -------COUNT CURRENT ELEMENT INDEX------- ;
			mov esi, edi
			add esi, ecx
			
			; -------PERFORMING ELEMENT------- ;
			mov eax, [ebx][esi*4] ; MOVE CURRENT ELEMENT TO EAX

			cmp eax, 0
			je _zero_element; if eax == 0
			; else
			inc CUR_LINE
			jmp _continue_cols_cycle

			_zero_element:
				mov eax, CUR_LINE
				cmp eax, MAX_LINE
				jle _reinit_line
				mov MAX_LINE, eax
				mov MAX_LINE_ROW, edx

			_reinit_line:
				mov CUR_LINE, 0

			_continue_cols_cycle:
				inc ecx
				cmp ecx, COLS
				jl cols_cycle

		mov eax, CUR_LINE
		cmp eax, MAX_LINE
		jle _continue_rows_cycle
		mov MAX_LINE, eax
		mov MAX_LINE_ROW, edx

		_continue_rows_cycle:
			inc edx
			cmp edx, ROWS 
			jl rows_cycle
			jmp _end
	_end:
		mov eax, MAX_LINE_ROW
		ret

_FindMaxLine endp ; END _FindMaxLine
end ; END MODULE