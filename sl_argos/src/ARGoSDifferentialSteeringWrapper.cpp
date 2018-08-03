#include "ARGoSDifferentialSteeringWrapper.h"

argostype argosDifferentialSteering_constructor(CCI_Controller* controller)
{
    CCI_DifferentialSteeringActuator* actuator = controller->GetActuator<CCI_DifferentialSteeringActuator>("differential_steering");
	argostype actuatorPointer = (argostype)actuator;
	return actuatorPointer;
}

void argosDifferentialSteering_setLinearVelocity(argostype actuatorPointer, double left_velocity, double right_velocity)
{
	CCI_DifferentialSteeringActuator* actuator = (CCI_DifferentialSteeringActuator*)actuatorPointer;
	actuator->SetLinearVelocity(left_velocity,right_velocity);

}

void argosDifferentialSteering_destructor(argostype actuatorPointer)
{
	CCI_DifferentialSteeringActuator* actuator = (CCI_DifferentialSteeringActuator*)actuatorPointer;
	delete(actuator);
}