#pragma once

public ref class ThreadWork
{
public:

	ThreadWork(){}
	 void work();
	 inline System::String^ getText(){
		 return text;
	 }
protected:
private:
	System::String^ text;//
};


