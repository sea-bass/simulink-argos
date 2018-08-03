//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// File: testArgosModel.h
//
// Code generated for Simulink model 'testArgosModel'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Fri Aug  3 09:36:33 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_testArgosModel_h_
#define RTW_HEADER_testArgosModel_h_
#include <string.h>
#include <stddef.h>
#ifndef testArgosModel_COMMON_INCLUDES_
# define testArgosModel_COMMON_INCLUDES_
#include <argos3/core/control_interface/ci_controller.h>
#include "rtwtypes.h"
#include "ARGoSDifferentialSteeringWrapper.h"
#include "ARGoSFootBotProximitySensorWrapper.h"
#endif                                 // testArgosModel_COMMON_INCLUDES_

#include "testArgosModel_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T wl;                           // '<Root>/Controller Chart'
  real_T wr;                           // '<Root>/Controller Chart'
} B_testArgosModel_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ARGoSDifferentialSteering_tes_T obj; // '<Root>/MATLAB System'
  ARGoSFootBotProximitySensor_t_T obj_n;// '<Root>/MATLAB System1'
  uint8_T is_active_c3_testArgosModel; // '<Root>/Controller Chart'
  uint8_T is_Turn;                     // '<Root>/Controller Chart'
  uint8_T is_Main;                     // '<Root>/Controller Chart'
} DW_testArgosModel_T;

// Real-time Model Data Structure
struct tag_RTM_testArgosModel_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model testArgosModel
class testArgosModelModelClass {
  // public data and function members
 public:
  // model initialize function
  void initialize(CCI_Controller *controller);

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  testArgosModelModelClass();

  // Destructor
  ~testArgosModelModelClass();

  // Real-Time Model get method
  RT_MODEL_testArgosModel_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_testArgosModel_T testArgosModel_B;

  // Block states
  DW_testArgosModel_T testArgosModel_DW;

  // Real-Time Model
  RT_MODEL_testArgosModel_T testArgosModel_M;

  // private member function(s) for subsystem '<Root>'
  real_T testArgosModel_sum(const real_T x_data[], const int32_T *x_size);
  boolean_T testArgosModel_isClear(const real_T MATLABSystem1_o1[25], const
    real_T MATLABSystem1_o2[25], const boolean_T validIdx[25]);
  void testArgosM_SystemCore_release_o(const ARGoSFootBotProximitySensor_t_T
    *obj);
  void testArgosMo_SystemCore_delete_o(const ARGoSFootBotProximitySensor_t_T
    *obj);
  void matlabCodegenHandle_matlabCod_o(ARGoSFootBotProximitySensor_t_T *obj);
  void testArgosMod_SystemCore_release(const ARGoSDifferentialSteering_tes_T
    *obj);
  void testArgosMode_SystemCore_delete(const ARGoSDifferentialSteering_tes_T
    *obj);
  void matlabCodegenHandle_matlabCodeg(ARGoSDifferentialSteering_tes_T *obj);
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'testArgosModel'
//  '<S1>'   : 'testArgosModel/Controller Chart'

#endif                                 // RTW_HEADER_testArgosModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
