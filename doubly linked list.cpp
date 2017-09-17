#include<iostream>
using namespace std;

class Doubly{
  struct node{
  struct node *pre;
  int info;
  struct node *next;
}*start,*last;
public:
Doubly(){
  //pre=NULL;
  start=NULL;
  last=NULL;
}
void createNodes();
void display_forward();
void display_backward();
void beg_insert();
void end_insert();
void pos_insert();
int count_elements();
};

void Doubly::createNodes(){
  node *n,*temp;
  cout<<"\nInsertion function\n";
  while(1){
    int num;
    cout<<"Enter the number\n";
    cin>>num;
    if(num==-1) break;
    n=new node;
    n->info=num;
    if(start==NULL){ start=n;n->pre=NULL;}
    else{
      temp->next=n;
      n->pre=temp;
    }
    temp=n;
  }
  n->next=NULL;
  last=n;
}
void Doubly::display_forward(){
  node *temp=start;
  cout<<"\nForward Output: ";
  while(temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->next;
  }
}
void Doubly::display_backward(){
  node *temp=last;
  cout<<"\nBackward Output: ";
  while(temp!=NULL){
    cout<<temp->info<<" ";
    temp=temp->pre;
  }
}

void Doubly::beg_insert(){
  node *n;
  cout<<"\nInsertion in Begining Function\n";
  int num;
  cout<<"Enter the Number you want to insert\n";
  cin>>num;
  n=new node;
  n->info=num;
  n->next=start;
  n->pre=NULL;
  start->pre=n;
  start=n;
}

void Doubly::end_insert(){
  node *n;
  cout<<"\nInsertion in End Function\n";
  int num;
  cout<<"Enter the number\n";
  cin>>num;
  n=new node;
  n->info=num;
  n->next=NULL;
  n->pre=last;
  last->next=n;
  last=n;
}

int Doubly::count_elements(){
  int c=0;
  node *temp=start;
  while(temp!=NULL){
    c++;
    temp=temp->next;
  }
  return c;
}

void Doubly::pos_insert(){
  int num;
  cout<<"\nEnter the position\n";
  cin>>num;
  node *n,*temp=start,*prev;
  int count=count_elements();
  if(num==1) beg_insert();
  else if(num==count) end_insert();
  else{
    int input;
    int c=0;
    cout<<"\nEnter number you want to insert\n";
    cin>>input;
    n=new node;
    n->info=input;
    while(temp!=NULL){c++;
      if(c==num){
        n->next=temp;
        n->pre=prev;
        prev->next=n;
        temp->pre=n;
        break;
      }
      prev=temp;
      temp=temp->next;
    }
  }

}

int main(){
  Doubly ob;
  ob.createNodes();
  ob.display_forward();
  ob.display_backward();
  cout<<"\n";
/*  ob.beg_insert();
  ob.display_forward();
  ob.display_backward();
  cout<<"\n";
  ob.end_insert();
  ob.display_forward();
  ob.display_backward();
  cout<<"\n";*/
  ob.pos_insert();
  ob.display_forward();
  ob.display_backward();
}
