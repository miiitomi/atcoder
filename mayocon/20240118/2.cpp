// https://atcoder.jp/contests/abc128/tasks/abc128_b
#include <bits/stdc++.h>
using namespace std;

struct Restaurant {
    int id;
    string name;
    int score;
    Restaurant(int i, string n, int s): id(i), name(n), score(s) {}
};

int main() {
    int N;
    cin >> N;
    vector<Restaurant> v;
    for (int i = 0; i < N; i++) {
        string s;
        int p;
        cin >> s >> p;
        v.push_back(Restaurant(i+1, s, p));
    }

    sort(v.begin(), v.end(), [](const Restaurant &l, const Restaurant &r) {if (l.name != r.name) return l.name < r.name; else return l.score > r.score;});

    for (Restaurant &r : v) {
        cout << r.id << "\n";
    }
}
