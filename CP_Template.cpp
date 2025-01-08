//687C (CF) , advanced version of 2D DP



#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fa(i, n) for (ll i = 0; i < n; i++)
#define fd(i, n) for (ll i = n-1; i>=0; i--)
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll mod = 1000000007;
vector <bool> prime;
void seive()
{
	prime.resize(1000000001, true);
    for (int p = 2; p * p <= 1000000001; p++)
		if (prime[p] == true) 
			for (int i = p * p; i <= 1000000001; i += p)
				prime[i] = false;
	prime[0] = false;
	prime[1] = false;
}
long long inv(long long base, long long exp, long long mod)
{
	base %= mod;
	long long result = 1;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			result = (result * base) % mod;
		base = (base * base) % mod;
		exp = exp / 2;
	}
	return result;
}
//Cant create a normal 2D DP , then iterate thru elements , if k-c[i] is found then add it to another vector , 
//and then create all sums possible , for eq take (1,5,4,2) and target 6. we would get 3 with that method which is 
//not achieved.
void solve()
{
	ll n, tar;
	cin >> n >> tar;
	vll a(n);
	fa(i, n) cin >> a[i];
	vector <vector<vector<bool>>> possible(n + 1, vector<vector<bool>>(tar + 1, vector<bool>(tar + 1, 0)));
	for(int i=0;i<=n;i++)
		possible[i][0][0] = 1;
	for (int i=1;i<=n;i++)
	{
		for (int j = 0; j <= tar; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				possible[i][j][k]=possible[i - 1][j][k];
				if (j >= a[i - 1])
				{
					possible[i][j][k] = possible[i][j][k] || possible[i - 1][j - a[i - 1]][k];
					if (k >= a[i - 1])
						possible[i][j][k] = possible[i][j][k] || possible[i - 1][j - a[i - 1]][k - a[i - 1]];
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<=tar;i++)
		if(possible[n][tar][i])
			ans++;
	cout << ans << endl;
	for(int i=0;i<=tar;i++)
		if(possible[n][tar][i])
			cout << i << " ";
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 1;
	while (t--)
		solve();
}
