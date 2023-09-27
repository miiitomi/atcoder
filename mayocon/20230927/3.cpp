// https://atcoder.jp/contests/abc254/tasks/abc254_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<int>> b(K); 
    for (int k = 0; k < K; k++) b[k].reserve(N/K + 1);
    for (int i = 0; i < N; i++) {
        b[i % K].push_back(a[i]);
    }

    sort(a.begin(), a.end());
    for (int k = 0; k < K; k++) sort(b[k].begin(), b[k].end());

    vector<int> c;
    c.reserve(N);
    for (int i = 0; i < N; i++) {
        c.push_back(b[i % K][i / K]);
    }

    if (a == c) cout << "Yes" << endl;
    else cout << "No" << endl;
}
