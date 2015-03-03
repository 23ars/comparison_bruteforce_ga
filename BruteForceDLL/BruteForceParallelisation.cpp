#include "stdafx.h"
#include "BruteForceParallelisation.h"


BruteForceParallelisation::BruteForceParallelisation()
{
	isWordFound = false;ff

}
void BruteForceParallelisation::executeTaskInParallel(int width, int position, std::string baseString, void(*pThreadConsumer)(int, int, std::string))
{
	size_t numberOfThreads;
	concurrency::parallel_invoke(
		[&]{pThreadConsumer(width, position, baseString); },
		[&]{pThreadConsumer(width+1, position, baseString); }
		);
	
}

BruteForceParallelisation::~BruteForceParallelisation()
{
	isWordFound = false;
	numberOfPossibleThreads = 0;
}

