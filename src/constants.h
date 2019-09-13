#ifndef CONSTANTS_H
#define CONSTANTS_H

typedef unsigned int bool;
#define true 1
#define false 0

typedef enum Register{
	EAX = 0, ECX, EDX, EBX, ESP, EBP, ESI, EDI
} Register;

typedef enum SegmentRegister{
	CS = 0, DS, SS, ES, FS, GS
} SegmentRegister;

typedef enum Flags{
	CF = 1,
	PF = 1 << 2,
	AF = 1 << 4,
	ZF = 1 << 6,
	SF = 1 << 7,
	TF = 1 << 8,
	IF = 1 << 9,
	DF = 1 << 10,
	OF = 1 << 11,
	IOPL = (1 << 12) | (1 << 13),
	NT = 1 << 14,
	RF = 1 << 16,
	VM = 1 << 17,
	AC = 1 << 18,
	VIF = 1 << 19,
	VIP = 1 << 20,
	ID = 1 << 21
} Flags;

typedef enum OperatorType{
	UNK, REG, MEM, IMM
} OperatorType;

typedef struct Operator{
	OperatorType type;
	unsigned int value;
} Operator;

typedef enum InstructionMode{
	IM8,
	IM16,
	IM32
} InstructionMode;

#endif