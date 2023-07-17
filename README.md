# TinyML wearable for environmental sensing :ear:

![Cover Image](media/cover%20image.png)

You can find the public Edge Impulse project here:  [Environment hearing aider](https://studio.edgeimpulse.com/public/171255/latest). To add this project into your account projects, click “Clone this project” at the top of the window. Please read up on the project's documentation on [Edge Impulse's page](https://www.edgeimpulse.com/blog/now-hear-this) to help you get started on your own creation.

On Edge Impulse Studio, the Impulse was deployed as an optimized Syntiant NDP 101/120 library. This packages all the signal processing blocks, configuration and learning blocks up into a single package. Afterwards, a custom Arduino code was created to analyze the predicted classes.

The [Arduino code](syntiant-tinyml-firmware-environment-hearing-aider.ino) turns GPIO 1 HIGH when ambulance, firetruck or car siren/horn sounds are detected. GPIO 1 is then used to trigger a motor control circuit that creates a vibration.

The wearable's casing and wrist straps are available for download from [printables.com](https://www.printables.com/model/511919-syntiant-tinyml-wearable) or [thingiverse.com](https://www.thingiverse.com/thing:6092871)


![Wearable responding to siren sound](media/wearable%20responding%20to%20siren%20sounds.gif)

A video showing the wearable's vibration test performance:

![Wearable vibration test](media/wearable%20vibration%20test.gif)

Below is the circuit layout. It consists of the following components:
- [Syntiant TinyML board](https://www.digikey.com/en/products/detail/syntiant-corp/SYNTIANT-TINYML/15293343?s=N4IgTCBcDaIM4E8B2AXAlgQ1SAugXyA)
- [Vibration motor module](https://www.amazon.com/ZYM119-Vibration-Switch-Vibrator-Circuit/dp/B09M84JF6B/ref=sr_1_5?crid=1JOJC8SZS6KR7&keywords=vibration+motor+module&qid=1683818656&sprefix=vibration+motor+module%27%2Caps%2C941&sr=8-5)
- [3.7V LiPo battery](https://www.adafruit.com/product/1578). I used one with 500mAh
- Veroboard/stripboard
- 1 220 Ω resistor – one end connects to the Syntiant GPIO 1, the other ends connects to base of transistor
- 1 2N3904 transistor
- 1 5.7 k Ω resistor - one end connects to the positive terminal of the battery, the other end connects to the collector of the transistor.
- Some jumper wires and male header pins

![Circuit layout](media/circuit%20layout.png)

Once the electronic parts have been assembled, they can be put in the wearable's case according to the layout in the image below.

![Components layout](media/components%20layout.png)

----

## Config build and flash

This project uses the `arduino-cli` compiler to build & flash new firmware. You can also use the Arduino IDE to compile and upload the code (tested with v1.8.15).

### Usage - Windows

* Run `update_libraries_windows.bat` script to install Arduino libraries.
> **Note:** If you are using the Arduino IDE downloaded from the Window Store you need to download the Arduino SAMD BOARDS (32-bits ARM Cortex-M0+) version 1.8.9 manually from the Boards Manager.

* For audio support:

    * Open the `firmware-syntiant-tinyml.ino` with the Arduino IDE.
    * Select MKRZero as board target and compile/upload.

### Usage - macOS and Linux

The script will verify if all needed libraries and the samd core is installed and install them if needed. If you prefer to do this 
step manually, follow the step in the next chapter.

For building the project:

* For audio support, use:
```
./arduino-build.sh --build
```

* For IMU sensor support, use:
```
./arduino-build.sh --build --with-imu
```


For flashing use:

```
./arduino-build.sh --flash
```


You can also do both by using:
```
./arduino-build.sh --all [--with-imu]
```

### Usage - Different classes :rocket:

You can use this repository to build custom firmware for any Syntiant audio project. From Edge Impulse Studio, deploy your impulse as Syntiant NDP101 library. 

This will create an output zip that contains a model-parameters folder that contains dsp_blocks.h and model_metadata.h that you will need to copy to `src/model-parameters` folder.

>**Note:** In the model_variables.h file of your library, ensure `ei_model_types.h` is included using the path `#include "../edge-impulse-sdk/classifier/ei_model_types.h"`

Afterwards follow the usage instructions described above.

---
## Acknowledgement :+1:

This custom firmware repository is built from Edge Impulse firmware for Syntiant TinyML board.

Official repository is here [firmware-syntiant-tinyml](https://github.com/edgeimpulse/firmware-syntiant-tinyml)
