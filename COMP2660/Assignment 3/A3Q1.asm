TITLE

; Name:Spondon Sayeed 
; Date:
; ID: 110101278
; Description: Assignment 3 Q1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
.data
    result1 db "The first num is: ", 0
    result2 db "The second num is: ", 0
    result db "The sum is: ", 0
    buffer db "+", 11 dup(0) 
.code

main PROC

    call ClrScr
  
    mov eax, 0  ; Row 
    mov ebx, 0  ; Column 
    call gotoxy

    mov edx, OFFSET result1
    call WriteString
    call ReadInt
    mov ebx, eax  ; Store the first integer in ebx

    mov edx, OFFSET result2
    call WriteString
    call ReadInt
    add ebx, eax  ; Add the second integer to ebx

    mov edx, OFFSET result
    call WriteString
    mov eax, ebx
    call WriteInt
    call Crlf  
    call WaitMsg
exit
main ENDP
END main