data segment
a dw 111h
b db -12h
res dw 0
data ends

code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax

mov ax,a
mov bl,b
div bl

mov ah,4ch
int 21h
code ends
end start
