; Name: Spondon Sayeed
; Date: 
; ID: 110101278
; Description: Asignment 2

INCLUDELIB Irvine32.lib
INCLUDE Irvine32.inc

.data

array DWORD 10000h, 20000h, 30000h, 40000h
sum DWORD ?

.code
main PROC
   mov ecx, LENGTHOF array
   mov eax, 0
   mov esi, 0

   L1:
   add eax, array[esi* TYPE array]
   inc esi
   loop L1

   ;call DumpRegs

exit
main ENDP
END main