#include "stdafx.h"
#include "GADll.h"

CGADll::CGADll(int populationSize, int numberOfIterations, double eliteRate, double mutationRate, std::string target)
{
	if (MEMORY_ALLOC(properties, _GA_Properties*, sizeof(_GA_Properties)) == false)
	{
		std::cerr << "Could not allocate memory!\n";
		exit(1);
	}
	properties->GaPopulationSize = populationSize;
	properties->GaNumberOfIterations = numberOfIterations;
	properties->GaEliteRate = eliteRate;
	properties->GaMutationRate = mutationRate;
	properties->GaTarget = target;

	srand(time(NULL));

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


void CGADll::calculateFitness(POPULATION &population)//will use a hash function that will come as parameter
{
	std::string target = properties->GaTarget;
	/*
	int tsize = target.size();
	unsigned int fitness;

	for (int i = 0; i<GA_POPSIZE; i++) {
		fitness = 0;
		for (int j = 0; j<tsize; j++) {
			fitness += abs(int(population[i].str[j] - target[j]));
		}

		population[i].fitness = fitness;
	}
	*/
}
void CGADll::elitism(POPULATION &population, POPULATION &buffer, size_t esize)
{
	for (size_t index; index < esize; ++index)
	{
		buffer[index].str = population[index].str;
		buffer[index].fitness = population[index].fitness;
	}
}

void CGADll::mutate(_GA_Genome &member)
{
	size_t targetSize = properties->GaTarget.size();
	size_t position = rand() % targetSize;
	unsigned int delta = (rand() % 90) + 32;

	member.str[position] = ((member.str[position] + delta) % 122);
}