#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <libloaderapi.h>

using namespace std;

void getProcId(const char *windowTitle, DWORD &procId)
{
	GetWindowThreadProcessId(FindWindow(NULL, windowTitle), &procId);
}

void error(const char *errorTitle, const char *errorMessage)
{
	MessageBoxA(0, errorMessage, errorTitle, 0);
	exit(-1);
}

/* bool file_exists(string filename)
{
	struct stat buffer;
	return (stat(filename.c_str(), &buffer) == 0);
} */

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		MessageBoxA(NULL, "U GAY", "SMTH FOR U", 0);
		return 0;
	}
	DWORD procID = 0;
	char dllPath[MAX_PATH];
	const char *dllName = argv[1];
	const char *windowTitle = "torvy - Discord";

	// file_exists

	if (!GetFullPathNameA(dllName, MAX_PATH, dllPath, nullptr))
		error("File Path", "Could not find the file path");

	getProcId(windowTitle, procID);
	if (procID == 0)
		error("Process ID", "Could not find the process ID");

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, procID);
	if (!hProcess)
		error("Handle Process", "Could not handle the process");

	void *allocatedMemory = VirtualAllocEx(hProcess, nullptr, MAX_PATH, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (!allocatedMemory)
		error("MemAlloc", "Could not allocate the memory");

	if (!WriteProcessMemory(hProcess, allocatedMemory, dllPath, MAX_PATH, nullptr))
		error("Write Memory", "Could not write in the memory");

	HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0, LPTHREAD_START_ROUTINE(LoadLibraryA), allocatedMemory, 0, nullptr);
	if (!hThread)
		error("Thread", "Could not create the remote thread");

	CloseHandle(hProcess);
	VirtualFreeEx(hProcess, allocatedMemory, 0, MEM_RELEASE);
	MessageBoxA(NULL, "Successfully injected", "Success", 0);
}