#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> dp(N, INF);
    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(dp.begin(), dp.end(), a[i]);
        *iter = a[i];
    }
    auto iter = lower_bound(dp.begin(), dp.end(), INF);
    cout << distance(dp.begin(), iter) << endl;
}
