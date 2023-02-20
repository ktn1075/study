#include<iostream>
#include<thread>
#include<Windows.h>

using namespace std;

DWORD WINAPI testThread(LPVOID pParam)
{
	int countX = 0;

	while (countX < 10)
	{
		cout <<"testThread:" << countX << "\n";
		countX++;
	}
	return 0;
}

int main(void)
{
	DWORD dwThraedId = 0;
	HANDLE h = CreateThread(NULL, 0, testThread, NULL, 0 , &dwThraedId );

	int countX = 0;
	while (countX < 10)
	{
		cout << "mainthread" << countX << "\n";
		countX++;
		Sleep(1000);
	}
		
	return 0;
}

