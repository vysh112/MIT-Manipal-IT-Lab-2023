data segment
a dw 00E3h
b dw 0007h
ans dd 0
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

mov cx,b
mov ax,0
mov bx,0
back:
add ax,a
adc bl,0
loop back
mov word ptr ans,bx
mov word ptr ans + 2, ax

mov ah,4ch
int 21h
code ends
end start

