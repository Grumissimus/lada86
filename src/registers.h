#ifndef REGISTERS_H
#define REGISTERS_H

typedef enum Reg_8{
	AL, CL, DL, BL, AH, CH, DH, BH
} Reg_8;

typedef enum Reg_16{
	AX, CX, DX, BX, SP, BP, SI, DI
} Reg_16;

typedef enum Reg_32{
	EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI
} Reg_32;

typedef enum Reg_64{
	RAX, RCX, RDX, RBX, RSP, RBP, RSI, RDI
} Reg_64;

typedef enum Seg_reg{
	CS = 0, DS, SS, ES, FS, GS
} Seg_reg;

typedef enum Con_reg{
	CR0, CR1, CR2, CR3, CR4
} Con_reg;

typedef enum desc_reg{
	GDTR, LDTR, IDTR
} desc_reg;

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

#endif //REGISTERS_H