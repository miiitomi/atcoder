// https://atcoder.jp/contests/abc147/tasks/abc147_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size(), cnt = 0;
    for (int i = 0; i < N/2; i++) {
        if (S[i] != S[N-1-i]) cnt++;
    }
    cout << cnt << endl;
}
