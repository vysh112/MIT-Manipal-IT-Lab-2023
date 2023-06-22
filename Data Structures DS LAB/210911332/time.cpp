#include<iostream>
#include<stdio.h>
using namespace std;
class time
{
  private:
  int hh,mm,ss,day;
  public:
  time()
  {
    day=0;
    hh=mm=ss=0;
  }
  void display();
  void diff();
  void add();
  void read();
}t1,t2,t;

void time::add()
{
  if(t1.ss+t2.ss>=60)
  {
    t.ss=(t1.ss+t2.ss)-60;
    t.mm++;
  }
  else
    t.ss=t1.ss+t2.ss;

  int am=t1.mm+t2.mm+t.mm;
  if(am>=60)
  {
    t.mm=am-60;
    t.hh++;
  }
  else
    t.mm=am;

  int ah=t1.hh+t2.hh+t.hh;
  if(ah>=24)
  {
    t.hh=ah-24;
    t.day++;
  }
  else
    t.hh=ah;

  cout<<"\nTime after adding ";
  display();
  cout<<" and "<<t.day<<" day";
}

void time::diff()
{
  if(t1.ss-t2.ss<0)
    t.ss=t2.ss-t1.ss;
  else
    t.ss=t1.ss-t2.ss;

  if(t1.mm-t2.mm<0)
    t.mm=t2.mm-t1.mm;
  else
    t.mm=t1.mm-t2.mm;

  if(t1.hh-t2.hh<0)
    t.hh=t2.hh-t1.hh;
  else
    t.hh=t1.hh-t2.hh;

  cout<<"\nTime after difference ";
  display();
}

void time::display()
{
  cout<<"\is: "<<t.hh<<"/"<<t.mm<<"/"<<t.ss;
}

void time::read()
{
  cout<<"Enter time 1(hh/mm/ss): ";
  cin>>t1.hh>>t1.mm>>t1.ss;
  cout<<"\nEnter time 2: ";
  cin>>t2.hh>>t2.mm>>t2.ss;
  add();
  diff();
}

int main()
{

  time tt;
  tt.read();

}
