#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S(N+1, '-');
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= 9; j++) {
            if (N % j == 0 && i%(N/j) == 0) {
                S[i] = (char)((int)'0'+j);
                break;
            }
        }        
    }

    cout << S << endl;
}
