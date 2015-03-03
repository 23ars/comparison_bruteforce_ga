#ifdef BRUTEFORCEDLL_EXPORTS
#define BRUTEFORCEDLL_API __declspec(dllexport)
#else
#define BRUTEFORCEDLL_API __declspec(dllimport)
#endif


class BRUTEFORCEDLL_API BruteForce
{
public:
	BruteForce();
	virtual ~BruteForce();
	void bruteForce(std::string generateString);

private:
	void recurse(int width, int position, std::string baseString);
	const std::string availableCharacters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789_-";
};