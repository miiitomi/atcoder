// https://atcoder.jp/contests/abc073/tasks/abc073_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (S.count(a)) S.erase(a);
        else S.insert(a);
    }

    cout << S.size() << endl;
}
