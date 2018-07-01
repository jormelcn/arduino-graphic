
#ifndef _GRAPHIC_LIST_H_
#define _GRAPHIC_LIST_H_

#include <Arduino.h>
#include "../GraphicItem/GraphicItem.h"

class GraphicList {

private:
  GraphicList* _next;
  int _size;

public:  
  GraphicItem* item;

  GraphicList();
  GraphicList* addNew(HardwareSerial*);
  GraphicList* next();
  boolean empty();
  int size();
};
#endif
