	.data
newline: .asciiz "\n"
.align 2
tab: .asciiz "\t"
.align 2
temp_0: .space 4
temp_1: .space 4
temp_2: .space 4
temp_3: .space 4
X: .space 4
B: .space 4
IA: .space 4
A: .space 4
det: .space 8
temp_4: .space 8
der: .space 8
temp_5: .space 4
temp_6: .space 4
temp_7: .space 4
temp_8: .space 4
temp_9: .space 4
string0: .asciiz "La solution de l’équation AX=B, avec A = "
.align 2
string1: .asciiz "et B = "
.align 2
string2: .asciiz "est X= "
.align 2
string3: .asciiz "\n"
.align 2

	.text
main:
	L3:
		li $t2, 0
		sw $t2, A
	L2:
		li $t2, 4
		sw $t2, IA
		sw $t2, B
		sw $t2, X
	L4:
	L5:
		li.s $f2, 2.300000
		s.s $f2, der
	L7:
		li $t2, 0
		sw $t2, temp_0
	L6:
		lw $t0, temp_5
		lw $t1, temp_6
	L9:
		li $t2, 0
		sw $t2, temp_0
	L8:
		lw $t0, temp_0
		lw $t1, temp_0
	L11:
		li $t2, 0
		sw $t2, temp_0
	L10:
		lw $t0, temp_0
		lw $t1, temp_0
	L12:
		li $v0, 4
		la $a0, string0
		syscall
	L13:
		li $v0, 1
		lw $a0, temp_0
		syscall
		li $v0, 4
		la $a0, newline
		syscall
	L14:
		li $v0, 4
		la $a0, string1
		syscall
	L15:
		li $v0, 1
		lw $a0, temp_0
		syscall
		li $v0, 4
		la $a0, newline
		syscall
	L16:
		li $v0, 4
		la $a0, string2
		syscall
	L17:
		li $v0, 1
		lw $a0, temp_0
		syscall
		li $v0, 4
		la $a0, newline
		syscall
	L18:
		li $v0, 4
		la $a0, string3
		syscall
	exit:
		li $v0, 10
		syscall
