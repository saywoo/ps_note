#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
#define MOD 524287

int ans = 0;
string a, b;
bool pn[100000];
vector<int> v;
vector<pr> Hash[524287];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b;
	
	for (int i = 2; i <= sqrt(100000); i++) {
		if (v.size() >= 52) break;
		if (pn[i]) continue;
		v.push_back(i);
		for (int j = i * 2; j < 100000; j += i) pn[j] = true;
	}
	
	for (int i = 0; i < a.length(); i++) {
		int x = 1; int y = 1;
		for (int j = i; j < a.length(); j++) {
			int now = a[j]-'a';
			x = (x * v[now]) % MOD;
			y = (y * v[now+26]) % MOD;
			Hash[x].push_back({y, j - i + 1});
		}
	}
	
	for (int i = 0; i < b.length(); i++) {
		int x = 1; int y = 1;
		for (int j = i; j < b.length(); j++) {
			int now = b[j] - 'a';
			x = (x * v[now]) % MOD;
			y = (y * v[now+26]) % MOD;
			
			for (int k = 0; k < Hash[x].size(); k++) {
				if (Hash[x][k] == make_pair(y, j - i + 1)) ans = max(ans, j - i + 1);
			}
		}
	}
	
	cout << ans << '\n';
	 
	return 0;
}