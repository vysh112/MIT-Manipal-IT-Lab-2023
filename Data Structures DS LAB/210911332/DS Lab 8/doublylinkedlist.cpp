#include<iostream>
class dnode{
int info;
dnode *prev;
dnode *next;
public:
    *dnode insert_front(dnode *head);
    *dnode del_front(dnode *head);
    *dnode insert_rear(dnode *head);
};

dnode* dnode::insert_rear(dnode *head){
dnode *temp,*cur;

}

dnode* dnode::insert_front(dnode *head){
dnode *temp, *cur;
temp = new dnode;
cout<<"Enter element to be inserted \n";
cin>>temp->info;
cur=head->next;
head->next=temp;
temp->prev=head;
temp->next=cur;
cur->prev=temp;
return head;
}

dnode *dnode::del_front(dnode *head)
{
    dnode *cur,*next;
    if(head->next==head)
    {
        cout<<"Empty\n";
        return head;
    }
    cur=head->next;
    next=cur->next;
    head->next=next;
    next->prev=head;
    cout<<"Deleted item is:"<<cur->info;
    delete(cur);
    return head;
}
int main(){


}
