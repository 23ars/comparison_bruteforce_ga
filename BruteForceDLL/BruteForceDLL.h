#ifdef BRUTEFORCEDLL_EXPORTS
#define BRUTEFORCEDLL_API __declspec(dllexport)
#else
#define BRUTEFORCEDLL_API __declspec(dllimport)
#endif


class BRUTEFORCEDLL_API BruteForce
{
public:
	inline BruteForce()
	{
		
	}
	inline virtual ~BruteForce()
	{

	}
	void bruteForce(std::string targetString);

private:
	
	static void recurse(int threadNo, std::string targetString , std::string availableCharacters, int width, int position, std::string baseString);
	const std::string availableCharacters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789_-";
	
};