#include "stdafx.h"
#include "GADll.h"

CGADll::CGADll(int populationSize, int numberOfIterations, double eliteRate, double mutationRate, std::string target)
{
	if (MEMORY_ALLOC(properties, _GA_Properties*, sizeof(_GA_Properties)) == false)
	{
		std::cerr << "Could not allocate memory!\n";
		exit(1);
	}
	srand(time(NULL));
	properties->GaPopulationSize = populationSize;
	properties->GaNumberOfIterations = numberOfIterations;
	properties->GaEliteRate = eliteRate;
	properties->GaMutationRate = mutationRate;
	properties->GaTarget = target;

}
void CGADll::init(POPULATION &population, POPULATION &buffer,size_t targetSize)
{
	size_t indexI;
	size_t indexJ;
	for (indexI = 0; indexI < targetSize; ++indexI)
	{
		_GA_Genome citizen;
		citizen.fitness = 0;
		citizen.str.erase();
		for (indexJ = 0; indexJ < targetSize; ++indexJ)
		{
			citizen.str += (rand() % 90) + 32;
		}
		population.push_back(citizen);
	}
	buffer.resize(properties->GaPopulationSize);
}