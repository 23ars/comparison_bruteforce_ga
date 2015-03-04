#pragma once
class BruteForceParallelisation
{
public:
	BruteForceParallelisation();

	virtual ~BruteForceParallelisation();

	void executeTaskInParallel(std::string availableCharacters, int width, int position, std::string baseString, void(*pThreadConsumer)(int threadNo,std::string, int, int, std::string));

private:
	std::atomic_bool isWordFound;
	INT16 numberOfPossibleThreads;
};

