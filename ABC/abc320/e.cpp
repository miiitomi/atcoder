#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> T(M), W(M), S(M);
    for (int i = 0; i < M; i++) cin >> T[i] >> W[i] >> S[i];

    priority_queue<int, vector<int>, greater<int>> retsu;
    for (int i = 0; i < N; i++) retsu.push(i);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> modori;

    vector<ll> ans(N, 0);

    for (int i = 0; i < M; i++) {
        int t = T[i], w = W[i], s = S[i];

        while (!modori.empty() && modori.top().first <= t) {
            int x = modori.top().second;
            modori.pop();
            retsu.push(x);
        }

        if (retsu.empty()) continue;

        int x = retsu.top();
        retsu.pop();
        ans[x] += w;
        modori.push(make_pair(t+s, x));
    }

    for (ll x : ans) cout << x << endl;
}
