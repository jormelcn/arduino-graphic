
#include "Plot.h"

Plot::Plot(GraphicList* _list, HardwareSerial* _serial){
  serial = _serial;
  list = _list;
  reset();
}

void Plot::reset(){
  current = list;
  serial->print("&A;");
}


Plot Plot::operator << (int data){

  current = current->next();
  return *this;
}

Plot Plot::operator << (float data){
  
  current = current->next();
  return *this;
}

Plot Plot::operator << (double data){
  
  current = current->next();
  return *this;
}