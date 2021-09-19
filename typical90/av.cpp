#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    priority_queue<pair<ll, pair<int, int>>> P;
    for (int i = 0; i < N; i++) {
        pair<ll, pair<int, int>> p = make_pair(B[i], make_pair(i, 1));
        P.push(p);  
    }

    ll ans = 0LL;
    while (K > 0 && !P.empty()) {
        auto p = P.top();
        P.pop();
        ans += p.first;
        K--;
        if (p.second.second == 1) {
            int i = p.second.first;
            pair<ll, pair<int, int>> q = make_pair((A[i]-B[i]), make_pair(i, 2));
            P.push(q);
        }
    }
    cout << ans << endl;
}
