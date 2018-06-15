#pragma once

#define MEMORY_COUNTER 1000

#define READ       10  
#define WRITE      11  

#define LOAD       20  
#define STORE      21  

#define ADD        30  
#define SUBTRACT   31  
#define DEVIDE     32  
#define MULTIPLY   33  

#define MODULUS    34
#define EXPONENTIATION 35

#define BRANCH     40  
#define BRANCHNEG  41  
#define BRANCHZERO 42  
#define HALT       43 

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

class Simpletron
{
public:
	Simpletron();
	Simpletron(Simpletron &rhs);
	//Simpletron(const int &newAccumulator = +00000, const int &newInstructionCounter = 000,
	//	const int &newInstructionRegister = +00000, const int &newOperationCode = 00,
	//	const int &newOperand = 000, int newMemory[] = {0});
	Simpletron(const int &newAccumulator, const int &newInstructionCounter,
		const int &newInstructionRegister, const int &newOperationCode,
		const int &newOperand, const int newMemory[]);
	~Simpletron();

	void fetch();
	void decode();
	void execute();

	int getOperationCode() const;

	void readIntoInstruction();
	void MakeArray();

private:
	int mAccumulator;
	int mInstructionCounter;
	int mInstructionRegister;
	int mOperationCode;
	int mOperand;
	int mMemory[MEMORY_COUNTER];
};