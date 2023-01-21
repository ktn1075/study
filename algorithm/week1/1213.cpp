#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n, flag;
string a, ret;
int t[200];
int mid;
int main(void) {
	cin >> a;
	for (char zx : a) t[zx]++;
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (t[i])
		{
			if (t[i] & 1) {
				mid = char(i); flag++;
				t[i]--;
			}
			if (flag == 2) break;
			for (int j = 0; j < t[i]; j += 2)
			{
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}

	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2) cout << "I'm Sorry Hansoo" << "\n";
	else cout << ret << "\n";
}