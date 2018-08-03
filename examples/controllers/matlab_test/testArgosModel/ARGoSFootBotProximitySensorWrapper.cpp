#include "ARGoSFootBotProximitySensorWrapper.h"
#include <iostream>

argostype footBotProximitySensor_constructor(CCI_Controller* controller)
{
    CCI_FootBotProximitySensor* sensor = controller->GetSensor<CCI_FootBotProximitySensor>("footbot_proximity");
	argostype sensorPointer = (argostype)sensor;
	return sensorPointer;
}

void footBotProximitySensor_getReadings(argostype sensorPointer, double* angles, double* ranges)
{
	CCI_FootBotProximitySensor* sensor = (CCI_FootBotProximitySensor*)sensorPointer;
	
    // Get the sensor readings in the ARGoS type
    const CCI_FootBotProximitySensor::TReadings& readings = sensor->GetReadings();
    
    // Unpack the sensor readings into angles and ranges arrays
    for (size_t i = 0; i < readings.size(); ++i) {
      angles[i] = readings[i].Angle.GetValue();
      ranges[i] = readings[i].Value;
      //std::cout << std::to_string(ranges[i]);
    }
    
    //std::cout << "\n";

}

void footBotProximitySensor_destructor(argostype sensorPointer)
{
	CCI_FootBotProximitySensor* sensor = (CCI_FootBotProximitySensor*)sensorPointer;
	delete(sensor);
}