#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b)
{
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1>r2;
}
int main()
{
    int capacity;
    cin>>capacity; //capacity of the knapsack

    int n;
    cin>>n; //number of items

    vector<pair<int , int > > v(n); //make a container for the items

    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second; //taking profit and weight of each item

    }

sort(v.begin(),v.end(),compare);// sort the items in descending order by ratio
    double ans=0; //profit

    for(int i=0;i<n;i++)
    {
        if(capacity>=v[i].second)
        {
            ans+=v[i].first; //update the profit
            capacity-=v[i].second;//update the capacity

            continue;
        }

        double ratio=(double)v[i].first/v[i].second;
        ans+=ratio*capacity; //update the profit
        capacity=0;
        break;

    }

    cout<<"profit = "<<ans<<endl;
}
