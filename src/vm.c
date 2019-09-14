#include "vm.h"

#define GET_INS (*vm)->program[(*vm)->segreg[CS]+(*vm)->eip]

VirtualMachine *vm_new(){
	VirtualMachine *vm = (VirtualMachine*)malloc(sizeof(VirtualMachine));
	
	if(!vm){
		return NULL;
	}
	
	vm->state = VM_NEW;
	
	vm->program = NULL;
	vm->eip = 0;
	vm->eflags = 0;
	
	memset(&vm->registers, 0, 8*sizeof(unsigned int));
	memset(&vm->segreg, 0, 4*sizeof(unsigned int));
	memset(&vm->st, 0, 8*sizeof(double));
	
	memset(&vm->size, 0, sizeof(SegmentSize));
	
	memset(&vm->instruction, 0, 15);
	vm->insLength = 0;
	
	vm->op1.type = UNK;
	vm->op1.value = 0;
	
	vm->op2.type = UNK;
	vm->op2.value = 0;
	
	return vm;
}

boolean vm_init_seg(VirtualMachine **vm, SegmentSize ss){
	if(*vm == NULL) return false;
	
	memcpy(&(*vm)->size, &ss, sizeof(ss));
			
	(*vm)->segreg[CS] = 0;
	(*vm)->segreg[DS] = ss.code;
	(*vm)->segreg[ES] = ss.code+ss.data;
	(*vm)->segreg[FS] = ss.code+ss.data+ss.extra;
	(*vm)->segreg[GS] = ss.code+ss.data+ss.extra+ss.fseg+ss.gseg;
	(*vm)->segreg[SS] = ss.code+ss.data+ss.extra+ss.fseg+ss.gseg;
	(*vm)->registers[ESP] = ss.code+ss.data+ss.extra+ss.fseg+ss.gseg+ss.stack;
	
	(*vm)->program = calloc((*vm)->programSize, sizeof(1));
	
	return true;
}

boolean vm_load_code(VirtualMachine **vm, const char *code, unsigned int length){
	if(*vm == NULL || code == NULL || length > (*vm)->size.code ) return false;
	
	memcpy(&(*vm)->program[(*vm)->segreg[CS]], code, length);
	(*vm)->programSize = length;
	return true;
}

boolean vm_load_data(VirtualMachine **vm, const char *data, unsigned int length){
	if(*vm == NULL || data == NULL || length > (*vm)->size.data ) return false;
	
	memcpy(&(*vm)->program[(*vm)->segreg[DS]], data, length);
	return true;
}

boolean vm_is_ready(VirtualMachine **vm){
	if( (*vm) == NULL ) return false;
	if( (*vm)->state != VM_NEW ) return false;
	if( (*vm)->program == NULL ) return false;
	if( (*vm)->size.code == 0 && (*vm)->size.data == 0 && (*vm)->size.stack == 0 ) return false;
	if( (*vm)->programSize == 0 ) return false;
	
	(*vm)->state = VM_READY;
	
	return true;
}

void vm_fetch(VirtualMachine **vm){
	while( (*vm)->insLength < 15 ){
		unsigned char ins = GET_INS;
		
		switch(ins){
			case 0x26:
			case 0x2E:
			case 0x36:
			case 0x3E:
			case 0x64:
			case 0x65:
			case 0x66:
			case 0x67:
			case 0xF0:
			case 0xF2:
			case 0xF3:
				(*vm)->instruction[(*vm)->insLength] = ins;
				break;
			default:
				break;
		}
		(*vm)->insLength++;
		(*vm)->eip++;
	}
}

void vm_print_full(VirtualMachine **vm){
	if(*vm == NULL) return;
	
	puts(" * * * GENERAL INFO * * *");
	printf("%s", "State: ");
	switch((*vm)->state){
		case VM_ERROR:	printf("%s\n", "ERROR"); 	break;
		case VM_NEW:	printf("%s\n", "NEW"); 		break;
		case VM_READY:	printf("%s\n", "READY"); 	break;
		case VM_FINISH:	printf("%s\n", "FINISH"); 	break;
	}
	printf("EIP=%d\n", (*vm)->eip);
	printf("%s","EFLAGS=");
	for(unsigned int i = 0; i < sizeof((*vm)->eflags)*8; i++){
		printf("%d", (*vm)->eflags & 1 << i);
	}
	printf("%s", "\n\n");
	vm_print_reg(vm);
	printf("%s", "\n");
	vm_print_segreg(vm);
	printf("%s", "\n");
	vm_print_fpreg(vm);
}

void vm_print_reg(VirtualMachine **vm){
	if(*vm == NULL) return;
	
	puts(" * * * GENERAL USE REGISTERS * * *");
	printf(	
		"EAX=%d\n"
		"EBX=%d\n" 
		"ECX=%d\n"
		"EDX=%d\n"
		"ESP=%d\n"
		"EBP=%d\n"
		"ESI=%d\n"
		"EDI=%d\n",			
		(*vm)->registers[EAX], 
		(*vm)->registers[EBX],
		(*vm)->registers[ECX],
		(*vm)->registers[EDX],
		(*vm)->registers[ESP],
		(*vm)->registers[EBP],
		(*vm)->registers[ESI],
		(*vm)->registers[EDI]
	); 
}


void vm_print_segreg(VirtualMachine **vm){
	if(*vm == NULL) return;
	
	puts(" * * * SEGMENT REGISTERS * * *");
	printf(	
		"DS=%d\n"
		"CS=%d\n" 
		"SS=%d\n"
		"ES=%d\n"
		"FS=%d\n"
		"GS=%d\n",
		(*vm)->segreg[DS], 
		(*vm)->segreg[CS],
		(*vm)->segreg[SS],
		(*vm)->segreg[ES],
		(*vm)->segreg[FS],
		(*vm)->segreg[GS]
	); 
}

void vm_print_fpreg(VirtualMachine **vm){
	if(*vm == NULL) return;
	
	puts(" * * * FLOATING-POINT REGISTERS * * *");
	for(unsigned int i = 0; i < 8; i++){
		printf("ST%d=%.8f\n", i+1, (*vm)->st[i]);
	}
}

void vm_delete(VirtualMachine **vm){
	if(*vm == NULL) return;
	
	free((*vm)->program);
	(*vm)->program = NULL;
	free(*vm);
	*vm = NULL;
}