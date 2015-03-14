#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>

#include "GADll.h"
#include "PerformanceMetricsDll.h"

#include <cstdio>

int main(int argc, char **argv)
{
	/*
	ClockTicksMetrics pf = ClockTicksMetrics();//new CpuTimeMetrics(stdout);

	pf.start();
	int i = 0;
	for (int i = 0; i < 1000000; i++){
		//std::cout << "TEST";
		_asm{
			NOP	;; doing a no operation to avoid optimization by the compiler.
				;;operation made just for testing
			
		}
		
	}
	
	pf.stop();
	std::cout << pf;
	
	*/
	
	//BruteForce *bf = new BruteForce();
	//bf->bruteForce(testingString);
	
	
	//delete bf;

	size_t populationSize = 3000;
	size_t numberOfIterations = 20000;
	double eliteRate = 0.05;
	double mutationRate = 0.25;
	std::string target = "la dracu";
	srand(unsigned(time(NULL)));
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, target);
	
	CGADll::POPULATION pop_alpha, pop_beta;
	
	CGADll::POPULATION *population, *buffer;
	
	geneticAlgo->init(pop_alpha, pop_beta,target.size());
	population = &pop_alpha;
	buffer = &pop_beta;
	for (size_t i = 0; i < numberOfIterations; i++)
	{
		geneticAlgo->calculateFitness(*population);
		geneticAlgo->sortByFitness(*population);
		std::cout << *population;
		if ((*population)[0].fitness == 0)
			break;
		geneticAlgo->mate(*population, *buffer);
		geneticAlgo->swap(population, buffer);
	}
	delete geneticAlgo;
	std::getchar();
	return 0;
}