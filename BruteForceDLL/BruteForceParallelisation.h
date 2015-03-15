#pragma once

struct QuitNow : public std::exception
{
private:std::string message;
public:
	QuitNow(const std::string message) 
	{
		this->message = message; 
	}
	QuitNow(){}
	virtual ~QuitNow() throw() { }
	virtual const char* what() throw()
	{
		return message.c_str();
	}
};

class BruteForceParallelisation
{
public:
	BruteForceParallelisation();

	virtual ~BruteForceParallelisation();

	void executeTaskInParallel(std::string targetString, std::string availableCharacters, int width, int position, std::string baseString, void(*pThreadConsumer)(int threadNo,std::string,  std::string, int, int, std::string));
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

