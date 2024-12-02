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
var singleNumber = function(nums) {
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        res ^= nums[i];
    }
    return res;
};
```

#### [single-number-ii](https://leetcode-cn.com/problems/single-number-ii/)

```js
var singleNumber = function(nums) {
    let res = 0;
    for (let i = 0; i < 32; i++) {
        let sum = 0;
        for (let j = 0; j < nums.length; j++) {
            sum += (nums[j] >> i) & 1;
        }
        res ^= (sum % 3) << i;
    }
    return res;
};
```

#### [single-number-iii](https://leetcode-cn.com/problems/single-number-iii/)

```js
var singleNumber = function(nums) {
    let a = 0, b = 0, xor = 0;
    for (let i = 0; i < nums.length; i++)
        xor ^= nums[i];
    
    let div = 1;
    while ((xor & div) === 0)
        div = div << 1;
    
    for (let i = 0; i < nums.length; i++) {
        if ((nums[i] & div) === 0)
            a ^= nums[i];
        else 
            b ^= nums[i];
    }

    return [a, b];
};
```

#### [number-of-1-bits](https://leetcode-cn.com/problems/number-of-1-bits/)

```js
var hammingWeight = function(n) {
    let res = 0;

    // 移除最后一个1
    while (n) {
        n &= n - 1;
        res++;
    }

    return res;
};
```

#### [counting-bits](https://leetcode-cn.com/problems/counting-bits/)

```js
var countBits = function(n) {
    let res = [];
    for (let i = 0; i < n+1; i++) {
        res.push(count(i));
    }
    return res;
};

let count = function(n) {
    let res = 0;
    while (n) {
        n &= n - 1;
        res++;
    }
    return res;
}
```

#### [reverse-bits](https://leetcode-cn.com/problems/reverse-bits/)

```js
var reverseBits = function(n) {
    let res = 0;
    for (let i = 0; i < 32; i++) {
        //取得0/1
        let bit = (n >> i) & 1;
        //交换
        res = res | (bit << (31 - i));
    }
    //确保作为无符号整数结束
    return res>>>0;
};
```

#### [bitwise-and-of-numbers-range](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

```js
var rangeBitwiseAnd = function(left, right) {
    let cnt = 0;
    while (left !== right) {
        left >>= 1;
        right >>= 1;
        cnt++;
    }
    return left << cnt;
};
```

