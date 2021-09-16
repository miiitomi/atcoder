#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    ll min_K = 0LL;
    for (int i = 0; i < N; i++) {
        min_K += (ll)abs(A[i] - B[i]);
    }
    if (min_K > K || (K - min_K) % 2 == 1) cout << "No" << endl;
    else cout << "Yes" << endl; 
}
