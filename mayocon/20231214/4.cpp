// https://atcoder.jp/contests/abc197/tasks/abc197_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 2e+9;

    for (int s = 0; s < (1 << (N-1)); s++) {
        vector<vector<int>> v;
        v.push_back(vector<int>{A[0]});
        for (int i = 0; i < (N-1); i++) {
            if (s & (1 << i)) v.back().push_back(A[i+1]);
            else v.push_back(vector<int>{A[i+1]});
        }
        vector<int> x((int)v.size(), 0);
        for (int i = 0; i < (int)v.size(); i++) {
            for (int a : v[i]) x[i] = (x[i] | a);
        }
        int tmp = 0;
        for (int y : x) tmp = (tmp ^ y);
        ans = min(ans , tmp);
    }

    cout << ans << endl;
}
