class Solution {
public:
    vector<string> ans;
    void ans1(int opening,int closing,string temp){ 
       if(opening==0){
        while(closing!=0){
            temp=temp+')';
            closing--;
        }
        ans.push_back(temp);
        return;
       }
        if(opening==closing){
            temp=temp+'(';
            ans1(opening-1,closing,temp);
        }
        else{
            temp=temp+'(';
            ans1(opening-1,closing,temp);
            temp.erase(temp.length()-1);
            if(closing>0){
                temp=temp+')';
                ans1(opening,closing-1,temp);
                temp.erase(temp.length()-1);
            }
        }


    }
    vector<string> generateParenthesis(int n) {
         int closing=n;
         int opening=n;
         string temp;
        ans1(n,n,temp);
        return ans;
    }
};