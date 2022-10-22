#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int wordBreakUtil(string A, unordered_set<string> &st) {

        int n = A.length();
        if(!n)
            return 1;
        
        for(int i = 1 ; i <= n; i++)
        {
            if((st.find(A.substr(0, i)) != st.end()) && (wordBreakUtil(A.substr(i, n),st)))
                return 1;
        }
        
        return 0;
        
    }

    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> st(B.begin(),B.end());
        
        int n = A.length();
        
        vector<bool> dp(n, false);
        
        for(int i = 0 ; i <= n; i++)
        {
            if(dp[i] == false)
            {
                if(st.find(A.substr(0,i)) != st.end())
                    dp[i] = true;
            }
            
            if(dp[i])
            {
                for(int j = i + 1; j<=n; j++)
                {
                    if(!dp[j] && st.find(A.substr(i, j - i)) != st.end())
                        dp[j] = true;
                }
            }
            
            if(dp[n] == true)
                return true;
        }
        
        
        return dp[n];
    }
 
int main()
{
fastio();
fstream file;
    string word, t, q, filename;
    vector<string> v;
    string res, res_2;
    ll n=0,m=0;
  
    // filename of the file
    cin>>filename;
  
    // opening file
    file.open(filename.c_str());
  
    // extracting words from the file
    while (file >> word)
    {
        cout<<word<<' ';
        v.push_back(word);
    }

    for (int i = 0; i < v.size(); i++)
    {

        if(wordBreak(v[i],v))
        {
            if(v[i].length()>n){
                m=n;
                res_2=res;
                n=v[i].length();
                res=v[i];
            }
            else if(v[i].length()>m){
                m=v[i].length();
                res_2=v[i];
            }
        }
    }

    cout<<"1. Longest Compound Word: "<< res<<'\n'<<"2. Second Longest Compound Word: "<<res_2;

    
return 0;
}