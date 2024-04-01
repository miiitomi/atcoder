// https://atcoder.jp/contests/abc337/tasks/abc337_e
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int M = 1;
    while ((1 << M) < N) M++;
    cout << M << endl;
    vector<vector<int>> v(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) v[j].push_back(i);
        }
    }
    for (int j = 0; j < M; j++) {
        cout << v[j].size() << " ";
        for (int c : v[j]) cout << c+1 << " ";
        cout << endl;
    }
    string S;
    cin >> S;
    int x = 0;
    for (int j = 0; j < M; j++) {
        if (S[j] == '1') x += (1 << j);
    }
    cout << x+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
