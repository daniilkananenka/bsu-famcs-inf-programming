.586
.model flat

; INIT FUNCTIONS
public @IntegralCount@4

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
	N dd 0.0
	X dd 0.0
	DIAMETR dd 0.0
	RESULT dd 0.0

; CODE
.code
@IntegralCount@4 proc; X^2 + sin(x) [0, 2pi]
	xor eax, eax
	mov N, ecx

	finit
	fld ZERO
	fstp RESULT

	fldpi
	fld TWO
	fmul
	fild N
	fdiv
	fstp DIAMETR

	fld ZERO
	fstp X

	; COUNTER LOOP
	counter:
		fld X
		fld X
		fmul
		fld X
		fsin
		fadd
		fld DIAMETR
		fmul
		fld RESULT
		fadd
		fstp RESULT

		fld X
		fld DIAMETR
		fadd
		fstp X
		loop counter

	; RETURN RESULT
	lea eax, RESULT
	ret
@IntegralCount@4 endp
end