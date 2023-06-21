DATA SEGMENT
   A DD 62847263H
   B DW 0FF43H
   Q DW 0H
   R DW 0H
DATA ENDS

CODE SEGMENT
   ASSUME CS:CODE, DS:DATA
   START: MOV AX,DATA
          MOV DS,AX

          MOV AX,WORD PTR A
          MOV DX,WORD PTR [A+2]
          MOV CX,B
          DIV CX;
          MOV Q,AX
          MOV R,DX

          MOV AH,4CH
          INT 21H
CODE ENDS
     END START
