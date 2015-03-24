#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
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
void generateWithGA(System::Windows::Forms::TextBox^  textBox, CpuTimeMetrics performance);
void generateWithGA(System::Windows::Forms::TextBox^  textBox, ClockTicksMetrics performance);
void generateWithBruteForce(System::Windows::Forms::TextBox^  textBox, ClockTicksMetrics whatPerformance);
void generateWithBruteForce(System::Windows::Forms::TextBox^  textBox, CpuTimeMetrics performance);

#include "ThreadWork.h"

#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;



[STAThreadAttribute]
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
	for (size_t indexI = 0; indexI < populationSize; indexI++)
	{
		//hashedString = sha1(population[indexI].str);
		fitness = 0;
		for (size_t indexJ = 0; indexJ < targetSize; indexJ++)
		{

			fitness += abs(int(population[indexI].str[indexJ] - target[indexJ]));
		}

		population[indexI].fitness = fitness;
	}

}


void generateWithGA(System::Windows::Forms::TextBox^  textBox, CpuTimeMetrics performance)
{

	srand(unsigned(time(NULL)));
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, gaTargetString, gaTargetString.size());

	CGADll::POPULATION pop_alpha, pop_beta;

	CGADll::POPULATION *population, *buffer;


	performance.start();

	geneticAlgo->init(pop_alpha, pop_beta);
	population = &pop_alpha;
	buffer = &pop_beta;

	for (size_t i = 0; i < numberOfIterations; i++)
	{
		geneticAlgo->calculateFitness(*population, fitnessFunction);
		geneticAlgo->sortByFitness(*population);

		textBox->Text += gcnew String(geneticAlgo->printResult(*population).c_str()) + "\r\n";
		if ((*population)[0].fitness == 0)
			break;
		geneticAlgo->mate(*population, *buffer);
		geneticAlgo->swap(population, buffer);
	}
	performance.stop();
	textBox->Text += gcnew String(performance.printResult().c_str());
	delete geneticAlgo;

}

void generateWithGA(System::Windows::Forms::TextBox^  textBox, ClockTicksMetrics performance)
{

	srand(unsigned(time(NULL)));
	CGADll *geneticAlgo = new CGADll(populationSize, numberOfIterations, eliteRate, mutationRate, gaTargetString, gaTargetString.size());

	CGADll::POPULATION pop_alpha, pop_beta;

	CGADll::POPULATION *population, *buffer;


	performance.start();

	geneticAlgo->init(pop_alpha, pop_beta);
	population = &pop_alpha;
	buffer = &pop_beta;

	for (size_t i = 0; i < numberOfIterations; i++)
	{
		geneticAlgo->calculateFitness(*population, fitnessFunction);
		geneticAlgo->sortByFitness(*population);

		textBox->Text += gcnew String(geneticAlgo->printResult(*population).c_str()) + "\r\n";
		if ((*population)[0].fitness == 0)
			break;
		geneticAlgo->mate(*population, *buffer);
		geneticAlgo->swap(population, buffer);
	}
	performance.stop();
	textBox->Text += gcnew String(performance.printResult().c_str());
	delete geneticAlgo;

}


void generateWithBruteForce(System::Windows::Forms::TextBox^  textBox, CpuTimeMetrics performance)
{


	performance.start();
	BruteForce *bf = new BruteForce();
	bf->bruteForce(bruteforceTargetString);
	textBox->Text += "String is:" + gcnew String(bf->getGeneratedString().c_str()) + "\r\n";
	performance.stop();
	textBox->Text += gcnew String(performance.printResult().c_str());
	delete bf;
}

void generateWithBruteForce(System::Windows::Forms::TextBox^  textBox, ClockTicksMetrics performance)
{


	performance.start();
	BruteForce *bf = new BruteForce();
	bf->bruteForce(bruteforceTargetString);
	textBox->Text += "String is:" + gcnew String(bf->getGeneratedString().c_str()) + "\r\n";
	performance.stop();
	textBox->Text += gcnew String(performance.printResult().c_str());
	delete bf;
}
