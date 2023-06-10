#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 3; i <= 9; i++) {
        int x = (int)pow(10, i);
        
        if (N / x == 0) {
            x /= 1000;
            cout << N - N % x << endl;
            return 0;
        }
    }
}
