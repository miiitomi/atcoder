#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N-1);
    for (int i = 0; i < N-1; i++) cin >> A[i];

    vector<ll> B(N+1, 0);
    vector<ll> others;

    for (int i = 0; i < N-1; i++) {
        ll x = A[i];
        if (i > 0) x -= A[i-1];

        if (1 <= x && x <= N) B[x]++;
        else others.push_back(x);
    }

    if ((int)others.size() >= 2) {
        cout << "NO" << endl;
        return;
    }

    if ((int)others.size() == 1) {
        ll o = others[0];
        ll a, b;
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (B[i] != 1) {
                if (B[i] >= 2) {
                    cout << "NO" << endl;
                    return;
                }
                if (B[i] == 0) {
                    count++;
                    if (count == 1) a = i;
                    else if (count == 2) b = i; 
                    if (count == 3) {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
        if (count == 2 && o == a + b) {
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    ll o, a, b;
    int count2 = 0;
    int count0 = 0;
    for (int i = 1; i <= N; i++) {
        if (B[i] == 1) continue;
        if (B[i] >= 3) {
            cout << "NO" << endl;
            return;
        }
        if (B[i] == 2) {
            count2++;
            if (count2 >= 2) {
                cout << "NO" << endl;
                return;
            }
            o = i;
        }
        if (B[i] == 0) {
            count0++;
            if (count0 == 1) a = i;
            else if (count0 == 2) b = i;
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if ((count0 == 1 && count2 == 0) || (count2 == 1 && count0 == 2 && o == a + b)) {
        cout << "YES" << endl;
        return;
    } else {
        cout << "NO" << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
