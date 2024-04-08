.586
.model flat

; INIT FUNCTIONS
public @FirstCount@8 ; X * X * tan(X / Y) + Y * Y * (1 / tan(X / Y))
public @SecondCount@8 ; (X * Y + Y * log2(X)) / (atan(X / Y))
public @ThirdCount@8 ; abs(X - Y) * cos(X / Y + Y / X)

; INIT DATA 
.data
	result dd 0.0 ; RESULT
	one dd 1.0 ; 1

; CODE
.code
	@FirstCount@8 proc ; extern "C" float* _fastcall FirstCount(float*, float*);
		finit ; INIT FPU
		fld dword ptr[ecx]; X
		fld dword ptr[ecx]; X X
		fmul; XX
		fld dword ptr[ecx]; XX X
		fld dword ptr[edx]; XX X Y
		fdiv; XX (X / Y)
		fptan; XX tan(X / Y) 1
		fstp result; XX tan(X / Y)
		fmul; (XX * tan(X / Y))

		fld dword ptr[edx] ; (XX * tan(X / Y)) Y
		fld dword ptr[edx] ; (XX * tan(X / Y)) Y Y
		fmul
		fld one
		fld dword ptr[ecx]
		fld dword ptr[edx]
		fdiv
		fptan
		fstp result;
		fdiv
		fmul
		fadd

		; RESULT RETURN
		fstp result
		lea eax, result
		ret
	@FirstCount@8 endp

	@SecondCount@8 proc ; extern "C" float* _fastcall SecondCount(float*, float*);
		finit ; INIT FPU
		fld dword ptr[ecx]
		fld dword ptr[edx]
		fmul
		fld dword ptr[edx]
		fld dword ptr[ecx]
		fyl2x
		fadd
		fld dword ptr[ecx]
		fld dword ptr[edx]
		fdiv
		fld one
		fpatan
		fdiv

		; RESULT RETURN
		fst result
		lea eax, result
		ret
	@SecondCount@8 endp

	@ThirdCount@8 proc ; extern "C" float* _fastcall ThirdCount(float*, float*);
		finit ; INIT FPU
		fld dword ptr[ecx]
		fld dword ptr[edx]
		fsub
		fabs
		fld dword ptr[ecx]
		fld dword ptr[edx]
		fdiv
		fld dword ptr[edx]
		fld dword ptr[ecx]
		fdiv
		fadd
		fcos
		fmul

		; RETURN RESULT
		fstp result
		lea eax, result
		ret
	@ThirdCount@8 endp
end