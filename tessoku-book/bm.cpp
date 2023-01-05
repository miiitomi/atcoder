#include <bits/stdc++.h>
using namespace std;

void dp(int i, vector<vector<int>> &G, vector<int> &S) {
    for (int j : G[i]) {
        dp(j, G, S);
        S[i] += S[j] + 1;
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> G(N);
    for (int i = 1; i < N; i++) {
        int a;
        cin >> a;
        a--;
        G[a].push_back(i);
    }

    vector<int> S(N, 0);
    dp(0, G, S);

    for (int i = 0; i < N; i++) {
        cout << S[i];
        if (i < N-1) cout << " ";
        else cout << endl;
    }
}
