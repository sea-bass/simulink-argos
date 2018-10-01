#ifndef ARGOSDIFFERENTIALSTEERINGWRAPPER_H
#define ARGOSDIFFERENTIALSTEERINGWRAPPER_H

#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>

using namespace argos;

#if defined __cplusplus
extern "C" {
#endif

typedef void * argostype; 

argostype argosDifferentialSteering_constructor(CCI_Controller* controller);
void argosDifferentialSteering_setLinearVelocity(argostype actuatorPointer, double left_velocity, double right_velocity);
void argosDifferentialSteering_destructor(argostype actuatorPointer);

#if defined __cplusplus
}
#endif

#endif
