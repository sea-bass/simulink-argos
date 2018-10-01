add_library(testArgosModelCtrl MODULE testArgosModelCtrl.h testArgosModelCtrl.cpp 
            testArgosModel/ARGoSDifferentialSteeringWrapper.cpp
            testArgosModel/ARGoSFootBotProximitySensorWrapper.cpp
            testArgosModel/testArgosModel.cpp)
include_directories(testArgosModel)
target_link_libraries(testArgosModelCtrl
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
