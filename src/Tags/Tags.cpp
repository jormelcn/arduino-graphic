
#include "Tags.h"

Tags::Tags(GraphicList* _list, HardwareSerial* _serial){
  list = _list;
  serial = _serial;
  reset();
}

void Tags::reset(){
  current = list;
}

Tags Tags::operator << (const char* tag){
  if(current->empty())
    current = list->addNew(serial);
  current->item->setTag(tag);
  current = current->next();
  return *this;
}