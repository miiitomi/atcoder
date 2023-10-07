#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<ll>> B(N);
    vector<ll> Scores(N, 0);
    multiset<ll> X;

    for (int i = 0; i < N; i++) {
        Scores[i] += i+1;
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') Scores[i] += A[j];
            else B[i].push_back(A[j]);
        }
        X.insert(Scores[i]);
    }

    for (int i = 0; i < N; i++) {
        ll score = Scores[i];
        X.erase(X.find(score));

        auto iter = X.end();
        iter--;
        ll other_score = *iter;

        int ans = 0;
        sort(B[i].begin(), B[i].end());
        while (score < other_score) {
            ll s = B[i][B[i].size()-1];
            B[i].pop_back();
            score += s;
            ans++;
        }

        cout << ans << endl;
        X.insert(Scores[i]);
    }
}
