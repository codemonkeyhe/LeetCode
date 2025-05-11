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


### lower_bound返回的是迭代器

#### leetcode2089
``` cpp

    vector<int> targetIndicesM2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        // first >=
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || (*it != target)) {
            return res;
        }
        int idx = it - nums.begin();
        while (idx < nums.size() && (nums[idx] == target)) {
            res.push_back(idx);
            idx++;
        }
        return res;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        // first >=
        int it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (it == nums.size() || (nums[it] != target)) {
            return res;
        }
        while (it < nums.size() && (nums[it] == target)) {
            res.push_back(it);
            it++;
        }
        return res;
    }


```

