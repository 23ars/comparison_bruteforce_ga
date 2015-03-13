
#ifdef GADLL_EXPORTS
#define GADLL_API __declspec(dllexport)
#else
#define GADLL_API __declspec(dllimport)
#endif


class GADLL_API CGADll {
public:
	CGADll(void);

};




