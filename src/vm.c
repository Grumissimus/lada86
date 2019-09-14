#include "vm.h"

VirtualMachine *vm_new(){
	VirtualMachine *vm = (VirtualMachine*)malloc(sizeof(VirtualMachine));
	
	if(!vm){
		return NULL;
	}
	
	vm->state = VM_NEW;
	vm->size.data = 0;
	vm->size.code = 0;
	vm->size.stack = 0;
	vm->size.extra = 0;
	
	vm->program = NULL;
	vm->eip = 0;
	vm->eflags = 0;
	
	memset(&vm->registers, 0, 8*sizeof(unsigned int));
	memset(&vm->segreg, 0, 4*sizeof(unsigned int));
	memset(&vm->st, 0, 8*sizeof(double));
	
	vm->op1.type = UNK;
	vm->op1.value = 0;
	
	vm->op2.type = UNK;
	vm->op2.value = 0;
	
	return vm;
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
		"ES=%d\n",
		(*vm)->segreg[DS], 
		(*vm)->segreg[CS],
		(*vm)->segreg[SS],
		(*vm)->segreg[ES]
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