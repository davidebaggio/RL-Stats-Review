#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <libloaderapi.h>

void getProcId(const wchar_t *windowTitle, DWORD &procId)
{
	GetWindowThreadProcessId(FindWindow(NULL, windowTitle), &procId);
}

void error(const wchar_t *errorTitle, const wchar_t *errorMessage)
{
	MessageBox(0, errorMessage, errorTitle, 0);
	exit(-1);
}

int main()
{
}
