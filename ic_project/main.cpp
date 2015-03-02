#include <iostream>
#include "BruteForceDLL.h"
#include <thread>

int main(int argc, char **argv)
{
	
	

	std::string ana = "ana";//MUST DELETE
	BruteForce *bf = new BruteForce();
	bf->bruteForce(ana);
	
	
	delete bf;
	return 0;
}