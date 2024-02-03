#include <bits/stdc++.h> 
using namespace std;
int maximumScore(int num1, int num2, int num3) 
{
	// Write Your Code here
	int ans=0;
    priority_queue<int>q;
    q.push(num1);
    q.push(num2);
    q.push(num3);
    while(q.size()>1)
    {
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        x--;
        y--;
        if(x){
            q.push(x);
        }
        if(y){
            q.push(y);
        }
        ans++;
    }
    return ans;
}