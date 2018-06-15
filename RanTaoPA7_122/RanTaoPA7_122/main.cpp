#include "simpleTron.h"

int main()
{
	int i = 0;
	Simpletron s1;
	s1.readIntoInstruction();

	while(1) {
		s1.fetch();
		s1.decode();
		s1.execute();

		if (s1.getOperationCode() == HALT) 
		{
			s1.MakeArray();
			break;
		}
	}
	return 0;
}