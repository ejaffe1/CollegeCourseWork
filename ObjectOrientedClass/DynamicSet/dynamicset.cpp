#include "dynamicset.h"

DynamicSet::DynamicSet(){
  used_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

DynamicSet::DynamicSet(const DynamicSet & s){
  if (s.capacity_>0) {
    data_ = new int[s.capacity_];
    for (size_t i=0; i<s.used_; i++) {
      data_[i] = s.data_[i];
    }
  }else{
    data_ = nullptr;
  }
  capacity_ = s.capacity_;
  used_ = s.used_;
}

DynamicSet::~DynamicSet(){
  delete [] data_;
  data_ = nullptr;
}

bool DynamicSet::contains(int target) const{
  for(int i=0;i<used_;i++){
    if(data_[i]==target){
      return true;
    }
  }
  return false;
}

bool DynamicSet::remove(int target){
  size_t i=0;
  while (i<used_ && data_[i]!=target) i++;
  if (i==used_) return false;

  for (i++; i<used_; i++) {
    data_[i-1]=data_[i];
  }
  used_--;

  if (used_ <= .25*capacity_ ) {
    capacity_ /= 2;
    int *temp = new int[capacity_];
    for (size_t i = 0; i<used_; i++) {
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
  }
  return true;
}

void DynamicSet::insert(int target){
  if(!this->contains(target)){
    if (capacity_ == 0) {
      capacity_ = 1;
      data_ = new int[capacity_];
    } else if (capacity_ == used_) {
      capacity_ *= 2;
      int *temp = new int[capacity_];
      for (size_t i = 0; i<used_; i++) {
        temp[i] = data_[i];
      }
      delete [] data_;
      data_ = temp;
    }
    data_[used_] = target;
    used_++;
  }
}

std::ostream& operator <<(std::ostream& out, const DynamicSet & s){
  for (size_t i=0; i<s.size(); i++) {
    out << s[i] << " ";
  }
  return out;
}

void DynamicSet::operator =(const DynamicSet & s2){
  used_ = s2.used_;
  if (capacity_ != s2.capacity_) {
    capacity_ = s2.capacity_;
    delete [] data_;
    data_ = new int[capacity_];
  }
  for (size_t i=0; i<used_; i++) {
    data_[i] = s2.data_[i];
  }
}

void DynamicSet::operator +=(const DynamicSet & s2){
  int counter=0;
  for (size_t i=0; i<s2.capacity_; i++) {
      if(!this->contains(s2.data_[i])){
        this->insert(s2.data_[i]);
         counter++;
      }
  }
  for(int i=counter; i<capacity_; i++){
    this->remove(0);
  }
}

void DynamicSet::operator *=(const DynamicSet & s2){
  int counter=0;
  for(size_t i=0;i<capacity_;i++){
    if(!s2.contains(data_[i])){
        this->remove(data_[i]);
        counter++;
    }
  }
  for(int i=counter; i<capacity_; i++){
    this->remove(0);
  }
}

void DynamicSet::operator -=(const DynamicSet & s2){
  int counter=0;
  for(int i=0;i<s2.capacity_;i++){
    if(this->contains(s2.data_[i])){
        this->remove(s2.data_[i]);
        counter++;
    }
  }
  for(int i=counter; i<capacity_; i++){
    this->remove(0);
  }
}

DynamicSet operator +(const DynamicSet & s1, const DynamicSet & s2){
  DynamicSet plus;
  int counter=0;
  for (size_t i=0; i<s1.size(); i++) {
    plus.insert(s1[i]);
  }
  for (size_t i=0; i<s2.size(); i++) {
      if(!plus.contains(s2[i])){
        plus.insert(s2[i]);
        counter++;
      }
  }
  for(int i=counter; i<s1.size()+s2.size(); i++){
    plus.remove(0);
  }
  return plus;
}

DynamicSet operator *(const DynamicSet & s1, const DynamicSet & s2){
  DynamicSet times;
  int counter=0;
  for (size_t i=0; i<s1.size()+s2.size(); i++) {
    if(s1.contains(s2[i])){
      if(!times.contains(s2[i])){
        times.insert(s2[i]);
        counter++;
      }
    }
  }
  for(int i=counter; i<s1.size()+s2.size(); i++){
    times.remove(0);
  }
  return times;
}

DynamicSet operator -(const DynamicSet & ls, const DynamicSet & s2){
  DynamicSet minus;
  int counter=0;
  for (size_t i=0; i<ls.size(); i++) {
    if(!s2.contains(ls[i])){
      if(!minus.contains(ls[i])){
        minus.insert(ls[i]);
        counter++;
      }
    }
  }
  for(int i=counter;i<ls.size()+s2.size();i++){
    minus.remove(0);
  }
  return minus;
}
