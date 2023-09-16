#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Info {
    ll a, b, x, y;
    Info(ll a_, ll b_, ll x_, ll y_) {
        a = a_;
        b = b_;
        x = x_;
        y = y_;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<Info> V;
    V.reserve(M);
    map<int, vector<int>> mp;

    for (int i = 0; i < M; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        a--;
        b--;
        Info I(a, b, x, y);
        V.push_back(I);
        mp[a].push_back(i);
        mp[b].push_back(i);
    }

    queue<int> Q;
    Q.push(0);
    vector<ll> X(N, 0), Y(N, 0);
    vector<bool> done(N, false);
    done[0] = true;

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int i : mp[v]) {
            Info I = V[i];
            ll a = I.a, b = I.b, x = I.x, y = I.y;

            if (done[a] && !done[b]) {
                done[b] = true;
                Q.push(b);
                X[b] = X[a] + x;
                Y[b] = Y[a] + y;
            } else if (!done[a] && done[b]) {
                done[a] = true;
                Q.push(a);
                X[a] = X[b] - x;
                Y[a] = Y[b] - y;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!done[i]) {
            cout << "undecidable" << endl;
        } else {
            cout << X[i] << " " << Y[i] << endl;
        }
    }
}
