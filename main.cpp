/* #region header */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// types
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<ll, ll> Pl;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
template <typename T> using mat = vector<vector<T>>;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<char>> vvc;
// abreviations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep_(i , a_, b_, a, b, ...) for (ll i = (a); i < b; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define rrep_(i, a_, b_, a, b, ...) for (ll i = (b - 1); i >= a; i--)
#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define srep(i, a, b, c) for (ll i = (a); i < b; i += c)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp make_pair
//入出力
#define print(x) cout << x << endl
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return os;
}
void scan(int &a) {
    cin >> a;
}
void scan(long long &a) {
    cin >> a;
}
void scan(char &a) {
    cin >> a;
}
void scan(double &a) {
    cin >> a;
}
void scan(string &a) {
    cin >> a;
}
template <class T> void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
#define vsum(x) accumulate(all(x), 0LL)
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// functions
// gcd(0, x) fails.
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll safemod(ll a, ll b) {
    return (a % b + b) % b;
}
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> T mypow(T x, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}
ll modpow(ll x, ll n, const ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}

uint64_t my_rand(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
int popcnt(ull x) {
    return __builtin_popcountll(x);
}
template <typename T> vector<int> IOTA(vector<T> a) {
    int n = a.size();
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });
    return id;
}
struct Timer {
    clock_t start_time;
    Timer() {
        start_time = clock();
    }
    void reset() {
        start_time = clock();
    }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
template <int Mod> struct modint {
    int x;

    modint() : x(0) {
    }

    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {
    }

    modint &operator+=(const modint &p) {
        if ((x += p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator-=(const modint &p) {
        if ((x += Mod - p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % Mod);
        return *this;
    }

    modint &operator/=(const modint &p) {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const {
        return modint(-x);
    }

    modint operator+(const modint &p) const {
        return modint(*this) += p;
    }

    modint operator-(const modint &p) const {
        return modint(*this) -= p;
    }

    modint operator*(const modint &p) const {
        return modint(*this) *= p;
    }

    modint operator/(const modint &p) const {
        return modint(*this) /= p;
    }

    bool operator==(const modint &p) const {
        return x == p.x;
    }

    bool operator!=(const modint &p) const {
        return x != p.x;
    }

    modint inverse() const {
        int a = x, b = Mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        long long t;
        is >> t;
        a = modint<Mod>(t);
        return (is);
    }

    static int get_mod() {
        return Mod;
    }

    constexpr int get() const {
        return x;
    }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {
    }

    operator int() const {
        return to;
    }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

/* #endregion*/
// constant
#define inf 1000000000ll
#define INF 4000000004000000000LL

long long xor64(long long range) {
    static uint64_t x = 88172645463325252ULL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}

int D, N;
vi dx = {1, 0, -1, 0};
vi dy = {0, 1, 0, -1};

bool time_check() {
    static Timer timer;
    if (timer.lap() > 1500)
        return false;
    return true;
}

double calc_score(vi b){
    double score = 0;
    rep(i, D * D - N - 1){
        rep(j, i + 1, D * D - N - 1){
            if (b[i] > b[j])
                score += 1;
        }
    }
    score = (1 - 2 * score / ((D * D - N) * (D * D - N - 1))) * 1e9;
    return score;
}

vector<tuple<int, int, int>> greedy(mat<int> souko, set<tuple<int, int, int>> reacheable){
    vector<tuple<int, int, int>> res;
    int n = 0;
    rep(i, D){
        rep(j, D){
            if(souko[i][j] > 0) n++;
        }
    }
    rep(_, n){
        auto iter = reacheable.begin();
        auto [t, x, y] = *iter;
        res.emplace_back(t, x, y);
        reacheable.erase(iter);
        souko[x][y] = 0;
        rep(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= D || ny >= D)
                continue;
            if (souko[nx][ny] == 0 || souko[nx][ny] == -1)
                continue;
            reacheable.emplace(souko[nx][ny], nx, ny);
        }
    }
    return res;
}

struct State{
    double score;
    mat<int> souko;
    set<tuple<int, int, int>> reacheable;
    vi b;
    vector<pair<int, int>> hist;

    State(mat<int> souko, set<tuple<int, int, int>> reacheable) : souko(souko), reacheable(reacheable){}

    // for beam search
    vector<State> get_next_states(){
        vector<State> next_states;
        for(auto [t, x, y]: reacheable){
            State next_state = *this;
            next_state.souko[x][y] = 0;
            next_state.reacheable.erase({t, x, y});
            next_state.b.emplace_back(t);
            next_state.hist.emplace_back(x, y);
            rep(i, 4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= D || ny >= D)
                    continue;
                if (souko[nx][ny] == 0 || souko[nx][ny] == -1)
                    continue;
                next_state.reacheable.emplace(souko[nx][ny], nx, ny);
            }
            auto res = greedy(next_state.souko, next_state.reacheable);
            vi b_ = next_state.b;
            for(auto [t_, x_, y_]: res){
                b_.emplace_back(t_);
            }
            next_state.score = calc_score(b_);
            next_states.emplace_back(next_state);
        }
        return next_states;
    }  
    bool operator<(const State &rhs) const {
        return score < rhs.score;
    }
};

State chokudai_search(State initial_state, int max_turn){
    vector<priority_queue<State>> beam(max_turn+1);
    beam[0].push(initial_state);
    int chokudai_width = 1;
    while(time_check()){
        rep(t, max_turn){
            rep(i, chokudai_width){
                if(beam[t].empty()) break;
                State state = beam[t].top();
                beam[t].pop();
                for(auto next_state: state.get_next_states()){
                    beam[t+1].push(next_state);
                }
            }
        }
    }
    State best_state = beam[max_turn].top();
    return best_state;
}

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(30) << fixed;
    cerr << setprecision(30) << fixed;
    cin >> D >> N;
    mat<int> souko(D, vi(D));
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        souko[x][y] = -1;
    }
    vector<pair<int, int>> que;
    auto bfs = [&](int x, int y){
        queue<pair<int, int>> q;
        q.emplace(x, y);
        mat<bool> used(D, vector<bool>(D));
        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            if (souko[x][y] == -1 || used[x][y])
                continue;
            if (souko[x][y] == 0){
                que.emplace_back(x, y);
                used[x][y] = true;
            }
            rep(i, 4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= D || ny >= D)
                    continue;
                q.emplace(nx, ny);
            }
        }
    };
    auto connected_cells = [&](int x, int y){
        queue<pair<int, int>> q;
        q.emplace(x, y);
        mat<bool> used(D, vector<bool>(D));
        used[x][y] = true;
        int cnt = 0;
        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            cnt++;
            rep(i, 4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= D || ny >= D)
                    continue;
                if (used[nx][ny])
                    continue;
                if (souko[nx][ny] != 0)
                    continue;
                used[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
        return cnt;
    };
    bfs(0, D / 2);
    reverse(all(que));
    que.pop_back();
    reverse(all(que));

    rep(i, D * D - N - 1){
        int t;
        cin >> t;
        t++;
        int idx = t - 1;
        if(t > 15) idx = min(SZ(que) - 1, t + 2);
        int x, y;
        int j = 0;
        while(true){
            tie(x, y) = que[idx];
            if(j % 2 == 0){
                idx += j / 2 + 1;
            }else{
                idx -= j / 2 + 1;
            }
            idx = max(0, min(idx, (int)que.size() - 1));
            j++;
            if(souko[x][y] != 0){
                continue;
            }
            souko[x][y] = t;
            if(connected_cells(0, D / 2) != D * D - N - i - 1){
                souko[x][y] = 0;
                continue;
            }
            break;
        }
        cout << x << ' ' << y << endl;
    }
    

    set<tuple<int, int, int>> reacheable;
    reacheable.emplace(souko[0][D / 2 - 1], 0, D / 2 - 1);
    reacheable.emplace(souko[0][D / 2 + 1], 0, D / 2 + 1);
    reacheable.emplace(souko[1][D / 2], 1, D / 2);
    State state(souko, reacheable);
    state = chokudai_search(state, D * D - N - 1);
    // auto res = greedy(souko, reacheable);
    vi b = state.b;
    for(auto [x, y]: state.hist){
        cout << x << ' ' << y << endl;
    }

    double score = calc_score(b);
    cerr << score << endl;
}