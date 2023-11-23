// https://atcoder.jp/contests/abc284/tasks/abc284_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) cout << S[N-1-i] << endl;
}
