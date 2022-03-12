#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    ull X;
    cin >> X;
    ll state = 0;
    string S;
    cin >> S;

    for (int i = 0; i < N; i++) {
        if (state > 0) {
            if (S[i] == 'U') state--;
            else state++;
        } else {
            if (S[i] == 'U') X /= 2;
            else if (2*X > 1e+18) {
                state++;
            } else {
                if (S[i] == 'L') X = 2*X;
                else X = 2*X + 1;
            }
        }
    }
    cout << X << endl;
}
