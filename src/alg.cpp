// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    if (arr != 0) {
        int ans = 0;
        int cur = size - 1;
        while (cur >= 0) {
            if (arr[cur] == value) {
                ans++;
                cur--;
            }
            if (arr[cur] > value) {
                cur--;
            }
            if (arr[cur] < value) {
                cur = -1;
            }
        }
        return ans;
    }
    return 0;
}
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int halfval = value / 2;
    for (int i = 0; arr[i] <= halfval && i < len; i++) {
        bool found = false;
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                found = true;
                count++;
                continue;
            }
            if (found) {
                break;
        }
    }
    return count
}
int countPairs3(int *arr, int len, int value) {
    int halfval = value / 2;
    int count = 0;
    int halfAmount = cbinsearch(arr, len, halfval);
    for (int i = 0; arr[i] <= halfval && i < len; i++) {
        count += cbinsearch(arr, len, value - arr[i]);
    }
    for (int i = 1; i <= halfAmount; i++) {
        count -= i;
    }
    return count;
}
