TITLE

; Name: Spondon Sayeed
; Date: 2023-09-24
; ID: 110101278
; Description: Assignment 1 Section 2.1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data
	; data declarations go here
	Y dword 0 ;Select what Y value you want here 
	X dword 0 ;here to set X's memoery
.code
main PROC
	; program syntax here
	mov eax, Y
	add eax, 4
	mov ebx, 3
	mul ebx
	call DumpRegs ; displays registers in console
	exit
main ENDP
END main