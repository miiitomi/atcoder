#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    map<int, set<int>> S;
    while (M--) {
        int x, y;
        cin >> x >> y;
        S[y].insert(x);
    }
    set<pair<int,int>> done;
    set<pair<int,int>> R;
    R.insert(make_pair(0, N));
    done.insert(make_pair(0, N));
    set<int> ans;

    while (!R.empty()) {
        pair<int,int> p = *R.begin();
        R.erase(p);
        int x = p.first, y = p.second;
        if (x == 2*N) {
            ans.insert(y);
            continue;
        }

        int t = x;
        if (S[y].empty()) t = 2*N;
        else {
            auto iter = S[y].lower_bound(x+1);
            if (iter == S[y].end()) t = 2*N;
            else t = *iter - 1;
        }
        if (!done.count(make_pair(t, y))) {
            done.insert(make_pair(t, y));
            R.insert(make_pair(t, y));
        }
        y = y-1;
        if (!S[y].empty()) {
            auto iter = S[y].lower_bound(x+1);
            while (iter != S[y].end() && *iter <= t+1) {
                if (!done.count(make_pair(*iter, y))) {
                    done.insert(make_pair(*iter, y));
                    R.insert(make_pair(*iter, y));
                }
                iter++;
            }
        }
        y = y+2;
        if (!S[y].empty()) {
            auto iter = S[y].lower_bound(x+1);
            while (iter != S[y].end() && *iter <= t+1) {
                if (!done.count(make_pair(*iter, y))) {
                    done.insert(make_pair(*iter, y));
                    R.insert(make_pair(*iter, y));
                }
                iter++;
            }
        }
    }

    cout << ans.size() << endl;
}
