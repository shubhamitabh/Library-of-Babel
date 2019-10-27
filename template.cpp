#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (ll i = 0; i < n; ++i) cin >> c[i];
#define exit_message(s) return 0 * printf(s)
#define show_all(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, a, n) cout << "Displaying array \"" << #c << "\" : \n"; for (ll (i) = (a); (i) < (n); ++(i)) cout << (c)[(i)] << " "; cout << "\n";
#define forl(i, a, n) for (ll i = (a); (i) < (n); ++(i))
#define dugbe(k) cout << "-\t> " << #k << " : " << k << "\n";
#define dugbev(vec, idx) cout << "-\t> " << #vec << "[" << idx << "] : " << vec[idx] << "\n";

// What follows is a magical ordered set data structure.
// Supports the following functions:
// find_by_order(ll k) - returns k'th smallest element (0-indexed)
// order_of_key(ll k) - returns number of elements strictly smaller than k.

// using namespace __gnu_pbds;
// #define ordered_set tree <ll, null_type, greater_equal <ll>, rb_tree_tag, tree_order_statistics_node_update>

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
typedef pair<ll, ll> pr;
typedef pair<ll, ll> prll;
typedef vector<ll> vi;
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

ll mod_pow(ll a, ll b)
{
	if (b == 0)
		return 1LL;

	ll res = mod_pow(a, b >> 1);
	res = (res * res) % mod;
	if (b & 1LL)
		res = (res * a) % mod;
	
	return res;
}

ll inverse(ll a)
{
	return mod_pow(a, mod - 2);
}

const ll N = 1e5 + 5;
const ll INF = 1e9 + 100;

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	
	
	return 0;
}