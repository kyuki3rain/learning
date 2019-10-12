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

double randl(){
    return (double)rand()/RAND_MAX;
}

int myRand(int p){
    int rnd;
    while((rnd=rand())==RAND_MAX);
    return (int)((double)rnd/RAND_MAX*p);
}

#define EP 0.15
#define AL 3.75
#define GA 0.8

int main(){
    srand((unsigned)time(NULL));
    int step=10;
    int low=1,high=5;
    vi first(step,low);
    vi second(step,high);
    int arino=10;
    vector<double> felo(step*2,0);
    vvi ari(arino,vi(step,0));
    int turn=100;
    rep(i,arino){
        rep(j,step){
            ari[i][j]=myRand(2);
            cout << ari[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int minimini=inf;
    rep(now,turn){
        int mini=inf;
        double ave=0;
        cout << now << endl << endl;
        rep(i,step*2){
            felo[i]=GA*felo[i];
        }
        rep(i,step){
            cout << felo[i*2] << " ";
        }
        cout << endl;
        rep(i,step){
            cout << felo[i*2+1] << " ";
        }
        cout << endl;
        cout << endl;
        // char p;
        // scanf("%c",&p);
        cout <<endl << "k:";
        vi sum(arino,0);
        rep(i,arino){
            sum[i]=0;
            rep(j,step){
                sum[i]+=(ari[i][j]==0)?first[j]:second[j];
            }
            mini=min(sum[i],mini);
            ave+=sum[i];
        }
        minimini=min(mini,minimini);
        rep(i,arino){
            double k=AL*(1.0/(1+sum[i]-minimini));
            cout << k << " ";
            rep(j,step){
                felo[j*2+ari[i][j]]+=k;
                if(randl()<0.01){
                    felo[j*2+ari[i][j]]=felo[j*2+(ari[i][j]+1)%2];
                }
            }
        }
        cout << endl << endl;
        rep(i,arino){
            rep(j,step){
                if(randl()<EP||felo[j*2]==felo[j*2+1]){
                    ari[i][j]=myRand(2);
                }
                else{
                    ari[i][j]=(felo[j*2]>felo[j*2+1])?0:1;
                }
                cout << ari[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl;
        cout << mini << " " << ave/10 << endl;
        cout << endl;
        
    }


    return 0;
}