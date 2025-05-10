# 优先级
## ErrorCase

### Case1 >>
Error:
       int mid = left + (right - left) >> 1;
OK:
       int mid = left + ((right - left) >> 1);



# 模版

## BinarySearch


### 红蓝染色法
[0, left] 为蓝色
[right, N) 为红色
明确isBlue的条件，然后明确return left/right or+-1
优点1 ： 不用考虑+-1
优点2： 不用考虑==等情况

``` CPP
int BlueRedSplit(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size();

    while(left+1 < right) {
        int mid = left + ((right-left) >> 1);
        if (isBlue(nums[mid], target)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // or return left+-1, right+-1 depends on the problems
    return left;
}


```

