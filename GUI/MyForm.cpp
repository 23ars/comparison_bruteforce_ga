#include <iostream>

size_t populationSize;
size_t numberOfIterations;
double eliteRate;
double mutationRate;
std::string bruteforceTargetString;
std::string gaTargetString;
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
