// https://atcoder.jp/contests/abc206/tasks/abc206_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> v(2e+5);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        v[A[i]].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != A[N-1-i]) {
            ans++;
            int a = A[i], b = A[N-1-i];
            if (v[a].size() > v[b].size()) swap(a, b);
            while (!v[a].empty()) {
                int j = v[a].back();
                v[a].pop_back();
                A[j] = b;
                v[b].push_back(j);
            }
        }
    }

    cout << ans << endl;
}
