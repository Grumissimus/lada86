#ifndef CONSTANTS_H
#define CONSTANTS_H

typedef unsigned int boolean;
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
	PF = 1 << 1,
	AF = 1 << 3,
	ZF = 1 << 5,
	SF = 1 << 6,
	TF = 1 << 7,
	IF = 1 << 8,
	DF = 1 << 9,
	OF = 1 << 10,
	IOPL = (1 << 11) | (1 << 12),
	NT = 1 << 13,
	RF = 1 << 15,
	VM = 1 << 16,
	AC = 1 << 17,
	VIF = 1 << 18,
	VIP = 1 << 19,
	ID = 1 << 20
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

typedef struct SegmentSize{
	unsigned int data;
	unsigned int code;
	unsigned int stack;
	unsigned int extra;
	unsigned int fseg;
	unsigned int gseg;
} SegmentSize;

#endif