# 优先级
## ErrorCase

### Case1 >>
Error:
       int mid = left + (right - left) >> 1;
OK:
       int mid = left + ((right - left) >> 1);

### Case2 &
Error:
     if (cur & (cur - 1)  == 0) {
OK:
    if ((cur & (cur - 1) ) == 0) {

# STD
1 求max和min
min(op1, op2)
min({op1, op2, op3}) // C++ 11 新方法

2  vector求min max
在 C++ 中查找Vector中的最小值或最大值
std::min_element 和 std::max_element 分别返回指定范围内的最小值和最大值的迭代器
   std::vector<int> v = {2, 1, 3, 6, 7, 9, 8};
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());



# 模版

## BinarySearch


### 红蓝染色法-开区间
初始值 left=-1 right=N
（left, right） = (-1, N) = [0, N-1] 为待判定区间，需要进一步判定红蓝

开区间空的条件 left+1 == right
开区间非空定义  left+1 < right
例如 (1, 2) = [2, 1] 正好是非空
例如 (1, 3) = [2, 2]  不是非空，存在一个2


[intMin, left] 为蓝色
[right, intMax] 为红色
明确isBlue的条件，然后明确return left/right or+-1
优点1 ： 不用考虑+-1
    当mid是blue时，直接 left=blue，依然满足 [0, left]为蓝色的条件，
    否则 right=blue
优点2： 不用考虑==等情况


3Case
INT_MAX
right=N, left=N-1 不满足left+1 < right

INT_MIN
left=-1, right=0 ,不满足 left+1 < right

[1] left=-1,right=1, mid=0,
接下来 left=0  ， right=1  不满足while
or left=-1, right=0  不满足while


换句话说，如果 return right,需要考虑right=N的访问数组越界问题
换句话说，如果 return left,需要考虑left=-1的访问数组越界问题


``` CPP

bool isBlue(vector<int> nums, int mid, int target);

int BlueRedSplit(vector<int> nums, int target) {
    int left = -1;
    int right = nums.size();

    while(left+1 < right) { //  (left, right) 开区间非空
        int mid = left + ((right-left) >> 1);
        if (isBlue(nums, mid, target)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // or return left+-1, right+-1 depends on the problems
    return left;
}


```

### 红蓝染色法-闭区间
初始值 left=0 right=N-1
[left, right] =  [0, N-1] 为待判定区间，需要进一步判定红蓝

闭区间空的条件 left == right + 1
闭区间非空定义  left <= right
例如  [2, 2]  不是非空，存在一个2
例如 [3, 2]  正好是非空

[intMin, left) 为蓝色  , 因为 ==left为待判定区间， 所以<left为蓝色，
(right, intMax] 为红色
明确isBlue的条件，然后明确return left/right or+-1
优点1： 不用考虑==等情况
需要考虑+-1
[left,      mid-1,  mid,  mid+1,       right]
    当mid是blue时， left=mid+1，
    直接 left=blue，依然满足 [intMin, left)为蓝色的条件，
    否则 right=mid-1，依然满足 （right， intMax]为红色


``` CPP

bool isBlue(vector<int> nums, int mid, int target);

int BlueRedSplit(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() -1;

    while(left <= right) { //  [left, right] 开区间非空
        int mid = left + ((right-left) >> 1);
        if (isBlue(nums, mid, target)) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }

    // or return left+-1, right+-1 depends on the problems
    return left;
}


```




## lower_bound & upper_bound
返回的是迭代器 vector<int>::iterator  it;  使用前需判空，如果it= nums.end(); 使用*it会报错
要获取下标 idx = it - nums.begin();
lower_bound 意思 find the first >= target
upper_bound 意思 find the first > target

lower_bound：
功能：查找非递减序列[first,last) 内第一个大于或等于某个元素的位置。
返回值：如果找到第一个大于或等于的，则返回找到元素的地址,否则返回last的地址。（这样不注意的话会越界，小心）
用法：
1 auto it=lower_bound(a.begin(),a.end(), target);
2 int t=lower_bound(a.begin(),a.end(), target)-a.begin();

Case1 即target不在范围内，会返回两种值:
一种是first，说明target比整个数组都小
一种是last，说明target比整个数组都大

Case2 target在范围内，并且存在: 则有 *it == target

Case3 target在范围内，但不存在: 则有 *it != target && *it > target

upper_bound:
功能：查找非递减序列[first,last) 内第一个大于某个元素的位置。
返回值：如果找到第一个大于，返回找到元素的地址,否则返回last的地址。（同样这样不注意的话会越界，小心）
用法同上

Case1 即target不在范围内，会返回两种值:
一种是first，说明target比整个数组都小
一种是last，说明target比整个数组都大

Case2 target在范围内，并且存在: 则有 *(it-1) == target
Case3 target在范围内，但不存在: 则有 *it != target && *it > target

target=7
     UB3(target3=6)
        |     LB2-1  LB2(target2=8)
        |       |     |
1   3   7   7   7     9
        |       |     |
        LB    UB-1    UB



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
## sort
### sort与pair<int, int>
默认使用pair的first元素进行排序，不用额外写cmp函数
    vector<pair<int, int> > datas;
    sort(datas.begin(), datas.end());


### 对于二维Vector排序，需要写cmpFn，必须保证严格弱序
 vector<vector<int>>& intervals
    // 弱序 严格   a=b must return false
    // a < b return true
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        return false;
    }




