## 二分搜索

### 模板

1. 简易：最简单的二分搜索，不需要找第一个、最后一个位置、或者是没有重复元素

   ```js
   var search = function(nums, target) {
       let left = 0, right = nums.length - 1;
       while(left <= right) {
           let mid = left + Math.floor((right - left) / 2);
           if (target < nums[mid])
               right = mid - 1;
           else if(target > nums[mid])
               left = mid + 1;
           else 
               return mid;
       }
       return -1;
   };
   
   // right + 1 === left
   // 无需后续处理
   ```

   

2. 通用

```js
var search = function(nums, target) {
    let left = 0, right = nums.length - 1;
    while(left + 1 < right) {
        let mid = left + Math.floor((right - left) / 2);
        if (target < nums[mid])
            right = mid - 1;
        else 
            left = mid + 1;
    }
    
    ....	//还有left和right两个元素未处理
};

// left + 1 === right
// 剩余两个元素等待后续处理
```

### [search-for-range](https://www.lintcode.com/problem/search-for-a-range/description)

思路：核心点就是找第一个 target 的索引，和最后一个 target 的索引，所以用两次二分搜索分别找第一次和最后一次的位置

```js
searchRange(a, target) {
    let n = a.length;
    if (n === 0)
    	return [-1, -1];

    let res = [];

    let left = 0, right = n -1;
    // 查左边
    while (left + 1 < right) {
    	let mid = left + Math.floor((right - left) / 2);
    	if (target < a[mid]) {
    		right = mid;
    	} else if (target > a[mid]) {
    		left = mid;
    	} else  //找到目标值，继续向左
    	right = mid;
    }

    // 先检查left
    if (a[left] === target) {
    	res[0] = left;
    } else if (a[right] === target) {
    	res[0] = right;
    } else {
    	return [-1, -1];
    }

    left = 0, right = n -1;
    // 查右边
    while (left + 1 < right) {
    	let mid = left + Math.floor((right - left) / 2);
    	if (target < a[mid]) {
    		right = mid;
    	} else if (target > a[mid]) {
    	left = mid;
    	} else  //找到目标值，继续向右
    	left = mid;
    }

    // 先检查left
    if (a[right] === target) {
    	res[1] = right;
    } else if (a[left] === target) {
    	res[1] = left;
    } else {
    	return [-1, -1];
    }

    return res;
}
```

### [search-insert-position](https://leetcode-cn.com/problems/search-insert-position/)

```js
var searchInsert = function(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left + 1 < right) {
        let mid = left + Math.floor((right - left) / 2);
        if (target === nums[mid])   return mid;
        if (target < nums[mid]) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (nums[left] >= target)   return left;
    if (nums[right] >= target)  return right;
    return right + 1;
};
```

### [search-a-2d-matrix](https://leetcode-cn.com/problems/search-a-2d-matrix/)

```js
function searchMatrix(matrix, target) {
    // 思路：将二维数组视为一维数组，进行二分搜索
    if (matrix.length === 0 || matrix[0].length === 0) {
        return false; // 空数组直接返回 false
    }

    const rows = matrix.length;
    const cols = matrix[0].length;
    let start = 0;
    let end = rows * cols - 1;

    // 二分搜索
    while (start + 1 < end) {
        const mid = start + Math.floor((end - start) / 2);
        const val = matrix[Math.floor(mid / cols)][mid % cols]; // 将一维索引转换为二维索引
        if (val > target) {
            end = mid; // 缩小到左半区间
        } else if (val < target) {
            start = mid; // 缩小到右半区间
        } else {
            return true; // 找到目标值
        }
    }

    // 检查 start 和 end 是否为目标值
    if (matrix[Math.floor(start / cols)][start % cols] === target || 
        matrix[Math.floor(end / cols)][end % cols] === target) {
        return true;
    }

    return false; // 未找到目标值
}
```

### [first-bad-version](https://leetcode-cn.com/problems/first-bad-version/)

```js
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let left = 1, right = n;
        while (left + 1 < right) {
            let mid = left + Math.floor((right - left) / 2);
            if (isBadVersion(mid))  //去左边找
                right = mid;
            else 
                left = mid;
        }
        if (isBadVersion(left))
            return left;
        return right;
    };
};
```

### [find-minimum-in-rotated-sorted-array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

```js
var findMin = function(nums) {
    let left = 0, right = nums.length - 1;
    while (left + 1 < right) {
        let mid = left + Math.floor((right - left) / 2);
        if (nums[mid] < nums[right])
            right = mid;
        else 
            left = mid;
    }
    if (nums[left] < nums[right])
        return nums[left];
    else 
        return nums[right];
};
```

### [find-minimum-in-rotated-sorted-array-ii](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

```js
var findMin = function(nums) {
    let left = 0, right = nums.length - 1;
    while (left + 1 < right) {
        // 跳过重复元素
        while (left < right && nums[right] === nums[right - 1]) right--;
        while (left < right && nums[left] === nums[left + 1])   left++;
        
        let mid = left + Math.floor((right - left) / 2);
        if(nums[mid] < nums[right])
            right = mid;
        else
            left = mid;
    }
    if (nums[left] < nums[right])
        return nums[left];
    else 
        return nums[right];
};
```

### [search-in-rotated-sorted-array](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

```js
var search = function(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left + 1 < right) {
        let mid = left + Math.floor((right - left) / 2);
        // 直接返回
        if (target === nums[mid])   return mid;
        //左半严格递增
        if (nums[left] <= nums[mid]) {
            // 在左侧
            if (nums[left] <= target && target <= nums[mid])
                right = mid;
            else 
                left = mid;
        } else {
            // 在右侧
            if (nums[mid] <= target && target <= nums[right])
                left = mid;
            else 
                right = mid;
        }
    }
    
    if (nums[left] === target)
        return left;
    else if (nums[right] === target)
        return right;
    else
        return -1;
};
```

### [search-in-rotated-sorted-array-ii](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

```js
var search = function(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left + 1 < right) {
        while (left < right && nums[right] === nums[right - 1]) right--;
        while (left < right && nums[left] === nums[left + 1])   left++;
        let mid = left + Math.floor((right - left) / 2);
        if (nums[mid] === target)   return true;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target <= nums[mid])
                right = mid;
            else
                left = mid;
        } else {
            if (nums[mid] <= target && target <= nums[right])
                left = mid;
            else
                right = mid;
        }
    }
    if (nums[left] === target || nums[right] === target)
        return true;
    return false;
};
```

