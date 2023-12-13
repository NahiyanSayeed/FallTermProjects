TITLE

; Name:Spondon Sayeed 
; Date:
; ID: 110101278
; Description: Assignment 3 Q3

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
.data
 
.code
main PROC
 mov ecx, 10; only here to stop the memory handle exception in add eax,[esi]
 ;begins
 ;push eai,ecx
 push esi
 push ecx
 ;eax = 0
 mov eax, 0
 ;start of loop or yes to loop condition
 L1:
 ;add eax,[esi]
 add eax,[esi]
 ;add esi,4
 add esi,4
 ;loop does ecx = ecx -1
 ;loop checks ecx > 0
 loop L1
 ;no to loop condition
 ;pop ecx,esi
 pop ecx
 pop esi
 ;end
exit
main ENDP
END main