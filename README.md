# DATA STRUCTURE NOTES

# 数据结构
---
## C/C++程序内存分配 
+ **栈(stack)**：编译器自动分配和释放内存，存放函数参数值和==局部变量==等；
+ **堆(heap)**：程序员分配释放，如链表节点存放于堆；  
+ **全局静态(static)**：全局和静态变量存储，程序结束后系统释放；  
+ **文字常量**


## 表ADT  

+ **数组(Array)**：  
  - 内存连续, 更好利用局部性原理；  
  - 内存空间必须一次性分配够，数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去,有界    
  - 插入和删除花费昂贵，代价为O(N)；  
+ **链表(List)**：  
  - 内存空间不连续，包含元素值和前后元素位置的指针，会消耗相对更多的储存空间
  - 避免插入和删除线性开销；

  优缺点：
  >（1）访问：数组O(1),链表O(N)；  
 （2）存储：取决于数据大小；
 （3）插入与删除：数组O(N),链表只需改变指针；  
 
 
+ **链表实现**：创建一个指向头节点的指针，分配新节点的内存并赋值新节点，将新节点地址给指针；
  ```c
  typedef struct Node{  /*整形链表,并赋别名Node可直接定义变量*/
    int data;
    struct Node *link;
  }Node;
  Node *A; /*指向Node结构类型的“指针”*/
  A=NULL;
  Node *tmp=(Node*)malloc(sizeof(Node));  /*malloc创建新节点给tmp指向*/  
  (*tmp)->data=2;
  (*tmp)->link=NULL;/*tmp赋值*/
  A=tmp;
  ```
   
   * **头部插入一个节点**：代码见/1_list/head_insert/;==注意节点指针和头指针是否为全局变量==  
   * **打印一个链表**：代码见/1_list/node_test/node.cpp;注意递归和迭代区别；
   * **任意位置插入节点**：代码见/1_list/node_test/node.cpp;
   * **任意位置删除节点**：代码见/1_list/node_test/node.cpp;==注意释放内存delete==
   * **反转链表**：代码见/1_list/node_test/node.cpp==注意head是局部变量,并且注意递归时的返回值==  
  
+ **双向链表**：有两个指针，一个指前节点一个指后节点；   
  ```c
  typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
  }Node;
  ```
  * **头部/尾部插入节点**：代码见/1_list/double_link_list;  
---
## 栈ADT
+ **栈(Stack)**：栈也是一种线性表，因此也有顺序和链式结构，比较常用的为顺序栈。
  - 特点：插入和删除只能从最上部进行(LIFO)；
  - 操作：  
    (1)压栈(push)；  
    (2)出栈(pop)；  
    (3)返回栈顶元素(top)；  
    (4)判断是否为空:  
    时间复杂度都为O(1)；
  - 应用：  
    (1)函数调用/递归；  
    (2)编辑器；  
    (3)编译器；
+ **实现**：  
  * **数组实现栈**：代码见/2_stack/array_imple;
  * **链表实现栈**: 代码见/2_stack/list_imple;  
+ **应用**：  
  * **反转一个字符串/链表**：代码见/2_stack/stack_usage;
  * **检查括号匹配**：代码见/2_stack/stack_usage/CheckBalance.cpp;
