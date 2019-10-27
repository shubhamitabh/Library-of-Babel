#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
// #define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (int (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (int i = (a); (i) < (n); ++(i))
#define dugbe(k) cerr << "-\t> " << #k << " = " << k << "\n";
#define dugbev(arr, idx) cerr << "-\t " << #arr << "[" << idx << "] : " << arr[idx] << "\n";

/*
 * What follows is a magical ordered set data structure.
 * Supports the following functions:
 * find_by_order(int k) - returns k'th smallest element (0-indexed)
 * order_of_key(int k) - returns number of elements strictly smaller than k.
using namespace __gnu_pbds;
#define ordered_set tree <ll, null_type, greater_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>
*/

/* TIPS FOR DEBUGGING
 * Check if values are not overflowing (use long long where required)
 * Check if ranges are inclusive or not.
 * Check properly if greedy will work or not before using it.
 * Check EDGE CASES!! Seriously, even in 2B, saving 8 points by being
 * 2 minutes faster will bite you in the ass if you don't make sure
 * it works on edge cases.
 * Keep adding to this list.
*/
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
typedef pair<ll, ll> prll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const long double eps = 1e-7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
long long true_rand(long long n)
{
	// Returns a random number between 0 and n - 1 inclusive using mt19937.
    uniform_int_distribution<long long> uid(0, n - 1);
    return uid(rng);
}
 
ll mod_pow(ll a, ll b, ll mod)
{
	if (b == 0)
		return 1LL;
 
	ll res = mod_pow(a, b >> 1, mod);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;
	
	return res;
}
 
const int N = 2e5 + 5;
const ll INF = 1e18;

int n, m;
vi a(N), delta(N);
vi g[N], vis(N);
vi sub(N), par(N);

int find_centroid(int root)
{
	dugbe(root);
	int n = 0;
	function<int(int)> find_size = [&](int src)
	{
		vis[src] = 1;
		sub[src] = 1;
		++n;
		for (auto e: g[src])
		{
			if (!vis[e])
				sub[src] += find_size(e);
		}
		dugbev(sub, src);
		return sub[src];
	};
	find_size(root);
	// assert(k == n);

	function<int(int)> dfs = [&](int src)
	{
		vis[src] = 0;
		int ans = src;
		for (auto e: g[src])
		{
			if (vis[e] == 1)
			{
				if (sub[e] > n / 2)
					ans = dfs(e);
				else
					dfs(e);
			}
		}
		return ans;
	};
	int centroid = dfs(root);
	return centroid;
}

int decompose(int root)
{
	int centroid = find_centroid(root);
	dugbe(centroid);
	vis[centroid] = 2;
	for (auto e: g[centroid])
	{
		if (vis[e] != 2)
		{
			int child = decompose(e);
			par[child] = centroid;
		}
	}
	return centroid;
}

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;// >> m;
	// forl(i, 0, n)
	// {
	// 	cin >> a[i];
	// }
	forl(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		// --a, --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int root = decompose(0);
	par[root] = root;

	vi g_centroid[n];
	forl(i, 0, n)
	{
		dugbev(par, i);
		g_centroid[par[i]].pb(i);
	}
	// Show a BFS now.
	int level = 0;
	queue<pr> q;
	vis.assign(n, 0);
	q.push({root, 0});
	vis[root] = 1;
	dugbe(n);
	while (!q.empty())
	{
		pr u = q.front();
		if (u.ss != level)
		{
			cout << "\n";
			level = u.ss;
		}
		cout << u.ff << " ";
		q.pop();
		for (auto e: g_centroid[u.ff])
		{
			// dugbe(e);
			if (!vis[e])
			{
				vis[e] = 1;
				q.push({e, u.ss + 1});
			}
		}
	}

	return 0;
}