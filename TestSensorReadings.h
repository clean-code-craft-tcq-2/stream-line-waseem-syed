#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#include "SensorReadings.h"
TEST_CASE("Test getSensorReadings and setSensorReadingsList")
{
   SensorReadings sensorReadings;
   int numberOfReadings = 50;
   sensorReadings.setSensorReadingsList(numberOfReadings);
   std::vector<BatteryParameters> sensorReadingsOutputList = sensorReadings.getSensorReadingsList();
   assert(sensorReadingsOutputList.size() == numberOfReadings);
}

TEST_CASE("Test generateBatteryParameters")
{
   SensorReadings sensorReadings;
   BatteryParameters batteryParameters;
   int randomNumber = 25;
   sensorReadings.generateBatteryParameters(batteryParameters, randomNumber);
   REQUIRE(batteryParameters.m_temperature == 25);
   REQUIRE(batteryParameters.m_currentStateOfCharge == 28);
   REQUIRE(batteryParameters.m_chargeRate == 2.5f);
}