#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, C;
    cin >> N >> M >> C;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A.push_back(A[i] + M);
        A.push_back(A[i] + 2*M);
        A.push_back(A[i] + 3*M);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    queue<ll> Q;
    while ((ll)Q.size() < C || Q.back() == A.back()) {
        Q.push(A.back());
        A.pop_back();
    }
    ll ans = 0;
    for (ll i = 0; i < M; ) {
        while (!Q.empty() && Q.front() <= i) Q.pop();
        while ((ll)Q.size() < C || Q.back() == A.back()) {
            Q.push(A.back());
            A.pop_back();
        }
        ll r = min(Q.front()-1, M-1);
        ans += (r-i+1)*((ll)Q.size());
        i = Q.front();
    }
    cout << ans << "\n";
}
