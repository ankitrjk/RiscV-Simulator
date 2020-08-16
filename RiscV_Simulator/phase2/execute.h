#ifndef EXECUTE_H_
#define EXECUTE_H_
#include<stdint.h>
#include "register.h"
#include "pc.h"

void execute()
{	//R-type
	//for add
	if(Instruction_Label == "add")
	{	RZ = RA + RB;
	}
	
	//for sub
	if(Instruction_Label == "sub")
	{	RZ = RA - RB;
	}

	//for and
	if(Instruction_Label == "and")
	{	RZ = RA & RB;
	}

	//for or
	if(Instruction_Label == "or")
	{	RZ = RA | RB;
	}

	//for xor
	if(Instruction_Label == "xor")
	{	RZ = RA ^ RB;
	}

	//for sll
	if(Instruction_Label == "sll")
	{	unsigned int temp = RA;
		RZ = temp >> RB;
	}

	//for srl
	if(Instruction_Label == "srl")
	{	unsigned int temp = RA;
		RZ = temp >> RB;
	}

	//for sra
	if(Instruction_Label == "sra")
	{	RZ = RA >> RB;
	}

	//for slt
	if(Instruction_Label == "slt")
	{	if(RA < RB)
			RZ = 1;
		else
			RZ = 0;
	}

	//for sltu
	if(Instruction_Label == "sltu")
	{	if(RA < RB)
			RZ = 1;
		else
			RZ = 0;
	}

	//for mul
	if(Instruction_Label == "mul")
	{	RZ = RA * RB;
	}

	//for div
	if(Instruction_Label == "div")
	{	RZ = RA / RB;
	}

	//for rem
	if(Instruction_Label == "rem")
	{	RZ = RA % RB;
	}


	//I-type
	//for addi
	if(Instruction_Label == "addi")
	{	RZ = RA + IMMEDIATE;
	}

	//for xori
	if(Instruction_Label == "xori")
	{	RZ = RA ^ IMMEDIATE;
	}

	//for ori
	if(Instruction_Label == "ori")
	{	RZ = RA | IMMEDIATE;
	}

	//for andi
	if(Instruction_Label == "andi")
	{	RZ = RA & IMMEDIATE;
	}

	//for slli
	if(Instruction_Label == "slli")
	{	unsigned int temp = RA;
		RZ = temp << IMMEDIATE;
	}

	//for srli
	if(Instruction_Label == "srli")
	{	unsigned int temp = RA;
		RZ = temp >> IMMEDIATE;
	}

	//for srai
	if(Instruction_Label == "srai")
	{	RZ = RA >> IMMEDIATE;
	}

	//for slti
	if(Instruction_Label == "slti")
	{	if(RA < IMMEDIATE)
			RZ = 1;
		else
			RZ = 0;
	}

	//for sltiu
	if(Instruction_Label == "sltiu")
	{	if(RA < IMMEDIATE)
			RZ = 1;
		else
			RZ = 0;
	}

	//for lb
	if(Instruction_Label == "lb")
	{	RZ = RA + IMMEDIATE;
	}

	//for lh
	if(Instruction_Label == "lh")
	{	RZ = RA + IMMEDIATE;
	}

	//for lw
	if(Instruction_Label == "lw")
	{	RZ = RA + IMMEDIATE;
	}

	//for lbu
	if(Instruction_Label == "lbu")
	{	RZ = RA + IMMEDIATE;
	}

	//for lhu
	if(Instruction_Label == "lhu")
	{	RZ = RA + IMMEDIATE;
	}

	//for jalr
	if(Instruction_Label == "jalr")
	{	int32_t program_counter = std::stoul(PC, nullptr, 16);
		Register[RD_INDEX] = program_counter;
		int32_t temp = RA + IMMEDIATE;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	PC = stream.str();
	}

	//S-type
	//for sw
	if(Instruction_Label == "sw")
	{	RZ = RA + IMMEDIATE;
		RM = RB;
	}

	//for sb
	if(Instruction_Label == "sb")
	{	RZ = RA + IMMEDIATE;
		RM = RB;
	}

	//for sh
	if(Instruction_Label == "sh")
	{	RZ = RA + IMMEDIATE;
		RM = RB;
	}

	//UJ-type
    //for jal
    if(Instruction_Label == "jal")
	{	int32_t program_counter = std::stoul(PC, nullptr, 16);
		Register[RD_INDEX] = program_counter;
		program_counter += IMMEDIATE;
		program_counter -= 4; //compensate for +4 in fetch stage
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    	PC = stream.str();
	}

	//U-type
	//for auipc
	if(Instruction_Label == "auipc")
	{	int32_t program_counter = std::stoul(PC, nullptr, 16);
		program_counter += IMMEDIATE;
		program_counter -= 4; //compensate for +4 in fetch stage
		RZ = program_counter;
	}

	//for lui
	if(Instruction_Label == "lui")
	{	RZ = IMMEDIATE;
	}

	//SB-type
    //for beq
    if(Instruction_Label == "beq")
	{	if(RA == RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

	//for bne
	if(Instruction_Label == "bne")
	{	if(RA != RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

	//for blt
	if(Instruction_Label == "blt")
	{	if(RA < RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

	//for bge
	if(Instruction_Label == "bge")
	{	if(RA >= RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

	//for bltu
	if(Instruction_Label == "bltu")
	{	if(RA < RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

	//for bgeu
	if(Instruction_Label == "bgeu")
	{	if(RA >= RB)
		{	int32_t program_counter = std::stoul(PC, nullptr, 16);
			program_counter += IMMEDIATE;
			program_counter -= 4; //compensate for +4 in fetch stage
			std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << program_counter;
    		PC = stream.str();
		}
	}

}

#endif