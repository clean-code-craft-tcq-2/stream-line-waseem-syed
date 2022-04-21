#include "test/catch.hpp"
#include "Sender.h"

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