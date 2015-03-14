#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>

#include "GADll.h"
#include "PerformanceMetricsDll.h"

#include <cstdio>
#include "sha1.h"

static void fitnessFunction(CGADll::POPULATION &population, size_t populationSize,std::string target)
{
	size_t targetSize = target.size();
	unsigned int fitness;
//	std::string hashedString;
//	std::string	targetString = sha1(target);
	for (size_t indexI = 0; indexI<populationSize; indexI++)
	{
		//hashedString = sha1(population[indexI].str);
		fitness = 0;
		for (size_t indexJ = 0; indexJ<targetSize; indexJ++) 
		{
			
			fitness += abs(int(population[indexI].str[indexJ] - target[indexJ]));
		}

	population[indexI].fitness = fitness;
	}

}

void generateWithGA(std::string targetString)
{
	size_t populationSize = 3000;
	size_t numberOfIterations = 20000;
	double eliteRate = 0.05;
	double mutationRate = 0.25;
	std::string target = targetString;
	srand(unsigned(time(NULL)));
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, target);

	CGADll::POPULATION pop_alpha, pop_beta;

	CGADll::POPULATION *population, *buffer;

	geneticAlgo->init(pop_alpha, pop_beta);
	population = &pop_alpha;
	buffer = &pop_beta;
	for (size_t i = 0; i < numberOfIterations; i++)
	{
		geneticAlgo->calculateFitness(*population, fitnessFunction);
		geneticAlgo->sortByFitness(*population);
		std::cout << *population;
		if ((*population)[0].fitness == 0)
			break;
		geneticAlgo->mate(*population, *buffer);
		geneticAlgo->swap(population, buffer);
	}
	delete geneticAlgo;

}


int main(int argc, char **argv)
{
	generateWithGA("TEST");
	
	std::getchar();
	return 0;
}