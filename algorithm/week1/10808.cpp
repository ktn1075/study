/*

���� :  ���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S��  �־�����. �� ���ĺ��� �ܾ ��� ���ԵǾ� �ִ���
        ���ϴ� ���α׷��� �ۼ��Ͻÿ� .

�Է� : ù° �ٿ� �ܾ� S�� �־�����. �ܾ��� ���̴� 100�� ���� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

�ؼ� : ���ڴ� �ƽ�Ű�ڵ�� ó�� �ȴٰ� �����ϰ�, �迭�� ���� ���� ó�� �Ѵ�.


#include<iostream>
#include<string>


using namespace std;


int result[26];
int main(void)
{
	string a;
	cin >> a;

	for (char t : a)
	{
		result[t - 'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		cout << result[i] << " ";
	}
}

*/