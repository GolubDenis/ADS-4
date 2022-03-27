// Copyright 2021 NNTU-CS
int cbinsearch(int* arr, int size, int value) {
    int i = size - 1;
    int count = 0;
    int step = size;
    while (true) {
        step = step >> 1;
        if (value > arr[i]) {
            i += step;
        } else if (value < arr[i]) {
            i -= step;
        } else if (value == arr[i]) {
            for (; value == arr[i]; i++) {
            }
            i--;
            for (; value == arr[i] && i >= 0; i--) {
                count++;
            }
            break;
        }
        if (step == 0)
            break;
    }
    return count;
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
    }
    return count;
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

