class MedianFinder {
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num <= left_max_heap.top()){
            left_max_heap.push(num);
        }else{
            right_min_heap.push(num);
        }

        //we have to ensure that the number of elements in the left max heap can be at most 1 greater than the right min heap
        if(left_max_heap.size() > right_min_heap.size() + 1){
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        }else if(right_min_heap.size() > left_max_heap.size()){
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }
    
    double findMedian() {
         if(left_max_heap.size() == right_min_heap.size()){
            double mean = (left_max_heap.top() + right_min_heap.top())/2.0;
            return mean;
        }
        return left_max_heap.top();
    }
};

//TC = O(NlogN) for adding n elements
//SC = O(N)
