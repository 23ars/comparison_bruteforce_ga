
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
	for (int i = 0; i < maxChars; i+=2) {
		std::cout << "Checking with  [" << i << "]..." << std::endl;
		
		parallelBruteforce->executeTaskInParallel(i, 0, "", &BruteForceDll::recurse);

	}
	delete parallelBruteforce;
}

void BruteForce::recurse(int width, int position, std::string baseString)
{
	for (size_t i = 0; i < availableCharacters.length(); i++)
	{
		if (position < width - 1)
		{
			//std::cout << "CHECKED:" << baseString << std::endl;
			recurse(width, position + 1, baseString + availableCharacters.at(i));
		}
	}
}