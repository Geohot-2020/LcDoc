## 二进制

### 基本操作

a = 0^a = a^0

0 =a ^ a

a = a ^ b ^ b



### 交换两个数

a=a^b

b=a^b

a=a^b



### 移除最后一个 1

a=n&(n-1)



### 获取最后一个 1

diff=(n&(n-1))^n



### 常见题目

#### [single-number](https://leetcode-cn.com/problems/single-number/)

```js
function singleNumber(nums) {
    // 初始化结果为 0
    let result = 0;

    // 遍历数组，通过异或操作找到唯一的数字
    for (let i = 0; i < nums.length; i++) {
        result = result ^ nums[i]; // 两个相同的数异或会抵消为 0，最终剩下的就是只出现一次的数
    }

    return result; // 返回结果
}
```

#### [single-number-ii](https://leetcode-cn.com/problems/single-number-ii/)

```js
function singleNumber(nums) {
    let result = 0;

    // 遍历每一位（假设数值范围是 64 位整数）
    for (let i = 0; i < 64; i++) {
        let sum = 0;

        // 统计每个数字在第 i 位的 1 的个数
        for (let j = 0; j < nums.length; j++) {
            sum += (nums[j] >> i) & 1; // 右移 i 位后与 1 进行与运算
        }

        // sum % 3 得到当前位是 0 还是 1（因为每个数字出现 3 次，除了唯一出现一次的数字）
        // 用按位异或操作将当前位的值还原
        result ^= (sum % 3) << i;
    }

    return result; // 返回结果，即唯一出现一次的数字
}
```

#### [single-number-iii](https://leetcode-cn.com/problems/single-number-iii/)

```js
var singleNumber = function(nums) {
    // 获取异或值
    let a = 0, b = 0, xor = 0;
    for (let i = 0; i < nums.length; i++) {
        xor ^= nums[i];
    }
    
    // 从右往左，找到异或值为1的
    let div = 1;
    while ((xor & div) == 0) {
        div = div << 1;
    } 

    // 遍历，分两组
    for (let i = 0; i < nums.length; i++) {
        if ((nums[i] & div) == 0)
            a = a ^ nums[i];
        else 
            b = b ^ nums[i];
    }

    return [a, b];
};
```

#### [number-of-1-bits](https://leetcode-cn.com/problems/number-of-1-bits/)

```js
function hammingWeight(num) {
    let res = 0;

    // 当 num 不为 0 时，执行循环
    while (num !== 0) {
        // 每次操作将 num 的最低位的 1 置为 0
        num = num & (num - 1);
        // 统计 1 的个数
        res++;
    }

    return res;
}
```

#### [counting-bits](https://leetcode-cn.com/problems/counting-bits/)

```js
function countBits(num) {
    let res = new Array(num + 1).fill(0);

    // 遍历 0 到 num 的所有数字
    for (let i = 0; i <= num; i++) {
        res[i] = count1(i);  // 计算每个数字的 1 的个数
    }

    return res;
}

function count1(n) {
    let res = 0;
    // 每次操作将 n 的最低位的 1 置为 0，并统计 1 的个数
    while (n !== 0) {
        n = n & (n - 1);
        res++;
    }
    return res;
}
```

#### [reverse-bits](https://leetcode-cn.com/problems/reverse-bits/)

```js
function reverseBits(num) {
    let res = 0;
    let pow = 31;  // 用来表示当前位的权重

    while (num !== 0) {
        // 获取 num 的最低位，并左移到相应的高位
        res += (num & 1) << pow;
        num >>= 1;  // num 右移一位
        pow--;  // 权重减少
    }

    return res;
}

```

#### [bitwise-and-of-numbers-range](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

```js
function rangeBitwiseAnd(m, n) {
    let count = 0;

    // 当 m 和 n 不相等时，逐位右移 m 和 n
    while (m !== n) {
        m >>= 1;
        n >>= 1;
        count++;  // 记录右移的次数
    }

    // 将 m 左移 count 次，得到最终结果
    return m << count;
}
```

