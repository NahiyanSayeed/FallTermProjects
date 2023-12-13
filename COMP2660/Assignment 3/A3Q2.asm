TITLE

; Name:Spondon Sayeed 
; Date:
; ID: 110101278
; Description: Assignment 3 Q2

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
.data
    text db "Hello, Assembly!", 0
    colors dd 2, 4, 6, 14  ; Color codes for different text colors
.code

main PROC
    call ClrScr
    mov edx, OFFSET text
    mov ecx, 4  ; Number of colors to loop through
    mov esi, 0  
    colorLoop:
    mov eax, colors[esi*4]  
    call SetTextColor
    call WriteString
    call Crlf
    inc esi 
    loop colorLoop
    call WaitMsg
exit
main ENDP
END main