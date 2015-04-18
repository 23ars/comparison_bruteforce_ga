#ifdef PERFORMANCEMETRICSDLL_EXPORTS
#define PERFORMANCEMETRICSDLL_API __declspec(dllexport)
#else
#define PERFORMANCEMETRICSDLL_API __declspec(dllimport)
#endif


class PERFORMANCEMETRICSDLL_API PerformanceMetrics {
public:
	inline PerformanceMetrics()
	{
		
	}
	inline virtual ~PerformanceMetrics()
	{
		
	}
	virtual void start() = 0;
	virtual void stop() = 0;
	inline friend std::ostream& operator<<(std::ostream& out, const PerformanceMetrics& p)
	{
		out << "Metric not available!\n";
	}
	inline std::string printResult()
	{
		return "";
	}
protected:

private:
	
};
class PERFORMANCEMETRICSDLL_API ClockTicksMetrics :public PerformanceMetrics
{
public:
	inline ClockTicksMetrics() :PerformanceMetrics(){}

	void start();
	void stop();
	
	inline friend std::ostream& operator<<(std::ostream& out, const ClockTicksMetrics& p){
		return out << "Clock:" << p.clockTicks << "\n";
	}
	inline std::string printResult()
	{

		return "Clock:" + std::to_string(clockTicks) +"\n";

	}
protected:

private:
	clock_t clockTicks;
};
class PERFORMANCEMETRICSDLL_API CpuTimeMetrics :public PerformanceMetrics
{
public:
	inline CpuTimeMetrics() :PerformanceMetrics(){}
	void start();
	void stop();

	inline friend std::ostream& operator<<(std::ostream& out, const CpuTimeMetrics& p){
		return out << "CPU time used:" << p.cpuTimeValue << "\n";
	}
	inline std::string printResult()
	{

		return "CPU time used:" + std::to_string(cpuTimeValue) + "\n";

	}
protected:

private:
	double calculateCpuTimeValue();
	double cpuTimeValue;
};
