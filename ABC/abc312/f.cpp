#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> A, B, O;
    for (int i = 0; i < N; i++) {
        ll t, x;
        cin >> t >> x;
        if (t == 0) A.push_back(x);
        else if (t == 1) B.push_back(x);
        else O.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(O.begin(), O.end());

    priority_queue<ll, vector<ll>, greater<ll>> P;
    ll score = 0;
    vector<ll> S;

    for (int i = 0; i < min(M, (int)A.size()); i++) {
        ll x = A[(int)A.size()-1-i];
        score += x;
        P.push(x);
    }

    S.push_back(score);
    for (int i = 0; i < min((int)O.size(), M); i++) {
        int t = O[(int)O.size()-1-i];
        if (P.size() + i+1 > M) {
            ll s = P.top();
            P.pop();
            score -= s;
        }

        while (t > 0 && B.size() > 0 && (P.size() + i + 1 < M || P.top() <= B.back())) {
            t--;
            if (P.size() + i + 1 < M) {
                ll x = B.back();
                B.pop_back();
                score += x;
                P.push(x);
            } else {
                ll y = P.top();
                P.pop();
                score -= y;
                ll x = B.back();
                B.pop_back();
                score += x;
                P.push(x);
            }
        }
        S.push_back(score);
    }

    cout << *max_element(S.begin(), S.end()) << endl;
}
