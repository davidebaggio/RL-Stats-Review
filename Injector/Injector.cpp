#include <string>
#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <libloaderapi.h>

void getProcId(const char *windowTitle, DWORD &procId)
{
	GetWindowThreadProcessId(FindWindowA(NULL, windowTitle), &procId);
}

void error(const char *errorTitle, const char *errorMessage)
{
	MessageBoxA(0, errorMessage, errorTitle, 0);
	exit(-1);
}

/* bool file_exists(std::string filename)
{
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
} */

int main()
{
	MessageBoxA(NULL, "U GAY", "SMTH FOR U", 0);
}