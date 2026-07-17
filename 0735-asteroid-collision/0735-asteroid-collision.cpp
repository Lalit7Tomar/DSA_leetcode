class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stable;
        for(int i=0;i<asteroids.size();i++){
            int j=asteroids[i];
            bool destroyed=false;
            while(!stable.empty() && stable.back()>0 && j<0){
                
                     
                     if(stable[stable.size()-1]<-1*j){
                         stable.pop_back();
                         
                    }
                    else if(stable[stable.size()-1]==-1*j){
                        stable.pop_back();
                        destroyed=true;
                    break;
                    }
                    
                else{
                    destroyed=true;
                    break;
                }
                 

            }
             if(destroyed==false){
                  stable.push_back(j);  
                  }

        }
        return stable;
        
    }
};