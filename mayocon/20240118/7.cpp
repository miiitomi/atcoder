// https://atcoder.jp/contests/abc139/tasks/abc139_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<pair<ll,ll>> v;
    for (int i = 0; i < N; i++) {
        pair<ll, ll> p;
        cin >> p.first >> p.second;
        if (p.first != 0 || p.second != 0) v.push_back(p);
    }
    N = v.size();
    if (N == 0) {
        cout << 0.0 << endl;
        return 0;
    }

    sort(v.begin(), v.end(), [](const auto &l, const auto &r) {return atan2(l.second, l.first) < atan2(r.second, r.first);});

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll X = 0, Y = 0;
        int j = i;
        do {
            X += v[j].first;
            Y += v[j].second;
            ans = max(ans, X*X+Y*Y);
            j = (j+1) % N;
        } while (j != i);
    }

    cout << sqrt(ans) << endl;
}
