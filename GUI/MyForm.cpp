#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>

#include "GADll.h"
#include "PerformanceMetricsDll.h"

#include <cstdio>
size_t populationSize;
size_t numberOfIterations;
double eliteRate;
double mutationRate;
std::string bruteforceTargetString;
std::string gaTargetString;


static void fitnessFunction(CGADll::POPULATION &population, size_t populationSize, std::string target, size_t size);
void generateWithGA();
void generateWithBruteForce();

#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;


void Main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MyForm form;
	Application::Run(%form);

}


static void fitnessFunction(CGADll::POPULATION &population, size_t populationSize, std::string target, size_t size)
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


void generateWithGA()
{

	
	srand(unsigned(time(NULL)));
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, gaTargetString, gaTargetString.size());

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
	std::cout << "With GA" << performance;
	delete geneticAlgo;

}


void generateWithBruteForce()
{
	ClockTicksMetrics performance = ClockTicksMetrics();
	performance.start();
	BruteForce *bf = new BruteForce();
	bf->bruteForce(bruteforceTargetString);
	performance.stop();
	std::cout << "With BruteForce" << performance;
	delete bf;
}