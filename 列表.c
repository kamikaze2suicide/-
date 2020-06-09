#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *nextPtr;
};
typedef struct node LISTNODE;
typedef LISTNODE *LISTNODEPTR;
 
LISTNODEPTR creatSortList();
LISTNODEPTR insertNode(LISTNODEPTR headPtr,LISTNODEPTR newPtr);
LISTNODEPTR findNode(LISTNODEPTR headPtr, int num);
void printList(LISTNODEPTR headPtr);


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
