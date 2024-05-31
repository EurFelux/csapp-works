# Homework of Chapter 2

过于困难而未能解决：

- [ ] 2.65
- [ ] 2.66

## 第一部分

### 2.55

从运行结果来看，我的机器是使用小端法的机器。

### 2.56

已经这样做了。

### 2.57

写是写出来了。但我哪来的几种机器啊？别难为我了吧。

### 2.58

`2.58.cpp`

### 2.59

`2.59.cpp`

### 2.60

`2.60.cpp`

## 第二部分

这里开始要应用以下规则：

- 假设
  - 整数用补码表示
  - 有符号数使用算术右移
  - 数据类型 int 有 $\omega$ 位，可以使用`sizeof(int) << 3`来计算$\omega$
- 禁止使用
  - 条件语句（`if`, `?:`）、循环、分支语句、函数调用、宏调用
  - 除法、模运算、乘法
  - 相对比较运算（`>`、`<`、`>=`、`<=`）
- 可以使用
  - 逻辑运算、位运算
  - 左移和右移，但是位移量在 0 和 w-1 之间
  - 加法、减法
  - `==` 和 `!=`
  - 常数 `INT_MIN` 和 `INT_MAX`
  - 对 `int` 和 `unsigned` 进行强制类型转换，无论是显式的还是隐式的

### 2.61

`2.61.cpp`

### 2.62

`2.62.cpp`

所以说测不了啊！！

### 2.63

`2.63.cpp`

#### `srl`的实现

因为逻辑右移无论如何只会补充0，所以只要把高k位清零就行了。目标是创建一个高k位全为0，低w-k位全为1的数，然后与x做与运算。但是`k == 0`的情况下，`w - k`会变成`w`，所以要特殊处理。

哦这简直是天才般的发想！`~(!!k) + 1`，还有异或操作！

#### `sra`的实现

只要判断出符号，然后把高k位补上符号位就行了。目标是创建一个高k位全为1，低w-k位全为0的数，然后如果x是负数，就与这个数做或运算，否则与0做或运算。然而这里不能再用右移了，怎么判断符号呢？

龟龟，完美的投球，马内！这表达式看得我自己都头晕！

### 2.64

`2.64.cpp`

### 2.65

`2.65.cpp`

不会啊！

### 2.66

`2.66.cpp`

也不会啊！

### 2.67

A. C语言标准不保证`int`有32位表示。对于16位机器而言，这是未定义行为。另外，`<< 32` 也是未定义行为。编译器在实现上可能会取模使得结果相当于`<< 0`，但对C语言标准而言，这是未定义行为。
B. `2.67.cpp` 
C. `2.67.cpp`

### 2.68

`2.68.cpp`

很遗憾，我在2.63里已经把这个问题解决了。

### 2.69

`2.69.cpp`

果然我已经在2.63解决了很核心的问题。没有白思考三个小时啊。啊哈哈~

### 2.70

`2.70.cpp`

对于一个w位补码表示的非负数而言，判断其是否能够由n位补码表示，只要判断从它是否从第n位开始到最高位全为0即可。所以只要构造一个n位全为1的数，然后与x做与运算，看结果是否为0即可。

对于一个w位补码表示的负数，则要判断它是否从第n位开始到最高位全为1。所以只要构造一个n位全为0的数，然后与x做或运算，看结果是否为全1即可。

哎呀，这个问题我在2.63里也解决了啊！说到底最核心的就是掩码问题，而掩码问题在2.63里已经解决了。

### 2.71

A. 问题在于，字节是有符号字节，而抽出的时候没有处理符号。例如，如果抽出的字节是`0xFF`，那么它实际上是-1，而不是255。
B. `2.71.cpp`.

只允许使用移位和一次减法，这怎么解决呢？这真的是1级难度吗？

### 2.72
