#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int N;
    cin >> N;
    vector<int> A(7*N);
    for (int i = 0; i < 7*N; i++) cin >> A[i];

    int ans = 0;
    for (int k = 0; k < 7*N; k++) {
        ans += A[k];
        if (k % 7 == 6) {
            cout << ans << " ";
            ans = 0;
        }
    }
    cout << endl;
}
