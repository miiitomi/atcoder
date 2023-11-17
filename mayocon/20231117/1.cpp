// https://atcoder.jp/contests/abc168/tasks/abc168_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    string S;
    cin >> K >> S;

    if (S.size() <= K) cout << S << endl;
    else {
        for (int i = 0; i < K; i++) {
            cout << S[i];
        }
        cout << "..." << endl;
    }
}
