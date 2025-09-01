## TimeComplexity
### Order
O(1)
O(logn)
O(sqrt(n))
O(n)
O(n*logn)
O(n^2)
O(n^3)
O(2^n)
O(n!)
O(n^n)

## size_t 和 int的坑
不要把 int  i,j 和各种vector.size()直接比较，先把size转成int再比较


``` cpp
\\ LC355
   for (int i = 0; i < k; i++) {
            vector<int>& cur = alltw[i];
            for (int j = cur.size() - 1; j >= 0; j--) {
                int& timeid = tweetTime[cur[j]];
                maxHeap.push(make_pair(timeid, cur[j]));
                if (j < int(cur.size() - 10)) { // enough
                // ERROR TYPE WTF
                //if (j < cur.size() - 10) { // enough
                    break;
                }
            }
        }

```


## ASCII
把26个小写字母 映射到 下标0-25    ch - 'a'

a 97
b 98
z 122

把26个大写字母 映射到 下标0-25    ch - 'A'
A 65
B 66


###  大小写转换
    int diff = 'a' - 'A'; // 97-65
    int diff = 32;

大写变小写:  char(ch + diff)
小写变大写:  char(ch - diff)

大写变小写、小写变大写 : 字符 ^= 32;
大写变小写、小写变小写 : 字符 |= 32;
小写变大写、大写变大写 : 字符 &= -33;


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
## min&max
1 求max和min
min(op1, op2)
min({op1, op2, op3}) // C++ 11 新方法

2  vector求min max
在 C++ 中查找Vector中的最小值或最大值
std::min_element 和 std::max_element 分别返回指定范围内的最小值和最大值的迭代器
   std::vector<int> v = {2, 1, 3, 6, 7, 9, 8};
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

https://en.cppreference.com/w/cpp/algorithm/minmax_element.html
    const auto [min, max] = std::minmax_element(begin(v), end(v));

## next_permutation &  prev_permutation
LC556 LC31
template<class Iterator>
  bool next_permutation (Iterator first, Iterator last);
next_permutation的作用是在给定范围内找到下一个排列，如果有下一个排列，则返回true，否则返回false。

https://cppreference.cn/w/cpp/algorithm/next_permutation
https://cppreference.cn/w/cpp/algorithm/prev_permutation

``` cpp
int main()
{
    std::string s = "aba";
    do
    {
        std::cout << s << '\n';
    }
    while (std::next_permutation(s.begin(), s.end()));
    std::cout << s << '\n';
}

输出
aba
baa
aab
```


# sort
## sort与pair<int, int>
默认使用pair的first元素进行排序，不用额外写cmp函数
    vector<pair<int, int> > datas;
    sort(datas.begin(), datas.end());


## 对于二维Vector排序，需要写cmpFn，必须保证严格弱序
``` cpp
 vector<vector<int>>& intervals
    // 弱序 严格   a=b must return false
    // a < b return true
    static bool cmpFn(vector<int>& a, vector<int>& b) {
        if (a[0] < b[0]) {
            return true;
        }
        return false;
    }

```

## sort利用外关键字排序

LC-692
作者：力扣官方题解
链接：https://leetcode.cn/problems/top-k-frequent-words/solutions/785903/qian-kge-gao-pin-dan-ci-by-leetcode-solu-3qk0/
``` cpp
   vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            ++cnt[word];
        }
        vector<string> rec;
        for (auto& [key, value] : cnt) {
            rec.emplace_back(key);
        }
        sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
        });
        rec.erase(rec.begin() + k, rec.end());
        return rec;
    }
```





# String API
<cctype>
 0-9
int isdigit(int ch)

int isupper(int ch)
大写字母 ABCDEFGHIJKLMNOPQRSTUVWXYZ

int islower(int ch)
小写字母 abcdefghijklmnopqrstuvwxyz


大写+小写判定
int isalpha(int ch)

字母或数字
int isalnum(int ch)


# STD
## vector

### 三纬Vector初始化
``` cpp
\\ LC241
    vector<vector<vector<int>>> cache;
    cache = vector<vector<vector<int>>>(len, vector<vector<int> >(len, vector<int>()));

\\ LC123
    vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(4, 0)));

```

### vector值初始化
LC57
``` cpp
    vector<vector<int> > res;
    res.push_back(vector<int>{left, right});
```

### vector逆序构造
vector<int> res;
经常需要逆序后再返回
reverse(res.begin(), res.end());
return res;

2种优化：
M1 提前用 auto it = vec.rbegin(); it != vec.rend(); it++来构造res
M2 提前把res设置容量，vector<int> res(N, 0); 然后逆序赋值  res[k--]  = 123;

### 二维Vector的复制
LC289

``` cpp
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > oldbd(board.begin(), board.end());
    }

```

### vector逆向拷贝
 LC126
      vector<string> one(path.rbegin(), path.rend());


## vector作为方向数组
### 上下左右4格子
等价写法
    const vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


### 周围8格子
LC289
``` cpp
    const vector<pair<int, int> > dires = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

        int getAround(vector<vector<int>>& oldbd, int i, int j) {
        int cnt = 0;
        for (auto& dir: dires) {
            int ni =  i + dir.first;
            int nj =  j + dir.second;
            if (ni < 0 || ni >= row || nj < 0 || nj >= col) {
                continue;
            }
            if (oldbd[ni][nj]) {
                cnt++;
            }
        }
        return cnt;
    }

```


## queue&stack坑
From LC207
cur使用引用，pop后，对象容易被回收，后续再利用cur时，容易出问题
           //BUG int& cur = que.front();
            int cur = que.front();
            que.pop();
            // 后续利用cur


### 二维vector扩容

LC-304
``` cpp
        int row = matrix.size();
        int col = matrix[0].size();
        ps.resize(row + 1, vector<int>(col + 1, 0));
```


## stack -Skill
stack可以用vector来代替，因为stack不方便遍历中间元素，必须不断地top和pop
也不方便从栈底构建结果

对应vector操作
back()            | top 访问栈顶元素
pop_back()        | pop 删除栈顶元素
push_back()       | push 向栈顶插入元素
empty()           | empty 检查底层的容器是否为空
size()            | size 返回容纳的元素数
emplace()         | emplace (C++11) 于顶原位构造元素

## demo
LeetCode-394


## deque
### demo
LeetCode-239

### CoreAPI

push_back
emplace_back
pop_back

push_front
emplace_front
pop_front

clear
erase

### 小结
stack和queue核心API相同，都是push和pop
stack是pop栈顶，queue是pop队列头
stack是top访问栈顶，queue是front/back访问队列头尾，和vector类似

deque和vector的核心API相同，都有push_back和pop_back，
vector没有push_front的API的

stack可以用vector来代替
queue可以用deque来代替
vector也可以用deque来代替
stack和queue底层就是deque, deque更加通用


https://en.cppreference.com/w/cpp/container/stack.html
https://en.cppreference.com/w/cpp/container/queue.html
https://www.apiref.com/cpp-zh/cpp/container/deque.html


## ProirityQueue

### demo
LeetCode-23, 215, 264, 239

默认是大根堆
        priority_queue<int> maxHeap;
等价写法
    priority_queue<int,vector<int>,less<int>> maxHeap;


默认是大根堆，且按照pair.first元素排序
       priority_queue<pair<int, int>> q;
       相当于
       priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>> > q;

LC743
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;

初始化方式
        priority_queue<int> maxHeap(nums.begin(), nums.end());

小根堆写法
       priority_queue<int, vector<int>, greater<int>> minHeap;
记忆方法，cmp函数取反，greater就是minHeap, less就是maxHeap

同理， 默认是大根堆,按照 tuple第一个元素排序
  priority_queue<tuple<int, int, int>> pq;

### 仿函数less & greater
bool less(T& a, T& b)
  a < b 则返回true,  a less b return true ,  a 在前面

bool greater(T& a, T& b)
  a > b 则返回true,  a greater b return true ， a在前面

从小到大
sort(nums.begin(), nums.end(), less<int>());

从大到小
sort(nums.begin(), nums.end(), greater<int>());

无论是less还是 greater，当a==b时，都返回false，保证严格弱序

### 优先队列的仿函数

LC347 LC373

M1
``` cpp
    // greater
    static bool cmpFn(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }


    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmpFn)> minHeap(cmpFn);

//ERROR1
 // priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(&cmpFn)> minHeap;

//ERROR2
 // priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmpFn)> minHeap;

```



M2
``` cpp

class CmpFun2 {
    public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int> >, CmpFun2> minHeap;

```


M3
``` cpp
// LC347
        auto cmpFn3 = [](pair<int, int>& a, pair<int, int>& b) -> bool {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmpFn3)> minHeap;

//LC373


        auto greateCmp = [&nums1, &nums2](pair<int, int>& v1, pair<int, int>& v2) -> bool {
            if ((nums1[v1.first]+nums2[v1.second]) > (nums1[v2.first]+nums2[v2.second])) {
                return true;
            }
            return false;
        };

        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(greateCmp)> minHeap(greateCmp);

        //ERROR 去掉greateCmp初始化minHeap则报错
        //priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(greateCmp)> minHeap;

```



## unordered_map
插入时，如果负载因子过大，可能会触发rehash
也可以主动调用rehash函数

unordered_map遍历是无序的
在没有调用各种写入API(插入/扩容/rehash)的前提下，多次遍历的顺序是固定的(依然是无序)，但是最好不要对这种顺序有依赖，即使unordered_map的数据相同，不同编译环境编译的可执行程序的遍历顺序也可能是不一致的

## 判断两个 unordered_map 是否相等
直接用 == 判断即可，参见 LC30
也适用于 map和vector，
不可以直接用==比较  int arr1[10] 和 int arr2[10]是否相等，参见LC438，数组名会转化为指针，可以用 std::equal来比较


## 接收pair的值
M1 用tie
LC474
``` cpp


    vector<pair<int, int> > cnt01;
        int cnt0 = 0;
        int cnt1 = 0;
        tie(cnt0, cnt1) = cnt01[i];

```

M2 用auto [v1, v2]
``` cpp

    vector<pair<int, int> > cnt01;
    auto [cnt0, cnt1] = cnt01[i];
```

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
[left, right]为待染色区间，因此，闭区间非空时要继续循环

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

    while(left <= right) { //  [left, right] 闭区间非空
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

