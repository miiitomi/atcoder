#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i, vector<vector<int>> &G, vector<bool> &reached) {
    reached[i] = true;
    for (int j : G[i]) {
        if (!reached[j]) {
            dfs(j, G, reached);
        }
    }
}

int main() {
    int N;
    cin >> N;
    ll D;
    cin >> D;

    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<vector<int>> G(N);
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            ll dist_squared = pow(X[i]-X[j], 2LL) + pow(Y[i]-Y[j], 2LL);
            if (D*D >= dist_squared) {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    vector<bool> reached(N, false);

    dfs(0, G, reached);

    for (int i = 0; i < N; i++) {
        if (reached[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
