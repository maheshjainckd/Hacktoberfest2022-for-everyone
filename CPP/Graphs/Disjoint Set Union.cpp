class DSU
{
    public:
    vector<ll>v;

    DSU(ll n)
    {
        v = vector<ll>(n+1);
        for(ll i=0;i<=n;i++)
        {
            v[i]=i;
        }
    }

    ll find(ll n)
    {
        if(v[n]==n)
        {
            return n;
        }
        v[n] = find(v[n]);
        return  v[n];
    }
    
    void merge(ll a,ll b)
    {
        ll a1 = find(a);
        ll b1 = find(b);
        if(a1==b1)
        {
            return;
        }
        v[b1]=a1;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n,m1,m2;
    cin>>n>>m1>>m2;

    DSU d1(n),d2(n);
    ll a,b;

    for(ll i=1;i<=m1;i++)
    {
        cin>>a>>b;
        d1.merge(a,b);    
    }

    for(ll i=1;i<=m2;i++)
    {
        cin>>a>>b;
        d2.merge(a,b);    
    }

    vector<pair<ll,ll>>v;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if((d1.find(i)!=d1.find(j)) && (d2.find(i)!=d2.find(j)))
            {
                d1.merge(i,j);
                d2.merge(i,j);
                v.push_back({i,j});
            }
        }
    }

    cout<<v.size()<<"\n";
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }


    return 0;
}
