#include<iostream>
#include<thread>
#include<Windows.h>

using namespace std;

int x = 0;

DWORD WINAPI testThread(LPVOID pParam)
{
	int countX = 0;
	puts("종료 이벤트 세트 전");

	Sleep(3000);

	SetEvent((HANDLE)pParam);

	puts("종료 이벤트 세트 후");
	puts("End Thread");

	return 0;
}

int main(void)
{
	DWORD dwThraedId = 0;
	// 쓰레드에 전달할 이벤트를 생성한다
	HANDLE ev = CreateEvent(NULL, FALSE, FALSE, NULL);

	// 쓰레드 생성시 이벤트를 매개변수로 전달한다.
	HANDLE h = CreateThread(NULL, 0, testThread, ev, 0, &dwThraedId);


	int countX = 0;
	for (int i = 0; i < 5; i++)
	{
		// EV 이벤트 가 셋 될때 까지 무한정 기다린다.
		if (i == 3 && WaitForSingleObject(ev, INFINITE) == WAIT_OBJECT_0)
		{
			puts("종료 이벤트 감지");
			CloseHandle(ev);
			ev = NULL;
		}
	}

	CloseHandle(h);

	return 0;
}

