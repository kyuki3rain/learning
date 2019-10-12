#include<bits/stdc++.h>
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
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define SETSIZE 100
#define CNO 10

int main(){
    rep(i,SETSIZE){
        rep(j,CNO){
            cout << rand()%2 << " ";
        }
        cout << rand()%2 << endl;
    }

    return 0;
}