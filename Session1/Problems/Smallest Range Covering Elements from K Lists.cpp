#include<bits/stdc++.h>
using namespace std;
vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int>ans;
    int k = nums.size();
    vector<pair<int,int>>vec;
    for(int i=0;i<k;i++){
        for(auto itr:nums[i]){
            vec.push_back({itr,i});
        }
    }
    sort(vec.begin(),vec.end());
    int l=0;
    int r=0;
    unordered_map<int,int>cnt;
    while(r<vec.size()){
        cnt[vec[r].second]++;
        while(cnt.size()==k){
            if(ans.empty() or (vec[r].first-vec[l].first)<(ans[1]-ans[0])){
                ans = {vec[l].first,vec[r].first};
            }
            cnt[vec[l].second]--;
            if(cnt[vec[l].second]==0){
                cnt.erase(vec[l].second);
            }
            l++;
        }
        r++;
    }
    return ans;
}