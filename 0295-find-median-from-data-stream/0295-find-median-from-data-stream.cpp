class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> p;
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        if(pq.empty() || pq.top()>=num){
            pq.push(num);
        }
        else{
            // balance heap
            p.push(num);
        }
        // balance heap
        if(pq.size()>p.size()+1){
            p.push(pq.top());
            pq.pop();
        }
      else if(p.size()>pq.size()+1){
          pq.push(p.top());
          p.pop();
       }
    }
    
    double findMedian() {
       int size=pq.size();
       int s1=p.size();
       if(size>s1){
        return pq.top();
       }
      else if(s1>size){
        return p.top();

      }
      return 0.5*(p.top()+pq.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */