class MinStack {
public:
   
   stack<long long> st;
   long long min=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        long long x=(long long)val;
      if(st.empty()){
        st.push(x);
        min=x;
        }
      else if(x<min && !st.empty()){
        st.push(2*x-min);
        min=x;
      }
      else {
        st.push(x);
      }
     }
     
    
    void pop() {
       if(st.empty()) return;
       if(st.top()<min){
        min=2*min-st.top();
        }
         st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<min){
           return min;
        }
        else{
           return st.top();
        }

    }
    
    int getMin() {
        return min;
    }
};
