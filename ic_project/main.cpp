#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include "PerformanceMetricsDll.h"


int main(int argc, char **argv)
{
	PerformanceMetrics *pf = new PerformanceMetrics(stdout);
	pf->startCpuTimeMeasure();
	int i = 0;
	for (int i = 0; i < 1000000; i++){
		_asm{
			NOP	;; doing a no operation to avoid optimization by the compiler.
				;;operation made just for testing
			
		}
		
	}
	pf->stopCpuTimeMeasure();
	pf->printInformation();

	std::string testingString = "testingString";//MUST DELETE
	//BruteForce *bf = new BruteForce();
	//bf->bruteForce(testingString);
	
	
	//delete bf;
	return 0;
}