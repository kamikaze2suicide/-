# 北京邮电大学的第一计算机个作业

## 总结

  - [实验目的](#实验目的)
  - [假设有链表的结点类型定义如下](#假设有链表的结点类型定义如下)
  
## 实验目的

链表的基本操作（链表的创建，遍历，链表结点的插入）

## 假设有链表的结点类型定义如下

  struct node 
{
	int data;
	struct node *nextPtr;
};
typedef struct node LISTNODE;
typedef LISTNODE *LISTNODEPTR;
