data segment
a dw 1111h
b dw -1h
res dw 0
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0
mov bx,0
mov ax,a
mov bx,b
imul bx
mov res,bx
mov ah,4ch
int 21h
code ends
end start

