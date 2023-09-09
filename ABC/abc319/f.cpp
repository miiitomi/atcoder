#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int id=0;
    int medicine_id=-1;
    int type=0; // 0 if root, 1 if enemy, 2 if medicine
    int strength=0;
    int g=0;
    int par=-1;
    vector<int> children;
};

int N, M;
vector<Node> V;
vector<ll> dp;

ll rec(int S) {
    if (dp[S] != -1) return dp[S];
    dp[S] = 0;

    for (int j = 0; j < M; j++) {
        if (!(S & (1 << j))) continue;
        ll tmp = rec(S - (1 << j));
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
        Q.push(make_pair(0, 0));
        int m_id = -1;
        bool ok = false;
        while (!Q.empty()) {
            auto p = Q.top();
            ll s = p.first;
            int v = p.second;
            if (s > tmp) break;
            Q.pop();
            Node &c = V[v];
            if (c.medicine_id == j) {
                ok = true;
                m_id = c.id;
                continue;
            } else if (c.type != 2 || (c.type == 2 && (S & 1 << c.medicine_id))) {
                for (int w : c.children) if (w != c.par) Q.push(make_pair(V[w].strength, w));
            }
        }

        if (!ok) continue;

        Q.push(make_pair(0, m_id));
        tmp = min((ll)1e+9 + 1, tmp * V[m_id].g);
        while (!Q.empty()) {
            auto p = Q.top();
            ll s = p.first;
            int v = p.second;
            if (s > tmp) break;
            Q.pop();
            Node &c = V[v];
            if (c.type == 2 && !(S & (1 << c.medicine_id))) continue;
            if (c.type == 1) tmp = min(tmp + c.g, (ll)1e+9 + 1);
            for (int w : c.children) if (w != c.par) Q.push(make_pair(V[w].strength, w));
        }

        dp[S] = max(tmp, dp[S]);
    }
    return dp[S];
}

int main() {
    cin >> N;
    V.resize(N);
    M = 0;
    int max_s = -1;
    for (int i = 1; i < N; i++) {
        V[i].id = i;
        cin >> V[i].par >> V[i].type >> V[i].strength >> V[i].g;
        V[i].par--;
        if (V[i].type == 2) {
            V[i].medicine_id = M;
            M++;
        }
        V[V[i].par].children.push_back(i);
        max_s = max(max_s, V[i].strength);
    }

    dp.assign((1 << M), -1);
    ll tmp = 1;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        auto p = Q.top();
        ll s = p.first;
        int v = p.second;
        if (s > tmp) break;
        Q.pop();
        Node &c = V[v];
        if (c.type != 2) {
            if (c.type == 1) tmp = min((ll)1e+9 + 1, tmp + c.g);
            for (int w : c.children) if (w != c.par) Q.push(make_pair(V[w].strength, w));
        }
    }
    dp[0] = tmp;

    rec((1 << M)-1);

    if (dp[(1 << M)-1] >= max_s) cout << "Yes" << endl;
    else cout << "No" << endl;
}
