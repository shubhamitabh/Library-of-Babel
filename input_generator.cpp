#include <bits/stdc++.h>
#define FASTIO
#define endl "\n"  // Since endl forces a buffer flush which slows down large I/O operations.
#define ff first
#define ss second
#define pb push_back
#define input(c, n) for (int i = 0; i < n; i++) cin >> c[i];
#define exit_message(s) return 0*printf(s)
#define show(c) for (auto i: c) cout << i << " "; cout << "\n";
#define display(c, n) for (int i = 0; i < n; i++) cout << c[i] << " "; cout << "\n";
#define forl(i, a, n) for (int i = a; i < n; i++)
#define dugbe(k) cout << "-\t> " << #k << " = " << k << "\n";

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
typedef vector<ll> vill;
typedef vector<pr> vpr;
ifstream in("input.txt");
const ll mod = 1e9 + 7;
const int N = 1e5 + 5;

int32_t main()
{
	#ifdef FASTIO
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	#endif
	//freopen("input.txt", "r", stdin);
	freopen("input.txt", "w", stdout);

	int n = 1e5, m = 1e5;
	cout << n << " " << m << "\n";

	srand(0);
	
	// forl(i, 0, n)
	// {
	// 	int x = rand() % 101;
	// 	if (i)
	// 		cout << " ";
	// 	cout << x;
	// }
	// cout << "\n";

	forl(i, 0, n)
	{
		int x = 1e5;
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}