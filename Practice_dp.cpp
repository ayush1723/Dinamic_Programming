#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

//////////////////////////<-Template->//////////////////////////
#define ll long long int
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define PI 3.1415926535897932384626433832795
#define F first
#define S second
#define pb push_back
///////////////////////<-Data Struture->////////////////////////
#define vii vector<int>
#define vll vector<long long>
#define mp map<int, int>
#define mpl map<long long, long long>
#define pq priority_queue<int>
#define pql priority_queue<long long>
#define st set<int> 
#define stl set<long long>
///////////////////////<-Daily use->////////////////
#define MOD 1000000007

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

//<------------------------------------------------------------------------------------------------------------------------------------------------------------>//

void debugll(vector<ll> &v){
    for(ll i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void debug(vector<int> &v){
    for(ll i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int repeat = 0;
int repeat2 = 0;
int fibo(int n){
    repeat++;
    if(n == 1 || n == 2){
        return 1;
    }
    return fibo(n-1) + fibo(n - 2);
}

int fibo_mem(int n, vector<int> &v){
    repeat2++;
    if(n == 1 || n == 2){
        return 1;
    }

    if(v[n] != -1){
        return v[n];
    }
    return v[n] = fibo_mem(n - 1, v) + fibo_mem(n - 2, v);
}

int fibo_dp(int n, vector<int> &v){
    v[1] = 1;
    v[2] = 1;
    for(int i = 3; i <= n; i++){
        v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n + 1, -1);

    // cout << fibo(n) << endl;  -------> recursive:
    // cout << repeat << endl;   -------> no. of repeation it took:

    // cout << fibo_mem(n, v) << endl; --------> Memoization:
    // cout << repeat2 << endl;  --------------> no. of repeation it took:

    cout << fibo_dp(n, v) << endl; //------------> dp solution:
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}