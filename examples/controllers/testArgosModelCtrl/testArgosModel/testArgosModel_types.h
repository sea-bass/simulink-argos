//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// File: testArgosModel_types.h
//
// Code generated for Simulink model 'testArgosModel'.
//
// Model version                  : 1.33
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Oct  1 11:04:37 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_testArgosModel_types_h_
#define RTW_HEADER_testArgosModel_types_h_
#include "rtwtypes.h"

// Custom Type definition for MATLABSystem: '<Root>/MATLAB System1'
#include "ARGoSFootBotProximitySensorWrapper.h"
#ifndef typedef_ARGoSDifferentialSteering_tes_T
#define typedef_ARGoSDifferentialSteering_tes_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  argostype actPtr;
} ARGoSDifferentialSteering_tes_T;

#endif                                 //typedef_ARGoSDifferentialSteering_tes_T

#ifndef typedef_ARGoSFootBotProximitySensor_t_T
#define typedef_ARGoSFootBotProximitySensor_t_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  argostype sensPtr;
} ARGoSFootBotProximitySensor_t_T;

#endif                                 //typedef_ARGoSFootBotProximitySensor_t_T

// Forward declaration for rtModel
typedef struct tag_RTM_testArgosModel_T RT_MODEL_testArgosModel_T;

#endif                                 // RTW_HEADER_testArgosModel_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
