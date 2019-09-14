#include <stdio.h>
#include "src/constants.h"
#include "src/vm.h"
#include "src/instruction.h"

int main(){
	VirtualMachine *vm = vm_new();
	if(vm == NULL) return 1;
	
	vm_print_full(&vm);
	
	vm_delete(&vm);
	
	return 0;
}
