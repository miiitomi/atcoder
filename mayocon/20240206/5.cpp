// https://atcoder.jp/contests/abc312/tasks/abc312_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;
    priority_queue<ll> Fuyou, Hitsuyou, Kankiri;
    for (int i = 0; i < N; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) Fuyou.push(x);
        else if (t == 1) Hitsuyou.push(x);
        else Kankiri.push(x);
    }

    priority_queue<ll, vector<ll>, greater<ll>> PQ;

    ll cnt = 0, ans = 0, kankiri_remain = 0;
    while (cnt < M && !Fuyou.empty()) {
        ans += Fuyou.top();
        PQ.push(Fuyou.top());
        Fuyou.pop();
        cnt++;
    }

    ll tmp = ans;
    while (true) {
        if (cnt == M) {
            if (PQ.empty()) break;
            ll x = PQ.top();
            tmp -= x;
            PQ.pop();
            cnt--;
        } else if (kankiri_remain > 0) {
            if (Hitsuyou.empty()) break;
            ll x = Hitsuyou.top();
            Hitsuyou.pop();
            tmp += x;
            PQ.push(x);
            kankiri_remain--;
            cnt++;
            ans = max(ans, tmp);
        } else {
            if (Kankiri.empty()) break;
            ll x = Kankiri.top();
            Kankiri.pop();
            kankiri_remain += x;
            cnt++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
