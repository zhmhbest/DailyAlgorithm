<link rel="stylesheet" href="https://zhmhbest.gitee.io/hellomathematics/style/index.css">
<script src="https://zhmhbest.gitee.io/hellomathematics/style/index.js"></script>

# [内排序算法](../index.html)

[TOC]

## 插入排序

### 直接插入排序

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
- 时间复杂度：$O(n^2)$
  - 序列完全正序：仅需比较$n-1$次
  - 序列完全逆序：比较$\sum\nolimits_{i=2}^{n}i$次、移动$\sum\nolimits_{i=2}^{n}(i+1)$次
  - 序列基本有序：$O(n)$
- 适应性：随着排序的的进行，序列变得基本有序，算法效率逐渐提高。

@import "src/straight_insertion_sort.c"

### 折半插入排序

略

### 希尔排序

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
- 大概时间复杂度：$O(n^{\frac{3}{2}})$（由于数学问题，无法准确描述）
- 适应性：由于希尔排序基于插入排序，希尔排序继承了插入排序的自适应性，但适应性较直接插入排序弱。

@import "./src/shell_insertion_sort.c"

## 选择排序

### 简单选择排序

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
- $O(1)$额外空间
- 时间复杂度：$O(n^2)$
- 不适应性

@import "./src/simple_selection_sort.c"

### 树形选择排序

略

### 堆排序

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
- $O(1)$额外空间
- $O(n \cdot \log_{2}n)$时间
- 没有真正适应

@import "./src/heap_selection_sort.c"

#### ArrayToHeap

```c
int arr[] = {A, B, C, D, E, F, G, H};
//      i = {0, 1, 2, 3, 4, 5, 6, 7};

// liftLeafNodeIndex  = 2 * currentNodeIndex + 1;
// rightLeafNodeIndex = 2 * currentNodeIndex + 2;
```

```mermaid
graph TB
    A((A));
    B((B));
    C((C));
    D((D));
    E((E));
    F((F));
    G((G));
    H((H));
    A---B; A---C;
    B---D; B---E;
    C---F; C---G;
    D---H;
```

#### HeapAdjust

```c
int arr[] = {49, 38, 13, 49, 76, 65, 27, 97};
// 构建大顶堆
int res[] = {97, 76, 65, 49, 49, 13, 27, 38};
```

- <span style='color: pink'>冻结前</span>、<span style='color: red'>冻结</span>、<span style='color: lightgreen'>取代冻结点</span>、<span style='color: yellow'>调整节点</span>

```mermaid
graph TD
    subgraph 2
        style 2 stroke:#333,stroke-width:2px,fill:grey;
        style B2 fill:yellow;
        A2((49));
        B2((38));
        C2((65));
        D2((97));
        E2((76));
        F2((13));
        G2((27));
        H2((49));
        A2---B2; A2---C2;
        B2-.-D2; B2---E2;
        C2---F2; C2---G2;
        D2-.-H2;
    end
    subgraph 1
        style 1 stroke:#333,stroke-width:2px,fill:grey;
        style C1 fill:yellow;
        A1((49));
        B1((38));
        C1((13));
        D1((97));
        E1((76));
        F1((65));
        G1((27));
        H1((49));
        A1---B1; A1---C1;
        B1---D1; B1---E1;
        C1-.-F1; C1---G1;
        D1---H1;
    end
    subgraph 0
        style 0 stroke:#333,stroke-width:2px,fill:grey;
        style D0 fill:yellow;
        A0((49));
        B0((38));
        C0((13));
        D0((49));
        E0((76));
        F0((65));
        G0((27));
        H0((97));
        A0---B0; A0---C0;
        B0---D0; B0---E0;
        C0---F0; C0---G0;
        D0-.-H0;
    end
```

```mermaid
graph TD
    subgraph 5
        style 5 stroke:#333,stroke-width:2px,fill:grey;
        style H5 fill:red;
        style A5 fill:yellow;
        A5((38));
        B5((76));
        C5((65));
        D5((49));
        E5((49));
        F5((13));
        G5((27));
        H5((97));
        A5-.-B5; A5---C5;
        B5-.-D5; B5---E5;
        C5---F5; C5---G5;
        D5---H5;
    end
    subgraph 4
        style 4 stroke:#333,stroke-width:2px,fill:grey;
        style A4 fill:pink;
        style H4 fill:lightgreen;
        A4((97));
        B4((76));
        C4((65));
        D4((49));
        E4((49));
        F4((13));
        G4((27));
        H4((38));
        A4---B4; A4---C4;
        B4---D4; B4---E4;
        C4---F4; C4---G4;
        D4---H4;
    end
    subgraph 3
        style 3 stroke:#333,stroke-width:2px,fill:grey;
        style A3 fill:yellow;
        A3((49));
        B3((97));
        C3((65));
        D3((49));
        E3((76));
        F3((13));
        G3((27));
        H3((38));
        A3-.-B3; A3---C3;
        B3---D3; B3-.-E3;
        C3---F3; C3---G3;
        D3---H3;
    end
```

- 0-4为构建大顶堆
- 4为构建大顶堆的结果
- 从4开始为调整大顶堆

## 交换排序

### 冒泡排序

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
- 时间复杂的：$O(n^2)$
  - 基本有序：$O(n)$
- 适应性

@import "./src/bubble_swap_sort.c"

### 快速排序

>通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小。

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
- $O(\log_{2}n)$额外空间
- 时间复杂度：$O(n^2)$，但通常$O(n \cdot log_{2}n)$
- 没有真正适应

@import "./src/quick_swap_sort.c"

### 快速排序三平均

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
- $O(\log_{2}n)$额外空间
- 时间复杂度：$O(n^2)$，但通常$O(n \cdot log_{2}n)$
- 自适应：当有$O(1)$个**Unique Keys**时需要，$O(n)$时间

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
- 数组要$O(n)$额外空间；链表要$O(\log_{2}n)$额外空间
- $O(n \cdot \log_{2}n)$时间
- 不自适应
- 不需要随机接入数据

## 基数排序

略
