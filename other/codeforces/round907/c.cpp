#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    multiset<int> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }

    ll cnt = 0;

    ll x = 0;
    while (S.size() >= 2) {
        auto iter1 = S.end();
        iter1--;
        ll z = *iter1;

        if (x >= z) {
            x -= z;
            S.erase(iter1);
            continue;
            cnt++;
        }

        auto iter = S.begin();
        ll y = *iter;
        S.erase(iter);

        if (x + y >= z) {
            y -= z - x;
            cnt += z - x;
            if (y > 0) S.insert(y);
            S.erase(iter1);
            cnt++;
            x = 0;
        } else {
            x += y;
            cnt += y;
        }
    }

    if (!S.empty()) {
        ll a = *S.begin();
        if (a <= x) {
            cnt++;
        } else {
            ll b = (a - x + 1) / 2;
            cnt += b;
            a -= b;
            if (a > 0) cnt++;
        }
    }

    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
