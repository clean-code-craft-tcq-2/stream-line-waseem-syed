#pragma once
#include<vector>
#include "Sender.h"

class SensorReadings
{
public:
std::vector<BatteryParameters> getSensorReadingsList() const;
void setSensorReadingsList(const int numberOfReadings);
void generateBatteryParameters(BatteryParameters& batteryParameters, int randomNumber);
void transferSensorDataToSender();

private:
std::vector<BatteryParameters> m_sensorReadingsList;
Sender m_sender;
};

std::vector<BatteryParameters> SensorReadings::getSensorReadingsList()const
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
	batteryParameters.m_chargeRate = (float)randomNumber/10.0f;
}

void SensorReadings::transferSensorDataToSender()
{
   if(false == m_sensorReadingsList.empty())
   {
      m_sender.sensorReadingsListFromSensor(m_sensorReadingsList);
      m_sensorReadingsList.clear();
   }
}

class SensorDataHandler
{
public:
void fillNewData(int numberOfReadings);
void sendDataFromSensor();
SensorReadings m_sensorReadings;
};

void SensorDataHandler::fillNewData(int numberOfReadings)
{
  m_sensorReadings.setSensorReadingsList(numberOfReadings);
}

void SensorDataHandler::sendDataFromSensor()
{
  m_sensorReadings.transferSensorDataToSender();
}