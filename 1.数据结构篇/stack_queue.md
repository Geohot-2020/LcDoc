## 栈和队列

栈：DFS

队列：BFS

### 栈

#### [min-stack](https://leetcode-cn.com/problems/min-stack/)

思路：用两个栈实现，一个最小栈始终保证最小值在顶部

```js
class MinStack {
    constructor() {
        // 初始化两个栈：一个存储所有值，一个存储当前的最小值
        this.stack = [];
        this.minStack = [];
    }

    /**
     * 添加元素到栈中
     * @param {number} x
     */
    push(x) {
        this.stack.push(x);
        // 如果 minStack 为空或 x 小于等于当前最小值，将 x 推入 minStack
        if (this.minStack.length === 0 || x <= this.getMin()) {
            this.minStack.push(x);
        }
    }

    /**
     * 删除栈顶元素
     */
    pop() {
        // 如果栈顶元素等于最小值，也需要从 minStack 中移除
        if (this.stack.pop() === this.getMin()) {
            this.minStack.pop();
        }
    }

    /**
     * 获取栈顶元素
     * @return {number}
     */
    top() {
        // 返回栈顶元素
        return this.stack[this.stack.length - 1];
    }

    /**
     * 获取栈中的最小值
     * @return {number}
     */
    getMin() {
        // 返回 minStack 的栈顶元素
        return this.minStack[this.minStack.length - 1];
    }
}
```

#### [evaluate-reverse-polish-notation](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

思路：通过栈保存原来的元素，遇到表达式弹出运算，再推入结果，重复这个过程

```js
function evalRPN(tokens) {
    if (tokens.length === 0) {
        return 0;
    }
    
    const stack = [];
    
    for (let i = 0; i < tokens.length; i++) {
        const token = tokens[i];
        
        switch (token) {
            case "+":
            case "-":
            case "*":
            case "/":
                if (stack.length < 2) {
                    return -1; // 错误处理，无法操作
                }
                const b = stack.pop(); // 栈顶是 b（被操作数2）
                const a = stack.pop(); // 次栈顶是 a（被操作数1）
                let result = 0;
                switch (token) {
                    case "+":
                        result = a + b;
                        break;
                    case "-":
                        result = a - b;
                        break;
                    case "*":
                        result = a * b;
                        break;
                    case "/":
                        // 注意 JavaScript 中整除需要 Math.trunc 处理（向零取整）
                        result = Math.trunc(a / b);
                        break;
                }
                stack.push(result);
                break;
            default:
                // 转换为数字并推入栈中
                stack.push(Number(token));
        }
    }
    
    return stack[0];
}
```

#### [decode-string](https://leetcode-cn.com/problems/decode-string/)

思路：通过栈辅助进行操作

```js
function decodeString(s) {
    if (s.length === 0) {
        return "";
    }
    
    const stack = [];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] === ']') {
            let temp = [];
            
            // 取出当前栈中的字符，直到遇到 '['
            while (stack.length > 0 && stack[stack.length - 1] !== '[') {
                temp.push(stack.pop());
            }
            
            // 弹出 '['
            stack.pop();
            
            // 提取重复次数（数字）
            let num = [];
            while (
                stack.length > 0 &&
                stack[stack.length - 1] >= '0' &&
                stack[stack.length - 1] <= '9'
            ) {
                num.push(stack.pop());
            }
            
            // 数字是逆序存储的，需要翻转
            const count = parseInt(num.reverse().join(''), 10);
            
            // 根据 count 重复 temp 并放回栈
            const expanded = temp.reverse().join('').repeat(count);
            for (let char of expanded) {
                stack.push(char);
            }
        } else {
            // 非 ']' 的字符直接入栈
            stack.push(s[i]);
        }
    }
    
    // 最后栈中存储的就是解码后的字符串
    return stack.join('');
}
```

#### [binary-tree-inorder-traversal](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

思路：通过stack 保存已经访问的元素，用于原路返回

```js
function inorderTraversal(root) {
    const result = []; // To store the inorder traversal result
    const stack = []; // Stack to simulate recursion

    while (stack.length > 0 || root !== null) {
        // Traverse left subtree
        while (root !== null) {
            stack.push(root);
            root = root.left;
        }

        // Visit the current node
        const node = stack.pop();
        result.push(node.val);

        // Traverse right subtree
        root = node.right;
    }

    return result;
}
```

#### [clone-graph](https://leetcode-cn.com/problems/clone-graph/)

```js
/**
 * 节点定义
 * @param {number} val 节点值
 * @param {Node[]} neighbors 节点的邻居数组
 */
class Node {
    constructor(val, neighbors = []) {
        this.val = val; // 节点的值
        this.neighbors = neighbors; // 邻居节点列表
    }
}

/**
 * 克隆图
 * @param {Node} node - 输入图的起始节点
 * @return {Node} - 克隆后的图的起始节点
 */
function cloneGraph(node) {
    // 用于存储已访问过的节点及其克隆
    const visited = new Map();
    return clone(node, visited);
}

/**
 * 递归克隆图的辅助函数
 * @param {Node} node - 当前需要克隆的节点
 * @param {Map<Node, Node>} visited - 记录已经克隆的节点
 * @return {Node} - 克隆后的节点
 */
function clone(node, visited) {
    if (!node) return null; // 如果节点为空，直接返回 null

    // 如果当前节点已经克隆过，直接返回对应的克隆节点
    if (visited.has(node)) {
        return visited.get(node);
    }

    // 创建新的节点，值和原节点相同，但邻居列表为空
    const newNode = new Node(node.val);
    // 将新节点存入已访问映射中
    visited.set(node, newNode);

    // 遍历当前节点的所有邻居，递归克隆邻居并添加到新节点的邻居列表中
    for (const neighbor of node.neighbors) {
        newNode.neighbors.push(clone(neighbor, visited));
    }

    return newNode; // 返回克隆后的节点
}
```

#### [number-of-islands](https://leetcode-cn.com/problems/number-of-islands/)

思路：通过深度搜索遍历可能性（注意标记已访问元素）

```js
/**
 * 计算二维网格中岛屿的数量
 * @param {character[][]} grid - 二维网格，其中 '1' 表示陆地，'0' 表示水
 * @return {number} - 岛屿的数量
 */
function numIslands(grid) {
    let count = 0; // 记录岛屿数量

    // 遍历网格中的每个位置
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            // 如果当前位置是陆地且可以通过 DFS 进行标记，则岛屿数量加 1
            if (grid[i][j] === '1' && dfs(grid, i, j) >= 1) {
                count++;
            }
        }
    }

    return count; // 返回总岛屿数量
}

/**
 * 深度优先搜索（DFS）标记岛屿的陆地
 * @param {character[][]} grid - 二维网格
 * @param {number} i - 当前的行索引
 * @param {number} j - 当前的列索引
 * @return {number} - 标记的陆地数量
 */
function dfs(grid, i, j) {
    // 如果超出网格边界，返回 0
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
        return 0;
    }

    // 如果当前位置是陆地（'1'），进行标记为已访问
    if (grid[i][j] === '1') {
        grid[i][j] = '0'; // 标记为已访问（防止重复访问）
        // 递归检查四个方向的邻居，并累加标记的陆地数量
        return (
            dfs(grid, i - 1, j) + // 上
            dfs(grid, i + 1, j) + // 下
            dfs(grid, i, j - 1) + // 左
            dfs(grid, i, j + 1) + // 右
            1 // 当前陆地计数
        );
    }

    return 0; // 如果当前位置不是陆地，返回 0
}
```

#### [largest-rectangle-in-histogram](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/) [Hard]



### 队列

#### [implement-queue-using-stacks](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

栈实现队列

```js
class MyQueue {
    constructor() {
        this.stack = [];
        this.back = [];
    }

    // 将元素添加到队列尾部
    Push(x) {
        while (this.back.length!== 0) {
            const val = this.back.pop();
            this.stack.push(val);
        }
        this.stack.push(x);
    }

    // 移除并返回队列头部的元素
    Pop() {
        while (this.stack.length!== 0) {
            const val = this.stack.pop();
            this.back.push(val);
        }
        if (this.back.length === 0) {
            return 0;
        }
        const val = this.back.pop();
        return val;
    }

    // 返回队列头部的元素（不移除）
    Peek() {
        while (this.stack.length!== 0) {
            const val = this.stack.pop();
            this.back.push(val);
        }
        if (this.back.length === 0) {
            return 0;
        }
        const val = this.back[this.back.length - 1];
        return val;
    }

    // 判断队列是否为空
    Empty() {
        return this.stack.length === 0 && this.back.length === 0;
    }
}
```

#### [01-matrix](https://leetcode-cn.com/problems/01-matrix/)

BFS 从0进队列，弹出之后计算上下左右的结果，将上下左右重新进队列进行二层操作

```javascript
function updateMatrix(matrix) {
    const q = [];
    const rows = matrix.length;
    const cols = matrix[0].length;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (matrix[i][j] === 0) {
                // 进队列
                q.push([i, j]);
            } else {
                matrix[i][j] = -1;
            }
        }
    }
    const directions = [[0, 1], [0, -1], [-1, 0], [1, 0]];
    while (q.length!== 0) {
        // 出队列
        const point = q.shift();
        for (const v of directions) {
            const x = point[0] + v[0];
            const y = point[1] + v[1];
            if (x >= 0 && x < rows && y >= 0 && y < cols && matrix[x][y] === -1) {
                matrix[x][y] = matrix[point[0]][point[1]] + 1;
                // 将当前的元素进队列，进行一次BFS
                q.push([x, y]);
            }
        }
    }
    return matrix;
}
```