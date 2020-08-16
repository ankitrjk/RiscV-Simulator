#ifndef MEMORY_ACCESS_H_
#define MEMORY_ACCESS_H_
#include<string>
#include<vector>
#include<bitset>
#include<stdint.h>
#include "register.h"

void memory_access()
{	if( (Instruction_Label == "add") || (Instruction_Label == "sub") || (Instruction_Label == "and") || 
(Instruction_Label == "or") || (Instruction_Label == "xor") || (Instruction_Label == "mul") || 
(Instruction_Label == "div") || (Instruction_Label == "addi") || (Instruction_Label == "xori") || 
(Instruction_Label == "ori") || (Instruction_Label == "andi") || (Instruction_Label == "slli") || 
(Instruction_Label == "srli") || (Instruction_Label == "slti") || (Instruction_Label == "sltiu") ||
(Instruction_Label == "sll") || (Instruction_Label == "slt") || (Instruction_Label == "sltu") || 
(Instruction_Label == "srl") || (Instruction_Label == "auipc") || (Instruction_Label == "lui") ||
(Instruction_Label == "rem") || (Instruction_Label == "sra") || (Instruction_Label == "srai") )
		RY = RZ;

	

	//for lb
	if(Instruction_Label == "lb")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 255;
			bitset<32> Sign_extended_temp(temp);
			for(int i=8; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[7];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 255;
			bitset<32> Sign_extended_temp(temp);
			for(int i=8; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[7];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}
	}



	//for lh
	if(Instruction_Label == "lh")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			bitset<32> Sign_extended_temp(temp);
			for(int i=16; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[15];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			bitset<32> Sign_extended_temp(temp);
			for(int i=16; i<32; i++)
				Sign_extended_temp[i] = Sign_extended_temp[15];

			temp = (int32_t)(Sign_extended_temp.to_ulong());
			RY = temp;
    	}
	}

	// for lw
	if(Instruction_Label == "lw")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			RY = temp;
    	}
    	
	}

	//for lbu
	if(Instruction_Label == "lbu")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 255;
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 255;
			RY = temp;
    	}
	}

	//for lhu
	if(Instruction_Label == "lhu")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Data_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			RY = temp;
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = std::stoul(Stack_Memory_Data[index], nullptr, 16);
			temp &= 65535;
			RY = temp;
    	}
	}

	// for sb
	if(Instruction_Label == "sb")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();
    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 255;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 255;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}
	}

	// for sh
	if(Instruction_Label == "sh")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();
    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 65535;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			temp &= 65535;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}
	}


	// for sw
	if(Instruction_Label == "sw")
	{	string Memory_Address;
		int32_t temp = RZ;
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
    	Memory_Address = stream.str();

    	if(RZ >= 268435456 && RZ <= 268439452)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Data_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Data_Memory_Data[index] = stream1.str();
    	}

    	if(RZ >= 2147479648 && RZ <= 2147483644)
    	{	int index;
			for(index=0; index<1000; index++)
			{	if(Stack_Memory_Address[index] == Memory_Address)
				break;
			}
			temp = RM;
			std::stringstream stream1;
			stream1 << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << temp;
			Stack_Memory_Data[index] = stream1.str();
    	}		
	}

	
}

#endif