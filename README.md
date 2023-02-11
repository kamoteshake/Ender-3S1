# Custom Ender 3 S1 Plus Firmware
This is what I use for my personal Ender 3 S1 Plus. This firmware may not work with your machine. Please read the [disclaimer](#disclaimer).

<!-- White Space -->
$~$
## Upgrades
Here are the upgrades I installed on my Ender 3 S1 Plus.

| Upgrade | Details | Firmware Changes |
|---------|---------|:-----------------------:|
| [Heater Block kit](https://www.amazon.com/gp/product/B0B2DN5SKD/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1) | This comes with a bi metal throat to allow me to print up to 300&deg;C | ✅ |
| [Tungsten Nozzle](https://www.amazon.com/dp/B08DR79WX5?psc=1&ref=ppx_yo2ov_dt_b_product_details) | I was printing PETG and it loved to stick to brass. I put this nozzle to prevent PETG from hugging the nozzle and to future proof my machine just in case I decided to print abrasive materials. | ⬛
| [Zuff's Cold-end Duct with Probe No Y Offset](https://cults3d.com/en/3d-model/tool/ender-3-s1-pro-4020-fan-cr-touch-no-y-offset) | This moves the CR Touch to be inline with the nozzle on the Y axis. I also installed a [4020](https://www.amazon.com/dp/B07L2XZKS7?psc=1&ref=ppx_yo2ov_dt_b_product_details) blower fan<sup id="4020-note-mark">[[1]](#4020-note)</sup> for the cold-end. | ✅ |
| [Zuff's 5015 Part Cooling Duct](https://cults3d.com/en/3d-model/tool/air-duct-5015-ender-3-s1-pro-v3) | Installed this to reduce the high pitch whine of the stock fan. Using [5015](https://www.amazon.com/dp/B079BPS9Q8?psc=1&ref=ppx_yo2ov_dt_b_product_details), I can reduce the part cooling fan to 80%. | ⬛ |
| [Silicon Spacers for the Heat bed](https://www.amazon.com/dp/B093Y89KS9?psc=1&ref=ppx_yo2ov_dt_b_product_details) | Just wanted to put more tention so the bed tramming wheel doesn't loosen up much. | ⬛ |
| [PEI Bed Surface](https://www.amazon.com/dp/B08PFH3G82?psc=1&ref=ppx_yo2ov_dt_b_product_details)<sup id="pei-note-mark">[[2]](#pei-note)</sup> | I abused the stock PC spring steel so I had to replace it. PEI is worth it the cost. The prints stick well and comes off easily. Easier than the stock PC spring steel. | ⬛ |
| [Extruder Cable Stress Relief](https://www.printables.com/model/281061-ender-3-s1-cable-holder) | Just a way to reduce the stress on the extruder ribbon cable.  | ⬛ |
| [X Stepper motor and Limit Switch Stress Relief](https://www.printables.com/model/328521-ender-3-s1-ribbon-cable-holder) | This one is for the thin wires for the X stepper motor and limit switch | ⬛ |
---
<sup id="4020-note">[1]</sup> I couldn't find a way to reduce the speed on the firmware side. It seems like there's a bug or an issue somewhere. I've tracked all of the things I tried in this [issue](https://github.com/CrealityOfficial/Ender-3S1/issues/46) post in Creality's repo. I had to put an inline resistor to slow the 4030 down. [↩](#4020-note-mark)

<sup id="pei-note">[2]</sup> The PEI from Amazon is 310mm x 310mm while the Ender 3 S1 Plus bed is 310mm x 315mm. So there will be a gap where indexing screws are. I would suggest the [Creality PEI plate](https://vip.creality.com/en/goods-detail/1321) for the CR-10. I think that will fit the Ender 3 S1 Plus perfectly and it also have the notches for indexing on the screws. [↩](#pei-note-mark)

<!-- White Space -->
$~$
## Building Marlin 2.1

To build and upload Marlin you will use one of these tools:

- The free [Visual Studio Code](https://code.visualstudio.com/download) using the [Auto Build Marlin](https://marlinfw.org/docs/basics/auto_build_marlin.html) extension.
- The free [Arduino IDE](https://www.arduino.cc/en/main/software) : See [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html)

Marlin is optimized to build with the **PlatformIO IDE** extension for **Visual Studio Code**. You can still build Marlin with **Arduino IDE**, and we hope to improve the Arduino build experience, but at this time PlatformIO is the better choice.

<!-- White Space -->
$~$
## Special Thanks 💖
| | |
|----------|------------|
| [@Pethical](https://github.com/Pethical) | For the fixes on the S1 Pro firmware that Creality released and for working on reverse engineering the [touch screen](https://github.com/Pethical/Ender-3-S1-Pro-Screen).|
| [@synman](https://github.com/synman) | For rebasing the [S1 Pro firmware](https://github.com/synman/Ender-3-S1-Pro-Firmware) with the latest 2.1.2 and bugfix 2.1.x Marlin firmwares. |

<!-- White Space -->
$~$
## Disclaimer
I configured this firmware for my Ender 3 S1 Plus. So this is taylored for my S1 Plus. I haven't tested this to any other machines. This also serve as my playground to test firmware features and other configurations. There will be bugs and kinks.

**USE AT YOUR OWN RISK**. I am not responsible for any damages and/or injuries that occur while using this firmware.