// https://atcoder.jp/contests/abc221/tasks/abc221_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> C(N), D(N), v;
    v.reserve(2*N);

    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        C[i] = a;
        D[i] = a + b;
        v.push_back(C[i]);
        v.push_back(D[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < N; i++) {
        C[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), C[i]));
        D[i] = distance(v.begin(), lower_bound(v.begin(), v.end(), D[i]));
    }

    vector<ll> S((int)v.size(), 0);
    for (int i = 0; i < N; i++) {
        S[C[i]]++;
        S[D[i]]--;
    }

    for (int i = 1; i < (int)S.size(); i++) S[i] += S[i-1];

    vector<int> ans(N+1, 0);
    for (int i = 0; i < (int)v.size()-1; i++) {
        ans[S[i]] += v[i+1] - v[i];
    }

    for (int k = 1; k <= N; k++) cout << ans[k] << " ";
    cout << endl;
}
