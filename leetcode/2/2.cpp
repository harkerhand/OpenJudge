#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int min;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                min = nums1[i++];
                ans.push_back(min);
                continue;
            }
            min = nums2[j++];
            ans.push_back(min);
        }
        while (i < nums1.size())
        {
            ans.push_back(nums1[i++]);
        }
        while (j < nums2.size())
        {
            ans.push_back(nums2[j++]);
        }
        for (auto i : ans)
        {
            cout << i << ' ';
        }

        return (ans.size() % 2) ? ans[ans.size() / 2] : ((ans[ans.size() / 2 - 1] + ans[ans.size() / 2]) / 2.0);
    }
};
int main()
{
    Solution a;

    vector<int> aa = {1, 2};
    vector<int> bb = {3, 4};
    a.findMedianSortedArrays(aa, bb);
}