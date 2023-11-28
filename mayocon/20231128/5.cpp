// https://atcoder.jp/contests/abc258/tasks/abc258_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q, X;
    cin >> N >> Q >> X;
    ll sum = 0;
    vector<ll> W(2*N, 0), S(2*N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        W[N+i] = W[i];
        sum += W[i];
    }
    for (int i = 0; i < 2*N; i++) S[i+1] = S[i] + W[i];

    set<ll> st;
    vector<pair<ll,ll>> V;
    int s = 0;
    while (!st.count(s)) {
        st.insert(s);
        ll Y = X;
        V.push_back(make_pair(s, (Y / sum) * N));
        Y %= sum;
        if (Y == 0) continue;
        int left=0, right=N, mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (S[s + mid] - S[s] >= Y) right = mid;
            else left = mid;
        }
        V[(int)V.size()-1].second += right;
        s = (s + right) % N;
    }

    vector<pair<ll,ll>> U;
    while (U.empty() || U.back().first != s) {
        U.push_back(V.back());
        V.pop_back();
    }
    reverse(U.begin(), U.end());


    while (Q--) {
        ll K;
        cin >> K;
        K--;

        if (K < (int)V.size()) cout << V[K].second << endl;
        else {
            K -= V.size();
            K %= (ll)U.size();
            cout << U[K].second << endl;   
        }
    }
}
