double findKth(int* a, int size_a, int* b, int size_b, int k);
double min(double a, double b);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if (total & 0x1) {
        return findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    } else {
        return (findKth(nums1, nums1Size, nums2, nums2Size, total / 2) + 
        findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1)) / 2.0;
    }
}

double findKth(int* a, int size_a, int* b, int size_b, int k) {
    if (size_a > size_b) return findKth(b, size_b, a, size_a, k); //size_a is equal or smaller than size_b
    if (size_a == 0) return b[k-1];
    if (k == 1) return min(a[0], b[0]);
    int pa = min(k / 2, size_a), pb = k - pa;
    if (a[pa - 1] < b[pb - 1]) {
        return findKth(a + pa, size_a - pa, b, size_b, k - pa);
    } else if (a[pa - 1] > b[pb - 1]) {
        return findKth(a, size_a, b + pb, size_b - pb, k - pb);
    } else {
        return a[pa - 1];
    }
}

double min(double a, double b) {
    return a > b? b : a;
}
