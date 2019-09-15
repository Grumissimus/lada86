#ifndef LADA_86_CONFIG_H
#define LADA_86_CONFIG_H

/* Small boolean type */
typedef unsigned int boolean;
#define true 1
#define false 0

/* Unsigned types aliases */
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long long qword;

/* Signed types aliases */
typedef char s_byte;
typedef short s_word;
typedef int s_dword;
typedef long long s_qword;

/* CPU type */
typedef enum CPU_type{
	intel8086,
	intel186,
	intel286,
	intel386,
	intel486,
	pentium,
	pentium_ii,
	pentium_iii,
	pentium_4,
	core_1,
	core_2,
	core_7
} CPU_type;

#define OP_DIR(x)		((x) & 2)
#define OP_SIZE(x)		((x) & 1)

#define MOD(x) 		(((x) & 0x60) >> 5)
#define REG(x) 		(((x) & 0x1c) >> 2)
#define RM(x) 		((x) & 0x07)
#define MOD_RM(x)	(MOD(x) << 3 | RM(x))

#define SCALE(x) 	(((x) & 0x60) >> 5) 
#define INDEX(x) 	(((x) & 0x1c) >> 2) 
#define BASE(x) 	((x) & 0x07)

#endif /*LADA_86_CONFIG_H*/