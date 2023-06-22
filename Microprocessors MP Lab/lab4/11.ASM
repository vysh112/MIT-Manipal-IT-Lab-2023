data segment
a dw 1111h
b dw 2222h
res dw 0
data ends

code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax

mov ax,a
mov bx,b
mul bx

mov ah,4ch
int 21h
code ends
end start
