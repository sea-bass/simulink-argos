#ifndef ARGOSFOOTBOTPROXIMITYSENSORWRAPPER_H
#define ARGOSFOOTBOTPROXIMITYSENSORWRAPPER_H

#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/foot-bot/control_interface/ci_footbot_proximity_sensor.h>

using namespace argos;

#if defined __cplusplus
extern "C" {
#endif

typedef void * argostype; 

argostype footBotProximitySensor_constructor(CCI_Controller* controller);
void footBotProximitySensor_getReadings(argostype sensorPointer, double *angles, double *ranges);
void footBotProximitySensor_destructor(argostype sensorPointer);

#if defined __cplusplus
}
#endif

#endif
