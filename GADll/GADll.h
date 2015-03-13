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
		std::string GaTarget;//will be the HASH
	};
	typedef std::vector<_GA_Genome> POPULATION;
	
	CGADll(int populationSize, int numberOfIterations, double eliteRate, double mutationRate, std::string target);
	
	inline virtual ~CGADll()
	{
		MEMORY_FREE(properties);
	}
	void init(POPULATION &population, POPULATION &buffer,size_t targetSize);

	void calculateFitness(POPULATION &population);

	inline void sortByFitness(POPULATION &population)
	{
		
		std::sort(population.begin(), population.end(), sortFitness);
		
	}

	void mate(POPULATION &population, POPULATION &buffer);
protected:
private:
	inline static bool sortFitness(_GA_Genome x, _GA_Genome y)
	{
		return (x.fitness < y.fitness);
	}
	
	void elitism(POPULATION &population, POPULATION &buffer, size_t esize);

	void mutate(_GA_Genome &member);

	_GA_Properties *properties;
	
};




