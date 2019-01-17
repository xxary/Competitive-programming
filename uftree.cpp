/*動作確認済み
https://abc097.contest.atcoder.jp/tasks/arc097_b
union-find-treeのライブラリをより実践的に改造させる予定
*/


#include<iostream>
#include<vector>

using namespace std;

class unionFtree{
  public:
    vector<int> rank,p;

    unionFtree(){}
    unionFtree(int size){
       rank.resize(size,0);
       p.resize(size,0);
       for (int i=0;i<size;i++) makeSet(i);
     }

    void makeSet(int x){
       p[x] = x;
       rank[x] = 0;
     }

     bool same(int x,int y){
       return findSet(x)==findSet(y);
     }

     void unite(int x,int y){
        link(findSet(x),findSet(y));
     }

     void link(int x,int y){
       if(rank[x]>rank[y]){
          p[y] = x;
       }else{
          p[x] = y;
       if(rank[x]==rank[y]){
          rank[y]++;
       }
     }
   }

    int findSet(int x){
        if(x!=p[x]){
          p[x]=findSet(p[x]);
        }
       return p[x];
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    unionFtree tree = unionFtree(M);
    
    vector<int> P(N+1);
    for(int i=0;i<N;++i) cin>>P[i];
    
    int a,b;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        tree.unite(a,b);
    }
    
    int ans=0;    
    for(int i=0;i<M;++i){
        if(tree.same(i,P[i])) ++ans;
    }
    
    cout<<ans<<endl;
}
