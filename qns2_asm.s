.data			@switch to data segment 
.balign 4		@pad location counter by 4	

string: .asciz "\n The total area of the two shapes is(sqm): %d\n" 		@set 1st string
string2: .asciz "\nEnter a positive decimal number Length1(meters): \n"     @set 2nd string
string3: .asciz "\nEnter a positive decimal number Width1(meters): \n" 	@set 3rd string

input: .string "%d" 	@set the format specifier as decimal for scanf

s1: .word 20 			@set side 1 of triangle to 20
s2: .word 15			@set side 2 of triangle to 15
s3Length: .word 0		@set side 3 of triangle/length of rectangle to 0
s4Width: .word 0		@set width of rectangle to 0
c: .word 0			@set totalarea to 0

.text				@switch to text segment
.global main			@declare for linker
.extern printf			@call external object printf
.extern scanf			@call external object scanf

sqrtloop:			@get sqrt of number
	CMP R8,R9			@compare R8 and R9
	BEQ end			@end when R8 is equal to R9
	ADD R1,R1,#1			@increment R1 by 1
	MUL R9,R1,R1			@square R1 by multipling R1 by R1, store in R9
	B sqrtloop			@continue looping if R8 not equal R9
end:
	MOV R0,R1			@copy R1 into R0, as only R0 is readable outside
	BX LR				@end; return address to R1

main:
	PUSH {ip,lr}	@store return address link register,intra procedural call register in Stack

	LDR R0,=string2		@get address of string2 into R0
	BL printf			@branch link to printf, print string2
	LDR R0,=input			@get address of input into R0
	LDR R1,=s3Length		@get address of s3Length into R1
	BL scanf			@branch link scanf,scan data into s3Length

	LDR R3,=s3Length		@get address of s3Length into R3
	LDR R3,[R3]			@get value of s3Length into R3

	LDR R0,=string3		@get address of string3 into R0
	BL printf			@branch link to printf, print string3
	LDR R0,=input		             @get address of input into R0
	LDR R1,=s4Width		@get address of s4Width into R1
	BL scanf	  @branch link scanf, set format specifer as input, scan data into s4Width
	LDR R10,=s4Width		@get address of s4Width into R10
	LDR R10,[R10]			@get value of s4Width into R10


	LDR R1,=s1			@get address of s1 into R1
	LDR R1,[R1]			@get value of s1 into R1
	LDR R2,=s2			@get address of s2 into R2
	LDR R2,[R2]			@get value of s2 into R2
	LDR R3,=s3Length		@get address of s3Length into R3
	LDR R3,[R3]			@get value of s3Length into R3
	ADD R4,R1,R2			@add r1,r2 set value to r4
	ADD R4,R4,R3 			@add r4,r3 set value to r4, s = s1 +s2 +s3		
	ASR R4,R4,#1 			@arithmetic shift right by #1, R4, s = s1+s2+s3/2
	SUB R5,R4,R1 			@subtract r4,r1 set value to R5, s-s1
	SUB R6,R4,R2 			@subtract r4,r2 set value to r6, s-s2
	SUB R7,R4,R3 			@subtract r4,r3 set value to r7, s-s3

	MUL R8,R4,R5 		@multiply r4,r5 set value to r8,s*(s-s1)			
	MUL R8,R6,R8 		@multiply r6,r8 set value to r8,s*(s-s1)*(s-s2)
	MUL R8,R7,R8 		@multiply r7,r8 set value to r8,s*(s-s1)*(s-s2)*(s-s3)
	MOV R1,#0			@move value #0 to R1
	BL sqrtloop			@branch link sqroot
	MUL R8,R10,R3		@multiply r10,r3 set value to r8, s3length*s4width
	ADD R1,R1,R8			@multiply r1,r8 set value to r1,totalarea

	LDR R2,=c			@load address of c into R2
	STR R1,[R2]			@store value of r1 into c
	LDR R0,=string			@load string into r0 to perform procedural call
	LDR R1,[R2]			@get value of c into r1
	BL printf			@branch link to printf, print string and R1 value


	POP {ip,pc}			@pop ip reg, lr reg value to PC and return
