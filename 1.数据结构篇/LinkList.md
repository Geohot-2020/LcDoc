## LinkList

### 基本技能

链表相关的核心点

- null/nil 异常处理
- dummy node 哑巴节点
- 快慢指针
- 插入一个节点到排序链表
- 从一个链表中移除一个节点
- 翻转链表
- 合并两个链表
- 找到链表的中间节点

### 常见题型

##### [删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)

```js
var deleteDuplicates = function(head) {
    let current = head;
    while (current !== null) {
        // 移除所有与当前节点值相同的后续节点
        while (current.next !== null && current.val === current.next.val) {
            current.next = current.next.next; // 跳过重复节点
        }
        current = current.next; // 移动到下一个节点
    }
    return head;
};
```

##### [删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)

思路：链表头结点可能被删除，所以用 dummy node 辅助删除

```js
var deleteDuplicates = function(head) {
    if (head === null) {
        return head;
    }

    // 创建虚拟头节点
    let dummy = new ListNode(0);
    dummy.next = head;
    let current = dummy;

    while (current.next !== null && current.next.next !== null) {
        if (current.next.val === current.next.next.val) {
            // 记录重复值
            let rmVal = current.next.val;
            // 删除所有重复节点
            while (current.next !== null && current.next.val === rmVal) {
                current.next = current.next.next;
            }
        } else {
            current = current.next; // 移动到下一个节点
        }
    }

    return dummy.next;
};
```

注意点 

• A->B->C 删除 B，A.next = C 

• 删除用一个 Dummy Node 节点辅助（允许头节点可变） 

• 访问 X.next 、X.value 一定要保证 X !=  null

##### [反转链表](https://leetcode.cn/problems/reverse-linked-list/)

思路：用一个 prev 节点保存向前指针，temp 保存向后的临时指针

```js
var reverseList = function(head) {
    let prev = null;

    while (head !== null) {
        // 保存当前 head.next 节点，防止覆盖
        let temp = head.next;
        // 反转当前节点指针
        head.next = prev;
        // 移动 prev 和 head 指针
        prev = head;
        head = temp;
    }

    // prev 最终指向反转后的链表头节点
    return prev;
};
```

##### [反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

思路：先遍历到 m 处，翻转，再拼接后续，注意指针处理

```js
var reverseBetween = function(head, m, n) {
    if (head === null) {
        return head;
    }

    // 创建 dummy 节点
    let dummy = new ListNode(0);
    dummy.next = head;
    let pre = dummy;

    // 遍历到第 m 个节点前
    for (let i = 1; i < m; i++) {
        pre = pre.next;
    }

    // 开始翻转
    let current = pre.next;
    let next = null;
    let mid = current;

    for (let i = m; i <= n; i++) {
        let temp = current.next;
        current.next = next;
        next = current;
        current = temp;
    }

    // 拼接翻转的部分与剩余部分
    pre.next = next;
    mid.next = current;

    return dummy.next;
};
```

##### [合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

思路：通过 dummy node 链表，连接各个元素

```js
var mergeTwoLists = function(l1, l2) {
    // 创建 dummy 节点
    let dummy = new ListNode(0);
    let head = dummy;

    // 合并两个链表，按值大小排序
    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            head.next = l1;
            l1 = l1.next;
        } else {
            head.next = l2;
            l2 = l2.next;
        }
        head = head.next;
    }

    // 如果 l1 未合并完
    while (l1 !== null) {
        head.next = l1;
        head = head.next;
        l1 = l1.next;
    }

    // 如果 l2 未合并完
    while (l2 !== null) {
        head.next = l2;
        head = head.next;
        l2 = l2.next;
    }

    return dummy.next;
};
```

##### [分隔链表](https://leetcode.cn/problems/partition-list/)

思路：将大于 x 的节点，放到另外一个链表，最后连接这两个链表

```js
var partition = function(head, x) {
    if (head === null) return head;

    // 初始化两个链表的哑节点
    let headDummy = new ListNode(0);
    let tailDummy = new ListNode(0);

    // 分别指向小于 x 和大于等于 x 的链表的尾部
    let headPointer = headDummy;
    let tailPointer = tailDummy;

    // 遍历链表
    while (head !== null) {
        if (head.val < x) {
            // 当前值小于 x，加入 headDummy 链表
            headPointer.next = head;
            headPointer = headPointer.next;
        } else {
            // 当前值大于等于 x，加入 tailDummy 链表
            tailPointer.next = head;
            tailPointer = tailPointer.next;
        }
        head = head.next;
    }

    // 防止形成环，将 tailDummy 链表的尾部指向 null
    tailPointer.next = null;

    // 拼接两个链表
    headPointer.next = tailDummy.next;

    return headDummy.next;
};
```

哑巴节点使用场景

> 当头节点不确定的时候，使用哑巴节点

##### [排序链表](https://leetcode.cn/problems/sort-list/)

思路：归并排序，找中点和合并操作

```js
var sortList = function(head) {
    return mergeSort(head);
};

// 找到链表的中间节点
const findMiddle = function(head) {
    let slow = head;
    let fast = head.next; // fast 比 slow 快一步

    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
};

// 合并两个有序链表
const mergeTwoLists = function(l1, l2) {
    let dummy = new ListNode(0);
    let current = dummy;

    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            current.next = l1;
            l1 = l1.next;
        } else {
            current.next = l2;
            l2 = l2.next;
        }
        current = current.next;
    }

    // 连接剩余的节点
    current.next = l1 !== null ? l1 : l2;

    return dummy.next;
};

// 归并排序
const mergeSort = function(head) {
    // 如果只有一个节点或链表为空，直接返回
    if (head === null || head.next === null) {
        return head;
    }

    // 找到中间节点并分割链表
    let middle = findMiddle(head);
    let nextToMiddle = middle.next;
    middle.next = null; // 断开链表

    // 递归地对左右部分排序
    let left = mergeSort(head);
    let right = mergeSort(nextToMiddle);

    // 合并已排序的两部分
    return mergeTwoLists(left, right);
};
```

##### [重排链表](https://leetcode.cn/problems/reorder-list/)

思路：找到中点断开，翻转后面部分，然后合并前后两个链表

```js
var reorderList = function(head) {
    if (head === null) return;

    // 找到链表的中点
    let mid = findMiddle(head);

    // 翻转后半部分链表
    let tail = reverseList(mid.next);
    mid.next = null; // 断开链表

    // 合并前后两个链表
    mergeTwoLists(head, tail);
};

// 找到链表的中点
const findMiddle = function(head) {
    let slow = head;
    let fast = head.next;

    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
};

// 合并两个链表，以交替顺序进行合并
const mergeTwoLists = function(l1, l2) {
    let dummy = new ListNode(0);
    let current = dummy;
    let toggle = true;

    while (l1 !== null && l2 !== null) {
        if (toggle) {
            current.next = l1;
            l1 = l1.next;
        } else {
            current.next = l2;
            l2 = l2.next;
        }
        toggle = !toggle;
        current = current.next;
    }

    // 如果有剩余的节点，直接连接
    current.next = l1 !== null ? l1 : l2;
};

// 翻转链表
const reverseList = function(head) {
    let prev = null;

    while (head !== null) {
        let temp = head.next; // 保存当前的下一个节点
        head.next = prev;     // 当前节点指向前一个节点
        prev = head;          // prev 前移
        head = temp;          // head 前移
    }

    return prev;
};
```

##### [环形链表](https://leetcode.cn/problems/linked-list-cycle/)

思路：快慢指针，快慢指针相同则有环，证明：如果有环每走一步快慢指针距离会减 1 

```js
var hasCycle = function(head) {
    // 使用快慢指针法检测环
    if (head === null) return false;

    let slow = head;
    let fast = head.next;

    while (fast !== null && fast.next !== null) {
        // 如果快慢指针相遇，说明链表有环
        if (fast === slow) {
            return true;
        }
        fast = fast.next.next; // 快指针每次移动两步
        slow = slow.next;      // 慢指针每次移动一步
    }

    // 遍历结束且没有相遇，说明链表无环
    return false;
};
```

##### [环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

思路：快慢指针，快慢相遇之后，慢指针回到头，快慢指针步调一致一起移动，相遇点即为入环点 

```js
var detectCycle = function(head) {
    // 检查输入链表是否为空
    if (head === null) {
        return null;
    }

    let slow = head;
    let fast = head;

    // 使用快慢指针检测环
    while (fast !== null && fast.next !== null) {
        fast = fast.next.next; // 快指针每次移动两步
        slow = slow.next;      // 慢指针每次移动一步

        // 如果快慢指针相遇，说明链表有环
        if (fast === slow) {
            // 重置慢指针到链表头部
            slow = head;

            // 快慢指针同步移动，每次移动一步
            while (slow !== fast) {
                slow = slow.next;
                fast = fast.next;
            }

            // 返回环的起点
            return slow;
        }
    }

    // 如果没有环，返回 null
    return null;
};
```

##### [回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

```js
// 判断链表是否是回文链表的函数
function isPalindrome(head) {
    if (head === null) {
        return true;
    }
    let slow = head;
    let fast = head.next;
    // 快慢指针同时移动，快指针每次移动两步，找到链表中点
    while (fast!== null && fast.next!== null) {
        fast = fast.next.next;
        slow = slow.next;
    }

    let tail = reverse(slow.next);
    // 断开两个链表（这里模拟断开后半部分链表与前半部分的连接）
    slow.next = null;
    while (head!== null && tail!== null) {
        if (head.val!== tail.val) {
            return false;
        }
        head = head.next;
        tail = tail.next;
    }
    return true;
}

// 反转链表的函数
function reverse(head) {
    if (head === null) {
        return head;
    }
    let prev = null;
    while (head!== null) {
        let temp = head.next;
        head.next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
```

##### [随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/)

思路：1、hash 表存储指针，2、复制节点跟在原节点后面

```js
function copyRandomList(head) {
    if (head === null) {
        return head;
    }
    // 复制节点，紧挨到到后面
    // 1->2->3  ==>  1->1'->2->2'->3->3'
    let cur = head;
    while (cur!== null) {
        const clone = new Node(cur.val, cur.next);
        const temp = cur.next;
        cur.next = clone;
        cur = temp;
    }
    // 处理random指针
    cur = head;
    while (cur!== null) {
        if (cur.random!== null) {
            cur.next.random = cur.random.next;
        }
        cur = cur.next.next;
    }
    // 分离两个链表
    cur = head;
    const cloneHead = cur.next;
    while (cur!== null && cur.next!== null) {
        const temp = cur.next;
        cur.next = cur.next.next;
        cur = temp;
    }
    // 原始链表头：head 1->2->3
    // 克隆的链表头：cloneHead 1'->2'->3'
    return cloneHead;
}
```

