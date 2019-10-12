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

int rand012(){
    int rnd;
    while((rnd=rand())==RAND_MAX);
    return (double)rnd/RAND_MAX*3;
}

int main(){
    vvi data(SETSIZE,vi(CNO,0));
    vi teacher(SETSIZE,0);
    rep(i,SETSIZE){
        rep(j,CNO){
            cin >> data[i][j];
        }
        cin >> teacher[i];
    }
    int score=0;
    vi answer(CNO);
    int maxScore=0;
    vi maxAnswer(CNO);
    ll now=0;

    // rep(i,SETSIZE){
    //     rep(j,CNO){
    //         cout << data[i][j] << " ";
    //     }
    //     cout << "    " << teacher[i] << endl;
    // }
    srand((unsigned)time(NULL));

    while(score<SETSIZE && now<1000000){
        now++;
        score=0;
        rep(j,CNO){
            answer[j]=rand012();
        }
        rep(i,SETSIZE){
            int point=0;
            rep(j,CNO){
                if(answer[j]==2)point++;
                else if(answer[j]==data[i][j])point++;
            }
            if(point==CNO&&teacher[i]==1)score++;
            else if(point!=CNO&&teacher[i]==0)score++;
        }
        if(maxScore<score){
            cout << now << "    ";
            maxAnswer=answer;
            maxScore=score;
            rep(i,CNO)cout << maxAnswer[i] << " ";
            cout << "   " << maxScore << endl;
        }
        // else cout << "x";
    }

    return 0;
}