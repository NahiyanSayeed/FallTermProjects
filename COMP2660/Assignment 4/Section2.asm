; Name: Spondon Sayeed 
; Date: 
; ID: 110101278 
; Description: Assignment4

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data
    plaintext BYTE "HELLOWORLD", 0
    key BYTE 2, 4, 1, 0, 3, 5, 2, 4, 4, 6
    encryptedString BYTE 11 DUP(?)  ; Buffer 
.code
MAIN PROC
    mov esi, 0  ; Index for plaintext
    mov edi, 0  ; Index for key
encrypt_loop:
    cmp plaintext[esi], 0
    je end_program
    movzx ecx, byte ptr key[edi]
    mov al, plaintext[esi]
    sub al, 'A'       
    movzx eax, al     
    ror eax, cl       
    and al, 1Fh       ; Ensure it's in the range 0-25
    add al, 'A'       ; Convert back to ASCII
    mov encryptedString[esi], al
    inc esi
    inc edi
    cmp edi, 10
    je reset_key
    jmp encrypt_loop
reset_key:
    mov edi, 0
    jmp encrypt_loop
end_program:
    mov edx, OFFSET encryptedString
    call WriteString
    exit
MAIN ENDP
END MAIN
