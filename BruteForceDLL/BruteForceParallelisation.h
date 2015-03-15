#pragma once
class BruteForceParallelisation
{
public:
	BruteForceParallelisation();

	virtual ~BruteForceParallelisation();

	void executeTaskInParallel(std::string targetString, std::string availableCharacters, int width, int position, std::string baseString, void(*pThreadConsumer)(int threadNo, bool found, std::string,  std::string, int, int, std::string));
	inline std::atomic_bool getIsWordFound()
	{
		return isWordFound;
	}
	inline void setIsWordFound(bool value)
	{
		isWordFound = value;
	}
private:
	std::atomic_bool isWordFound;
	INT16 numberOfPossibleThreads;
};

