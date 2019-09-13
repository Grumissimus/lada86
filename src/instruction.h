#include "constants.h"
#include "vm.h"

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

void x86_add(VirtualMachine **vm, InstructionMode im);
void x86_or (VirtualMachine **vm, InstructionMode im);
void x86_adc(VirtualMachine **vm, InstructionMode im);
void x86_sbb(VirtualMachine **vm, InstructionMode im);
void x86_and(VirtualMachine **vm, InstructionMode im);
void x86_sub(VirtualMachine **vm, InstructionMode im);
void x86_xor(VirtualMachine **vm, InstructionMode im);
void x86_cmp(VirtualMachine **vm, InstructionMode im);

void x86_inc_r(VirtualMachine **vm);
void x86_dec_r(VirtualMachine **vm);
void x86_push_r(VirtualMachine **vm);
void x86_pop_r(VirtualMachine **vm);
void x86_mov(VirtualMachine **vm);

#endif //INSTRUCTION_H
