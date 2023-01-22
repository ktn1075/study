

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int N;
    int k = 0;
    while (cin >> N) {
        int ans = 1;
        k = 1;

        while (1) {
            if (ans % N == 0) {
                break;
            }
            else {
                k++;
                ans = ans * 10 + 1;
                ans %= N;				
            }
        }

        cout << k << "\n";
    }

    return 0;
}