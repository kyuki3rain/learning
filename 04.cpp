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
#define AL 3.75
#define GA 0.8

int selectp(vector<P> roulette,int totalfitness){
    int s = myRand(totalfitness);
    rep(i,roulette.size()){
        if(s<roulette[i].second){
            return i;
            break;
        }
        else{
            s-=roulette[i].second;
        }
    }
}

int main(){
    srand((unsigned)time(NULL));
    vector<P> nim(30);
    rep(i,30) cin >> nim[i].first >> nim[i].second;
    vi gene(30);
    pow();
    rep(i,30)gene[i]=myRand(pow2[30]);
    vi pregene(30,0);
    // cout << pow2[30] << endl;
    vector<P> score;
    vi evo(50);

    rep(generation,50){
        // cout << generation << "gen" << endl;
        cout << generation << ",";
        vector<P> score(30,make_pair(0,0));
        ll totalR=0;
        int maxi=0;
        rep(i,30){
            rep(k,30){
                // cout << bitset<30>(gene[i]) << " " << (pow2[k]) << "   " << (gene[i]&pow2[k]) << endl;
                if((gene[i]&pow2[k])==pow2[k]){
                    score[i].first+=nim[k].first;
                    score[i].second+=nim[k].second;
                }
            }
            if(score[i].first>750)score[i].second=0;
            totalR+=score[i].second;
            maxi = max(maxi,score[i].second);
        }
        // rep(i,30) cout << bitset<30>(gene[i]) << "    " << score[i].first << endl;
        cout << maxi << "," << totalR/30 << endl;
        // cout << endl;
        pregene=gene;
        rep(i,30){
            int mm,pp;
            do{
                mm=selectp(score,totalR);
                pp=selectp(score,totalR);
            }while(mm==pp);
            gene[i]=0;
            int cp = myRand(30);
            gene[i]=(pregene[mm]&(pow2[cp]-1))+(pregene[pp]&(pow2[30]-pow2[cp]));
            rep(j,30){
                if(myRand(100)<=1)gene[i]=gene[i]^pow2[j];
            }
        }
        // char tttt;
        // scanf("%c",&tttt);
        Sleep(1000);
    }

    return 0;
}