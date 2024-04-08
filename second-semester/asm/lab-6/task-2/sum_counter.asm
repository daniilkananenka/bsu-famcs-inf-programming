.586
.model flat

; INIT FUNCTIONS
public @FindLn@8

; INIT DATA
.data
	; NUMBERS AND CONSTANTS
	ZERO dd 0.0
	ONE dd 1.0
	TWO dd 2.0
	THREE dd 3.0
	FOUR dd 4.0
	FIVE dd 5.0

	; VARS
	K dd 0.0
	RESULT dd 0.0

.code
@FindLn@8 proc; 1 / (K * (4 * K^2 - 1))
	finit
	fld ONE
	fstp K
	fld ZERO
	fstp RESULT

	; LOOP - COUNTING SUM
	counter:
		fld ONE
		fld K
		fld FOUR
		fld K
		fld K
		fmul
		fmul
		fld ONE
		fsub
		fmul
		fdiv

		fld RESULT
		fadd
		fstp RESULT

		fld K
		fld ONE
		fadd
		fstp K
		loop counter

	fld RESULT
	fld ONE
	fadd
	fld TWO
	fdiv
	fstp RESULT

	xor eax, eax
	lea eax, RESULT

	fldln2
	fld RESULT
	fsub
	fabs

	; RETURN RESULT
	fstp dword ptr[edx]
	ret
@FindLn@8 endp
end