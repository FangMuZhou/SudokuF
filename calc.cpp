#include<iostream>
#include<bitset>
using namespace std;
struct pos{
    int x,y;
};
bitset<10> hang[9];
bitset<10> lie[9];
bitset<10> ge[3][3];
int a[9][9],lg2[1025];
int cnt; //需要填的数的总数
int lowbit(int x){
    return x&(-x);
}
pos getnext(){    //选择”能填合法数字“最少的位置作为下一个分支
    pos res={0,0};
    int minn=10;
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            if (!a[i][j]){
                bitset<10> tmp=(hang[i]&lie[j]&ge[i/3][j/3]);
                if ((int)tmp.count()<minn){
                    res=(pos){i,j};
                    minn=tmp.count();
                }
            }
        }
    }
    return res;
}
bool dfs(int x){
    if (x==cnt+1){    //填完了，边界
        for (int i=0;i<9;++i){
            for (int j=0;j<9;++j){
                cout << a[i][j] << ",";
            }
            cout << "\n";
        }
        return 1;
    }
    pos nx=getnext();
    int xx=nx.x,yy=nx.y;
    int tmp=(hang[xx]&lie[yy]&ge[xx/3][yy/3]).to_ulong(); //综合下来能填的
    while(tmp>0){
        int llb=lowbit(tmp);
        int lb=lg2[llb]; //取出对应的数字
        hang[xx][lb]=lie[yy][lb]=ge[xx/3][yy/3][lb]=0;
        a[xx][yy]=lb;
        // printf("%d %d %d\n",xx,yy,a[xx][yy]);
        if (dfs(x+1)) return 1; //减小时间复杂度，若成功填出，直接步步退出
        hang[xx][lb]=lie[yy][lb]=ge[xx/3][yy/3][lb]=1;
        a[xx][yy]=0; //回溯
        tmp-=llb;
    }
    return 0;
}
void init(){
    for (int i=0;i<9;++i){
        hang[i].set();
        lie[i].set();
        ge[i/3][i%3].set();
        hang[i].reset(0);
        lie[i].reset(0);
        ge[i/3][i%3].reset(0);
    }
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            a[i][j]=0;
        }
    }
    cnt=0;
}
int main(){
    freopen("res.txt","r",stdin);
    freopen("solution.csv","w",stdout);
    for (int i=2;i<=1024;++i){ //预处理
        lg2[i]=lg2[i/2]+1;
    }
    init();
    char c=getchar();
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            if (c=='.') ++cnt;    //统计
            if (c!='.'){
                a[i][j]=c-48;
                hang[i][c-48]=0;
                lie[j][c-48]=0;
                ge[i/3][j/3][c-48]=0;
            }
            c=getchar();
        }
    }
    dfs(1);
    return 0;
}