#include<iostream>
#include<thread>
#include<Windows.h>

using namespace std;

int x = 0;

DWORD WINAPI testThread(LPVOID pParam)
{
	int countX = 0;
	puts("���� �̺�Ʈ ��Ʈ ��");

	Sleep(3000);

	SetEvent((HANDLE)pParam);

	puts("���� �̺�Ʈ ��Ʈ ��");
	puts("End Thread");

	return 0;
}

int main(void)
{
	DWORD dwThraedId = 0;
	// �����忡 ������ �̺�Ʈ�� �����Ѵ�
	HANDLE ev = CreateEvent(NULL, FALSE, FALSE, NULL);

	// ������ ������ �̺�Ʈ�� �Ű������� �����Ѵ�.
	HANDLE h = CreateThread(NULL, 0, testThread, ev, 0, &dwThraedId);


	int countX = 0;
	for (int i = 0; i < 5; i++)
	{
		// EV �̺�Ʈ �� �� �ɶ� ���� ������ ��ٸ���.
		if (i == 3 && WaitForSingleObject(ev, INFINITE) == WAIT_OBJECT_0)
		{
			puts("���� �̺�Ʈ ����");
			CloseHandle(ev);
			ev = NULL;
		}
	}

	CloseHandle(h);

	return 0;
}

