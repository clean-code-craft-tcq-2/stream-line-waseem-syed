import sys

Temperature_list = []
SOC_list = []
ChargeRate_list = []

class BatteryStatistics:
    Temperature_Maximum = 0,
    Temperature_Minimum = 0,
    SOC_Maximum = 0,
    SOC_Minimum = 0,
    ChargeRate_Maximum = 0.0,
    ChargeRate_Minimum = 0.0,
    MovingAverage_Temperature_Maximum = 0,
    MovingAverage_SOC_Maximum = 0,
    MovingAverage_ChargeRate_Maximum = 0.0

def readandstore_senderdata_fromconsole():
    senderdata = sys.stdin.read()
    return senderdata

def parse_batteryparameters_fromconsoledata(senderdata):
    batteryparam_list = senderdata.split('\n')
    for index in range(1,(len(batteryparam_list)-1)):
        split_list = batteryparam_list[index].split('\t\t')
        split_list= list(map(float, split_list))
        Temperature_list.append(split_list[0])
        SOC_list.append(split_list[1])
        ChargeRate_list.append(split_list[2])

def Compute_BatteryStatistics(index):
    BatteryStats = BatteryStatistics()
    if index <= 5:
        array_count = index
    else:
        array_count = 5
    BatteryStats.Temperature_Maximum = int (max(Temperature_list[0:index]))
    BatteryStats.SOC_Maximum = int (max(SOC_list[0:index]))
    BatteryStats.ChargeRate_Maximum = max(ChargeRate_list[0:index])
    BatteryStats.Temperature_Minimum = int (min(Temperature_list[0:index]))
    BatteryStats.SOC_Minimum = int (min(SOC_list[0:index]))
    BatteryStats.ChargeRate_Minimum = min(ChargeRate_list[0:index])
    BatteryStats.MovingAverage_Temperature_Maximum = round(sum(Temperature_list[0:index][-5:])/array_count,2)
    BatteryStats.MovingAverage_SOC_Maximum = round(sum(SOC_list[0:index][-5:])/array_count,2)
    BatteryStats.MovingAverage_ChargeRate_Maximum = round(sum(ChargeRate_list[0:index][-5:])/array_count,2)
    return BatteryStats

def printoutputonconsole(BatteryStats):
    print ("Temperature Max :{}\tTemperature Min:{}\tSOC Max:{}\tSOC Min:{}\tChargeRate Max:{}\tChargeRate Min:{}\tTemperature MovingAverage:{}\tSOC MovingAverage:{}\tChargeRate MovingAverage:{}".format(BatteryStats.Temperature_Maximum, BatteryStats.Temperature_Minimum, BatteryStats.SOC_Maximum, BatteryStats.SOC_Minimum, BatteryStats.ChargeRate_Maximum, BatteryStats.ChargeRate_Minimum, BatteryStats.MovingAverage_Temperature_Maximum, BatteryStats.MovingAverage_SOC_Maximum, BatteryStats.MovingAverage_ChargeRate_Maximum))

def process_data_from_sender(senderdata):
    parse_batteryparameters_fromconsoledata(senderdata)
    for index in range(1,(len(Temperature_list)+1)):
        BatteryStats = Compute_BatteryStatistics(index)
        printoutputonconsole(BatteryStats)
    return BatteryStats
       
if __name__ == '__main__':
    senderdata = readandstore_senderdata_fromconsole()
    process_data_from_sender(senderdata)
