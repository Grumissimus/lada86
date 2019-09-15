#include "config.h"
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef struct Instruction{
	word prefixes;
	word opcode;
	void *src;
	void *des;
} Instruction;

void ins_check_flags(dword *flags, void *prev_val, void *cur_val);

/*
	0x00: &reg, false, &r_m, sizeof(byte)
	0x01: &reg, false, &r_m, sizeof(word/dword/qword)
	0x02: &r_m, false, &reg, sizeof(byte)
	0x03: &r_m, false, &reg, sizeof(word/dword/qword)
	0x04: imm, true, &AL, sizeof(byte)
	0x05: imm, true, &(r/e)AX, sizeof(word/dword/qword)
	0x80/0, 0x82/0: imm, true, &r_m, sizeof(byte)
	0x81/0, 0x83/0: imm, true, &r_m, sizeof((-/d/q)word)
*/
void ins_add(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x06, 0x0E, 0x16, 0x1E, 0x26, 0x2E */
void ins_push_seg(void *seg_reg, void *stack, void *sp); 
/* 0x07, 0x0F, 0x17, 0x1F, 0x27, 0x2F */
void ins_pop_seg(void *seg_reg, void *stack, void *sp); 
/* 0x08..0x0D, 0x80/1..0x83/1 */
void ins_or(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x10..0x15, 0x80/2..0x83/2 */
void ins_adc(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x18..0x1D, 0x80/3..0x83/3 */
void ins_sbb(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x20..0x25, 0x80/4..0x83/4 */
void ins_and(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x28..0x2D, 0x80/5..0x83/5 */
void ins_sub(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x30..0x35, 0x80/6..0x83/6 */
void ins_xor(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x38..0x3D, 0x80/7..0x83/7 */
void ins_cmp(void *src, boolean is_src_imm, void *des, dword num_size);
/* 0x40..0x47 */
void ins_inc(void *src, dword num_size);
/* 0x48..0x4F */
void ins_dec(void *src, dword num_size);
/* 0x50..0x57 */
void ins_push_reg(void *src, dword num_size, void *stack, void *sp);
/* 0x58..0x5F */
void ins_pop_reg(void *src, dword num_size, void *stack, void *sp);
/*0x68, 0x6A*/
void ins_push_imm(void *src, dword num_size, void *stack, void *sp);
/* 0x84, 0x85, 0xA8, 0xA9, 0xF6/0, 0xF7/0, 
Maybe: 0xF6/1, 0xF7/1*/
void ins_test(void *src, boolean is_src_imm, void *des, dword num_size);

/*
0xD8/0: &sti/float, false/true, &ST, sizeof(float)
0xDC/0: &sti/float, false/true, &ST, sizeof(double)
*/
void ins_fadd(double *src, boolean is_src_imm, double *des, dword num_size);

#endif //INSTRUCTION_H