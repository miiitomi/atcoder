#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll L, N1, N2;
    cin >> L >> N1 >> N2;

    vector<ll> v1(N1), l1(N1), v2(N2), l2(N2), A1(N1), A2(N2);
    for (int i = 0; i < N1; i++) {
        cin >> v1[i] >> l1[i];
        if (i == 0) A1[i] = l1[i];
        else A1[i] = A1[i-1] + l1[i];
    }
    for (int j = 0; j < N2; j++) {
        cin >> v2[j] >> l2[j];
        if (j == 0) A2[j] = l2[j];
        else A2[j] = A2[j-1] + l2[j];
    }

    set<ll> S;
    for (ll a : A1) S.insert(a);
    for (ll a : A2) S.insert(a);

    int N = S.size();
    vector<ll> A(N);
    int i = 0;
    for (ll s : S) {
        A[i] = s;
        i++;
    }
    sort(A.begin(), A.end());

    vector<ll> w1(N), w2(N);

    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < N; i++) {
        ll a = A[i];

        ll a1 = A1[i1];
        if (a1 == a) {
            w1[i] = v1[i1];
            i1++;
        } else {
            w1[i] = v1[i1];
        }

        ll a2 = A2[i2];
        if (a2 == a) {
            w2[i] = v2[i2];
            i2++;
        } else {
            w2[i] = v2[i2];
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (w1[i] == w2[i]) {
            if (i == 0) ans += A[i];
            else ans += A[i] - A[i-1];
        }
    }

    cout << ans << endl;
}
