#pragma once
class BruteForceParallelisation
{
public:
	BruteForceParallelisation();

	virtual ~BruteForceParallelisation();

	void executeTaskInParallel(int width, int position, std::string baseString, void(*pThreadConsumer)(int, int, std::string));

private:
	std::atomic_bool isWordFound;
	INT16 numberOfPossibleThreads;
};

