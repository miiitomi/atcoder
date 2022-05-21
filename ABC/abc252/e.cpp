#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<ll, ll>>> G(N);
    map<pair<ll, ll>, int> mp;

    for (int i = 0; i < M; i++) {
        ll s, t, d;
        cin >> s >> t >> d;
        s--;
        t--;
        G[s].push_back(make_pair(t, d));
        G[t].push_back(make_pair(s, d));
        mp[make_pair(s, t)] = i + 1;
        mp[make_pair(t, s)] = i + 1;
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(make_pair(0, 0));
    vector<int> W(N, -1);
    vector<bool> done(N, false);
    done[0] = true;
    vector<int> V;

    while (!Q.empty()) {
        ll d = Q.top().first;
        ll v = Q.top().second;
        Q.pop();
        if (dist[v] < d) continue;

        if (!done[v]) {
            done[v] = true;
            V.push_back(mp[make_pair(v, W[v])]);
        }

        for (auto p : G[v]) {
            if (dist[v] + p.second < dist[p.first]) {
                dist[p.first] = dist[v] + p.second;
                pair<ll, ll> q = make_pair(dist[p.first], p.first);
                Q.push(q);
                W[p.first] = v;
            }
        }
    }

    sort(V.begin(), V.end());
    for (int i = 0; i < (int)V.size(); i++) {
        if (i != (int)V.size() - 1) cout << V[i] << " ";
        else cout << V[i] << endl;
    }
}
