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

#define EP 0.15
#define AL 10
#define GA 0.8

// #define input 3
// #define maxh 3
// #define maxData 8

int input,maxh,maxData;

double f(double p){
    return 1.0/(1.0+exp(-p));
}

double percep(vector<double> in,vector<double> wh,double v){
    double p=0;
    rep(i,input){
        p+=in[i]*wh[i];
    }
    return f(p-v);
}

double drand(){
    double rndno;
    while((rndno=(double)rand()/RAND_MAX)==1.0);
    rndno=rndno*2.0-1.0;
    return rndno;
}



int main(){
    pow();
    cin >> input;
    // cin >> maxh;
    maxh = input;
    maxData = input*input;
    srand((unsigned)time(NULL));
    vector<vector<double>> in(maxData,vector<double>(input));
    vector<double> teach(maxData);
    rep(i,maxData){rep(j,input){cin >> in[i][j];}cin >> teach[i];}
    
    vector<vector<double>> wh(maxh,vector<double>(input));
    vector<double> vh(maxh);
    vector<double> w(maxh);
    double v;
    vector<double> h(maxh);

    double err=inf;
    double ans;
    int now=0;
    
    rep(i,maxh)rep(j,input)wh[i][j]=drand();
    rep(i,maxh){vh[i]=drand(); w[i]=drand();}
    v=drand();
    
    while(true){
        now++;
        cout << endl << now << endl;
        rep(nowData,maxData){
            rep(i,maxh){
                h[i]=percep(in[nowData],wh[i],vh[i]);
            }
            ans=percep(h,w,v);
            // cout << endl;
            // cout << ans << " " << v << endl;
            // rep(i,maxh)cout << h[i] << " " << w[i] << " " << endl;
            // cout << endl;
            double d = (teach[nowData]-ans)*ans*(1-ans);
            // cout << d << endl;
            rep(i,maxh){
                w[i]=w[i]+AL*h[i]*d;
            }
            v=v+AL*(-1.0)*d;
            rep(i,maxh){
                double dh = h[i]*(1-h[i])*w[i]*d;
                // cout << dh << " ";
                rep(j,input){
                    wh[i][j]+=AL*in[nowData][j]*dh;
                }
                vh[i]+=AL*(-1.0)*dh;
                err=min(err,abs(teach[nowData]-ans));
            }
            // cout << endl;
            rep(i,input)cout << in[nowData][i] << " ";
            cout << "    ";
            string s="Wrong Answer!";
            if(abs(teach[nowData]-ans)<0.01)s="Correct Answer!";
            cout << teach[nowData] << "   " << ans << "   " << s << endl;
            // cout << endl;
        }
        // if(err/maxData<0.01)break;
        if(now*pow2[input]>=10000)break;
        cout << endl;
    }

    cout << endl;
    cout << ans << " " << v << endl;
    rep(i,maxh)cout << h[i] << " " << w[i] << " " << endl;
    cout << endl;

    return 0;
}