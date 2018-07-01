
#include <Arduino.h>
#include "../GraphicList/GraphicList.h"

class Plot {

private:
  HardwareSerial* serial;
  GraphicList* list;
  GraphicList* current;
public:
  Plot(GraphicList*, HardwareSerial*);
  void reset();
  Plot operator << (int);
  Plot operator << (float);
  Plot operator << (double);
};
