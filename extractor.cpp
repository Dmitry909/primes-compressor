#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <fstream>
#include <map>
#include <algorithm>

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
    freopen("compressed", "rb", stdin);
    freopen("decompressed.txt", "wb", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(4);
}

// #define int ll

const int MAXE = 1e5 + 10;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int W = 1e6 + 100;
const int K = 1000 + 1;

void Solve() {
    map<string, int> m;
    m["10001"] = 1;
m["01111"] = 2;
m["0101"] = 3;
m["00011"] = 4;
m["10011"] = 5;
m["11011"] = 6;
m["111101"] = 7;
m["110001"] = 8;
m["10101"] = 9;
m["110011"] = 10;
m["101101"] = 11;
m["00001"] = 12;
m["1110111"] = 13;
m["001011"] = 14;
m["111111"] = 15;
m["0110101"] = 16;
m["0110111"] = 17;
m["001101"] = 18;
m["0010011"] = 19;
m["0110011"] = 20;
m["1110101"] = 21;
m["11100001"] = 22;
m["10111011"] = 23;
m["0110001"] = 24;
m["10111101"] = 25;
m["00111001"] = 26;
m["11100101"] = 27;
m["00100001"] = 28;
m["101111111"] = 29;
m["11100011"] = 30;
m["001110101"] = 31;
m["001110111"] = 32;
m["00100011"] = 33;
m["1110011011"] = 34;
m["001111111"] = 35;
m["101110001"] = 36;
m["1011100101"] = 37;
m["0011110111"] = 38;
m["001111001"] = 39;
m["0011111001"] = 40;
m["11100110001"] = 41;
m["1110011101"] = 42;
m["00111110111"] = 43;
m["10111110001"] = 44;
m["1011100111"] = 45;
m["111001111101"] = 46;
m["111001111001"] = 47;
m["10111110101"] = 48;
m["101111101111"] = 49;
m["111001100111"] = 50;
m["00111101011"] = 51;
m["001111010001"] = 52;
m["1110011110111"] = 53;
m["111001100101"] = 54;
m["1110011111111"] = 55;
m["1011111011011"] = 56;
m["001111101011"] = 57;
m["0011110100111"] = 58;
m["0011110100101"] = 59;
m["001111101001"] = 60;
m["10111110011101"] = 61;
m["10111110110001"] = 62;
m["1011111001101"] = 63;
m["111001111110111"] = 64;
m["10111110010111"] = 65;
m["11100111111001"] = 66;
m["101111101100111"] = 67;
m["101111100111111"] = 68;
m["10111110010101"] = 69;
m["111001111010011"] = 70;
m["1110011111101011"] = 71;
m["111001111010111"] = 72;
m["1011111011001011"] = 73;
m["1110011110100011"] = 74;
m["111001111010101"] = 75;
m["1011111001001001"] = 76;
m["1011111001111011"] = 77;
m["101111100100001"] = 78;
m["11100111101000011"] = 79;
m["1011111001000101"] = 80;
m["1011111001111001"] = 81;
m["10111110010011101"] = 82;
m["10111110010001111"] = 83;
m["1011111001001101"] = 84;
m["10111110010010101"] = 85;
m["111001111110100001"] = 86;
m["11100111101000001"] = 87;
m["101111101100100101"] = 88;
m["101111100100101111"] = 89;
m["10111110110010001"] = 90;
m["101111100100011011"] = 91;
m["1110011111101001001"] = 92;
m["101111101100100111"] = 93;
m["1011111001001111001"] = 94;
m["1110011111101001011"] = 95;
m["101111100100011001"] = 96;
m["11100111111010011011"] = 97;
m["11100111111010011101"] = 98;
m["1110011111101000111"] = 99;
m["11100111111010001011"] = 100;
m["10111110010011111101"] = 101;
m["1011111001001011011"] = 102;
m["111001111110100111101"] = 103;
m["10111110010010110011"] = 104;
m["1011111001001111101"] = 105;
m["101111100100111101001"] = 106;
m["101111100100111101011"] = 107;
m["111001111110100111111"] = 108;
m["101111100100101100001"] = 109;
m["101111100100111111101"] = 110;
m["111001111110100010011"] = 111;
m["1110011111101001100001"] = 112;
m["1011111001001111011111"] = 113;
m["101111100100111101101"] = 114;
m["1011111001001111111101"] = 115;
m["11100111111010011001001"] = 116;
m["1110011111101001100111"] = 117;
m["11100111111010001000011"] = 118;
m["11100111111010011000111"] = 119;
m["1011111001001111111111"] = 120;
m["10111110010010110001001"] = 121;
m["10111110010010110001011"] = 122;
m["11100111111010001000101"] = 123;
m["111001111110100110001011"] = 124;
m["111001111110100010000011"] = 125;
m["11100111111010001000111"] = 126;
m["1110011111101001100101101"] = 127;
m["101111100100101100011001"] = 128;
m["10111110010010110001111"] = 129;
m["101111100100111101110011"] = 130;
m["1110011111101000100000001"] = 131;
m["101111100100111101110001"] = 132;
m["1110011111101001100010011"] = 133;
m["11100111111010011001011101"] = 134;
m["101111100100111101110111"] = 135;
m["11100111111010011001010101"] = 136;
m["11100111111010011001010011"] = 137;
m["1110011111101001100010001"] = 138;
m["10111110010011110111010011"] = 139;
m["1011111001001011000110101"] = 140;
m["11100111111010011001011111"] = 141;
m["111001111110100010000001111"] = 142;
m["10111110010011110111010101"] = 143;
m["10111110010011110111010111"] = 144;
m["11100111111010001000000101"] = 145;
m["1110011111101001100101000011"] = 146;
m["10111110010010110001101111"] = 147;
m["1110011111101001100101000101"] = 148;
m["11100111111010011001010111101"] = 149;
m["10111110010010110001101101"] = 150;
m["11100111111010011001010111111"] = 151;
m["1011111001001111011101000101"] = 152;
m["1110011111101001100101011101"] = 153;
m["11100111111010001000000110001"] = 154;
m["11100111111010001000000110011"] = 155;
m["1011111001001111011101000001"] = 156;
m["111001111110100110010100000111"] = 157;
m["1110011111101001100101011011101"] = 158;
m["1110011111101001100101000111"] = 159;
m["11100111111010011001010110001"] = 160;
m["11100111111010001000000110101"] = 161;
m["1110011111101001100101011011111"] = 162;
m["11100111111010001000000110111"] = 163;
m["111001111110100110010101100101"] = 164;
m["1011111001001111011101000011"] = 165;
m["11100111111010011001010000001"] = 166;
m["111001111110100110010101100111"] = 168;
m["1011111001001111011101000111"] = 170;
m["111001111110100110010101101001"] = 171;
m["111001111110100110010101101011"] = 173;
m["111001111110100110010101101101"] = 177;
m["111001111110100110010100000101"] = 191;
    string curS;
    cout << 2 << nl << 3 << nl;
    ll last = 3;
    unsigned char c = 0;
    int cntEq = 0, cnttt = 0;
    int n;
    fstream nfile("n.txt");
    nfile >> n;
    n -= 2;
    while (cntEq < 100) {
        cnttt++;
        unsigned char c1 = getchar();
        if (c1 != c) {
            cntEq = 0;
        }
        cntEq++;
        c = c1;
        string s;
        unsigned char cc = c;
        forn(i, 8) {
            s += (char)('0' + (cc % 2));
            cc /= 2;
        }
        reverse(all(s));
        for (auto ccc : s) {
            curS += ccc;
            if (m.count(curS)) {
                last += m[curS] * 2;
                cout << last << nl;
                n--;
                if (n <= 0) {
                    exit(0);
                }
                curS.clear();
            }
        }
    }
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
    cout << '\n' << "Time: " << (endTime - startTime) / 1000.0;
    return 0;
}
