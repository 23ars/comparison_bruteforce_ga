
#include "stdafx.h"
#include "BruteForceDLL.h"
#include "BruteForceParallelisation.h"

void BruteForce::bruteForce(std::string targetString)
{
	BruteForceParallelisation *parallelBruteforce = new BruteForceParallelisation();
	size_t maxChars = availableCharacters.length();
	for (int i = 0; i < maxChars; i++) {
		std::cout << "Checking with  [" << i << "]..." << std::endl;
		parallelBruteforce->executeTaskInParallel(targetString,availableCharacters, i, 0, "", this->recurse);
	}
	delete parallelBruteforce;
}

void BruteForce::recurse(int threadNo, bool found, std::string targetString, std::string availableCharacters, int width, int position, std::string baseString)
{


	for (size_t i = 0; i < availableCharacters.length() - 1; i += 2)
	{

		if (position < width - 1)
		{
			if (targetString.compare(baseString) == 0)
			{
				found = true;
				std::cout << "String is:" << baseString.c_str();
				std::cout << std::endl;
				break;
				//exit(1);
			}

			std::cout << "CHECKED:" << baseString << std::endl;
			if (threadNo == 0)
			{

				recurse(threadNo, found, targetString, availableCharacters, width, position + 1, baseString + availableCharacters.at(i));
			}
			else
			{

				recurse(threadNo, found, targetString, availableCharacters, width, position + 1, baseString + availableCharacters.at(i + 1));

			}

		}
	}
}