#ifndef WRITEBACK_H_
#define WRITEBACK_H_
#include<stdint.h>

void writeback()
{	if( (Instruction_Label == "add") || (Instruction_Label == "sub") || (Instruction_Label == "and") || 
(Instruction_Label == "or") || (Instruction_Label == "xor") || (Instruction_Label == "mul") || 
(Instruction_Label == "div") || (Instruction_Label == "addi") || (Instruction_Label == "xori") || 
(Instruction_Label == "ori") || (Instruction_Label == "andi") || (Instruction_Label == "slli") || 
(Instruction_Label == "srli") || (Instruction_Label == "lb") || (Instruction_Label == "lh") || 
(Instruction_Label == "lbu") || (Instruction_Label == "lhu") || (Instruction_Label == "lw") ||
(Instruction_Label == "slti") || (Instruction_Label == "sltiu") || (Instruction_Label == "sll") ||
(Instruction_Label == "slt") || (Instruction_Label == "sltu") || (Instruction_Label == "srl") || 
(Instruction_Label == "auipc") || (Instruction_Label == "lui") || (Instruction_Label == "rem") || 
(Instruction_Label == "sra") || (Instruction_Label == "srai") )
		Register[RD_INDEX] = RY;

	Register[0] = 0;
}

#endif