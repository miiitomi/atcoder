// https://atcoder.jp/contests/abc218/tasks/abc218_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), v;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &a : x) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));
    for (int &a : y) a = distance(v.begin(), lower_bound(v.begin(), v.end(), a));

    int M = v.size();
    vector<vector<bool>> A(M, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        A[x[i]][y[i]] = true;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (x[i] == x[j] || y[i] == y[j]) continue;
            if (A[x[i]][y[j]] && A[x[j]][y[i]]) ans++;
        }
    }
    ans /= 2;
    cout << ans << endl;
}
