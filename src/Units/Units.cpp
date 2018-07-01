
#include "Units.h"

Units::Units(GraphicList* _list, HardwareSerial* _serial){
  list = _list;
  serial = _serial;
}

void Units::reset(){
  current = list;
}

Units Units::operator << (const char* unit){
  if(current->empty())
    current = list->addNew(serial);
  current->item->setUnit(unit);
  current = current->next();
  return *this;
}