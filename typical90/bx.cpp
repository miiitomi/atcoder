#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), S(N+1, 0LL);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }
    ll x = S[N] / 10;
    if (x * 10LL != S[N]) {
        cout << "No" << endl;
        return 0;
    }
    int y = distance(S.begin(), lower_bound(S.begin(), S.end(), x));
    for (int i = 0; i <= y; i++) {
        S.push_back(S[(int)S.size()-1] + A[i]);
    }
    auto iter1 = lower_bound(S.begin(), S.end(), x);
    auto iter2 = S.begin();
    while (iter1 != S.end()) {
        ll z = *iter1 - *iter2;
        if (z == x) {
            cout << "Yes" << endl;
            return 0;
        } else if (z < x) {
            iter1++;
        } else {
            iter2++;
        }
    }
    cout << "No" << endl;
}
