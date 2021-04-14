<link rel="stylesheet" href="https://zhmhbest.gitee.io/hellomathematics/style/index.css">
<script src="https://zhmhbest.gitee.io/hellomathematics/style/index.js"></script>

# [内排序算法](../index.html)

[TOC]

## 插入排序

- 稳定
- $O(1)$额外空间
- $O(n^2)$比较和互换
- 自适应性——当**基本有序**时，耗费$O(n)$的时间
- 非常低的开销

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
    <td><image alt="" src="./images/animation/20/random-initial-order/insertion-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/nearly-sorted-initial-order/insertion-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/reversed-initial-order/insertion-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/few-unique-keys/insertion-sort.gif"/></td>
</tr></tbody>
</table>

@import "src/insertion.c"

## 选择排序

>在交换单位的消耗成本很高的应用中，选择排序很可能也是合适的算法选择。

- 不稳定
- $O(1)$ 额外空间
- $O(n2)$ 比较
- $O(n)$互换
- 不适应性

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
    <td><image alt="" src="./images/animation/20/random-initial-order/selection-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/nearly-sorted-initial-order/selection-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/reversed-initial-order/selection-sort.gif"/></td>
    <td><image alt="" src="./images/animation/20/few-unique-keys/selection-sort.gif"/></td>
</tr></tbody>
</table>

