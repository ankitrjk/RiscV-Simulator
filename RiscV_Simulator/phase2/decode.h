#ifndef DECODE_H_
#define DECODE_H_
#include<sstream>
#include<bitset>
#include<string>
#include<stdint.h>
#include "register.h"

void decode()
{	string temp = IR;
    stringstream ss;
    ss << hex << temp;
    unsigned n;
    ss >> n;
    bitset<32> machine_code(n);
    bitset<32> opcode_extraction(127);
    bitset<32> machine_code_opcode;
    machine_code_opcode = machine_code & opcode_extraction;
    bitset<32> func3_extraction(28672);
    bitset<32> machine_code_func3;
    machine_code_func3 = machine_code & func3_extraction;
    bitset<32> func7_extraction(4261412864);
    bitset<32> machine_code_func7;
    machine_code_func7 = machine_code & func7_extraction;
    bitset<32> rs1_extraction(1015808);
    bitset<32> machine_code_rs1;
    machine_code_rs1 = machine_code & rs1_extraction;
    machine_code_rs1 >>= 15;
    bitset<32> rs2_extraction(32505856);
    bitset<32> machine_code_rs2;
    machine_code_rs2 = machine_code & rs2_extraction;
    machine_code_rs2 >>= 20;
    bitset<32> rd_extraction(3968);
    bitset<32> machine_code_rd;
    machine_code_rd = machine_code & rd_extraction;
    machine_code_rd >>= 7;
    // IMMEDIATE for I-type
    bitset<32> imm_extraction(4293918720);
    bitset<32> machine_code_imm;
    machine_code_imm = machine_code & imm_extraction;
    machine_code_imm >>= 20;
    bitset<32> machine_code_imm_unsigned;
    machine_code_imm_unsigned = machine_code_imm; 
    //sign extension
    for(int i=12; i<16; i++)
			machine_code_imm[i] = machine_code_imm[11];

    // R-type
    //for add
    bitset<32> opcode(51);
    bitset<32> func3(0);
    bitset<32> func7(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "add";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }


    //for sub 
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sub";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for and
    opcode = bitset<32>(51);
    func3 = bitset<32>(28672);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "and";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for or
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "or";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xor
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "xor";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sll
    opcode = bitset<32>(51);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sll";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for srl
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "srl";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sra
    opcode = bitset<32>(51);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sra";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for slt
    opcode = bitset<32>(51);
    func3 = bitset<32>(8192);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "slt";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }

    //for sltu
    opcode = bitset<32>(51);
    func3 = bitset<32>(12288);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "sltu";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
    }




	//for mul
    opcode = bitset<32>(51);
    func3 = bitset<32>(0);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "mul";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for div
    opcode = bitset<32>(51);
    func3 = bitset<32>(16384);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "div";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for rem
    opcode = bitset<32>(51);
    func3 = bitset<32>(24576);
    func7 = bitset<32>(33554432);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7))
    {	Instruction_Label = "rem";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}


    //I-type
    //for addi
    opcode = bitset<32>(19);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "addi";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for xori
    opcode = bitset<32>(19);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "xori";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for ori
    opcode = bitset<32>(19);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "ori";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for andi
    opcode = bitset<32>(19);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "andi";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for slli
    opcode = bitset<32>(19);
    func3 = bitset<32>(4096);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "slli";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(slli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for srli
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srli";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srli)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for srai
    opcode = bitset<32>(19);
    func3 = bitset<32>(20480);
    func7 = bitset<32>(1073741824);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3) && (machine_code_func7 == func7) )
    {	Instruction_Label = "srai";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int imm_value = (int)(machine_code_rs2.to_ulong());
    	IMMEDIATE = imm_value;

    	if(IMMEDIATE < 0 || IMMEDIATE > 31)
    	{	cout<<"Immediate value out of range(srai)"<<endl;
    		exit(1);
    	}

    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for slti
    opcode = bitset<32>(19);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "slti";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for sltiu
    opcode = bitset<32>(19);
    func3 = bitset<32>(12288);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sltiu";
    	int rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	uint16_t temp = (uint16_t)imm_value;
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lb
    opcode = bitset<32>(3);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lb";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lh
    opcode = bitset<32>(3);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lh";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for lw
    opcode = bitset<32>(3);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lw";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lbu
    opcode = bitset<32>(3);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lbu";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

	//for lhu
    opcode = bitset<32>(3);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "lhu";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //for jalr
    opcode = bitset<32>(103);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "jalr";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int16_t imm_value = (int16_t)(machine_code_imm.to_ulong());
    	IMMEDIATE = imm_value;
    	RD_INDEX = (int)(machine_code_rd.to_ulong());
	}

    //S-type
    //for sw
    opcode = bitset<32>(35);
    func3 = bitset<32>(8192);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sw";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;

    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //for sb
    opcode = bitset<32>(35);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sb";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}

	//for sh
    opcode = bitset<32>(35);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "sh";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_temp;
    	machine_code_imm_temp = machine_code_func7 >> 20; //imm part 2 shifted
    	machine_code_imm_temp = machine_code_imm_temp | machine_code_rd;
   
    	for(int i=12; i<16; i++)
			machine_code_imm_temp[i] = machine_code_imm_temp[11];	

    	int16_t imm_value = (int16_t)(machine_code_imm_temp.to_ulong());
    	IMMEDIATE = imm_value;	
	}
	
    //UJ-type
    //for jal
    opcode = bitset<32>(111);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "jal";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(2145386496);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [21:30] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(1048576);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[20] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(1044480);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[12:19] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 20;
		machine_code_imm_part2 = machine_code_imm_part2 >> 9;
		machine_code_imm_part4 = machine_code_imm_part4 >> 11;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=21; i<32; i++)
			machine_code_imm_final[i] = machine_code_imm_final[20];	

		int32_t imm_value = (int32_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //U-type
    //for auipc
    opcode = bitset<32>(23);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "auipc";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(auipc)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

	//for lui
    opcode = bitset<32>(55);
    if((machine_code_opcode == opcode))
    {	Instruction_Label = "lui";
		RD_INDEX = (int)(machine_code_rd.to_ulong());
		bitset<32> machine_code_offset;
		bitset<32> machine_code_offset_extraction(4294963200);
		machine_code_offset = machine_code & machine_code_offset_extraction; //[12:31]
		int bound_check = (int)(machine_code_offset.to_ulong()); 
		bound_check = bound_check >> 12;
		if(bound_check < 0 || bound_check > 1048575)
    	{	cout<<"Immediate value out of range(lui)"<<endl;
    		exit(1);
    	}
		int imm_value = (int)(machine_code_offset.to_ulong());
		IMMEDIATE = imm_value;
	}

    //SB-type
    //for beq
    opcode = bitset<32>(99);
    func3 = bitset<32>(0);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "beq";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bne
    opcode = bitset<32>(99);
    func3 = bitset<32>(4096);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bne";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for blt
    opcode = bitset<32>(99);
    func3 = bitset<32>(16384);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "blt";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bge
    opcode = bitset<32>(99);
    func3 = bitset<32>(20480);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bge";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	RA = Register[rs1_index];
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	RB = Register[rs2_index];
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bltu
    opcode = bitset<32>(99);
    func3 = bitset<32>(24576);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bltu";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}

    //for bgeu
    opcode = bitset<32>(99);
    func3 = bitset<32>(28672);
    if((machine_code_opcode == opcode) && (machine_code_func3 == func3))
    {	Instruction_Label = "bgeu";
		int rs1_index = (int)(machine_code_rs1.to_ulong());
    	int32_t temp1 = Register[rs1_index];
    	uint32_t RA = (uint32_t)temp1;
    	int rs2_index = (int)(machine_code_rs2.to_ulong());
    	int32_t temp2 = Register[rs2_index];
    	uint32_t RB = (uint32_t)temp2;
    	bitset<32> machine_code_imm_part1;
		bitset<32> machine_code_imm_part1_extraction(3840);
		machine_code_imm_part1 = machine_code & machine_code_imm_part1_extraction; // [8:11] machine code
		bitset<32> machine_code_imm_part2;
		bitset<32> machine_code_imm_part2_extraction(2113929216);
		machine_code_imm_part2 = machine_code & machine_code_imm_part2_extraction; //[25:30] machine code
		bitset<32> machine_code_imm_part3;
		bitset<32> machine_code_imm_part3_extraction(128);
		machine_code_imm_part3 = machine_code & machine_code_imm_part3_extraction; //[7] machine code
		bitset<32> machine_code_imm_part4;
		bitset<32> machine_code_imm_part4_extraction(2147483648);
		machine_code_imm_part4 = machine_code & machine_code_imm_part4_extraction; //[31] machine code
		machine_code_imm_part1 = machine_code_imm_part1 >> 7;
		machine_code_imm_part2 = machine_code_imm_part2 >> 20;
		machine_code_imm_part3 = machine_code_imm_part3 << 4;
		machine_code_imm_part4 = machine_code_imm_part4 >> 19;
		bitset<32> machine_code_imm_final;
		machine_code_imm_final = machine_code_imm_part1 | machine_code_imm_part2;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part3;
		machine_code_imm_final = machine_code_imm_final | machine_code_imm_part4;

		for(int i=13; i<16; i++)
			machine_code_imm_final[i] = machine_code_imm_final[12];	

		int16_t imm_value = (int16_t)(machine_code_imm_final.to_ulong());
    	IMMEDIATE = imm_value;
	}
}


#endif
