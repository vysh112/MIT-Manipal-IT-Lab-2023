data segment
a dd 00011111h
b dw -111h
res dw 0
rem dw 0
data ends

code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
mov ax,a
mov dx,a+2
mov bx,b
idiv bx
mov res,ax
mov rem,dx
mov ah,4ch
int 21h
code ends
end start
