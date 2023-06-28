#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int MergedArrayLen = nums1.size() + nums2.size();
        int half = MergedArrayLen / 2;
        double median = 0;
        int k = 0; // goes to num1
        int j = 0; // goes to num2
       
        vector<int> Merged;
        Merged.resize(MergedArrayLen);
        for (int i = 0; i < MergedArrayLen; i++){
            if (k == nums1.size()){
                Merged[i] = nums2[j];
                j++;
            }
            else if (j == nums2.size()){
                Merged[i] = nums1[k];
                k++;
            }
            else{
                if (nums1[k] < nums2[j]){
                    Merged[i] = nums1[k];
                    k++;
                }
                else{
                    Merged[i] = nums2[j];
                    j++;
                }
            }
        }

        for (int i = 0; i < MergedArrayLen; i++){
            cout << Merged[i] << ", ";
        }
        if (MergedArrayLen % 2 == 0){
            median = (Merged[half] + Merged[half-1]) / 2.0;
        }
        else{
            median = Merged[MergedArrayLen/2];
        }
        return median;
    }
};