disp macro num
mov dl,num
and dl,0f0h
mov cl,04h
shr dl,cl
cmp dl,09h
ja l0
add dl,30h
jmp l1
l0:
add dl,37h
l1:
mov ah,02h
int 21h

mov dl,num
and dl,0fh
cmp dl,09h
ja l2
add dl,30h
jmp l3
l2:
add dl,37h
l3:
mov ah,02h
int 21h

mov dl,10
mov ah,02h
int 21h
endm

code segment
assume cs:code
start:
mov bl,0FFh
mov cx,0FFh
back:
	push cx
	disp bl
	dec bl
	call delay
	pop cx
MOV DL,0FFH
 MOV AH,06
 INT 21H
 JNZ DOWN 
	JMP l
DOWN: 
	CMP AL,13
 	JNZ exit
l:
loop back

exit:
mov ah,4ch
int 21h

delay proc
push si 
push di
mov si,0013h
up:
mov di,0ffffh
up1:
dec di
jnz up1
dec si
jnz up
pop di
pop si
ret
delay endp

code ends 
end start