/******************************************
          Mobarak Hosen Shakil
        ICE, Islamic University
     ID: mhiceiuk(all), 29698(LOJ)
   E-mail: mhiceiuk @ (Gmail/Yahoo/FB)
 Blog: https://iuconvergent.wordpress.com
*******************************************/

/// Problem Link: https://devskill.com/CodingProblems/ViewProblem/498


#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define LL long long int
#define ULL unsigned LL

const int inf=1<<30;
const LL INF=1e18;
const int MOD=1e9+7;

int a[100005], v;

pair<int, int> pq[300005];

int SOD(int n)
{
    int sum=0;
    while(n!=0)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}

pair<int, int> SegmentTreeBuild(int l, int r, int pos)
{
    pair<int, int> x, y;
    if(l==r)
    {

        pq[pos]=make_pair(a[l], l);
        return pq[pos];
    }
    x=SegmentTreeBuild(l, (l+r)/2, pos*2);
    y=SegmentTreeBuild((l+r)/2+1, r, pos*2+1);

    if(y.first>x.first) pq[pos]=y;
    else pq[pos]=x;

    return pq[pos];
}

pair<int, int> Segmentquery(int l, int r, int s, int e, int pos)
{
    pair<int, int> x, y;
    if(s<=l and e>=r) {
        return pq[pos];
    }
    if(s>r or e<l) {
        return make_pair(-inf, 0);
    }
    x=Segmentquery(l, (l+r)/2, s, e, pos*2);
    y=Segmentquery((l+r)/2+1, r, s, e, pos*2+1);

    if(y.first>x.first) return y;
    else return x;

}

int main()
{
    int tn, cn=0;
    scanf("%d", &tn);
    while(tn--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &v);
            a[i]=SOD(v);
        }

        printf("Case #%d:\n", ++cn);
        SegmentTreeBuild(1, n, 1);

        while(q--)
        {
            int s, e;
            scanf("%d%d", &s, &e);
            pair<int, int> ans=Segmentquery(1, n, s, e, 1);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}

