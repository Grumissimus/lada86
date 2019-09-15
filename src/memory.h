#ifndef __MEMORY_H__
#define __MEMORY_H__

typedef enum OperatingMode{
	REAL_MODE
} OperatingMode;

typedef struct Memory{
	unsigned char *mem;
	unsigned int totalsize;
	OperatingMode mode;
} Memory;

Memory *memory_new();
Memory *memory_delete();

#endif //__MEMORY_H__