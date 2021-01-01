#include "node.h"

// 2-arg node constructor
node::node(const value_type& data, node * link) : data_(data), link_(link) {}

// overloaded << for debugging
std::ostream& operator <<(std::ostream& out, const node * head) {
  for (const node* p=head; p!=nullptr; p=p->link()) {
    out << p->data() << " ";
  }
  return out;
}

int sequence(int n) {
  if((n==0)||(n==1)){return 1;}
  return(sequence(n-2)+(n-1));
}

void list_clear(node * & head_ptr, node * & tail_ptr) {
  if((head_ptr==nullptr)&&(tail_ptr==nullptr)){return;}
  node* temp = head_ptr->link();
  delete head_ptr;
  head_ptr = temp;
  if (temp==nullptr) tail_ptr = nullptr;
  list_clear(head_ptr,tail_ptr);
}

void reverse(int a[], int start, int end) {
  int temp;
  if(end<=start){return;}
  temp=a[start];
  a[start]=a[end];
  a[end]=temp;
  reverse(a,start+1,end-1);
}

void list_reverse(node*& head, node*& tail) {
  int count=0;
  int count2=0;
  for (const node* p=head; p!=nullptr; p=p->link()) {
    head=new node(p->data(),head);
    count++;
  }
  while(count2!=count){
    node *penultimate;
    for (penultimate=head; penultimate->link()!=tail; penultimate=penultimate->link());
    delete tail;
    tail = penultimate;
    tail->set_link(nullptr);
    count2++;
  }
}
