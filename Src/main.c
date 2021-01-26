
/*
 *
 * Load 2 values from memory, add them and store the result back to the memory
 * using inline assembly statements.
 *
 */


#include <stdint.h>



int main(void)
{

	__asm volatile("LDR R1,=#0x20001000");
	__asm volatile("LDR R2,=#0x20001004");
    __asm volatile("LDR R0,[R1]");
    __asm volatile("LDR R1,[R2]");
    __asm volatile("ADD R0,R0,R1");
    __asm volatile("STR R0,[R2]");

	for(;;);
}
