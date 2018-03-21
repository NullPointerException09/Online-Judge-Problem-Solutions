/******************************************
          Mobarak Hosen Shakil
        ICE, Islamic University
     ID: mhiceiuk(all), 29698(LOJ)
   E-mail: mhiceiuk @ (Gmail/Yahoo/FB)
 Blog: https://iuconvergent.wordpress.com
*******************************************/
/// Problem Link: http://lightoj.com/volume_showproblem.php?problem=1129

#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define LL long long int
#define ULL unsigned LL

const int inf=1<<30;
const LL INF=1e18;
const int MOD=1e9+7;

struct trie
{
    bool isend;
    int pp[10];

}node[100002];

int main()
{
    int cn, tc=0;
    scanf("%d", &cn);
    while(cn--)
    {
        int n;
        scanf("%d", &n);
        char s[15];
        vector<string>v;
        for(int i=0; i<n; i++)
        {
            scanf("%s", s);
            v.push_back(s);
        }
        int nnode=0;
        bool res=1;
        for(int i=0; i<10; i++)node[0].pp[i]=-1;

        for(int i=0; i<n; i++)
        {
            int len=v[i].length();
            int now=0;
            for(int j=0; j<len; j++)
            {
                if(node[now].pp[v[i][j]-'0']==-1)
                {
                    node[now].pp[v[i][j]-'0']=++nnode;
                    for(int k=0; k<10; k++)
                        node[nnode].pp[k]=-1;
                    node[nnode].isend=0;
                }
                else if(node[node[now].pp[v[i][j]-'0']].isend || j==len-1)
                {
                    res=0;
                    break;
                }
                now=node[now].pp[v[i][j]-'0'];
            }
            if(res!=1)break;
            node[now].isend=1;
        }

        if(res)printf("Case %d: YES\n", ++tc);
        else printf("Case %d: NO\n", ++tc);
    }
    return 0;

}

