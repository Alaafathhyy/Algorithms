#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;


int val[N], wight[N], id[N];

bool cmp(int i, int j) {
    return ((val[i] * 1.0) / wight[i]) > ((val[j] * 1.0) / wight[j]);
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> val[i] >> wight[i];
        id[i] = i;
    }
    sort(id, id + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (wight[id[i]] <= w) {
            w -= wight[id[i]];
            ans += val[id[i]];
        } else {
            double r = (val[id[i]] * 1.0) / wight[id[i]];
            ans += r * w;
            break;
        }
    }
    cout << ans;
}