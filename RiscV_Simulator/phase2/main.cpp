#include<iostream>
#include<fstream>
#include<stdint.h>
#include "memory.h"
#include "register.h"
#include "pc.h"
#include "file_read.h"
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "memory_access.h"
#include "writeback.h"
#include "cache.h"
using namespace std;

int main(int argc,char* argv[])
{	
	if(argc != 2)
	{	cout<<"Incorrect number of arguments"<<endl;
	    exit(1);	
	}

	int choice;
	cout<<"1. To see the final result press 1"<<endl;
	cout<<"2. To see step by step process press 2"<<endl;
	cin>>choice;
	if(argc == 2)
	{ 	init_Register();
		init_Instruction_Memory();
		init_Data_Memory();
		init_Stack_Memory();
		file_read(argv[1]);
		while(IR!="ENDOFPROGRAM")
		{	fetch();
		 	decode();
		 	execute();
		 	memory_access();
		 	writeback();

		 	if(choice == 2)
		 	{	cout<<"press 2 to continue : ";
		 		cin>>choice;
		 		ofstream file;
		 		file.open("output.txt");

		 		file<<endl<<"Registers:"<<endl;
				for(int i = 0; i < 32; i++)
				{	std::stringstream stream;
					stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << Register[i];
    				string hexval = stream.str();
					file<<"x"<<i<<"		"<<Register[i]<<"		"<<hexval<<endl;
				}
				file<<endl<<endl;
				file<<"Instruction memory section starts here:"<<endl<<endl;
				for(int i = 0; i < 4000; i++)
				{	if(Instruction_Memory_Data[i] != "$")
					file<<Instruction_Memory_Address[i]<<"	"<<Instruction_Memory_Data[i]<<endl;		
				}
				file<<endl<<endl;
				file<<"Data memory section starts here:"<<endl<<endl;
				for(int i = 0; i < 1000; i++)
				{	if(Data_Memory_Data[i] != "$")
					file<<Data_Memory_Address[i]<<"	"<<Data_Memory_Data[i]<<endl;		
				}
				file<<endl<<endl;
				file<<"Stack memory section starts here:"<<endl<<endl;
				for(int i = 0; i < 1000; i++)
				{	if(Stack_Memory_Data[i] != "$")
					file<<Stack_Memory_Address[i]<<"	"<<Stack_Memory_Data[i]<<endl;
				}

		 		file.close();

		 	}


		}

		if(choice == 1)
		{
		cout<<endl<<"Registers:"<<endl;
		for(int i = 0; i < 32; i++)
		{	std::stringstream stream;
			stream << "0x" << std::setfill ('0') << std::setw(sizeof(int32_t)*2) << std::hex << Register[i];
    		string hexval = stream.str();
			cout<<"x"<<i<<"		"<<Register[i]<<"		"<<hexval<<endl;
		}
		cout<<endl<<endl;
		cout<<"Instruction memory section starts here:"<<endl<<endl;
		for(int i = 0; i < 4000; i++)
		{	if(Instruction_Memory_Data[i] != "$")
			cout<<Instruction_Memory_Address[i]<<"	"<<Instruction_Memory_Data[i]<<endl;		
		}
		cout<<endl<<endl;
		cout<<"Data memory section starts here:"<<endl<<endl;
		for(int i = 0; i < 1000; i++)
		{	if(Data_Memory_Data[i] != "$")
			cout<<Data_Memory_Address[i]<<"	"<<Data_Memory_Data[i]<<endl;		
		}
		cout<<endl<<endl;
		cout<<"Stack memory section starts here:"<<endl<<endl;
		for(int i = 0; i < 1000; i++)
		{	if(Stack_Memory_Data[i] != "$")
			cout<<Stack_Memory_Address[i]<<"	"<<Stack_Memory_Data[i]<<endl;
		}

		}
		
	}


	return 0;
}
