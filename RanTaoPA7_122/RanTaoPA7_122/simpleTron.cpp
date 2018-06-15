#include "simpleTron.h"

Simpletron::Simpletron()
{
	mAccumulator = 0;
	mInstructionCounter = 0;
	mInstructionRegister = 0;
	mOperationCode = 0;
	mOperand = 0;
	for (int i = 0; i < MEMORY_COUNTER; ++i)
	{
		mMemory[i] = 0;
	}
}

Simpletron::Simpletron(Simpletron & rhs)
{
	mAccumulator = rhs.mAccumulator;
	mInstructionCounter = rhs.mInstructionCounter;
	mInstructionRegister = rhs.mInstructionRegister;
	mOperationCode = rhs.mOperationCode;
	mOperand = rhs.mOperand;
	for (int i = 0; i < MEMORY_COUNTER; ++i)
	{
		mMemory[i] = rhs.mMemory[i];
	}
}

Simpletron::Simpletron(const int & newAccumulator, const int & newInstructionCounter, const int & newInstructionRegister, const int & newOperationCode, const int & newOperand, const int newMemory[])
{
	mAccumulator = newAccumulator;
	mInstructionCounter = newInstructionCounter;
	mInstructionRegister = newInstructionRegister;
	mOperationCode = newOperationCode;
	mOperand = newOperand;
	for (int i = 0; i < MEMORY_COUNTER; ++i)
	{
		mMemory[i] = newMemory[i];
	}

}

Simpletron::~Simpletron()
{
}

void Simpletron::fetch()
{
	mInstructionRegister = mMemory[mInstructionCounter];
}

void Simpletron::decode()
{
	mOperationCode = mInstructionRegister / MEMORY_COUNTER;
	mOperand = mInstructionRegister % MEMORY_COUNTER;
	if (mOperand < 0 || mOperand >MEMORY_COUNTER-1)
		//exception(EXCEPTION_ERROR_OPERAND);
		cout << "EXCEPTION_ERROR_OPERAND" << endl;
}

void Simpletron::execute()
{
	switch(mOperationCode)
	{
	case READ:
		cout << "Enter a number: ";
		cin >> mMemory[mOperand];//read data from std input  
		if (mMemory[mOperand] < -99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_INPUT_DATA);
			cout << "EXCEPTION_INPUT_DATA" << endl;
			break;
		}
		mInstructionCounter++;
		break;
	case WRITE:    //write data to std output  
		cout << "you got: " <<mMemory[mOperand] << endl;
		mInstructionCounter++;
		break;

	case LOAD:    //add data to accumulator from memory  
		mAccumulator = mMemory[mOperand];
		mInstructionCounter++;
		break;

	case STORE:    //transfer data of accumulator to memory  
		mMemory[mOperand] = mAccumulator;
		mInstructionCounter++;
		break;

	case ADD:    //data of accumulator add to memory data  
		mAccumulator += mMemory[mOperand];
		if (mMemory[mOperand]<-99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_OUT_ACCUMULATOR);
			cout << "EXCEPTION_OUT_ACCUMULATOR" << endl;
			break;
		}
		mInstructionCounter++;

		break;

	case SUBTRACT:    //data of accumulator subtract memory data  
		mAccumulator -= mMemory[mOperand];
		if (mMemory[mOperand]<-99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_OUT_ACCUMULATOR);
			cout << "EXCEPTION_OUT_ACCUMULATOR" << endl;
			break;
		}
		mInstructionCounter++;
		break;

	case MULTIPLY:    //data of accumulator multiply memory data  
		mAccumulator *= mMemory[mOperand];
		if (mMemory[mOperand]<-99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_OUT_ACCUMULATOR);
			cout << "EXCEPTION_OUT_ACCUMULATOR" << endl;
			break;
		}
		mInstructionCounter++;
		break;

	case DEVIDE:    //data of accumulator divide memory data  
		mAccumulator /= mMemory[mOperand];
		if (mMemory[mOperand] == 0)
		{
			//exception(EXCEPTION_ERROR_DIVIDED);
			cout << "EXCEPTION_ERROR_DIVIDED" << endl;
			break;
		}
		mInstructionCounter++;
		break;

	case MODULUS:
		mAccumulator %= mMemory[mOperand];
		if (mMemory[mOperand]<-99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_OUT_ACCUMULATOR);
			cout << "EXCEPTION_OUT_ACCUMULATOR" << endl;
			break;
		}
		mInstructionCounter++;
		break;

	case EXPONENTIATION:
		mAccumulator = pow(mAccumulator, mOperand);
		if (mMemory[mOperand]<-99999 || mMemory[mOperand]>99999)
		{
			//exception(EXCEPTION_OUT_ACCUMULATOR);
			cout << "EXCEPTION_OUT_ACCUMULATOR" << endl;
			break;
		}
		mInstructionCounter++;
		break;

	case BRANCH:
		mInstructionCounter = mOperand;
		break;

	case BRANCHNEG:     //if accumulator less than zero,  //if accumulator equal to  zero, transfer memory  
		if (mAccumulator < 0)
			mInstructionCounter = mOperand;
		else
			mInstructionCounter++;
		break;

	case BRANCHZERO:    //if accumulator equal to  zero, transfer memory  
		if (mAccumulator == 0)
			mInstructionCounter = mOperand;
		else
			mInstructionCounter++;
		break;

	case HALT:    //if operation code equal to 43, break program 
		
		cout << endl << "*** Simpletron execution terminated ***" << endl;
		break;

	default:    //carry out other instruction code 
		//exception(EXCEPTION_INSRUCTION);
		cout << "EXCEPTION_INSRUCTION" << endl;
		break;

	}

}

int Simpletron::getOperationCode() const
{
	return mOperationCode;
}

void Simpletron::readIntoInstruction()
{
	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << "*** Please enter your program one istruction ***" << endl;
	cout << "*** (or data word) at a time .I will type the ***" << endl;
	cout << "*** Location number and a question mark(?). ***" << endl;
	cout << "*** You then tupe the word for that location. ***" << endl;
	cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
	cout << "*** You program. ***" << endl;
	ifstream input;
	int i = 0;
	input.open("Example1.sml");
	while (1)
	{
		while (!input.eof())
		{
			cout << i << " ? ";
			input >> mMemory[i];
			cout << mMemory[i] << endl;
			if (mMemory[i] == -99999)
			{
				cout << "*** Program loading completed ***" << endl;
				cout << "*** Program execution begins ***" << endl;
				break;
			}
			i++;
		}
		break;
	}
	input.close();
}

void Simpletron::MakeArray()
{
	int i=0, j=0, k=0, l=0, m=0, n=0;
	cout << endl;
	cout << "accumulator              " << mAccumulator << endl;
	cout << "instructionCounter       " << mInstructionCounter << endl;
	cout << "instructionRegister      " << mInstructionRegister << endl;
	cout << "operationCode            " << mOperationCode << endl;
	cout << "operand                  " << mOperand << endl;

	cout << "memory: " << endl;
	printf("%2c", ' ');

	for (i = 0; i < MEMORY_COUNTER / 100; i++)
	{
		//cout << l;
		printf("%8d", l);
		l++;
	}
	cout << endl << endl;

	for (j = 0; j < MEMORY_COUNTER / 10; j++)
	{
		//cout << m;
		printf("%3d", m);
		m += 10;
		for (k = 0; k < MEMORY_COUNTER / 100; k++)
		{
			if (mMemory[n] == 0)//cout << " +0000";
				printf("%3c%c%c%c%c%c%c", ' ', '+', '0', '0', '0', '0', '0');
				
			else//cout << mMemory[n];
			printf("%8d", mMemory[n]);
			n++;
		}
		cout << endl;
	}
}
