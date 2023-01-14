#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. �ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.
��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. �پ ������ �������� ������ �ִ� �鼳���ִ�, 
���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.
��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է� : �����̵��� Ű�� �ԷµǸ�, Ű�� 100�� ���� �ʴ� �ڿ����̸�, ��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.

��� : �ϰ� �������� Ű�� ���� �������� ����Ѵ�.

�ؼ� : 9���� ������ �� 7���� ��� ����  �ߺ� x, ���� x ������ ���϶�� ���̴�.
       ��� ������� ���Ͽ� ���������Ͽ� ����Ѵ�.
*/

vector<int> nList;
vector<int> result;

int k = 7;
int o = 9;

void combi(int start)
{

    if (result.size() == k)
    {
        int sum = 0;

        for (auto temp : result)
        {
            sum += temp;
        }

        if (sum == 100)
        {
            sort(result.begin(), result.end());

            for (auto temp : result)
            {
                cout << temp << "\n";
            }

            exit(0);
        }
        return;
    }

    for (int i = start+1; i < o; i++)
    {
        result.push_back(nList[i]);
        combi(i);
        result.pop_back();
    }
}


int main(void)
{

    for (int i = 0; i < o; i++)
    {
        int temp = 0;
        cin >> temp;
        nList.push_back(temp);
    }

    combi(-1);
}