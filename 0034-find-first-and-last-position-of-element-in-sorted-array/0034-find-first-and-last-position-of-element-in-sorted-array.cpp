class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          vector<int> ans;
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;
        int ans1=-1;
        int ans2=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else if(nums[mid]==target){
               // calculate ans1
                int end1=end;
                while(start<end){
                    mid=(start+end)/2;
                  if(nums[mid]==target){
                    end=mid;
                  }
                  else{
                    start=mid+1;
                  }}
                  ans1=(start+end)/2;
                  end=end1;
                  start=ans1;
                  while(start<end){
                    mid=(start+end)/2;
                    if(start==end-1 && nums[start]!=nums[end]){
                        break;
                    }
                    else if(start==end-1 && nums[start]==nums[end]){
                         start=end;
                         break;
                    }
                  if(nums[mid]==target){
                    start=mid;
                  }
                  else{
                    end=mid-1;
                  }}
                  ans2=(start+end)/2;
                  break;
                
            }
        }
        
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        
        return ans;
    }
};