
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include <Arduino.h>
#include "GraphicList/GraphicList.h"
#include "Plot/Plot.h"
#include "Tags/Tags.h"
#include "Units/Units.h"
#include "Colors/Colors.h"
#include "MsTimer2/MsTimer2.h"

class Graphic {

private:
  HardwareSerial* serial;
  GraphicList* list;
  Plot* _plot;
  Tags* _tags;
  Units* _units;
  Colors* _colors;
  int samplingTime;
  boolean firstPlot;

public:
  Graphic(HardwareSerial &);
  void sampling(int millis, void (*f)());
  Plot plot();
  Tags tags();
  Units units();
  Colors colors();
};

#endif
