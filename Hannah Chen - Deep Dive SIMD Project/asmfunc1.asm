; x86_SIMD_ISA codes
; Chen, Hannah L. / G01

section .text
bits 64
default rel
global SIMDdotProduct

SIMDdotProduct:

; rcx - 1st parameter, rdx - 2nd parameter, r8 - 3rd parameter, r9 - 4th parameter
; vmovdqu
	shr rcx, 1					; CHEN, HANNAH / G01

L1:
	; vmovdqu ymm1, [r8]
	; vmovdqu ymm2, [r9]

	vmovupd ymm1, [r8]
	vmovupd ymm2, [r9]

	vmulpd  ymm3, ymm1, ymm2
	vaddpd  ymm4, ymm4, ymm3

	add r8, 16
	add r9, 16

	loop L1

; vmovdqu [rdx], ymm4
vmovupd [rdx], ymm4
ret