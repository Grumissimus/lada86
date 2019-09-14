#include <stdio.h>
#include "src/constants.h"
#include "src/vm.h"

VirtualMachine *vm = NULL;

void finish(){
	vm_delete(&vm);
}

int main(){
	atexit(finish);
	
	vm = vm_new();
	if(vm == NULL) return 1;
	vm_init_seg(&vm, (SegmentSize){.code=128*4, .data=64*4, .stack=64*4, .extra=0, .fseg=0, .gseg=0} );
	vm_load_code(&vm, "\x04\x0F", 2);
	vm_print_full(&vm);
	return 0;
}
