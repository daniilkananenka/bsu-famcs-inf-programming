.586 
.model flat 
 
public @HeronSqrt@8

.data ; DATA BLOCK
A dd 0
N dd 0
X_PREV dd 2.0
two dd 2.0
RUB dd 0.0

.code ; CODE BLOCK

@HeronSqrt@8 proc ; BEGIN - float* _fastcall HeronSqrt(int a, int n)
; ecx - a, edx - n
finit ; INIT FPU
mov A, ecx ; A init
mov N, edx ; N init
mov ecx, N ; loop counter init

heron_loop: ; start heron sqrt loop
	fld X_PREV ; ST - X_PREV
	fild A ; ST - A, X_PREV
	fdiv st(0), st(1) ; A/X_PREV | ST - A/X_PREV, X_PREV
	fadd st(0), st(1) ; X_PREV + A/X_PREV | ST - X_PREV+A/X_PREV, X_PREV
	fld two ; ST - 2, X_PREV+A/X_PREV, X_PREV
	fxch ; ST - X_PREV+A/X_PREV, 2, X_PREV
	fdiv st(0), st(1) ; (X_PREV + A/X_PREV)/2 | ST - (X_PREV + A/X_PREV)/2, 2, X_PREV
	fstp X_PREV ; ST - 2, X_PREV
	fstp RUB ; ST - X_PREV
	fstp RUB ; ST - []
	loop heron_loop ; loop counter dec

	lea eax, X_PREV ; move result ptr to eax
	ret
@HeronSqrt@8 endp ; END - float* _fastcall HeronSqrt(int a, int n)
end ; ASM module end