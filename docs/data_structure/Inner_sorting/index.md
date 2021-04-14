<link rel="stylesheet" href="https://zhmhbest.gitee.io/hellomathematics/style/index.css">
<script src="https://zhmhbest.gitee.io/hellomathematics/style/index.js"></script>

# [内排序算法](../index.html)

[TOC]

## 插入排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>插入排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/insertion-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/insertion-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/insertion-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/insertion-sort.gif"/></td>
</tr></tbody>
</table>

- 稳定
- $O(1)$额外空间
- $O(n^2)$比较和互换
- 自适应性——当**基本有序**时，耗费$O(n)$的时间
- 非常低的开销

@import "src/insertion.c"

## 选择排序

>在交换单位的消耗成本很高的应用中，选择排序很可能也是合适的算法选择。

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>选择排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/selection-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/selection-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/selection-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/selection-sort.gif"/></td>
</tr></tbody>
</table>

- 不稳定
- $O(1)$ 额外空间
- $O(n2)$ 比较
- $O(n)$互换
- 不适应性

@import "./src/selection.c"

## 冒泡排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>冒泡排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/bubble-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/bubble-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/bubble-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/bubble-sort.gif"/></td>
</tr></tbody>
</table>

- 稳定
- $O(1)$额外空间
- $O(n^2)$比较和互换
- 适应性——当接近排序完的时候耗费 O(n) 时间

@import "./src/bubble.c"

## 希尔排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>希尔排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/shell-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/shell-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/shell-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/shell-sort.gif"/></td>
</tr></tbody>
</table>

- 不稳定
- $O(1)$额外空间
- 需要$O(n^{\frac{3}{2}})$时间
- 适应性——当接近排序完的时候耗费$O(n \cdot \log_2(n))$时间

@import "./src/shell.c"

## 归并排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>归并排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/merge-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/merge-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/merge-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/merge-sort.gif"/></td>
</tr></tbody>
</table>

- 稳定性
- 数组要$O(n)$额外空间
- 链表要$O(\log_2(n))$额外空间
- $O(n \cdot \log_2(n))$时间
- 不自适应
- 不需要随机接入数据

## 堆排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>堆排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/heap-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/heap-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/heap-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/heap-sort.gif"/></td>
</tr></tbody>
</table>

- 不稳定
- $O(1)$额外空间 (see discussion)
- $O(n \cdot \log_2(n))$时间
- 没有真正适应

## 快速排序

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>快速排序</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/quick-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/quick-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/quick-sort.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/quick-sort.gif"/></td>
</tr></tbody>
</table>

- 不稳定
- $O(\log_2(n))$额外空间
- $O(n^2)$时间，但通常$O(n \cdot \log_2(n))$的时间
- 没有真正适应

## 快速排序三平均

<table>
<thead><tr>
    <td>算法</td>
    <td>完全随机</td>
    <td>基本有序</td>
    <td>逆排序</td>
    <td>少有不同</td>
</tr></thead>
<tbody><tr>
    <td>快速排序三平均</td>
    <td><image alt="sorting" src="./images/animation/20/random-initial-order/quick-sort-3-way.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/nearly-sorted-initial-order/quick-sort-3-way.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/reversed-initial-order/quick-sort-3-way.gif"/></td>
    <td><image alt="sorting" src="./images/animation/20/few-unique-keys/quick-sort-3-way.gif"/></td>
</tr></tbody>
</table>

- 不稳定
- $O(\log_2(n))$额外空间
- $O(n^2)$时间，但通常O(n \cdot \log_2(n)) 的时间
- 自适应：$O(1)$ **Unique Keys**，$O(n)$时间
