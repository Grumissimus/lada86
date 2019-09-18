#include "ins.h"

void ins_add(void *src, boolean is_src_imm, void *des, dword num_size){
	dword *dest = (dword*)&des;
	dword prev = *dest & (1 << 8*num_size);
	
	*dest += is_src_imm ? (dword)(src) : *dest;
}

void ins_or(void *src, boolean is_src_imm, void *des, dword num_size){
	dword *dest = (dword*)&des;
	dword prev = *dest & (1 << 8*num_size);
	
	*dest |= is_src_imm ? (dword)(src) : *dest;
}

void ins_inc(void *src, dword num_size){
	dword *dest = (dword*)(&src);
	*dest &= (1 << 8*num_size);
	*dest++;
}
