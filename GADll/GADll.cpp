#include "stdafx.h"
#include "GADll.h"

CGADll::CGADll(size_t populationSize, size_t numberOfIterations, double eliteRate, double mutationRate, std::string target)
{
	/*
	if (MEMORY_ALLOC(properties, _GA_Properties*, sizeof(_GA_Properties)) == false)
	{
		std::cerr << "Could not allocate memory!\n";
		exit(1);
	}*/
	properties = new _GA_Properties;
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
	for (indexI = 0; indexI < properties->GaPopulationSize; ++indexI)
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


void CGADll::calculateFitness(POPULATION &population)//TODO:will use a hash function that will come as parameter
{
	std::string target = properties->GaTarget;
	
	size_t targetSize = properties->GaTarget.size();
	unsigned int fitness;

	for (size_t indexI = 0; indexI<properties->GaPopulationSize; indexI++) {
		fitness = 0;
		for (size_t indexJ = 0; indexJ<targetSize; indexJ++) {
			fitness += abs(int(population[indexI].str[indexJ] - target[indexJ]));
		}

		population[indexI].fitness = fitness;
	}
	
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
	size_t targetSize = properties->GaTarget.size();
	size_t position = rand() % targetSize;
	unsigned int delta = (rand() % 90) + 32;

	member.str[position] = ((member.str[position] + delta) % 122);
}

void CGADll::mate(POPULATION &population, POPULATION &buffer)
{
	int esize = (properties->GaPopulationSize)*(properties->GaEliteRate);
	size_t targetSize = properties->GaTarget.size();
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