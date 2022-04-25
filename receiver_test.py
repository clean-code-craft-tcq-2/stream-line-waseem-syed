import unittest
import receiver_node
import os

class receiver_test(unittest.TestCase):
    data = "|Temperature|\t|current SOC|\t|ChargeRate|\n1\t\t4\t\t0.1\n2\t\t5\t\t0.2\n3\t\t6\t\t0.3\n4\t\t7\t\t0.4\n5\t\t8\t\t0.5\n6\t\t9\t\t0.6\n7\t\t10\t\t0.7\n8\t\t11\t\t0.8\n9\t\t12\t\t0.9\n10\t\t13\t\t1\n11\t\t14\t\t1.1\n12\t\t15\t\t1.2\n13\t\t16\t\t1.3\n14\t\t17\t\t1.4\n15\t\t18\t\t1.5\n16\t\t19\t\t1.6\n17\t\t20\t\t1.7\n18\t\t21\t\t1.8\n19\t\t22\t\t1.9\n20\t\t23\t\t2\n21\t\t24\t\t2.1\n22\t\t25\t\t2.2\n23\t\t26\t\t2.3\n24\t\t27\t\t2.4\n25\t\t28\t\t2.5\n26\t\t29\t\t2.6\n27\t\t30\t\t2.7\n28\t\t31\t\t2.8\n29\t\t32\t\t2.9\n30\t\t33\t\t3\n31\t\t34\t\t3.1\n32\t\t35\t\t3.2\n33\t\t36\t\t3.3\n34\t\t37\t\t3.4\n35\t\t38\t\t3.5\n36\t\t39\t\t3.6\n37\t\t40\t\t3.7\n38\t\t41\t\t3.8\n39\t\t42\t\t3.9\n40\t\t43\t\t4\n41\t\t44\t\t4.1\n42\t\t45\t\t4.2\n43\t\t46\t\t4.3\n44\t\t47\t\t4.4\n45\t\t48\t\t4.5\n46\t\t49\t\t4.6\n47\t\t50\t\t4.7\n48\t\t51\t\t4.8\n49\t\t52\t\t4.9\n50\t\t53\t\t5\n"
    
    def test_process_data_from_sender(self):
        BatteryStats = receiver_node.process_data_from_sender(self.data)
        self.assertEqual(BatteryStats.Temperature_Maximum, 50)
        self.assertEqual(BatteryStats.SOC_Maximum, 53)
        self.assertEqual(BatteryStats.ChargeRate_Maximum, 5.0)
        self.assertEqual(BatteryStats.Temperature_Minimum, 1)
        self.assertEqual(BatteryStats.SOC_Minimum, 4)
        self.assertEqual(BatteryStats.ChargeRate_Minimum, 0.1)
        self.assertEqual(BatteryStats.MovingAverage_Temperature_Maximum, 48.0)
        self.assertEqual(BatteryStats.MovingAverage_SOC_Maximum, 51.0)
        self.assertEqual(BatteryStats.MovingAverage_ChargeRate_Maximum, 4.8)



if __name__ == '__main__':
  unittest.main()
