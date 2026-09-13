class Solution {
public:
    vector<string> ans;
    vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void recursion(string digits,string curr,int index){
          if(index==digits.size()){
            ans.push_back(curr);
            return;
          }
          int x=(int)digits[index];
          // 65+(x-2)*3+0,1,2
         int digit = digits[index] - '0';
        string letters = mapping[digit];

        for (char ch : letters) {
            curr.push_back(ch);         
            recursion(digits, curr, index + 1); 
            curr.pop_back();          
        }

    }
    vector<string> letterCombinations(string digits) {
      if(digits.empty()) return {};
     string curr;
     recursion(digits,curr,0); 
     return ans;    
    }
};