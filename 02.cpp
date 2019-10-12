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

#define EP 0.3
#define AL 0.1
#define GA 0.9

int main(){
    srand((unsigned)time(NULL));
    int depth;
    cin >> depth;
    int c=100000;
    // cin >> c;
    int nodeno=1;
    rep(i,depth)nodeno*=2;
    vi point(nodeno,0);
    cout << nodeno << endl;
    int maxP=0;
    rep(i,nodeno){
        point[i]=myRand(1000);
        cout << point[i] << " ";
        maxP=max(point[i],maxP);
    }
    cout << endl;
    nodeno=nodeno*2-2;
    vi node(nodeno,myRand(1000));
    vi up2(depth+2,0);
    int p=1;
    rep(i,depth+2){up2[i]=p;p*=2;}

    vi root(depth,0);
    ll now=0;
    while(maxP!=point[root[depth-1]]){
        now++;
        rep(i,depth)root[i]=0;
        rep(i,depth){
            if(randl()<EP){
                root[i]=myRand(up2[i]);
                // cout << up2[i] << endl;
            }
            else{
                if(i==0){
                    if(node[0]>node[1]){
                        root[i]=0;
                    }
                    else{
                        root[i]=1;
                    }
                }
                else{
                    // cout << (up2[i+1]-2)+root[i-1]*2 << endl;
                    if(node[(up2[i+1]-2)+root[i-1]*2]>node[(up2[i+1]-2)+root[i-1]*2+1]){
                        root[i]=root[i-1]*2;
                    }
                    else{
                        root[i]=root[i-1]*2+1;
                    }
                }
            }
            if(now%1000==0){
                rep(i,depth){
                    if(i==0){
                        if(node[0]>node[1]){
                            root[i]=0;
                        }
                        else{
                            root[i]=1;
                        }
                    }
                    else{
                        // cout << (up2[i+1]-2)+root[i-1]*2 << endl;
                        if(node[(up2[i+1]-2)+root[i-1]*2]>node[(up2[i+1]-2)+root[i-1]*2+1]){
                            root[i]=root[i-1]*2;
                        }
                        else{
                            root[i]=root[i-1]*2+1;
                        }
                    }
                }
                cout << endl;
                cout << point[root[depth-1]] << "," << maxP << "     ";

                if(maxP==point[root[depth-1]]){cout << "Correct!"; break;}
                else {cout << "No!";}
            }
        }
        rep(i,depth){
        // cout << up2[depth-i]-2+root[depth-i-1] << " " << root[depth-i-1];
        // cout << " " << up2[depth-i+1]-2+root[depth-i-1]*2 << endl;
        //     rep(j,depth+2)cout << up2[j] << " ";
            // cout << endl;
            if(i==0){  
                node[up2[depth-i]-2+root[depth-i-1]]+=AL*(point[root[depth-i-1]]-node[up2[depth-i]-2+root[depth-i-1]]);
            }
            else{
                node[up2[depth-i]-2+root[depth-i-1]]+=AL*(max(node[up2[depth-i+1]-2+root[depth-i-1]*2],node[up2[depth-i+1]-2+root[depth-i-1]*2+1])*GA-node[up2[depth-i]-2+root[depth-i-1]]);
            }
        }
        // cout << endl;
    }
    cout << endl << endl;
    // rep(i,depth){
    //     rep(j,up2[i+1]){
    //         cout << node[up2[i+1]-2+j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << endl << endl;
    cout << now << endl;
    

    return 0;
}