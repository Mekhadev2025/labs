DATA SEGMENT
STR DB 'AXYBCSDEF$'
SUBSTR DB 'BCS$'
LEN1 DB 0
LEN2 DB 0
MSG1 DB 10,13,'STRING IS : $'
MSG2 DB 10,13,'SUBSTRING IS : $'
MSG3 DB 10,13,'SUBSTRING IS FOUND AT POSITION : $'
POS DB -1
RTN DB '-1$'
DATA ENDS
DISPLAY MACRO MSG
MOV AH,9
LEA DX,MSG
INT 21H
ENDM
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
MOV AX,DATA
MOV DS,AX
DISPLAY MSG1
DISPLAY STR
DISPLAY MSG2
DISPLAY SUBSTR
LEA SI,STR
NXT1:
CMP [SI],'$'
JE DONE1
INC LEN1
INC SI
JMP NXT1
DONE1:
LEA DI,SUBSTR
NXT2:
CMP [DI],'$'
JE DONE2
INC LEN2
INC DI
JMP NXT2
DONE2:
DISPLAY MSG3
LEA SI,STR
MOV AL,LEN1
SUB AL,LEN2
MOV CL,AL
MOV CH,0
FIRST:
INC POS
MOV AL,[SI]
CMP AL,SUBSTR[0]
JE CMPR
INC SI
LOOP FIRST
CMPR: INC SI
MOV AL,[SI]
CMP AL,SUBSTR[1]
JNE NOTEQUAL
INC SI
MOV AL,[SI]
CMP AL,SUBSTR[2]
JE EQUAL
NOTEQUAL:
MOV POS,-1
DISPLAY RTN
JMP EXIT
EQUAL:
MOV DL,POS
ADD DL,30H
MOV AH,2
INT 21H
EXIT: MOV AH,4CH
INT 21H
CODE ENDS
END START