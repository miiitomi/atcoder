// https://atcoder.jp/contests/abc312/tasks/abc312_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> Nashi, Ari, Kankiri;

    for (int i = 0; i < N; i++) {
        ll t, x;
        cin >> t >> x;
        if (t == 0) Nashi.push_back(x);
        else if (t == 1) Ari.push_back(x);
        else Kankiri.push_back(x);
    }
    sort(Nashi.begin(), Nashi.end(), [] (const int &a, const int &b) {return a > b;});
    sort(Ari.begin(), Ari.end(), [] (const int &a, const int &b) {return a > b;});
    sort(Kankiri.begin(), Kankiri.end(), [] (const int &a, const int &b) {return a > b;});

    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll ans = 0;
    int count = 0;
    for (int i = 0; i < min(M, (int)Nashi.size()); i++) {
        ll a = Nashi[i];
        Q.push(a);
        ans += a;
        count++;
    }

    int idx = 0;
    for (int i = 0; i < (int)Kankiri.size(); i++) {
        ll tmp = ans;
        if (count == M) {
            if (!Q.empty()) {
                ll x = Q.top();
                Q.pop();
                tmp -= x;
            }
        } else {
            count++;
        }
        int x = Kankiri[i];
        for (int j = 0; j < min(x, (int)Ari.size()); j++) {
            if (idx >= (int)Ari.size()) break;
            ll y = Ari[idx];
            idx++;
            if (count == M) {
                if ((!Q.empty()) && (Q.top() < y)) {
                    tmp += (y - Q.top());
                    Q.pop();
                    Q.push(y);
                }
            } else {
                tmp += y;
                Q.push(y);
                count++;
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
