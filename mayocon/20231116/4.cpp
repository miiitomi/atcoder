// https://atcoder.jp/contests/abc114/tasks/abc114_c
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void dfs(int K, int i, string S) {
    if (K == i) {
        int x = 0;
        int l = 1;
        bool three=false, five=false, seven=false;
        while (S.size()) {
            int y = S.back() - '0';
            if (y == 3) three = true;
            if (y == 5) five = true;
            if (y == 7) seven = true;
            x += l * y;
            l *= 10;
            S.pop_back();
        }
        if (three && five && seven) v.push_back(x);
        return;
    }

    S.push_back('3');
    dfs(K, i+1, S);
    S[i] = '5';
    dfs(K, i+1, S);
    S[i] = '7';
    dfs(K, i+1, S);
    return;
}


int main() {
    for (int K = 9; K >= 3; K--) {
        dfs(K, 0, "");
    }
    sort(v.begin(), v.end());

    int N;
    cin >> N;
    int ans = distance(v.begin(), lower_bound(v.begin(), v.end(), N+1));
    cout << ans << endl;
}
