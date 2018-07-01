
#include <Arduino.h>
#include "../GraphicList/GraphicList.h"

class Units {

private:
  HardwareSerial* serial;
  GraphicList* list;
  GraphicList* current;
public:
  Units(GraphicList*, HardwareSerial*);
  void reset();
  Units operator << (const char* );
};

