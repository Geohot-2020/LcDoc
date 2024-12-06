## 排序算法

### 1. 快排

```js
var partition = function(nums, low, high) {
    let pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        nums[low] = nums[high];     //比枢轴元素小的放左边
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        nums[high] = nums[low];     //比枢轴元素大的放右边
    }
    nums[low] = pivot;
    return low;
}

var quickSort = function(nums, low, high) {
    if (low < high) {
        let pivotPos = partition(nums, low, high);
        quickSort(nums, low, pivotPos - 1);
        quickSort(nums, pivotPos + 1, high);
    }
}
```

### 2. 归并

```js
var mergeSort = function(nums) {
    if (nums.length <= 1)   return nums;
    let mid = Math.floor(nums.length / 2);

    // 递归地对左右子数组进行排序
    let left = mergeSort(nums.slice(0, mid));   // 左半部分
    let right = mergeSort(nums.slice(mid));     // 右半部分

    return merge(left, right);
}

var merge = function(arr1, arr2) {
    let m = arr1.length, n = arr2.length;
    let i = 0, j = 0;
    let res = [];
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            res.push(arr1[i++]);
        else 
            res.push(arr2[j++]);
    }
    while (i < m) {
        res.push(arr1[i++]);
    }
    while (j < n) {
        res.push(arr2[j++]);
    }
    return res;
}
```

### 3. 堆排序

```js
var heapSort = function(arr) {
    // 1. 构建一个大根堆
    for (let i = Math.floor(arr.length / 2) - 1; i >= 0; i--) {
        sink(arr, i, arr.length);
    }

    // 2. 交换堆顶元素和最后一个元素，并重新调整堆
    for (let i = arr.length - 1; i >= 1; i--) {
        swap(arr, 0, i); // 将堆顶最大值放到数组末尾
        sink(arr, 0, i); // 调整剩下的堆
    }

    return arr;
};

/**
 * 下沉操作
 * @param {number[]} arr - 数组
 * @param {number} i - 当前下沉的节点索引
 * @param {number} length - 堆的有效长度
 */
var sink = function(arr, i, length) {
    while (true) {
        let left = i * 2 + 1;  // 左子节点索引
        let right = i * 2 + 2; // 右子节点索引
        let largest = i;       // 假设当前节点为最大值

        // 如果左子节点存在且比当前节点大
        if (left < length && arr[left] > arr[largest]) {
            largest = left;
        }

        // 如果右子节点存在且比当前节点大
        if (right < length && arr[right] > arr[largest]) {
            largest = right;
        }

        // 如果当前节点已经是最大值，则退出循环
        if (largest === i) {
            break;
        }

        // 交换当前节点和最大值节点
        swap(arr, i, largest);

        // 继续下沉
        i = largest;
    }
};

/**
 * 交换数组中两个元素的位置
 * @param {number[]} arr - 数组
 * @param {number} i - 第一个元素的索引
 * @param {number} j - 第二个元素的索引
 */
var swap = function(arr, i, j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
};
```

