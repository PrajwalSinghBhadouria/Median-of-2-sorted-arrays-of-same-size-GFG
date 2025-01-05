//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Your code goes here
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        vector<int> v;
        while(i<n && j<m){
            if(a[i]<b[j]){
                v.push_back(a[i]);
                i++;
            }
            else{
                v.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(a[i]);
            i++;
        }
        while(j<m){
            v.push_back(b[j]);
            j++;
        }
        int size = v.size();
        double ans;
        if(size%2==0){
            ans = (double)(v[(size/2)-1]+v[(size/2)])/2;
            return ans;
            
        }
        ans = v[((size+1)/2)-1];
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOf2(array1, array2);
        int converted = static_cast<int>(ans);
        if (converted == ans) {
            cout << converted << endl;
        } else {
            cout << fixed << setprecision(1) << ans << endl;
        }

        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
