#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define x first
#define y second
const int N=310;
typedef pair<int,int>PII;
PII q[N*N];

char g[N][N];//存题图
int n,m;
int sx,sy;//起点
int res;//结果
PII cs[2];//存传送装置;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0}; 
int dist[N][N];
int bfs(int x1,int y1){
    memset(dist,-1,sizeof dist);
    q[0]={x1,y1};
    dist[x1][y1]=0;
    int hh=0,tt=1;
    while(hh<tt){
        auto t=q[hh++];
            for(int i=0;i<4;i++){
                int a=t.x+dx[i],b=t.y+dy[i];
                if(a<0||a>=n||b<0||b>=m||dist[a][b]>=0||g[a][b]=='#')continue;
                else if('A'<=g[a][b]&&g[a][b]<='Z'){
                    for(int j=0;j<2;j++){
                        if(a!=cs[j].x||b!=cs[j].y)q[tt++]={cs[j].x,cs[j].y};
                        dist[cs[j].x][cs[j].y]=dist[t.x][t.y]+1;
                    }
                }
                else {
                    dist[a][b]=dist[t.x][t.y]+1;
                    q[tt++]={a,b};
                }
                if(g[a][b]=='=')return dist[a][b];
            }
    }return -1;
}

int main(){
    cin>>n>>m;
    int t=0;
    for(int i=0;i<n;i++)
        scanf("%s",g[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='@'){
                sx=i;
                sy=j;
            }
            if('A'<=g[i][j]&&g[i][j]<='Z'){
                cs[t++]={i,j};
            }
        }
    }

    res=bfs(sx,sy);
    printf("%d",res);
    return 0;
}
