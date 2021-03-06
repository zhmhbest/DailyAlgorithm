<link rel="stylesheet" href="https://zhmhbest.gitee.io/hellomathematics/style/index.css">
<script src="https://zhmhbest.gitee.io/hellomathematics/style/index.js"></script>

# [线性表](../index.html)

[TOC]

## 链表

### 单链表

@import "singly_linked_list.c"

## 栈

栈（Stack）又名堆栈，它是限定仅在表尾（**栈顶**）进行插入和删除操作的线性表。

```CPP
push(x)     // 将一个元素放入栈顶。
pop()       // 从栈顶移除一个元素。
top()       // 返回栈顶元素。
empty()     // 是否为空。
length()    // 返回栈高（即已容纳元素的个数）。
```

@import "stack.c"

## 队列

队列（Queue）是只允许在表的前端进行删除，在表的后端进行插入的操作受限制的线性表。

```CPP
en(x)       // 将一个元素加入入队尾。
de()        // 从队首移除元素。
front()     // 返回队首元素。
empty()     // 是否队空。
full()      // 是否队满。
length()    // 返回队列长读（即已容纳元素的个数）。
```

### 循环队列

@import "queue.c"
