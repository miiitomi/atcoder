#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int M = *max_element(A.begin(), A.end());

    vector<ll> C(M+1, 0), S(M+1, 0);
    for (int a : A) {
        C[a]++;
    }
    ll s = 0;
    for (int a = 1; a < M+1; a++) {
        S[a] = (C[a] * (C[a] - 1)) / 2;
        s += S[a];
    }

    ll ans = 0;
    for (int a = 1; a < M+1; a++) {
        N -= C[a];
        s -= S[a];
        ans += C[a] * ((N*(N-1))/2 - s); 
    }
    cout << ans << endl;
}
