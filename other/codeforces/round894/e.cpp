#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N, M, D;
    cin >> N >> M >> D;

    vector<ll> A(N);
    priority_queue<pair<ll, int>> P;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] >= 0 && i < N-1) P.push(make_pair(A[i], i));
    }

    ll ans = 0, tmp = 0;
    vector<bool> used(N, false);
    for (int i = 0; i < M-1; i++) {
        if (P.empty()) break;
        auto p = P.top();
        P.pop();
        tmp += p.first;
        used[p.second] = true;
    }

    for (int i = N-1; i >= 0; i--) {
        if (!used[i]) {
            tmp += A[i];
        } else if (!P.empty()){
            int j = -1;
            do {
                j = P.top().second;
                P.pop();
            } while (!(0 <= j && j < i) && !P.empty());
            if (0 <= j && j < i) {
                used[j] = true;
                tmp += A[j];
            }
        }
        ans = max(ans, tmp - D*(i+1));
        tmp -= A[i];
    }

    cout << ans << endl;
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
