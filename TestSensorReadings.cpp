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

TEST_CASE("Test SensorReadings::generateBatteryParameters")
{
   SensorReadings sensorReadings;
   BatteryParameters batteryParameters;
   int randomNumber = 25;
   sensorReadings.generateBatteryParameters(batteryParameters, randomNumber);
   REQUIRE(batteryParameters.m_temperature == 25);
   REQUIRE(batteryParameters.m_currentStateOfCharge == 28);
   REQUIRE(batteryParameters.m_chargeRate == 2.5f);
}

TEST_CASE("Test SensorReadings::transferSensorDataToSender")
{
   SensorReadings sensorReadings;
   int numberOfReadings = 50;
   sensorReadings.setSensorReadingsList(numberOfReadings);
   sensorReadings.transferSensorDataToSender();
   //once data is transfered from sensor list is cleared as per impl.
   assert(sensorReadings.getSensorReadingsList().empty() == true);
}

std::vector<BatteryParameters> prepareBatteryParamList(int inputCount)
{
	std::vector<BatteryParameters> batteryParamList;
	for(int index = 0; index < inputCount ; index++)
	{
	   BatteryParameters batteryParam;
	   batteryParam.m_temperature = index + 1;
	   batteryParam.m_chargeRate = (float)(index + 1)/10.0f;
	   batteryParam.m_currentStateOfCharge = (index + 4);
	   batteryParamList.push_back(batteryParam);
	}
	return batteryParamList;
}

TEST_CASE("Test sensorReadingsListFromSensor")
{
	std::vector<BatteryParameters> batteryParametersListFromSensor = prepareBatteryParamList(50);
	Sender sender;
	sender.sensorReadingsListFromSensor(batteryParametersListFromSensor);
	assert(sender.getBatteryParametersList().size() == 50);
}