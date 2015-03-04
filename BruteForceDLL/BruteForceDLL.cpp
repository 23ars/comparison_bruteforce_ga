
#include "stdafx.h"
#include "BruteForceDLL.h"
#include "BruteForceParallelisation.h"

BruteForce::BruteForce()
{
}

BruteForce::~BruteForce()
{
}

void BruteForce::bruteForce(std::string generatedString)
{
	BruteForceParallelisation *parallelBruteforce = new BruteForceParallelisation();
	size_t maxChars = availableCharacters.length();
	for (int i = 0; i < maxChars; i++) {
		std::cout << "Checking with  [" << i << "]..." << std::endl;
		
		parallelBruteforce->executeTaskInParallel(availableCharacters,i, 0, "", this->recurse);
	
	}
	delete parallelBruteforce;
}

void BruteForce::recurse(int threadNo, std::string availableCharacters, int width, int position, std::string baseString)
{	
	for (size_t i = 0; i < availableCharacters.length()-1; i+=2)
	{
		
		if (position < width - 1)
		{
			std::cout << "CHECKED:" << baseString << std::endl;
			if (threadNo==0)
				recurse(threadNo,availableCharacters, width, position + 1, baseString + availableCharacters.at(i));
			else
				recurse(threadNo, availableCharacters, width, position +1, baseString + availableCharacters.at(i+1));
		}
	}
}