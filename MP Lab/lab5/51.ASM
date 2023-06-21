data segment
bcd db 63h
hex db ?
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

mov al,bcd
mov bl,0ah
mov cl,04h
shr al,cl
mul bl
mov cl,bcd
and cl, 0fh
add al,cl
mov hex,al

mov ah,4ch
int 21h
code ends
end start

