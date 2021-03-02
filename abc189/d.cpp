#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());

    vector<int64_t> S = {0};
    for (int i = 0; i < N; i++) {
        S.push_back(S.at(i) + A.at(i));
    }

    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += S.at(N) - S.at(i+1) - (N - i - 1) * A.at(i);
    } 
    cout << ans << endl;
}