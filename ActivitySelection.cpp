#include<bits/stdc++.h>
using namespace std;

// Comparator function
bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second; // sort by end time in ascending order
}

int main()
{
    vector<pair<int,int> >v;
    int n;
    cin>>n;// number of activities
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        v.push_back({s,e});//push the start and end time
    }
    sort(v.begin(),v.end(),comp); // sort the vector by end time
    int ans=1;
    int end=v[0].second; //end time of the first activity
    cout<<"Start: "<<v[0].first<<" "<<"End: "<<v[0].second<<endl;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>=end)
        {
            ans++; // update the number of activities can be performed
            cout<<"Start: "<<v[i].first<<" "<<"End: "<<v[i].second<<endl;
            end=v[i].second; //update the end time
        }
    }
    cout<<"Number of activities can be performed: "<<ans<<endl;
}
