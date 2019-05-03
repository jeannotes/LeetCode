class Solution {
public:
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int len = nums1.size() + nums2.size();
    if (len % 2)
    { // even
        // 1 2 3 4
        return findKthElement(nums1, nums2, (len + 1) / 2);
    }
    else
    {
        // 1 2 3
        return (findKthElement(nums1, nums2, len / 2) + findKthElement(nums1, nums2, 1 + len / 2)) / 2;
    }
}

double min(int x, int y)
{
    return x < y ? x : y;
}

double findKthElement(vector<int> &nums1, vector<int> &nums2, int k)
{
    if (nums1.size() > nums2.size())
        return findKthElement(nums2, nums1, k);
    if (nums1.empty())
        return nums2[k - 1];
    if (nums2.empty())
        return nums1[k - 1];
    if (k == 1)// this really matters, mainly time issue
        return min(nums1[0], nums2[0]);
    int ia = min(k / 2, nums1.size());
    int ib = k - ia;
    if (nums1[ia - 1] < nums2[ib - 1])
    {
        vector<int> new_vec(nums1.begin() + ia, nums1.end());
        return findKthElement(new_vec, nums2, k - ia);
    }
    if (nums2[ib - 1] < nums1[ia - 1])
    {
        vector<int> new_vec(nums2.begin() + ib, nums2.end());
        return findKthElement(nums1, new_vec, k - ib);
    }
    return nums1[ia - 1];
}
};
