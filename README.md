![QUTMS_Banner](https://raw.githubusercontent.com/Technosasquach/QUTMS_Master/master/src/qutmsBanner.jpg)
# Shutdown Board V2
Saftey System shutdown board dedicated to managing the vehicle shutdown loop.

## Function
Disables the car by opening the shutdown loop if at least one shudown device reports a fault. It also reports which devices are open circuit in the shutdown loop using sense wires in the wiring harness.

## Subsystems
* Shutdown loop latching for HVD, IMD, BMS, PDOC, MCU and BSPD.
* Brake Sensor Plausibility Device (BSPD).
* Shutdown node sensing and reporting.
