#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 
다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

입력 : 난쟁이들의 키가 입력되며, 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.

출력 : 일곱 난쟁이의 키를 오름 차순으로 출력한다.

해설 : 9명의 난쟁이 중 7명을 골라 뜻은  중복 x, 순서 x 조합을 구하라는 것이다.
       재귀 방식으로 구하여 오름차순하여 출력한다.
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