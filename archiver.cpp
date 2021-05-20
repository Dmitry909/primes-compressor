#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <fstream>

using namespace std;

template<typename T>
istream &operator>>(istream &in, vector<T> &x) {
    for (auto &i : x)
        in >> i;
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &x) {
    for (auto &i : x) {
        out << i << " ";
    }
    return out;
}

template<typename T, typename D>
istream &operator>>(istream &in, pair<T, D> &x) {
    in >> x.first >> x.second;
    return in;
}

template<typename T, typename D>
ostream &operator<<(ostream &out, const pair<T, D> &x) {
    out << x.first << " " << x.second;
    return out;
}

struct LogOutput {
    template<typename T>
    LogOutput &operator<<(T x) {
#ifdef Dmitry07
        cout << x;
#endif
        return *this;
    }
} dout;

typedef long long ll;
typedef unsigned long long ull;
typedef double dl;

#define nl '\n'
#define elif else if
#define all(_v) _v.begin(), _v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)(v.size())
#define sqr(_v) ((_v) * (_v))
#define vpi vector<pair<int, int>>
#define eb emplace_back
#define pb push_back
// #define MOD1(x, m) ((x) % m + ((x) < 0  && ((x % m) != 0) ? m : 0))
#define mod(x, m) (((x) % (m) + (m)) % (m))
#define vi vector<int>
#define pi pair<int, int>
#define ti tupMXle<int, int, int>
#define minq(x, y) x = min((x), (y))
#define maxq(x, y) x = max((x), (y))
#define forn(i, n) for (int i = 0; i < (n); ++i)

const ll INFL = 1e15;  // 9187201950435737471;
const ll nINFL = -9187201950435737472;
const int INF = 1e9 + 10;  // 2139062143;
const int nINF = -2139062144;
const ull ULINF = numeric_limits<ull>::max();
const dl PI = acos(-1);
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(seed);

inline void IO() {
    freopen("input.txt", "r", stdin);
    freopen("compressed", "wb", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(4);
}

// #define int ll

const int MAXN = 2.1e9 + 10;
const int MAXE = 1e5 + 10;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int W = 1e6 + 100;
const int K = 1000 + 1;

bitset<MAXN> resh;
int cnt[2000], le[10000], ri[10000], sum[10000], siz = 0, symb[10000];
string code[2000];

string ss;

void dfs(int v) {
    if (le[v] == -1) {
        code[symb[v]] = ss;
        return;
    }
    ss += '0';
    dfs(le[v]);
    ss.pop_back();
    ss += '1';
    dfs(ri[v]);
    ss.pop_back();
}

void Solve() {
    int last = 0, prs = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (!resh[i]) {
            if (i > 3) {
                cnt[(i - last) / 2]++;
            }
            prs++;
            last = i;
            for (ll j = i * 2; j < MAXN; j += i) {
                resh[j] = 1;
            }
        }
    }
    // cout << prs << nl;
    /*vi pr;
    for (int i = 2; i < MAXN; i++) {
        if (resh[i] == 0) {
            resh[i] = i;
            pr.push_back(i);
            if (i > 3) {
                cnt[(i - last) / 2]++;
            }
            last = i;
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= resh[i] && i * pr[j] <= MAXN; ++j)
            resh[i * pr[j]] = pr[j];
    }*/
    set<pi > s;
    forn(i, 2000) {
        if (cnt[i]) {
            s.insert({ cnt[i], siz });
            le[siz] = ri[siz] = -1;
            sum[siz] = cnt[i];
            symb[siz] = i;
            siz++;
        }
    }
    while (s.size() > 1) {
        auto[p1, id1] = *s.begin();
        s.erase(s.begin());
        auto[p2, id2] = *s.begin();
        s.erase(s.begin());
        le[siz] = id1;
        ri[siz] = id2;
        sum[siz] = sum[id1] + sum[id2];
        s.insert({ sum[siz], siz });
        siz++;
    }
    dfs(siz - 1);
    forn(i, 2000) {
        if (cnt[i]) {
            code[i] += '1';
            // cout << "m[" << '"' << code[i] << '"' << "] = " << i << ";\n";
        }
    }
    resh.reset();
    unsigned char lastChr = 0;
    int lastSz = 0;
    last = 0, prs = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (!resh[i]) {
            if (i > 3) {
                for (auto c : code[(i - last) / 2]) {
                    lastChr *= 2;
                    lastChr += (c - '0');
                    lastSz++;
                    if (lastSz == 8) {
                        cout << lastChr;
                        c = 0;
                        lastSz = 0;
                    }
                }
                cnt[(i - last) / 2]++;
            }
            last = i;
            for (ll j = i * 2; j < MAXN; j += i) {
                resh[j] = 1;
            }
        }
    }
    while (lastSz < 8) {
        lastChr *= 2;
        lastSz++;
    }
    cout << lastChr;
}

signed main() {
    IO();
    int t = 1;
    //    cin >> t;
    int startTime = clock();
    while (t--) {
        Solve();
    }
    int endTime = clock();
    // cout << '\n' << "Time: " << (endTime - startTime) / 1000.0;
    return 0;
}
