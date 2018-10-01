//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// File: testArgosModel.cpp
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
#include "testArgosModel.h"
#include "testArgosModel_private.h"

// Named constants for Chart: '<Root>/Controller Chart'
#define testArgosMod_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define testArgosModel_IN_Straight     ((uint8_T)1U)
#define testArgosModel_IN_Turn         ((uint8_T)2U)
#define testArgosModel_IN_TurnLeft     ((uint8_T)1U)
#define testArgosModel_IN_TurnRight    ((uint8_T)2U)

// Function for Chart: '<Root>/Controller Chart'
real_T testArgosModelModelClass::testArgosModel_sum(const real_T x_data[], const
  int32_T *x_size)
{
  real_T y;
  int32_T k;
  if (*x_size == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= *x_size; k++) {
      y += x_data[k - 1];
    }
  }

  return y;
}

// Function for Chart: '<Root>/Controller Chart'
boolean_T testArgosModelModelClass::testArgosModel_isClear(const real_T
  MATLABSystem1_o1[25], const real_T MATLABSystem1_o2[25], const boolean_T
  validIdx[25])
{
  boolean_T out;
  int8_T b_data[25];
  int8_T c_data[25];
  int32_T trueCount;
  int32_T i;
  int32_T partialTrueCount;
  boolean_T y;
  boolean_T x_data[25];
  boolean_T exitg1;
  trueCount = 0;
  partialTrueCount = 0;
  for (i = 0; i < 25; i++) {
    if (validIdx[i]) {
      trueCount++;
      b_data[partialTrueCount] = (int8_T)(i + 1);
      partialTrueCount++;
    }
  }

  for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++) {
    x_data[partialTrueCount] = (MATLABSystem1_o1[b_data[partialTrueCount] - 1] <=
      0.17453292519943295);
  }

  y = true;
  partialTrueCount = 1;
  exitg1 = false;
  while ((!exitg1) && (partialTrueCount <= trueCount)) {
    if (!x_data[partialTrueCount - 1]) {
      y = false;
      exitg1 = true;
    } else {
      partialTrueCount++;
    }
  }

  if (y) {
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 25; i++) {
      if (validIdx[i]) {
        trueCount++;
        c_data[partialTrueCount] = (int8_T)(i + 1);
        partialTrueCount++;
      }
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      x_data[partialTrueCount] = (MATLABSystem1_o2[c_data[partialTrueCount] - 1]
        >= 0.5);
    }

    out = true;
    partialTrueCount = 1;
    exitg1 = false;
    while ((!exitg1) && (partialTrueCount <= trueCount)) {
      if (!x_data[partialTrueCount - 1]) {
        out = false;
        exitg1 = true;
      } else {
        partialTrueCount++;
      }
    }
  } else {
    out = false;
  }

  return out;
}

void testArgosModelModelClass::testArgosM_SystemCore_release_o(const
  ARGoSFootBotProximitySensor_t_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    footBotProximitySensor_destructor(obj->sensPtr);
  }
}

void testArgosModelModelClass::testArgosMo_SystemCore_delete_o(const
  ARGoSFootBotProximitySensor_t_T *obj)
{
  testArgosM_SystemCore_release_o(obj);
}

void testArgosModelModelClass::matlabCodegenHandle_matlabCod_o
  (ARGoSFootBotProximitySensor_t_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    testArgosMo_SystemCore_delete_o(obj);
  }
}

void testArgosModelModelClass::testArgosMod_SystemCore_release(const
  ARGoSDifferentialSteering_tes_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    argosDifferentialSteering_destructor(obj->actPtr);
  }
}

void testArgosModelModelClass::testArgosMode_SystemCore_delete(const
  ARGoSDifferentialSteering_tes_T *obj)
{
  testArgosMod_SystemCore_release(obj);
}

void testArgosModelModelClass::matlabCodegenHandle_matlabCodeg
  (ARGoSDifferentialSteering_tes_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    testArgosMode_SystemCore_delete(obj);
  }
}

// Model step function
void testArgosModelModelClass::step()
{
  int8_T b_data[25];
  int32_T trueCount;
  int32_T partialTrueCount;
  real_T avgAng;
  real_T MATLABSystem1_o1[25];
  real_T MATLABSystem1_o2[25];
  boolean_T validIdx[25];
  int32_T i;
  real_T MATLABSystem1_o1_data[25];
  boolean_T validIdx_p;

  // MATLABSystem: '<Root>/MATLAB System1'
  memset(&MATLABSystem1_o1[0], 0, 25U * sizeof(real_T));
  memset(&MATLABSystem1_o2[0], 0, 25U * sizeof(real_T));
  footBotProximitySensor_getReadings(testArgosModel_DW.obj_n.sensPtr,
    MATLABSystem1_o1, MATLABSystem1_o2);

  // Chart: '<Root>/Controller Chart' incorporates:
  //   Constant: '<Root>/Wheel Speed'
  //   MATLABSystem: '<Root>/MATLAB System1'

  if (testArgosModel_DW.is_active_c3_testArgosModel == 0U) {
    testArgosModel_DW.is_active_c3_testArgosModel = 1U;
    testArgosModel_DW.is_Main = testArgosModel_IN_Straight;
    testArgosModel_B.wl = 2.5;
    testArgosModel_B.wr = 2.5;
  } else {
    trueCount = 0;
    partialTrueCount = 0;
    for (i = 0; i < 25; i++) {
      validIdx_p = (MATLABSystem1_o2[i] > 0.0);
      if (validIdx_p) {
        trueCount++;
        b_data[partialTrueCount] = (int8_T)(i + 1);
        partialTrueCount++;
      }

      validIdx[i] = validIdx_p;
    }

    for (partialTrueCount = 0; partialTrueCount < trueCount; partialTrueCount++)
    {
      MATLABSystem1_o1_data[partialTrueCount] =
        MATLABSystem1_o1[b_data[partialTrueCount] - 1];
    }

    avgAng = testArgosModel_sum(MATLABSystem1_o1_data, &trueCount) / 25.0;
    if (testArgosModel_DW.is_Main == testArgosModel_IN_Straight) {
      validIdx_p = !testArgosModel_isClear(MATLABSystem1_o1, MATLABSystem1_o2,
        validIdx);
      if (validIdx_p) {
        testArgosModel_DW.is_Main = testArgosModel_IN_Turn;
        if (avgAng < 0.0) {
          testArgosModel_DW.is_Turn = testArgosModel_IN_TurnLeft;
          testArgosModel_B.wl = 0.0;
          testArgosModel_B.wr = 2.5;
        } else {
          testArgosModel_DW.is_Turn = testArgosModel_IN_TurnRight;
          testArgosModel_B.wl = 2.5;
          testArgosModel_B.wr = 0.0;
        }
      }
    } else {
      validIdx_p = testArgosModel_isClear(MATLABSystem1_o1, MATLABSystem1_o2,
        validIdx);
      if (validIdx_p) {
        testArgosModel_DW.is_Turn = testArgosMod_IN_NO_ACTIVE_CHILD;
        testArgosModel_DW.is_Main = testArgosModel_IN_Straight;
        testArgosModel_B.wl = 2.5;
        testArgosModel_B.wr = 2.5;
      } else if (testArgosModel_DW.is_Turn == testArgosModel_IN_TurnLeft) {
        if (avgAng > 0.0) {
          testArgosModel_DW.is_Turn = testArgosModel_IN_TurnRight;
          testArgosModel_B.wl = 2.5;
          testArgosModel_B.wr = 0.0;
        }
      } else {
        if (avgAng < 0.0) {
          testArgosModel_DW.is_Turn = testArgosModel_IN_TurnLeft;
          testArgosModel_B.wl = 0.0;
          testArgosModel_B.wr = 2.5;
        }
      }
    }
  }

  // End of Chart: '<Root>/Controller Chart'

  // MATLABSystem: '<Root>/MATLAB System'
  argosDifferentialSteering_setLinearVelocity(testArgosModel_DW.obj.actPtr,
    testArgosModel_B.wl, testArgosModel_B.wr);
}

// Model initialize function
void testArgosModelModelClass::initialize(CCI_Controller *controller)
{
  // Registration code

  // initialize error status
  rtmSetErrorStatus(getRTM(), (NULL));

  // block I/O
  (void) memset(((void *) &testArgosModel_B), 0,
                sizeof(B_testArgosModel_T));

  // states (dwork)
  (void) memset((void *)&testArgosModel_DW, 0,
                sizeof(DW_testArgosModel_T));

  {
    ARGoSFootBotProximitySensor_t_T *obj;
    ARGoSDifferentialSteering_tes_T *obj_0;

    // Start for MATLABSystem: '<Root>/MATLAB System1'
    testArgosModel_DW.obj_n.matlabCodegenIsDeleted = true;
    testArgosModel_DW.obj_n.isInitialized = 0;
    testArgosModel_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &testArgosModel_DW.obj_n;
    testArgosModel_DW.obj_n.isSetupComplete = false;
    testArgosModel_DW.obj_n.isInitialized = 1;
    obj->sensPtr = footBotProximitySensor_constructor(controller);
    testArgosModel_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/MATLAB System'
    testArgosModel_DW.obj.matlabCodegenIsDeleted = true;
    testArgosModel_DW.obj.isInitialized = 0;
    testArgosModel_DW.obj.matlabCodegenIsDeleted = false;
    obj_0 = &testArgosModel_DW.obj;
    testArgosModel_DW.obj.isSetupComplete = false;
    testArgosModel_DW.obj.isInitialized = 1;
    obj_0->actPtr = argosDifferentialSteering_constructor(controller);
    testArgosModel_DW.obj.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Controller Chart'
    testArgosModel_DW.is_Main = testArgosMod_IN_NO_ACTIVE_CHILD;
    testArgosModel_DW.is_Turn = testArgosMod_IN_NO_ACTIVE_CHILD;
    testArgosModel_DW.is_active_c3_testArgosModel = 0U;
  }
}

// Model terminate function
void testArgosModelModelClass::terminate()
{
  // Terminate for MATLABSystem: '<Root>/MATLAB System1'
  matlabCodegenHandle_matlabCod_o(&testArgosModel_DW.obj_n);

  // Terminate for MATLABSystem: '<Root>/MATLAB System'
  matlabCodegenHandle_matlabCodeg(&testArgosModel_DW.obj);
}

// Constructor
testArgosModelModelClass::testArgosModelModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
testArgosModelModelClass::~testArgosModelModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_testArgosModel_T * testArgosModelModelClass::getRTM()
{
  return (&testArgosModel_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
