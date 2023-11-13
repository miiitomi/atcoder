// https://atcoder.jp/contests/abc269/tasks/abc269_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> v;
    for (int i = 0; i < 60; i++) {
        if (N & (1LL << i)) v.push_back(i);
    }

    vector<ll> ans;
    int K = (int)v.size();
    for (int i = 0; i < (1 << K); i++) {
        ll s = 0;
        for (int j = 0; j < K; j++) {
            if (i & (1LL << j)) {
                s += (1LL << v[j]);
            }
        }
        ans.push_back(s);
    }

    sort(ans.begin(), ans.end());

    for (ll x : ans) cout << x << endl;
}
