//Maximum of minimum for every window size 
//Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed

class Solution
{
    public:
    //find next maller element to the left
    vector<int> nsell(int arr[],int n){
        vector<int> nsel;
        stack<int> st;
        st.push(0);
        nsel.push_back(-1);
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(st.empty()) nsel.push_back(-1);
            else nsel.push_back(st.top());
            st.push(i);
        }
        return nsel;
    }
    //find next smaller element to the right
    vector<int> nserr(int arr[],int n){
        vector<int> nser(n);
        stack<int> st1;
        nser.push_back(n);
        st1.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
            if(st1.empty()) nser.push_back(n);
            else nser.push_back(st1.top());
            st1.push(i);
        }
        reverse(nser.begin(),nser.end());
        return nser;
    }
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> nsel = nsell(arr,n);
        vector<int> nser = nserr(arr,n);
        
        vector<int> res(n+1);
        for(int i=0;i<n;i++){
            int len = nser[i] - nsel[i] - 1;//window size
            res[len] = max(res[len],arr[i]);
        }
        
        res.erase(res.begin());
        for(int i=res.size()-2;i>=0;i--){
            res[i] = max(res[i],res[i+1]);
        }
        return res;
    }
};
