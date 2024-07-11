#include "libGenerateFile.h"
#include "libFile.h"
void f_GenerateFile(string fileName)
{
	ofstream fileWrite = f_openFileToWrite(fileName);
	if (fileWrite.is_open())
	{
		fileWrite << "1\n1000\n";
		for (int i = 0; i < 1000; i++)
		{
			fileWrite << i << " ";
		}
		fileWrite << "\n100\n";
		for (int i = 50; i < 151; i++)
		{
			fileWrite << i << " ";
		}
	}
}
