// https://atcoder.jp/contests/abc206/tasks/abc206_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));

    vector<vector<int>> V((int)v.size());
    for (int i = 0; i < N; i++) V[A[i]].push_back(i);

    int cnt = 0;
    for (int i = 0; i < N/2; i++) {
        if (A[i] == A[N-1-i]) continue;
        int a = A[i], b = A[N-1-i];
        if (V[a].size() > V[b].size()) swap(a, b);
        while (!V[a].empty()) {
            int j = V[a].back();
            V[a].pop_back();
            A[j] = b;
            V[b].push_back(j);
        }
        cnt++;
    }
    cout << cnt << endl;
}
