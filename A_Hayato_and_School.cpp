#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define dl double
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define vmin(a) *min_element(all(a))
#define vmax(a) *max_element(all(a))
#define sz(x) (ll)(x).size()
#define lb lower_bound
#define ub upper_bound
#define gi greater<int>
#define lb lower_bound
#define ub upper_bound

// This less<int> is comparatar (Replace greater<int> for descending)
template <class T>
using pbds = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
const char nl = '\n';

typedef vector<ll> v64;
typedef vector<int> v32;
typedef pair<ll, ll> pll;

void solution();
// const ll M = 1e9 + 7;
// const ll MOD = 1000000007;
#define setDecimal(num, y) cout << fixed << setprecision(y) << num
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(int a, int b) { return (a * b) / gcd(a, b); }
void prefixsum(v64 &v) { forsn(i, 1, sz(v)) v[i] += v[i - 1]; }
void postfixsum(v64 &v) { rforsn(i, sz(v) - 2, 0) v[i] += v[i + 1]; }

signed main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    forsn(i, 1, t + 1)
    {
        // cout << 'Case #' << i << ': ';
        solution();
    }
    return 0;
}
// string alpha = 'abcdefghijklmnopqrstuvwxyz';
// minHeap:  priority_queue<ll, v64, greater<int>> q;
// maxHeap:  priority_queue<ll> q;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// bool isValidPlace(int x, int y, int row, int colu){return (x >= 0 && y >= 0 && x < row && y < colu);}
// len-1-i
// ll msb = (int)(log2(i));
ll dtod(int x, int y, int colu) { return (x * colu) + y; }

void solution()
{

    ll n = 0, m = 0, k = 0, ans = 0;
    string s;

    cin >> n;

    v64 a(n);
    ll od = 0;
    ll ev = 0;

    forn(i, n)
    {
        cin >> a[i];
        if (a[i] & 1)
        {
            od++;
        }
        else
        {
            ev++;
        }
    }
    if (od >= 3)
    {
        cout << "YES" << nl;
        int od = 3;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & 1) && od)
            {
                cout << (i + 1) << " ";
                od--;
            }
        }
        cout << nl;
        return;
    }
    else if (ev >= 2 && od >= 1)
    {
        cout << "YES" << nl;
        int ev = 2;
        int od = 1;
        for (int i = 0; i < n; i++)
        {
            if (od && (a[i] & 1))
            {
                cout << (i + 1) << " ";
                od--;
            }
            else if (ev && (a[i] % 2 == 0))
            {
                cout << (i + 1) << " ";
                ev--;
            }
        }
        cout << nl;
        return;
    }
    cout << "NO" << nl;
}