#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), D(M);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < M; i++) cin >> D[i];
    sort(S.begin(), S.end());
    sort(D.begin(), D.end());

    int l = 0;
    int r = 1e+9 + 10;

    while (r - l > 1) {
        int m = (l + r) / 2;
        auto iter1 = lower_bound(S.begin(), S.end(), m+1);
        int n_seller = distance(S.begin(), iter1);
        auto iter2 = lower_bound(D.begin(), D.end(), m);
        int n_buyer = distance(iter2, D.end());
        if (n_seller >= n_buyer) r = m;
        else l = m;
    }

    cout << r << endl;
}
