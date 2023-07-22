; x86-64 codes
; Chen, Hannah L. / G01

section .text
bits 64
default rel
global x86dotProduct

x86dotProduct:

; rcx - 1st parameter, rdx - 2nd parameter, r8 - 3rd parameter, r9 - 4th parameter

L1:
	vmovsd xmm1, [r8]				; CHEN, HANNAH / G01
	vmovsd xmm2, [r9]
	vmulsd xmm3, xmm1, xmm2
	vaddsd xmm4, xmm4, xmm3

	add r8, 4
	add r9, 4

	loop L1

vmovsd [rdx], xmm4
ret