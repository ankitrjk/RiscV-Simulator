#ifndef REGISTER_H_
#define REGISTER_H_
#include<stdint.h>

int32_t Register[32];
string IR = "0";
string Instruction_Label = "not found";
int32_t RA,RB,RD,RM,RZ,RY,IMMEDIATE,RD_INDEX;

void init_Register()
{	for (int i=0; i<32; i++)
			Register[i] = 0;
	int32_t temp = std::stoul("0x7FFFFFF0", nullptr, 16);
	Register[2] = temp;
	temp = std::stoul("0x10000000", nullptr, 16);
	Register[3] = temp;
}

#endif