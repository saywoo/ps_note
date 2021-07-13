#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans = 1e9;
vector<int> p;

int Find(int x)
{
    if (x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
    x = Find(x); y = Find(y);
    if (x != y) p[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        if (Find(a) == Find(b)) ans = min(ans, i + 1);
        Union(a, b);
    }

    if (ans == 1e9) cout << 0 << '\n';
    else cout << ans << '\n';

    return 0;
}
