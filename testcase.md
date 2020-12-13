请问 [1, null, 2, 3] 在二叉树测试用例中代表什么
力扣 • 发表于：2018年10月26日 早上 00:39:08 • 更新于：2019年05月21日 下午 4:32:22
https://support.leetcode-cn.com/hc/kb/article/1194353/

[1, null, 2, 3] 是个串行化格式，表达了一个水平顺序遍历的二叉树。其中，你可以使用 null 来表达某一分支上没有子节点。为了方便您的深入理解，请参考一下示例：

[]
Empty tree. The root is a reference to NULL (C/C++), null (Java/C#/Javascript), None (Python), or nil (Ruby).

[1, 2, 3]

     1
    / \
   2   3

[1, null, 2, 3]
     1
      \
       2
      /
     3
[之前存在误解,以为是下面的非法二叉树]
      1
     / \
   null 2
   /
  3

[0,null,0,null,0]
      0
     / \
    n   0
       / \
      n   0


[5, 4, 7, 3, null, 2, null, -1, null, 9]
      5
     / \
    4   7
   /   /
  3   2
 /   /
-1  9
