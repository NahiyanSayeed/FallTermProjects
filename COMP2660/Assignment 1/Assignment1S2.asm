TITLE

; Name: Spondon Sayeed
; Date: 2023-09-24
; ID: 110101278
; Description: Assignment 1 Section 2.2

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data
	; data declarations go here
	var1 dword 20000h
	var2 dword 30000h
	var3 dword 10000h
.code
main PROC
	; program syntax here
	mov eax, var1 
	add eax, var2 
	sub eax, var3 
	call DumpRegs ; displays registers in console
	exit
main ENDP
END main