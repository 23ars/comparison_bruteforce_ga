#include "stdafx.h"
#include "GADll.h"

CGADll::CGADll(size_t populationSize, size_t numberOfIterations, double eliteRate, double mutationRate, std::string target,size_t targetSize)
{
	
	MEMORY_ALLOC(properties, _GA_Properties);
	properties->GaPopulationSize = populationSize;
	properties->GaNumberOfIterations = numberOfIterations;
	properties->GaEliteRate = eliteRate;
	properties->GaMutationRate = mutationRate;
	properties->GaTarget = target;
	properties->GaTargetSize = targetSize;
	

}
void CGADll::init(POPULATION &population, POPULATION &buffer)
{
	size_t indexI;
	size_t indexJ;
	for (indexI = 0; indexI < properties->GaPopulationSize; ++indexI)
	{
		_GA_Genome citizen;
		citizen.fitness = 0;
		citizen.str.erase();
		for (indexJ = 0; indexJ < properties->GaTargetSize; ++indexJ)
		{
			citizen.str += (rand() % 90) + 32;
		}
		population.push_back(citizen);
	}
	buffer.resize(properties->GaPopulationSize);
}


void CGADll::elitism(POPULATION &population, POPULATION &buffer, size_t esize)
{
	for (size_t index=0; index < esize; ++index)
	{
		buffer[index].str = population[index].str;
		buffer[index].fitness = population[index].fitness;
	}
}

void CGADll::mutate(_GA_Genome &member)
{
	size_t targetSize = properties->GaTargetSize;
	size_t position = rand() % targetSize;
	unsigned int delta = (rand() % 90) + 32;

	member.str[position] = ((member.str[position] + delta) % 122);
}

void CGADll::mate(POPULATION &population, POPULATION &buffer)
{
	int esize = (properties->GaPopulationSize)*(properties->GaEliteRate);
	size_t targetSize = properties->GaTargetSize;
	size_t spos, i1, i2;
	elitism(population, buffer, esize);
	for (size_t index = esize; index < properties->GaPopulationSize; index++)
	{
		i1 = rand() % (properties->GaPopulationSize / 2);
		i2 = rand() % (properties->GaPopulationSize / 2);
		spos = rand() % targetSize;
		buffer[index].str = population[i1].str.substr(0, spos) + population[i2].str.substr(spos, esize - spos);
		if (rand() < properties->GaMutationRate)
		{
			mutate(buffer[index]);
		}
	}
}