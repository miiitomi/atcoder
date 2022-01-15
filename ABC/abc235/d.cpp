#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, N;
    cin >> a >> N;

    vector<ll> d(1000000, -1);
    d[1] = 0;
    queue<ll> Q;
    Q.push(1);

    while (!Q.empty()) {
        ll x = Q.front();
        Q.pop();

        ll y = a * x;
        if (y == N) {
            cout << d[x] + 1 << endl;
            return 0;
        } else if (y >= 1000000) {

        } else if (d[y] != -1) {

        } else {
            d[y] = d[x] + 1;
            Q.push(y);
        }

        if (x < 10 || (x % 10) == 0) {
            continue;
        }
        string k = to_string(x);
        k = k[k.size()-1] + k;
        k.pop_back();
        y = stoll(k);

        if (y == N) {
            cout << d[x] + 1 << endl;
            return 0;
        } else if (y >= 1000000) {

        } else if (d[y] != -1) {

        } else {
            d[y] = d[x] + 1;
            Q.push(y);
        }
    }
    cout << d[N] << endl;
}
