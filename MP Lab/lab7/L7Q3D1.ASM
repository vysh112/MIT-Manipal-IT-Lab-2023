data segment
arr dw 3333h,2222h,1111h,4444h,1234h
data ends

code segment
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax

lea di,arr
mov cx,5
loop1:
        push cx
mov si,di
	mov bx,di
        loop2:
                mov ax,[si]
                cmp ax,[bx]
                jg L1
                mov bx,si
                L1:
                inc si
                inc si
        loop loop2
       mov ax,[di]
	mov dx,[bx]
	mov [bx],ax
	mov [di],dx
inc di
inc di
pop cx	
loop loop1
mov ah,4ch
int 21h
code ends
end start

