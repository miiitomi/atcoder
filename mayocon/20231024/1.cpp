// https://atcoder.jp/contests/abc290/tasks/abc290_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            if (K > 0) K--;
            else S[i] = 'x';
        }
    }
    cout << S << endl;
}
