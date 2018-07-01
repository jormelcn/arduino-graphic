
#include <Arduino.h>
#include "../GraphicList/GraphicList.h"

class Colors {

private:
  GraphicList* list;
  HardwareSerial* serial;
public:
  Colors(GraphicList*, HardwareSerial*);
  void reset();
};
