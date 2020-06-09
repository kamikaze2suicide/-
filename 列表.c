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
	
	printf("���������ݣ���-1������\n");
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
			printf("%d�������е�λ���ǵ�%dλ\n",num,count);	
			
			return headPtr;
		}
		headPtr=headPtr->nextPtr;
		count++;
	}	
	
		printf("ֵû���ҵ�\n"); 
   		return NULL;

}



void printList(LISTNODEPTR headPtr)  
{
	printf("�����ϸ���������Ϊ��\n");
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
	printf("������һ�����������\n");	
	scanf("%d",&newPtr->data);
	insertNode(headPtr,newPtr);
	printList(headPtr);
	
	printf("������һ���������Ҳ���λ��\n");
	scanf("%d",&num); 
	findNode(headPtr,num);
	
	return 0;
}
