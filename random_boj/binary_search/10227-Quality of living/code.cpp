#include <bits/stdc+.h>
using namespace std;

#define A first
#define B second

int h, r, w, c, x, y, ans;
vector<vector<int> > v, ps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> h >> w;

    v.resize(r + 1); ps.resize(r + 1);
    for (int i = 1; i <= r; i++) {
        v[i].resize(c + 1); ps[i].resize(c + 1);
        for (int j = 1; j <= c; j++) cin >> v[i][j];
    }

    ps[0].resize(c + 1);

    int low = 0; int high = r * c;

    while (low <= high) {

        int mid = (low + high) / 2;

        //cout << mid << endl;

        for (int i = 1; i <= r; i++) {
            int s = 0;
            for (int j = 1; j <= c; j++) {   
                if (v[i][j] == mid) {  x = i; y = j; ps[i][j] = 0; }
                else if (v[i][j] < mid) ps[i][j] = -1;
                else ps[i][j] = 1;

                s += ps[i][j];
                ps[i][j] = s + ps[i-1][j];
            }
        }


        bool fa = false; // >
        bool fb = false; // =
        bool fc = false; // <

        //cout << x << " " << y << endl << endl;

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (i + h - 1 > r || j + w - 1 > c) continue;

                //cout << i << " " << j << " " << i + h - 1 << " " << j + w - 1 << '\n';

                int tmp = ps[i+h-1][j+w-1] - ps[i+h-1][j-1] - ps[i-1][j+w-1] + ps[i-1][j-1];

                if (tmp > 0) fa = true;
                else if (tmp == 0) fb = true;
                else fc = true;
            }
        }

        //cout << fa << " " << fb << " " << fc << endl;

        if (fc) high = mid - 1;
        else if (fb) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}
