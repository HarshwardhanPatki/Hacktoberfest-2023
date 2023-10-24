//User function Template for C++

class Solution
{
public:
    void nextPermutation(vector<int> &v)
    {
        int n = v.size();
        int index=-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(v[i] < v[i+1])
            {
                index=i;
                break;
            }
        }
        
        if(index !=-1)
        {
            for(int i=n-1;i>=index;i--)
            {
                if(v[i] > v[index])
                {
                    swap(v[i],v[index]);
                    break;
                }
            }
        }
        
        reverse(v.begin()+index+1,v.end());
    }
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> v;
        // for(int i=1;i<=n;i++) v.push_back(i);
        // int cnt=0;
        // while(++cnt<k)
        // {
        //     for(auto it:v) cout<<it<<" ";
        //     cout<<endl;
        //     nextPermutation(v);
        // }
        // string ans="";
        // for(auto it:v)
        // {
        //     ans += to_string(it);
        // }
        // return ans;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            v.push_back(i);
        }
        v.push_back(n);
        --k;
        string ans="";
        while(1)
        {
            ans += to_string(v[k/fact]);
            v.erase(v.begin() + k/fact);
            if(v.size()==0)
            {
                break;
            }
            k = k%fact;
            fact = fact/v.size();
        }
        return ans;
    }
    
};
