#include<iostream>

using namespace std;
class list
{
  int coeff;
  int degree;
  list *next;

  public:
  void insert();
  void insert(int,int);
  void display();
  void add();
};

list *rear1=NULL;
list *rear2=NULL;
list *rear3=NULL;
list *head1=new list;
list *front1=head1;
list *head2=new list;
list *front2=head2;
list *head3=new list;
list *front3=head3;

void list::insert()
{
  cout<<"\nInsert in list 1 or 2? ";
  int n;
  cin>>n;
  list *temp=new list;
  int c,d;
  cout<<"\nEnter coeffecient: ";
  cin>>c;
  cout<<"\nEnter degree: ";
  cin>>d;
  temp->coeff=c;
  temp->degree=d;
  if(n==1)
  {
    if(rear1==NULL)
    {
      head1->next=temp;
      rear1=temp;
      temp->next=front1;
    }
    else
    {
      rear1->next=temp;
      rear1=temp;
      temp->next=front1;
    }
  }
  else if(n==2)
  {
    if(rear2==NULL)
    {
      head2->next=temp;
      rear2=temp;
      temp->next=front2;
    }
    else
    {
      rear2->next=temp;
      rear2=temp;
      temp->next=front2;
    }
  }
  else
    cout<<"\nEnter valid list number!!!";
}

void list::insert(int c, int d)
{
  list *temp=new list;
  temp->coeff=c;
  temp->degree=d;
  if(rear3==NULL)
  {
    head3->next=temp;
    rear3=temp;
    temp->next=front3;
  }
  else
  {
    rear3->next=temp;
    rear3=temp;
    temp->next=front3;
  }
}

void list::add()
{
  rear3=NULL;
  head3->next=NULL;
  list *curr2=front2->next;
  for(list *curr1=front1->next;curr1!=head1;curr1=curr1->next)
  {
    if(curr2->degree==curr1->degree)
    {
      insert((curr2->coeff+curr1->coeff), curr2->degree);
      curr2=curr2->next;
    }

    else if(curr1->degree>curr2->degree)
      insert(curr1->coeff,curr1->degree);

    else if(curr1->degree<curr2->degree)
    {
      while(curr2->degree<curr1->degree || curr2!=head2)
      {
	insert(curr2->coeff,curr2->degree);
	if(curr2->degree==curr1->degree)
	  insert((curr2->coeff+curr1->coeff), curr2->degree);
      }
    }
  }
  if(curr2!=head2)
  {
    while(curr2!=head2)
    {
      insert(curr2->coeff,curr2->degree);
      curr2=curr2->next;
    }
  }
  list *curr;
  for(curr=front3->next;curr!=head3;curr=curr->next)
    cout<<curr->coeff<<"x^"<<curr->degree<<" + ";
}

void list::display()
{
  cout<<"\nDisplay list 1 or 2?";
  int n;
  cin>>n;
  list *curr;
  if(n==1)
  {
    for(curr=front1->next;curr!=head1;curr=curr->next)
      cout<<curr->coeff<<"x^"<<curr->degree<<" + ";
  }
  else if(n==2)
  {
    for(list *curr=front2->next;curr!=head2;curr=curr->next)
      cout<<curr->coeff<<"x^"<<curr->degree<<" + ";
  }
  else
    cout<<"\nEnter valid list number!";
}

int main()
{

  char cont='y';
  int opt;
  list l;

  while(cont=='y')
  {
    cout<<"\n1.Insert\n2.Display\n3.Add\n4.Exit\n\nEnter your choice: ";
    cin>>opt;
    switch(opt)
    {
      case 1:  l.insert();
	       break;
      case 2:  l.display();
	       break;
      case 3:  l.add();
	       break;
      case 4: exit(0);
    }
    cout<<"Continue(y/n): ";
    cin>>cont;
  }
  return 0;
}
