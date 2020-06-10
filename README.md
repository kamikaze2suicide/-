# 北京邮电大学的第一个计算机作业

## 总结

  - [实验目的](#实验目的)
  - [假设有链表的结点类型定义如下](#假设有链表的结点类型定义如下)
  - [要求](#要求)
  - [代码风格要求](#代码风格要求)
  - [程序书写风格要求](#程序书写风格要求)
  - [开始](#开始)
  - [开应用方式始](#应用方式)
  - [作者](#作者)
  
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

## 要求

- 设计函数：LISTNODEPTR creatSortList（）; 函数功能为：读入任意一串整数，以-1结束，创建有序链表并返回表头指针。
- 设计插入结点的函数：void insertNode（LISTNODEPTR * headPtr，int num）; 
函数功能为：将参数num插入到链表中，要求调用查找到插入位置函数，然后插入。
- 设计查找插入位置函数LISTNODEPTR findNode（LISTNODEPTR headPtr，int num）; 函数功能为，按照数值大小查找到插入位置，并返回该结点的指针
- 设计输出链表的函数：void printList（LISTNODEPTR headPtr）; 函数功能是：输出该有序链表

## 代码风格要求

- 变量定义处对每个变量的用途（即用于保存什么数据）进行说明; 
- 适当使用空行来分隔实现不同功能的代码段; 
- 选择，循环语句要有缩进; 
- 对代码段的功能要有注释;

## 程序书写风格要求
从程序缩进，空行使用，注释以及变量命名几个方面进行要求;
- 变量命名要有含义，尽量做到见名知意。
- 程序要有必要注释，说明程序代码的功能。
- 使用空行，将不同功能的代码段进行分割，提高代码的可读性。
- 使用程序缩进，提高代码的可读性。

## 开始

- 链表的创建

		LISTNODEPTR creatSortList() 
		{
			LISTNODEPTR newPtr=NULL, headPtr = NULL;
			int num;

			printf("请输入数据，以-1结束：\n");
			scanf("%d",&num);
			while(num!=-1)
			{
				newPtr=malloc(sizeof(LISTNODE));
				newPtr->data=num;
				headPtr=insertNode(headPtr,newPtr);  

				scanf("%d",&num);
			}
			return headPtr;
		}

- 遍历

		LISTNODEPTR findNode (LISTNODEPTR headPtr, int num)
		{
			int count=1;
		    while(headPtr!=NULL)
		    {
			if(headPtr->data==num)
			{	
					printf("%d在链表中的位置是第%d位\n",num,count);	

					return headPtr;
				}
				headPtr=headPtr->nextPtr;
				count++;
			}	

				printf("值没有找到\n"); 
				return NULL;
		}
		
- 链表结点的插入

		LISTNODEPTR insertNode(LISTNODEPTR headPtr,LISTNODEPTR newPtr) 
		{
			LISTNODEPTR previousPtr,lastPtr;

			if(headPtr==NULL )
			{      
				headPtr=newPtr;  
				newPtr->nextPtr=NULL;

				return headPtr;
			}
			if(headPtr->data >= newPtr->data)  
			{
				newPtr->nextPtr=headPtr;   
				headPtr=newPtr;

				return headPtr;
			}

			lastPtr=previousPtr=headPtr;

			while(lastPtr->nextPtr && lastPtr->data < newPtr->data)  
			{
				previousPtr=lastPtr;  
				lastPtr=lastPtr->nextPtr;
			}
			if(lastPtr->data < newPtr->data) 
			{
				lastPtr->nextPtr=newPtr; 
				newPtr->nextPtr=NULL;
			}
			else  
			{
				newPtr->nextPtr=lastPtr; 
				previousPtr->nextPtr=newPtr;
			}

			return headPtr;
		}
- 输出列表

		void printList(LISTNODEPTR headPtr)  
		{
			printf("链表上各结点的数据为：\n");
			while(headPtr!=NULL)
			{
				printf("%d ",headPtr->data);
				headPtr=headPtr->nextPtr;
			}
			printf("\n");
		}
- 主要

		int main()
		{
			LISTNODEPTR headPtr;
			int num;

			headPtr=creatSortList();	
			printList(headPtr);

			LISTNODEPTR newPtr=malloc(sizeof(LISTNODE));
			printf("请输入一个待插入的数\n");	
			scanf("%d",&newPtr->data);
			insertNode(headPtr,newPtr);
			printList(headPtr);

			printf("请输入一个数，查找插入位置\n");
			scanf("%d",&num); 
			findNode(headPtr,num);

			return 0;
		}
注意: 就能输入正整数， 停的话输入: -1

## 应用方式

- 数据排序
- 数据保存
- 数据显示

## 作者

- 英文姓名: Daniil Perov
- 中文姓名: 裴丹宁
- 大学: 北京邮电大学
