// example5_1.cpp: 定义应用程序的入口点。
//

#include "example5_1.h"
#include "BatchImplement.h"
#include "RecursiveImplement.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;


	BatchImplement batch;
	batch.Calc();

	RecursiveImplement rescur;
	rescur.Calc();
	return 0;
}
