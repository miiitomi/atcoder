#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    for (int i = 0; i < N; i++) cin >> B.at(i);
    for (int i = 0; i < N; i++) cin >> C.at(i);

    vector<int> D(N, 0), E(N, 0);
    for (int i = 0; i < N; i++) {
        D.at(A.at(i)-1)++;
        E.at(B.at(C.at(i)-1)-1)++;
    }

    int64_t ans = 0LL;
    for (int i = 0; i < N; i++) {
        ans += (int64_t)D.at(i) * E.at(i);
    }

    cout << ans << endl;
}
