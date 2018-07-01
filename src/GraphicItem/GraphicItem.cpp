
#include <Arduino.h>
#include "GraphicItem.h"

GraphicItem::GraphicItem(HardwareSerial* _serial){
  serial = _serial;
  tag = 0;
  unit = 0;
  color = 0;
  status = GRAPH_NONE;
  updated = false;
  coef = 0.0625f;
}

void GraphicItem::setSamplingTime(int _time){
  samplingTime = _time;
}

void GraphicItem::setTag(char* _tag){
  tag = _tag;
}

void GraphicItem::setUnit(char* _unit){
  unit = _unit;
}

void GraphicItem::update(){
  updated = false;
  status = GRAPH_TAG;
}

boolean GraphicItem::isUpdated(){
  return updated;
}

boolean GraphicItem::newCoef(float data){
  float newCoef = coef;
  
  while(newCoef*32768.0f < data){
    newCoef *= 2;
  }
  if(newCoef != coef){
    coef = newCoef;
    sendCoef();
    return true;
  }
  return false;
}

unsigned long GraphicItem::updateElapsedTime(){
  return millis() + samplingTime - metaTime;
}

void GraphicItem::sendMetadata(){
  unsigned long eTime = updateElapsedTime();
  if(status == GRAPH_TAG && eTime >= GRAPH_META_TIME){
    sendTag();
    status = GRAPH_UNIT;
  }
  if(status == GRAPH_UNIT && eTime >= GRAPH_META_TIME * 2){
    sendUnit();
    status = GRAPH_COEF;
  }
  if(status == GRAPH_COEF && eTime >= GRAPH_META_TIME * 3){
    sendCoef();
    status = GRAPH_COLOR;
  }
  if(status == GRAPH_COLOR && eTime >= GRAPH_META_TIME * 4){
    sendColor();
    updated = true;
    status = GRAPH_NONE;
  }
}

void GraphicItem::plot(float data){
  if(!newCoef(data) && !updated){
    sendMetadata();
  }
  sendData(data);
}

void GraphicItem::sendTag(){
  serial->write('&');
  serial->write('B');
  serial->write(';');
  if(tag)
    serial->print(tag);
  serial->write(';');
}

void GraphicItem::sendUnit(){
  serial->write('&');
  serial->write('C');
  serial->write(';');
  if(unit)
    serial->print(unit);
  serial->write(';');
}

void GraphicItem::sendCoef(){
  serial->write('&');
  serial->write('D');
  serial->write(';');
  serial->write((byte*) &coef, 4);
  serial->write(';');
}

void GraphicItem::sendColor(){
  serial->write('&');
  serial->write('E');
  serial->write(';');
  if(color){
    serial->write(color->r);
    serial->write(color->g);
    serial->write(color->b);
  }
  else{
    serial->write(0x00);
    serial->write(0x00);
    serial->write(0x00);
  }
  serial->write(';');
}


void GraphicItem::sendData(float data){
  int steps = data/coef;
  serial->write((byte*) &steps, 2);
}