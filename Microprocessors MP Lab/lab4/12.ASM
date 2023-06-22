data segment
a db 4h
b db -4h
res db 0
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0
mov bx,0
mov al,a
mov bl,b
imul bl
mov ah,4ch
int 21h
code ends
end start

