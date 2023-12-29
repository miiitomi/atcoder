// https://atcoder.jp/contests/abc042/tasks/abc042_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end());
    for (string s : S) cout << s;
    cout << endl;
}
