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
		size_t GaPopulationSize;
		size_t GaNumberOfIterations;
		double GaEliteRate;
		double GaMutationRate;
		std::string GaTarget;//TODO:will be the HASH
	};
	typedef std::vector<_GA_Genome> POPULATION;
	
	CGADll(size_t populationSize, size_t numberOfIterations, double eliteRate, double mutationRate, std::string target);
	
	inline virtual ~CGADll()
	{
		//MEMORY_FREE(properties);
		delete properties;
	}
	void init(POPULATION &population, POPULATION &buffer,size_t targetSize);

	void calculateFitness(POPULATION &population);

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




