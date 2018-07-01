
#include "GraphicList.h"

GraphicList::GraphicList(){
  item = 0;
  _size = 0;
  _next = 0;
}

int GraphicList::size(){
  return _size;
}

GraphicList* GraphicList::addNew(HardwareSerial* serial){
  _size++;
  if(empty()){
    item = new GraphicItem(serial);
    return this;
  }
  return next()->addNew(serial);
}

boolean GraphicList::empty(){
  return item == 0;
}

GraphicList* GraphicList::next(){
  if(!_next)
    _next = new GraphicList();
  return _next;
}