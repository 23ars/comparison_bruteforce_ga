
#include "stdafx.h"
#include "BruteForceDLL.h"
#include "BruteForceParallelisation.h"


void BruteForce::bruteForce(std::string targetString)
{
	BruteForceParallelisation *parallelBruteforce = new BruteForceParallelisation();
	size_t maxChars = availableCharacters.length();
	for (int i = 0; i < maxChars; i++) {
		//std::cout << "Checking with  [" << i << "]..." << std::endl;
		try
		{
			parallelBruteforce->executeTaskInParallel(targetString,availableCharacters, i, 0, "", this->recurse);
		}
		catch (QuitNow e)
		{ 
			generatedString = e.what();
			goto end;
		}
	}
	end:
	delete parallelBruteforce;
}

void BruteForce::recurse(int threadNo, std::string targetString, std::string availableCharacters, int width, int position, std::string baseString)
{
	static bool isWordFound = false;

	for (size_t i = 0; i < availableCharacters.length() - 1; i += 2)
	{	
		
		if (position < width - 1)
		{
	
			recurse(threadNo, targetString, availableCharacters, width, position + 1, baseString + availableCharacters.at(i + threadNo));
		
		}
		
		if (targetString.compare(baseString) == 0)
		{
			isWordFound = false;
			//std::cout << "String is:" << baseString.c_str();
			
			throw QuitNow(baseString);//TODO:Know that I should not use the exceptions mecanism for stopping recursion
		}
	}

}