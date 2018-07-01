
#include <Arduino.h>
#include "../GraphicList/GraphicList.h"

class Tags {

private:
  HardwareSerial* serial;
  GraphicList* list;
  GraphicList* current;
public:
  Tags(GraphicList*, HardwareSerial*);
  void reset();
  Tags operator << (const char* tag);
};
