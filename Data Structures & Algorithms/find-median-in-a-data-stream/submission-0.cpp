class MedianFinder {
    vector<int> data;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.push_back(num);
        sort(data.begin(), data.end());
    }
    
    double findMedian() {
        int len = data.size();
        if(len%2 == 0){
            int a = len/2;
            double mean = (data[a-1] + data[a])/2.0;
            return mean;
        }
        return data[len/2];
    }
};
