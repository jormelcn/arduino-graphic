

#include <Arduino.h>
#include "../Color/Color.h"

#define GRAPH_HIGH_PRECISION  1
#define GRAPH_LOW_PRECISION   2

#define GRAPH_META_TIME 50

#define GRAPH_NONE  0
#define GRAPH_TAG   1
#define GRAPH_UNIT  2
#define GRAPH_COEF  3
#define GRAPH_COLOR 4

class GraphicItem {

private:
  HardwareSerial* serial;
  
  byte status;
  unsigned long metaTime;
  boolean updated;
  int samplingTime;

  char* tag;
  char* unit;
  Color* color;
  float coef;

  unsigned long updateElapsedTime();
  boolean newCoef(float);
  void sendMetadata();
  void sendTag();
  void sendUnit();
  void sendCoef();
  void sendColor();
  void sendData(float);

public:
  
  GraphicItem(HardwareSerial*);

  void setSamplingTime(int);
  boolean isUpdated();
  void update();

  void setTag(char*);
  void setUnit(char*);

  void plot(float);
};
