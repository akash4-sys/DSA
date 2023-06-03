// Data structures
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define pb push_back
#define p pair<int, int>
#define ll long long
#define vp vector<p>
#define pp pop_back
#define t tuple<int, int, int>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>

// Loops
#define loop(i, n) for (int i = 0; i < n; i++)
#define eloop(i, n) for (int i = 0; i <= n; i++)
#define rloop(i, n) for (int i = n; i >= 0; i--)
#define gloop(i, n) for (int i = n; i > 0; i--)

// Fast
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// I/O
#define II ({ int a; cin>>a; a; })
#define LL ({ Long a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout<<x
#define pl(x) cout<<x<<"\n"
#define br cout<<"\n"
#define pv(v) ({ for(auto &x : v) pf(x)<<" "; })
#define pvv(vv) ({ for(auto &v : vv) pv(v), br; })
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

// Misc
#define vowels {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}}
#define dfsExit(v, i, j) if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size())

int i, j, dx, dy;
int x = i + dx, y = j + dy;
int dirs[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};      // last 4 are diagonal
#define bfsExit(v, x, y) if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && vis[x][y])

#define fs first
#define sc second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


// knight
int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};