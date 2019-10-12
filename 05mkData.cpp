#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define frep(i, m, n) for(int i = m;i < n;i++)
#define frepr(i, m, n) for(int i = m;i >= n;i--)
#define vsort(v) sort(v.begin(),v.end())
#define ll long long
#define inf 999999999
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vst;
typedef pair<int, int> P;
// typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

double randl(){
    return (double)rand()/RAND_MAX;
}

int myRand(int p){
    int rnd;
    while((rnd=rand())==RAND_MAX);
    return (int)((double)rnd/RAND_MAX*p);
}

vi pow2(32);
void pow(){
    pow2[0]=1;
    frep(i,1,32){
        pow2[i]=pow2[i-1]*2;
        // cout << i << " " << pow2[i] << endl;
    }
}

int main(){
    srand((unsigned)time(NULL));

    int p;
    cin >> p;
    cout << p << endl;
    pow();
    rep(i,pow2[p]){
        int k=0;
        rep(j,p){
            int s=((i&pow2[j])==0)?0:1;
            cout << s << " ";
            k+=s;
        }
        if(k>p/2)cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}