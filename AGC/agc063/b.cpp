#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    vector<pair<int,int>> V;

    for (int i = N-1; i >= 0; i--) {
        if (A[i] != 1) {
            V.push_back(make_pair(A[i], i));
            continue;
        }
        int x = 2;
        while (!V.empty() && V.back().first == x) {
            V.pop_back();
            x++;
        }
        if (!V.empty()) ans += V.back().second - i;
        else ans += N - i;
    }

    cout << ans << endl;
}
