#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2e9;

template<class T> void chmin(T &a, T b) {
    if (b < a) a = b;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) cin >> B[i];

    int ans = 0LL;
    sort(A.begin(), A.end());
    for (int i = 0; i < Q; i++) {
        int min_dis = INF;
        auto iter = lower_bound(A.begin(), A.end(), B[i]);
        if (iter != A.end()) chmin(min_dis, abs(*iter - B[i]));
        if (iter != A.begin()) {
            iter--;
            chmin(min_dis, abs(*iter - B[i]));
        }
        cout << min_dis << endl;
    }
}
