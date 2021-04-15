
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
