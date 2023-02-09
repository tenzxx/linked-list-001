#include<iostream>

using namespace std;
typedef struct node
{
int info;
node *link;
}node;

void insert_beg(int);
void insert_end(int);
node *searchh(int);
void insafter(int,int);
void traverse();
void del_beg();
void del_endd();
void del_aftergiven(int);
node *ptr,*loc=NULL,*start=NULL,*temp;

int main()
{
char ch;
int x,item,aitem;
do
{
cout<<" 1. for Insertion at beginning. \n 2. for Insertion at End. \n 3. for Searching. \n 4. for Insertion at specific location. \n 5. for Traverse. \n 6. for Deletion at Beginning. \n 7. for Deletion at End. \n 8. for Deletion after a specific Location."<<endl;
cin>>x;

switch(x)
{
case 1: cout<<"Enter the Element to be inserted."<<endl;
cin>>item;
insert_beg(item);
break;
case 2: cout<<"Enter the Element to be inserted."<<endl;
cin>>item;
insert_end(item);
break;
case 3: cout<<"Enter an Element which is to be searched."<<endl;
cin>>item;
temp=searchh(item);
if(temp==NULL)
{
cout<<"Element is not found."<<endl;
}
else
{
cout<<"Element is at "<<temp<<" location."<<endl;
}
break;
case 4: cout<<"Enter that element after Insertion is to be done."<<endl;
cin>>aitem;
cout<<"Enter Element is to be Insert."<<endl;
cin>>item;
insafter(item ,aitem);
break;
case 5: traverse();
break;
case 6: del_beg();
break;
case 7: del_endd();
break;
case 8: cout<<"Enter element after that deletion is to done. "<<endl;
cin>>aitem;
del_aftergiven(aitem);
break;
default:cout<<"Wrong choice."<<endl;
break;
}
cout<<"press 'y' If want to enter again."<<endl;
cin>>ch;
}while(ch=='y');
return 0;
}
void insert_beg(int item)
{
ptr=new node;
ptr->info=item;
if(start==NULL)
{
ptr->link=NULL;
}
else
{
ptr->link=start;
}
start=ptr;
return;
}

void insert_end(int item)
{
ptr=new node;
ptr->info=item;
ptr->link=NULL;
if(start==NULL)
{
start=ptr;
}
else
{
loc=start;
while(loc->link!=NULL)
{
loc=loc->link;
}
loc->link=ptr;
}
return;
}

node *searchh(int item)
{
ptr=start;
while(ptr!=NULL)
{
if(item==ptr->info)
{
return ptr;
}
ptr=ptr->link;
}
return NULL;
}

void insafter(int item,int aitem)
{
loc=searchh(aitem);
if(loc==NULL)
{
cout<<"The element after that you want to insert not exist."<<endl;
}
else if(loc->link==NULL)
{
ptr=new node;
ptr->info=item;
ptr->link=NULL;
loc->link=ptr;
}
else
{
ptr=new node;
ptr->info=item;
ptr->link=loc->link;
loc->link=ptr;
return;
}

}

void traverse()
{
ptr=start;
while(ptr!=NULL)
{
cout<<ptr->info<<endl;
ptr=ptr->link;
}
}

void del_beg()
{
ptr=start;
start=start->link;
delete ptr;
}

void del_endd()
{
ptr=start;
if(start==NULL)
{
cout<<"List is Empty."<<endl;
return;
}
else if(start->link==NULL)
{
ptr=start;
start=NULL;
delete ptr;
}
else
{
loc=start;
ptr=ptr->link;
while(ptr->link!=NULL)
{
loc=ptr;
ptr=ptr->link;
}
loc->link=NULL;
delete ptr;
cout<<"Last Node is deleted"<<endl;
return;
}
delete ptr;
}
void del_aftergiven(int aitem)
{
loc=searchh(aitem);
if(loc==NULL)
{
cout<<"The element after deletion is to be done not exist."<<endl;
return;
}
else if(loc->link==NULL)
{
cout<<"this is last node of list deletion is not-possible."<<endl;
}
else
{
ptr=loc->link;
loc->link=ptr->link;
delete ptr;
cout<<"The element is deleted. "<<endl;
}
return;
}
