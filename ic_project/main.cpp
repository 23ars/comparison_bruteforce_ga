#include <iostream>
#include "BruteForceDLL.h"
#include <cstdio>
#include <ctime>
#include "PerformanceMetricsDll.h"


int main(int argc, char **argv)
{
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
	

	std::string testingString = "testingString";//MUST DELETE
	//BruteForce *bf = new BruteForce();
	//bf->bruteForce(testingString);
	
	
	//delete bf;
	return 0;
}