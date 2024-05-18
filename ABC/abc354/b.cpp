#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, sum = 0;
    cin >> N;
    vector<pair<string, int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
        sum += V[i].second;
    }
    sort(V.begin(), V.end());
    cout << V[sum % N].first << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
