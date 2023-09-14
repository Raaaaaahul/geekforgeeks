class Solution{
private:
    long long merge(long long arr[], long long ans[], int start, int end){
        
        //Initiating inverseCount with 0:
        long long inverseCount = 0;
        
        //Calculating mid:
        long long mid = start + (end-start)/2;
        
        //Index for the left part i.e. from start to mid:
        long long indexLeft = start;
        
        //Index for the right part i.e. from mid+1 to end:
        long long indexRight = mid+1;
        
        //Index for ans array:
        long long indexAns = start;
        
        //Merging:
        while((indexLeft <= mid) && (indexRight <= end)){
            
            if(arr[indexLeft] <= arr[indexRight]){
                
                ans[indexAns++] = arr[indexLeft++];
                
            }
            else{
                
                inverseCount = inverseCount + (mid+1-indexLeft);
                ans[indexAns++] = arr[indexRight++];
                
            }
            
        }
        
        //Copying remaining element of the left part:
        while(indexLeft <= mid){
            
            ans[indexAns++] = arr[indexLeft++];
            
        }
        
        //Copying remaining element of the right part:
        while(indexRight <= end){
            
            ans[indexAns++] = arr[indexRight++];
            
        }
        
        //Copying ans to arr:
        for(int i = start; i <= end; i++){
            
            arr[i] = ans[i];
            
        }
        
        return inverseCount;
        
    }
    
    long long count(long long arr[], long long ans[], int start, int end){
        
        //Base Case:
        if(start >= end)
            return 0;
         
         //Initiating inversion count with 0:
         long long inverseCount = 0;
         
        //Calculating mid:
        long long mid = start + (end-start)/2;
        
        //Fetching the inverseCount for the left part:
        inverseCount = inverseCount + count(arr, ans, start, mid);
        
        //Fetching the inversionCount for the right part:
        inverseCount = inverseCount + count(arr, ans, mid+1, end);
        
        //Fetching the inversionCount while merging:
        inverseCount = inverseCount + merge(arr, ans, start, end);
        
        return inverseCount;
        
    }
public:
    long long int inversionCount(long long arr[], long long N)
    {
        //Creating an array of same size as arr to copy elements while merging:
        long long ans[N];
        
        long long inverseCount = count(arr, ans, 0, N-1);
        
        return inverseCount;
    }

};