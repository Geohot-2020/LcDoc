## 栈和队列

栈：DFS

队列：BFS

### 栈

#### [min-stack](https://leetcode-cn.com/problems/min-stack/)

思路：用两个栈实现，一个最小栈始终保证最小值在顶部

```js
var MinStack = function () {
    // 初始化栈
    this.stack = [];
    this.minStack = [];
    return this;
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function (val) {
    this.stack.push(val);
    // 空或比最小小
    if (this.minStack.length === 0 || val <= this.getMin())
        this.minStack.push(val);
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    if (this.stack.pop() === this.getMin()) {
        this.minStack.pop();
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    // 返回栈顶
    return this.stack[this.stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    // 返回最小栈栈顶
    return this.minStack[this.minStack.length - 1];
};
```

#### [evaluate-reverse-polish-notation](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

思路：通过栈保存原来的元素，遇到表达式弹出运算，再推入结果，重复这个过程

```js
var evalRPN = function(tokens) {
    if (tokens.length === 0)    return 0;

    const stack = [];

    for (let i = 0; i < tokens.length; i++) {
        const token = tokens[i];
        let res = 0;

        switch(token) {
            case "+":
            case "-":
            case "*":
            case "/":
                if (stack.length < 2)   // 错误处理
                    return -1;
                const b = stack.pop();  
                const a = stack.pop();
                switch (token) {
                    case "+":
                        res = a + b;
                        break;
                    case "-":
                        res = a - b;
                        break;
                    case "*":
                        res = a * b;
                        break;
                    case "/":
                        // js特性。需往下取整
                        res = Math.trunc(a / b);
                        break;
                }
                stack.push(res);
                break;
            default:
                //数字
                stack.push(Number(token)); 
        }
    }
    return stack[0];
};
```

#### [decode-string](https://leetcode-cn.com/problems/decode-string/)

思路：通过栈辅助进行操作

```js
var decodeString = function(s) {
    let numStack = [];  //倍数
    let strStack = [];  //待拼接
    let num = 0;        
    let res = '';
    for (const c of s) {
        if (!isNaN(c)) {    //数字
            num = num * 10 + Number(c); 
        } else if (c === '[') { //入栈
            strStack.push(res);
            res = '';
            numStack.push(num);
            num = 0;
        } else if (c === ']') { //出栈
            let repeatTimes = numStack.pop();   //重复次数
            res = strStack.pop() + res.repeat(repeatTimes);
        } else {    //字母加入待处理
            res += c;
        }
    }
    return res;
};
```

#### [binary-tree-inorder-traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

思路：通过stack 保存已经访问的元素，用于原路返回

```js
var inorderTraversal = function(root) {
    const res = [];
    const stack = [];

    while (stack.length > 0 || root) {
        // 左根存入栈
        while (root) {
            stack.push(root);
            root = root.left;
        }

        // 访问中
        const node = stack.pop();
        res.push(node.val);

        // 走右
        root = node.right;
    }
    return res;
};
```

#### [clone-graph](https://leetcode-cn.com/problems/clone-graph/)

```js
var cloneGraph = function(node) {
    const visited = new Map();

    const clone = (node) => {
        if (node === null)  return null;
        // 遍历过，直接返回
        if (visited.has(node.val))  return visited.get(node.val);

        const cloneNode = new Node(node.val, []);
        visited.set(node.val, cloneNode);   //hash存储

        // 遍历邻居
        for (const nbNode of node.neighbors) {
            // 递归克隆邻居
            const cloneNBNode = clone(nbNode);
            // 克隆邻居关系
            cloneNode.neighbors.push(cloneNBNode);
        }
        return cloneNode;
    }

    return clone(node);
};
```

#### [number-of-islands](https://leetcode-cn.com/problems/number-of-islands/)

思路：通过深度搜索遍历可能性（注意标记已访问元素）

```js
var numIslands = function(grid) {
    let count = 0;
    //遍历
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            // 陆地且可以dfs，岛屿数量+1
            if (grid[i][j] === '1') {
                count++;
                dfs(grid, i, j);
            }      
        }
    }
    return count;
};

// 递归找陆地数量
var dfs = function(grid, i, j) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length)
        return 0;
    
    // 如果是陆地
    if (grid[i][j] === '1') {
        // 标记已访问
        grid[i][j] = '0';
        // 递归遍历 同时计数+1
        return (
            dfs(grid, i - 1, j) + 
            dfs(grid, i + 1, j) +
            dfs(grid, i, j - 1) +
            dfs(grid, i, j + 1) +
            1
        );
    } 

    // 非陆地
    return 0;
}
```

#### [largest-rectangle-in-histogram](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) [Hard]



### 队列

#### [implement-queue-using-stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

栈实现队列

```js
var MyQueue = function() {
    this.stackIn = [];
    this.stackOut = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    this.stackIn.push(x);
};

/**
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    if (!this.stackOut.length) {
        // 栈1倒给栈2
        while(this.stackIn.length) {
            this.stackOut.push(this.stackIn.pop());
        }
    }
    // 最顶上一个
    return this.stackOut.pop();
};

/**
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    if (!this.stackOut.length) {
        // 栈1倒给栈2
        while(this.stackIn.length) {
            this.stackOut.push(this.stackIn.pop());
        }
    }
    // 最顶上一个
    return this.stackOut[this.stackOut.length - 1];
};

/**
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    return this.stackOut.length === 0 && this.stackIn.length === 0;
};
```

#### [01-matrix](https://leetcode-cn.com/problems/01-matrix/)

BFS 从0进队列，弹出之后计算上下左右的结果，将上下左右重新进队列进行二层操作

```javascript
var updateMatrix = function(mat) {
    let queue = [];
    let directions = [[0, 1], [0, -1], [-1, 0], [1, 0]];

    const rows = mat.length;
    const cols = mat[0].length;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (mat[i][j] === 0)    //源点入队
                queue.push([i, j]);
            else    // 表示已遍历
                mat[i][j] = -1;
        }
    }

    // 遍历队列
    while (queue.length) {
        // 出队
        let point = queue.shift();
        for (const dire of directions) {
            let x = point[0] + dire[0];
            let y = point[1] + dire[1];
            // 未访问的
            if (x >= 0 && x < rows && y >= 0 && y < cols && mat[x][y] === -1) {
                mat[x][y] = mat[point[0]][point[1]] + 1;
                // 入队
                queue.push([x, y]);
            }
        }
    }
    return mat;
};
```