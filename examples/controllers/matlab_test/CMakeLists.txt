add_library(matlab_test MODULE matlab_test.h matlab_test.cpp 
            testArgosModel/testArgosModel.cpp 
            testArgosModel/ARGoSDifferentialSteeringWrapper.cpp
            testArgosModel/ARGoSFootBotProximitySensorWrapper.cpp)
include_directories(testArgosModel)
target_link_libraries(matlab_test
  argos3core_simulator
  argos3plugin_simulator_footbot
  argos3plugin_simulator_genericrobot)
