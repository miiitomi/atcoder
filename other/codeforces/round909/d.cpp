#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), v;
    v.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 2) A[i] = 1;
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < N; i++) A[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), A[i]));

    vector<ll> cnt(v.size(), 0);
    for (int a : A) cnt[a]++;

    ll ans = 0;
    for (int a = 0; a < v.size(); a++) {
        ans += cnt[a] * (cnt[a]-1) / 2;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
