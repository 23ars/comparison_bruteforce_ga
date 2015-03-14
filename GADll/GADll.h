#ifdef GADLL_EXPORTS
#define GADLL_API __declspec(dllexport)
#else
#define GADLL_API __declspec(dllimport)
#endif
#define MEMORY_ALLOC(variable,type)					((variable)=new (std::nothrow)(type))

#define MEMORY_FREE(variable)						(delete (variable))


class GADLL_API CGADll {
public:
	struct _GA_Genome
	{
		std::string str;
		unsigned int fitness;
	};
	struct _GA_Properties
	{
		size_t GaPopulationSize;
		size_t GaNumberOfIterations;
		double GaEliteRate;
		double GaMutationRate;
		std::string GaTarget;
	};

	typedef std::vector<_GA_Genome> POPULATION;
	
	CGADll(size_t populationSize, size_t numberOfIterations, double eliteRate, double mutationRate, std::string target);
	
	inline virtual ~CGADll()
	{
		MEMORY_FREE(properties);
	}
	void init(POPULATION &population, POPULATION &buffer);

	inline void calculateFitness(POPULATION &population, void(*fitnessFunction)(POPULATION &population, size_t populationSize, std::string target))
	{
		fitnessFunction(population, properties->GaPopulationSize, properties->GaTarget);
	}
	inline void sortByFitness(POPULATION &population)
	{
		
		std::sort(population.begin(), population.end(), sortFitness);
		
	}

	void mate(POPULATION &population, POPULATION &buffer);
	inline friend std::ostream& operator<<(std::ostream& out, const POPULATION& p){
		return out << "Best population:" << p[0].str.c_str() << " ( " << p[0].fitness << ")\n";
	}

	inline void swap(POPULATION *&population,POPULATION *&buffer)
	{
		POPULATION *temp = population; population = buffer; buffer = temp;
	}


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




