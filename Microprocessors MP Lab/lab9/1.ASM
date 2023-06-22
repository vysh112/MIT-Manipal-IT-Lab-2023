data segment
password db 'vyshnav'
len equ ($-password)
msg1 db 10,13,'Enter your password: $'
msg2 db 10,13,'Welcome: $'
msg3 db 10,13,'Incorrect password $'
new db 10,13,'$'
inst db 10 dup(0)
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
lea dx,msg1
mov ah,09h
int 21h
mov si,00
up1:
mov ah,08h
int 21h
cmp al,0DH
je down
mov [inst+si],al
mov dl,'*'
mov ah,02h
int 21h
inc si
jmp up1
down:
mov bx,00
mov cx,len
check:
mov al,[inst+bx]
mov dl,[password+bx]
cmp al,dl
jne fail
inc bx
loop check
lea dx,msg2
mov ah,09h
int 21h
jmp finish
fail:
lea dx,msg3
mov ah,009h
int 21h
finish:
mov AH,4CH
INT 21H
code ends
end start
