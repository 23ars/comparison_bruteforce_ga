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

static void fitnessFunction(CGADll::POPULATION &population, size_t populationSize,std::string target,size_t size)
{
	size_t targetSize = size;
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
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, target,target.size());

	CGADll::POPULATION pop_alpha, pop_beta;

	CGADll::POPULATION *population, *buffer;

	ClockTicksMetrics performance = ClockTicksMetrics();
	performance.start();

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
	performance.stop();
	std::cout <<"With GA"<< performance;
	delete geneticAlgo;

}

void generateWithBruteForce(std::string target)
{
	ClockTicksMetrics performance = ClockTicksMetrics();
	performance.start();
	BruteForce *bf = new BruteForce();
	bf->bruteForce(target);
	performance.stop();
	std::cout << "With BruteForce" << performance ;
	delete bf;
}

int main(int argc, char **argv)
{
	std::string target = "sex";
	generateWithGA(target);
	generateWithBruteForce(target);
	
	std::getchar();
	return 0;
}