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
    let cur = head;
    while (cur !== null ) {
        // 移除与当前节点值相同
        while (cur.next !== null && cur.val === cur.next.val)
            cur.next = cur.next.next;   //跳过重复节点
        cur = cur.next;
    }
    return head;
};
```

##### [删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)

思路：链表头结点可能被删除，所以用 dummy node 辅助删除

```js
var deleteDuplicates = function(head) {
    if (head === null)  return head;

    // 虚拟头节点
    let dummy = new ListNode(0);
    dummy.next = head;
    let cur = dummy;

    while (cur.next !== null && cur.next.next !== null) {
        if (cur.next.val === cur.next.next.val) {
            let rmVal = cur.next.val;   //重复节点值
            while (cur.next !== null && cur.next.val === rmVal)
                cur.next = cur.next.next;   //跳过cur.next
        } else {
            cur = cur.next;
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
    if (head === null || head.next === null)    return head;
    let cur = head, pre = null;
    while (cur !== null) {
        let nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
};
```

##### [反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

思路：先遍历到 m 处，翻转，再拼接后续，注意指针处理

```js
var reverseBetween = function(head, left, right) {
    if (head === null)  return head;

    let dummy = new ListNode(0);
    dummy.next = head;
    
    let pre = dummy;

    for (let i = 1; i < left; i++) {
        pre = pre.next;
    }
    // 开始反转
    let cur = pre.next;
    let ppre = null;
    let mid = cur;

    for (let i = left; i <= right; i++) {
        let nxt = cur.next;
        cur.next = ppre;
        ppre = cur;
        cur = nxt;
    }

    // 拼接剩余
    pre.next = ppre;
    mid.next = cur;

    return dummy.next;
};
```

##### [合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

思路：通过 dummy node 链表，连接各个元素

```js
var mergeTwoLists = function(list1, list2) {
    let dummy = new ListNode(0);
    let head = dummy;

    while (list1 !== null && list2 !== null) {
        if (list1.val < list2.val) {
            head.next = list1;
            list1 = list1.next;
        } else {
            head.next = list2;
            list2 = list2.next;
        }
        head = head.next;
    }

    // 1未完成
    while (list1 !== null) {
        head.next = list1;
        list1 = list1.next;
        head = head.next;
    }

    // 2未完成
    while (list2 !== null) {
        head.next = list2;
        list2 = list2.next;
        head = head.next;
    }

    return dummy.next;
};
```

##### [分隔链表](https://leetcode.cn/problems/partition-list/)

思路：将大于 x 的节点，放到另外一个链表，最后连接这两个链表

```js
var partition = function(head, x) {
    if (head === null)  return head;

    let headDummy = new ListNode(0);
    let tailDummy = new ListNode(0);

    let headCur = headDummy;
    let tailCur = tailDummy;

    while (head !== null) {
        if (head.val < x) {
            headCur.next = head;
            headCur = headCur.next;
        } else {
            tailCur.next = head;
            tailCur = tailCur.next;
        }
        head = head.next;
    }

    // 尾指向空
    tailCur.next = null;

    // 拼接
    headCur.next = tailDummy.next;

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

// 找中间
var findMiddle = function(head) {
    let slow = head;
    let fast = slow.next;   //fast比slow快一步

    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    
    return slow;
};

// 合并两个有序链表
var mergeTwoLists = function(l1, l2) {
    let dummy = new ListNode(0);
    let cur = dummy;
    while (l1 !== null && l2 !== null) {
        if (l1.val < l2.val) {
            cur.next = l1;
            l1 = l1.next;
        } else {
            cur.next = l2;
            l2 = l2.next;
        }
        cur = cur.next;
    }

    // 剩余
    cur.next = l1 !== null ? l1 : l2;

    return dummy.next;
}

// 归并排序
var mergeSort = function(head) {
    if (head === null || head.next === null)
        return head;
    
    // 找到中间分割
    let mid = findMiddle(head);
    let midNxt = mid.next;
    mid.next = null;    //断开
    
    // 递归排序左右
    let left = mergeSort(head);
    let right = mergeSort(midNxt);

    // 合并
    return mergeTwoLists(left, right);
}
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
    if (head === null)  return false;

    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        // 快慢相遇，有环
        if (slow === fast)  return true;
    }
    return false;
};
```

##### [环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)

思路：快慢指针，快慢相遇之后，慢指针回到头，快慢指针步调一致一起移动，相遇点即为入环点 

```js
var detectCycle = function(head) {
    if (head === null)  return null;
    let slow = head, fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) {
            // 重置指针
            slow = head;
            // 同步移动
            while (slow !== fast) {
                slow = slow.next;
                fast = fast.next;
            }
            // 返回环的起点
            return slow;
        }
    }
    return null;
};
```

##### [回文链表](https://leetcode.cn/problems/palindrome-linked-list/)

```js
var isPalindrome = function(head) {
    if (head === null)  return true;
    // 1.找中点 [slow], 带奇偶性质的：fast = head.next
    let slow = head, fast = head.next;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    // 2.反转并断开链表
    let tail = reverse(slow.next);
    slow.next = null;

    // 3.对比
    while(head && tail) {
        if (head.val !== tail.val)
            return false;
        head = head.next;
        tail = tail.next;
    }

    return true;
};

var reverse = function(head) {
    if (head === null)  return head;
    let pre = null, cur = head;
    while (cur) {
        let nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}
```

##### [随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/)

思路：1、hash 表存储指针，2、复制节点跟在原节点后面

```js
var copyRandomList = function(head) {
    if (head === null)  return head;

    //1.第一次遍历, 生成一个有val属性的链表
    let cur = head;
    const map = new Map();
    while (cur) {
        map.set(cur, new Node(cur.val));
        cur = cur.next;
    }

    //2.第二次遍历，根据映射关系，指向对应节点或null
    cur = head;
    while (cur) {
        map.get(cur).next = map.get(cur.next) || null;
        map.get(cur).random = map.get(cur.random) || null;
        cur = cur.next;
    }
    return map.get(head);
};
```

