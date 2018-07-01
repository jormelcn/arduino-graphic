
#include "Graphic.h"

Graphic::Graphic(HardwareSerial & _serial){
  serial = &_serial;
  list = new GraphicList();
  _plot = new Plot(list, serial);
  _tags = new Tags(list, serial);
  _units = new Units(list, serial);
  _colors = new Colors(list, serial);
  samplingTime = 0;
  firstPlot = true;
}

void Graphic::sampling(int _samplingTime, void (*f)()){
  samplingTime = _samplingTime;
  MsTimer2::set(samplingTime, f);
  MsTimer2::start();
  firstPlot = true; 
}

Plot Graphic::plot(){

  if(firstPlot){
    GraphicList* current = list;
    while(!current->empty()){
      current->item->setSamplingTime(samplingTime);
      current = current->next();
    }
    firstPlot = false;
  }

  _plot->reset();
  return *_plot;
}

Tags Graphic::tags(){
  _tags->reset();
  return *_tags;
}

Units Graphic::units(){
  _units->reset();
  return *_units;
}
