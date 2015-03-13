#ifdef GADLL_EXPORTS
#define GADLL_API __declspec(dllexport)
#else
#define GADLL_API __declspec(dllimport)
#endif
#define MEMORY_ALLOC(variable,type,size)					(((variable=(type)malloc(size))==NULL)?false:true)
#define MEMORY_REALLOC(variable,initial_variable,type,size)	(((variable=(type)realloc(initial_variable,size))==NULL)?false:true)
#define MEMORY_FREE(variable)								(free((void*)variable))


class GADLL_API CGADll {
public:
	struct _GA_Genome
	{
		std::string str;
		unsigned int fitness;
	};
	struct _GA_Properties
	{
		int GaPopulationSize;
		int GaNumberOfIterations;
		double GaEliteRate;
		double GaMutationRate;
		std::string GaTarget;
	};
	typedef std::vector<_GA_Genome> POPULATION;
	
	CGADll(int populationSize, int numberOfIterations, double eliteRate, double mutationRate, std::string target);
	
	inline virtual ~CGADll()
	{
		MEMORY_FREE(properties);
	}
	void init(POPULATION &population, POPULATION &buffer,size_t targetSize);



protected:
private:
	_GA_Properties *properties;
	
};




