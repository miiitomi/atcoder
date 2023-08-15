#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    set<ll> S;
    for (int i = 1; i <= N; i++) S.insert(i);
    vector<int> a(N);

    int i = 0;
    while (!S.empty()) {
        ll x = *S.begin();
        S.erase(x);
        a[i] = (int)x;
        i++;

        while (S.count(2*x)) {
            x *= 2;
            S.erase(x);
            a[i] = (int)x;
            i++;
        }
    }

    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
