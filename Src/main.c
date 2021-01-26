
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
	
    
    int val=50;
    __asm volatile("MOV R0,%0" : : "r"(val));  // r is meaning general purpose register  --- Input operand in this case.

    int control_reg;
    //read control register to control_reg
    __asm volatile("MRS %0,CONTROL":"=r"(control_reg)::);

    int p1,*p2;

    p2=(int*)0x20000008;

    __asm volatile("LDR %0,[%1]":"=r"(p1):"r"(p2));

	

	for(;;);
}
