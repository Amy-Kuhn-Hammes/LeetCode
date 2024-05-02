void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int aux[nums1Size], one = 0, two = 0, i;
    for(i = 0; i < m+n; i++) {
        if(two == n || (one != m && nums1[one] < nums2[two])) {
            aux[i] = nums1[one];
            one++;
        }else{
            aux[i] = nums2[two];
            two++;
        }
    }
    for(i = 0; i < m+n; i++) {
        nums1[i] = aux[i];
    }
}