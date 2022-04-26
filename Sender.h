#pragma once
#include "BatteryInfos.h"
#include <iostream>
#include <vector>

class Sender
{
public:
void sensorReadingsListFromSensor(std::vector<BatteryParameters> batteryParametersListFromSensor);
void displaySensorDataOnConsole();
std::vector<BatteryParameters> getBatteryParametersList()const;
private:
std::vector<BatteryParameters> m_batteryParametersListFromSensor;
};

std::vector<BatteryParameters> Sender::getBatteryParametersList()const
{
	return m_batteryParametersListFromSensor;
}

void Sender::sensorReadingsListFromSensor(std::vector<BatteryParameters> batteryParametersListFromSensor)
{
   m_batteryParametersListFromSensor = batteryParametersListFromSensor;
   displaySensorDataOnConsole();
}

void Sender::displaySensorDataOnConsole()
{
  std::cout<<"|Temperature|"<<"\t"<<"|current SOC|"<<"\t"<<"|ChargeRate|"<<std::endl;
  for(int index = 0; index < m_batteryParametersListFromSensor.size(); index++)
  {
    std::cout<<m_batteryParametersListFromSensor[index].m_temperature<<"\t\t"<<m_batteryParametersListFromSensor[index].m_currentStateOfCharge<<"\t\t"<<m_batteryParametersListFromSensor[index].m_chargeRate<<std::endl;
  }
}

