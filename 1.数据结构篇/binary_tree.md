## 二叉树

### 知识点

#### 二叉树遍历

**前序遍历**：**先访问根节点**，再前序遍历左子树，再前序遍历右子树 

**中序遍历**：先中序遍历左子树，**再访问根节点**，再中序遍历右子树 

**后序遍历**：先后序遍历左子树，再后序遍历右子树，**再访问根节点**

注意点

- 以根访问顺序决定是什么遍历
- 左子树都是优先右子树

##### **前序递归**

```js
function preorderTraversal(root) {
    if (root === null) {
        return;
    }
    // 先访问根再访问左右
    console.log(root.val);
    preorderTraversal(root.left);
    preorderTraversal(root.right);
}
```

##### **前序非递归**

通过遍历节点并处理左子树，直到没有左子树为止，然后访问右子树

```js
function preorderTraversal(root) {
    // 非递归遍历
    if (root === null) {
        return [];
    }

    let result = [];
    let stack = [];

    while (root !== null || stack.length !== 0) {
        while (root !== null) {
            // 前序遍历，所以先保存结果
            result.push(root.val);
            stack.push(root);
            root = root.left;
        }
        
        // pop
        let node = stack.pop();
        root = node.right;
    }

    return result;
}
```

##### **中序非递归**

先将左子节点依次压入栈中，然后弹出栈顶元素，访问该节点，并处理右子节点

```js
function inorderTraversal(root) {
    let result = [];
    if (root === null) {
        return result;
    }

    let stack = [];
    while (stack.length > 0 || root !== null) {
        while (root !== null) {
            stack.push(root);
            root = root.left; // 一直向左
        }

        // 弹出
        let node = stack.pop();
        result.push(node.val);
        root = node.right;
    }

    return result;
}
```

##### **后序非递归**

通过栈来模拟后序遍历，并通过 `lastVisit` 标识最后访问的节点，来确保根节点在右子树处理后再弹出

```js
function postorderTraversal(root) {
    // 通过lastVisit标识右子节点是否已经弹出
    if (root === null) {
        return [];
    }

    let result = [];
    let stack = [];
    let lastVisit = null;

    while (root !== null || stack.length !== 0) {
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }

        let node = stack[stack.length - 1];

        // 根节点必须在右节点弹出之后，再弹出
        if (node.right === null || node.right === lastVisit) {
            stack.pop(); // pop
            result.push(node.val);
            // 标记当前这个节点已经弹出过
            lastVisit = node;
        } else {
            root = node.right;
        }
    }

    return result;
}
```

注意点

- 核心就是：根节点必须在右节点弹出之后，再弹出

##### **DFS深度搜索，从上到下**

```js
function preorderTraversal(root) {
    let result = [];
    dfs(root, result);
    return result;
}

// V1: 深度优先遍历，结果作为参数传递给函数
function dfs(root, result) {
    if (root === null) {
        return;
    }
    result.push(root.val);
    dfs(root.left, result);
    dfs(root.right, result);
}
```

##### **DFS深度搜索-从下到上（分治）**

`divideAndConquer` 函数递归地处理左子树和右子树，然后将当前节点的值与左、右子树的结果合并

```js
function preorderTraversal(root) {
    let result = divideAndConquer(root);
    return result;
}

function divideAndConquer(root) {
    let result = [];
    // 返回条件 (null & leaf)
    if (root === null) {
        return result;
    }
    // 分治(Divide)
    let left = divideAndConquer(root.left);
    let right = divideAndConquer(root.right);
    // 合并结果(Conquer)
    result.push(root.val);
    result = result.concat(left, right);
    return result;
}
```

##### BFS层次遍历

使用队列来实现树的层次遍历（BFS），通过记录每一层的节点数量，我们可以确保在遍历完当前层的所有节点后，再处理下一层的节点。这样，我们就可以按层次顺序将树的节点值存储在结果数组中。

```js
function levelOrder(root) {
    // 通过上一层的长度确定下一层的元素
    let result = [];
    if (!root) {
        return result;
    }
    let queue = [];
    queue.push(root);
    while (queue.length > 0) {
        let list = [];
        // 为什么要取length？
        // 记录当前层有多少元素（遍历当前层，再添加下一层）
        let l = queue.length;
        for (let i = 0; i < l; i++) {
            // 出队列
            let level = queue.shift();
            list.push(level.val);
            if (level.left) {
                queue.push(level.left);
            }
            if (level.right) {
                queue.push(level.right);
            }
        }
        result.push(list);
    }
    return result;
}
```

#### 分治法应用

先分别处理局部，再合并结果

适用场景

- 快速排序
- 归并排序
- 二叉树相关问题

分治法模板

- 递归返回条件
- 分段处理
- 合并结果

```js
function traversal(root) {
    // root or leaf
    if (!root) {
        // do something and return
        return /* some initial value or result */;
    }

    // Divide
    let left = traversal(root.left);
    let right = traversal(root.right);

    // Conquer
    let result = merge(left, right);

    return result;
}
```

##### 典型示例

```js
// V2：通过分治法遍历二叉树
function preorderTraversal(root) {
    let result = divideAndConquer(root);
    return result;
}

function divideAndConquer(root) {
    let result = [];
    // 返回条件(null & leaf)
    if (!root) {
        return result;
    }
    // 分治(Divide)
    let left = divideAndConquer(root.left);
    let right = divideAndConquer(root.right);
    // 合并结果(Conquer)
    result.push(root.val);
    result = result.concat(left);
    result = result.concat(right);
    return result;
}
```

##### 归并排序

通过递归的分治法将数组不断分割为更小的子数组，直到每个子数组只有一个元素，然后通过合并函数将这些子数组合并为一个有序数组

```js
function MergeSort(nums) {
    return mergeSort(nums);
}

function mergeSort(nums) {
    if (nums.length <= 1) {
        return nums;
    }
    // 分治法：divide 分为两段
    let mid = Math.floor(nums.length / 2);
    let left = mergeSort(nums.slice(0, mid));
    let right = mergeSort(nums.slice(mid));
    // 合并两段数据
    let result = merge(left, right);
    return result;
}

function merge(left, right) {
    let result = [];
    // 两边数组合并游标
    let l = 0;
    let r = 0;
    // 注意不能越界
    while (l < left.length && r < right.length) {
        // 谁小合并谁
        if (left[l] > right[r]) {
            result.push(right[r]);
            r++;
        } else {
            result.push(left[l]);
            l++;
        }
    }
    // 剩余部分合并
    result = result.concat(left.slice(l));
    result = result.concat(right.slice(r));
    return result;
}
```

##### 快速排序

```js
function QuickSort(nums) {
    // 思路：把一个数组分为左右两段，左段小于右段，类似分治法没有合并过程
    quickSort(nums, 0, nums.length - 1);
    return nums;
}

// 原地交换，所以传入交换索引
function quickSort(nums, start, end) {
    if (start < end) {
        // 分治法：divide
        let pivot = partition(nums, start, end);
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }
}

// 分区
function partition(nums, start, end) {
    let p = nums[end];
    let i = start;
    for (let j = start; j < end; j++) {
        if (nums[j] < p) {
            swap(nums, i, j);
            i++;
        }
    }
    // 把中间的值换为用于比较的基准值
    swap(nums, i, end);
    return i;
}

function swap(nums, i, j) {
    let t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
```

#### 题目示例

##### 最大深度

[maximum-depth-of-binary-tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

```js
var maxDepth = function(root) {
    if (root === null)  return 0;
    let left = maxDepth(root.left);
    let right = maxDepth(root.right);
    return left>right ? left + 1: right+1;
};
```

##### 平衡二叉树

[balanced-binary-tree](https://leetcode-cn.com/problems/balanced-binary-tree/)

```js
var isBalanced = function(root) {
    return recur(root) != -1;
};

var recur = function(root) {
    if (root === null)   return 0;
    let left = recur(root.left);
    if (left === -1)    return -1;
    let right = recur(root.right);
    if (right === -1)   return -1;
    return Math.abs(left - right) < 2 ? Math.max(left, right) + 1: -1;
}
```

##### 二叉树最大路径和[hard]

##### 二叉树最近公共祖先

[lowest-common-ancestor-of-a-binary-tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

```js
var lowestCommonAncestor = function(root, p, q) {
    if (root === null)  return root;
    if (root === p || root === q)
        return root;
    let left = lowestCommonAncestor(root.left, p, q);
    let right = lowestCommonAncestor(root.right, p, q);

    if (left && right)  return root;
    if (left)   return left;
    if (right)  return right;
};
```

#### BFS应用

##### 层次遍历

```js
var levelOrder = function(root) {
    let res = [];
    if (root === null)  return res;

    let queue = [];
    queue.push(root);

    while (queue.length > 0) {
        let levelList = [];
        let levelSize = queue.length;
        for (let i = 0; i < levelSize; i++) {
            //出队
            let node = queue.shift();
            levelList.push(node.val);
            //有左进左
            if (node.left !== null)
                queue.push(node.left);
            //有右进右
            if (node.right !== null)
                queue.push(node.right);
        }

        res.push(levelList);
    }
    return res;
};
```

##### 反层次遍历

[binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

```js
var levelOrderBottom = function(root) {
    let res = [];
    if (root === null)  return res;

    let queue = [];
    queue.push(root);

    while (queue.length > 0) {
        let levelList = [];
        let levelSize = queue.length;
        for (let i = 0; i < levelSize; i++) {
            //出队
            let node = queue.shift();
            levelList.push(node.val);
            //有左进左
            if (node.left !== null)
                queue.push(node.left);
            //有右进右
            if (node.right !== null)
                queue.push(node.right);
        }
		// 反
        res.unshift(levelList);
    }
    return res;
};
```

##### Z字型遍历

[binary-tree-zigzag-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/)

```js
var zigzagLevelOrder = function(root) {
    let res = [];
    if (root === null)  return res;

    let queue = [];
    queue.push(root);

    let toggle = true;

    while (queue.length > 0) {
        let levelList = [];
        let levelSize = queue.length;
        for (let i = 0; i < levelSize; i++) {
            //出队
            let node = queue.shift();
            levelList.push(node.val);
            //有左进左
            if (node.left !== null)
                queue.push(node.left);
            //有右进右
            if (node.right !== null)
                queue.push(node.right);
        }
		// 反
        if (!toggle) 
            levelList.reverse();
        res.push(levelList);
        toggle = !toggle;
    }
    return res;
};
```

#### 二叉搜索树

##### 验证二叉搜索树

[validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

```js
var isValidBST = function(root) {
    return inOrder(root, null, null);
};

var inOrder = function(root, min, max) {
    if (root === null)
        return true;
    // 当前节点值不满足 BST 条件
    if((min !== null && root.val <= min) || (max != null && root.val >= max))
        return false;
    // 左子树：最大值约束为当前节点值
    // 右子树：最小值约束为当前节点值
    return (
        inOrder(root.left, min, root.val) &&
        inOrder(root.right, root.val, max)
    );
}
```

##### 二叉搜索树插入

[insert-into-a-binary-search-tree](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)

```
var insertIntoBST = function(root, val) {
    if (root === null) {
        let node = new TreeNode(val);
        return node;
    }
    if (val < root.val)
        root.left = insertIntoBST(root.left, val);
    else if (val > root.val)
        root.right = insertIntoBST(root.right, val);
    return root;
};
```

### 练习

- [ ] [maximum-depth-of-binary-tree](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)
- [ ] [balanced-binary-tree](https://leetcode-cn.com/problems/balanced-binary-tree/)
- [ ] [binary-tree-maximum-path-sum](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)
- [ ] [lowest-common-ancestor-of-a-binary-tree](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/)
- [ ] [binary-tree-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

- [ ] [binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)

- [ ] [binary-tree-zigzag-level-order-traversal](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/)

- [ ] [validate-binary-search-tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)

- [ ] [insert-into-a-binary-search-tree](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)
