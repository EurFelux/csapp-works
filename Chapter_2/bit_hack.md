# Bit hack

从这里偷了一点技巧：<https://catonmat.net/low-level-bit-hacks>

## 将最右边的1设为0

```
y = x & (x-1)
```

## 隔离最右边的1

```
y = x & (-x)
```

## 将最右边的1向右传播

```
y = x | (x-1)
```

## 隔离最右边的0

```
y = ~x & (x+1)
```

## 将最右边的0设为1

```
y = x | (x+1)
```