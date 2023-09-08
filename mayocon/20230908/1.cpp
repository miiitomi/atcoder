// https://atcoder.jp/contests/abc215/tasks/abc215_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;
    sort(S.begin(), S.end());

    set<string> X;
    do {
        X.insert(S);
    } while (next_permutation(S.begin(), S.end()));

    auto iter = X.begin();
    for (int i = 0; i < K-1; i++) iter++;
    cout << *iter << endl;   
}
