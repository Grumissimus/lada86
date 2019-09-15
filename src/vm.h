#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "registers.h"
#include "ins.h"

#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

typedef enum VMState{
	VM_ERROR, VM_NEW, VM_READY, VM_FINISH
} VMState;

typedef struct VirtualMachine{
	VMState state;
		
	CPU_type type;
	dword architecture;
	
	dword eip;
	dword eflags;
	
	dword registers[8];
	dword segreg[6];
	dword control[5];
	double st[8];
	
	Instruction ins;
} VirtualMachine;

VirtualMachine *vm_new();

void vm_print_full(VirtualMachine **vm);
void vm_print_reg(VirtualMachine **vm);
void vm_print_segreg(VirtualMachine **vm);
void vm_print_fpreg(VirtualMachine **vm);

void vm_fetch(VirtualMachine **vm);
void vm_decode(VirtualMachine **vm);
void vm_execute(VirtualMachine **vm);

boolean vm_run(VirtualMachine **vm);

void vm_delete(VirtualMachine **vm);

/* Please, don't use these macros below outside vm.c or vm.h */
#define REGISTER(x) (*vm)->registers[(x)]
#define SEG_REGISTER(x) (*vm)->segreg[(x)]
#define CNTL_REGISTER(x) (*vm)->control[(x)]
#define STI(x) (*vm)->st[(x)]
#define EIP(x) (*vm)->eip[(x)]
#define EFLAGS(x) (*vm)->flags[(x)]
#define FLAGS(x) ((*vm)->flags[(x)] & (0xFFFF))

#define GET_REG_L(x) ( REG(x) & 0x00FF )
#define GET_REG_H(x) ( REG(x) & 0xFF00 )

#endif //VIRTUAL_MACHINE_H
