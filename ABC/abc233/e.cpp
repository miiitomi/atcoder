#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    ll x = 0;
    for (char c : S) x += (int)(c - '0');

    ll K = S.size();
    vector<ll> V(K, 0);
    for (int i = 0; i < K; i++) {
        V[i] += x;
        x -= (int)(S.back() - '0');
        S.pop_back();
    }

    for (int i = 0; true; i++) {
        if (i == V.size()-1 && V[i] < 10) break;

        if (i == V.size()-1) V.push_back(0LL);
        V[i+1] += V[i] / 10;
        V[i] %= 10;
    }

    while (V.back() == 0) V.pop_back();
    reverse(V.begin(), V.end());
    for (ll a : V) cout << a;
    cout << endl;
}
