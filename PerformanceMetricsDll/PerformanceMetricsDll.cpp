#include "stdafx.h"
#include "PerformanceMetricsDll.h"

void ClockTicksMetrics::start()
{
	clockTicks = clock();
}

void ClockTicksMetrics::stop()
{
	clockTicks = clock() - clockTicks;
}

double CpuTimeMetrics::calculateCpuTimeValue()
{
	FILETIME createTime;
	FILETIME exitTime;
	FILETIME kernelTime;
	FILETIME userTime;
	if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime, &kernelTime, &userTime) != -1)
	{
		SYSTEMTIME userSystemTime;
		if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
			return (double)userSystemTime.wHour * 3600.0 +
			(double)userSystemTime.wMinute * 60.0 +
			(double)userSystemTime.wSecond +
			(double)userSystemTime.wMilliseconds / 1000.0;
	}
	return -1;
}

void CpuTimeMetrics::start()
{

	cpuTimeValue = calculateCpuTimeValue();
}

void CpuTimeMetrics::stop()
{
	cpuTimeValue = calculateCpuTimeValue() - cpuTimeValue;
}



