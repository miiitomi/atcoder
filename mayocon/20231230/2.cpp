// https://atcoder.jp/contests/abc273/tasks/abc273_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    map<int,int> mp;
    for (int a : A) mp[a]++;
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<int> cnt(N, 0);
    for (int a : A) {
        int k = distance(lower_bound(A.begin(), A.end(), a+1), A.end());
        cnt[k] += mp[a];
    }
    for (int c : cnt) cout << c << "\n";
}
