.data
.balign 4

string: .asciz "\n The total area of the two shapes is(sqm): %d\n"
string2: .asciz "\nEnter a positive decimal number Length1(meters): \n"
string3: .asciz "\nEnter a positive decimal number Width1(meters): \n"

input: .string "%d"

s1: .word 20
s2: .word 15
s3Length: .word 0
s4Width: .word 0
c: .word 0

.text
.global main
.extern printf
.extern scanf

sqrtloop:
	CMP R8,R9
	BEQ end
	ADD R1,R1,#1
	MUL R9,R1,R1
	B sqrtloop
end:
	MOV R0,R1
	BX LR

main:
	PUSH {ip,lr}

	LDR R0,=string2
	BL printf
	LDR R0,=input
	LDR R1,=s3Length
	BL scanf
	LDR R3,=s3Length
	LDR R3,[R3]
	@MOV R2,#0
	@ADD R3,R3,R2

	LDR R0,=string3
	BL printf
	LDR R0,=input
	LDR R1,=s4Width
	BL scanf
	LDR R10,=s4Width
	LDR R10,[R10]
	@MOV R2,#0
	@ADD R10,R10,R2
	LDR R0,=input
	MOV R1,R10
	BL printf

	LDR R1,=s1
	LDR R1,[R1]
	LDR R2,=s2
	LDR R2,[R2]
	LDR R3,=s3Length
	LDR R3,[R3]
	ADD R4,R1,R2
	ADD R4,R4,R3 @R4 s = s1 +s2 +s3
	ASR R4,R4,#1 @R4 s = s1+s2+s3/2
	SUB R5,R4,R1 @R5 s-s1
	SUB R6,R4,R2 @R6 s-s2
	SUB R7,R4,R3 @R7 s-s3

	MUL R8,R4,R5 @R8 s*(s-s1)
	MUL R8,R6,R8 @R8 s*(s-s1)*(s-s2)
	MUL R8,R7,R8 @R8 s*(s-s1)*(s-s2)*(s-s3)
	MOV R1,#0
	BL sqrtloop
	@LDR R10,=s4Width
	@LDR R10,[R10]
	MUL R8,R10,R3
	ADD R1,R1,R8

	LDR R2,=c
	STR R1,[R2]
	LDR R0,=string
	LDR R1,[R2]
	BL printf


	POP {ip,pc}
