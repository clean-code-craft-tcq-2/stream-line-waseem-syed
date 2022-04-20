#pragma once
#include<vector>

struct BatteryParameters
{
  float m_temperature;
  float m_chargeRate;
  int   m_currentStateOfCharge;
};

class SensorReadings
{
public:
std::vector<BatteryParameters> getSensorReadingsList() const;
void setSensorReadingsList(const int numberOfReadings);
void generateBatteryParameters(BatteryParameters& batteryParameters, int randomNumber);

private:
std::vector<BatteryParameters> m_sensorReadingsList;
}

std::vector<BatteryParameters> SensorReadings::getSensorReadings()const
{
   return m_sensorReadingsList;
}

void SensorReadings::setSensorReadingsList(const int numberOfReadings)
{
  for(int i = 1 ; i <= numberOfReadings; i++)
  {
	  BatteryParameters batteryParameters;
	  generateBatteryParameters(batteryParameters, i);
	  m_sensorReadingsList.push_back(batteryParameters); 
  }
}

void SensorReadings::generateBatteryParameters(BatteryParameters& batteryParameters, int randomNumber)
{
	batteryParameters.m_temperature = randomNumber;
	batteryParameters.m_currentStateOfCharge = randomNumber + 3;
	batteryParameters.m_chargeRate = (float)m_chargeRate/10.0f;
}