#include "stdafx.h"
#include "BruteForceParallelisation.h"


BruteForceParallelisation::BruteForceParallelisation()
{
	isWordFound = false;

}
void BruteForceParallelisation::executeTaskInParallel(std::string targetString, std::string availableCharacters, int width, int position, std::string baseString, void(*pThreadConsumer)(int threadNo, std::string,  std::string, int, int, std::string))
{
	size_t numberOfThreads;
	concurrency::parallel_invoke(
		[&]{pThreadConsumer(0,targetString,availableCharacters,width, position, baseString); },
		[&]{pThreadConsumer(1,targetString, availableCharacters, width, position, baseString); }
		);
}

BruteForceParallelisation::~BruteForceParallelisation()
{
	isWordFound = false;
	numberOfPossibleThreads = 0;
}

