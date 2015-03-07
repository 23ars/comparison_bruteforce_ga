#ifdef PERFORMANCEMETRICSDLL_EXPORTS
#define PERFORMANCEMETRICSDLL_API __declspec(dllexport)
#else
#define PERFORMANCEMETRICSDLL_API __declspec(dllimport)
#endif


class PERFORMANCEMETRICSDLL_API PerformanceMetrics {
public:
	inline PerformanceMetrics(FILE*outputStream)
	{
		this->outputStream = outputStream;
	}
	inline virtual ~PerformanceMetrics()
	{
		outputStream = stdout;
	}
	void startClockTicksCounter();
	void stopClockTicksCounter();
	void printInformation();

	void startCpuTimeMeasure();
	void stopCpuTimeMeasure();
private:
	double calculateCpuTimeValue();
	FILE *outputStream;
	clock_t clockTicks;
	double cpuTimeValue;

};




