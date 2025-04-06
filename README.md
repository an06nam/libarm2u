# About This Repo
This project is aim to write an open source framework for arm-cortex-m chip from different board vendors in C++.

# Current Suported Chip

| Chip | Status | Boards |
| --- | --- | --- |
| [stm32f0x0](https://www.st.com/resource/en/reference_manual/rm0360-stm32f030x4x6x8xc-and-stm32f070x6xb-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) | On Progress | [baite dev board](https://stm32-base.org/boards/STM32F030F4P6-Baite.html) |
| [stm32f10xx](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) | To Do | [blue pill](https://stm32-base.org/boards/STM32F103C8T6-Blue-Pill), [blackpill](https://stm32-base.org/boards/STM32F103C8T6-Black-Pill)|

   
## Generate and use the image for Development
1. Clone this repo
   ```bash
   git clone https://github.com/an06nam/libarm2u.git
   cd libarm2u
   ```
2. Install [Docker Engine](https://docs.docker.com/engine/install/) if you on linux
   or you can install [Docker Desktop](https://docs.docker.com/desktop/) if you on mac or windows
   
4. Install Dependencies for flashing and debug the firmware
   ```bash
   sudo apt update && sudo apt install -y \
      build-essential \
      ca-certificates \
      openocd \
      gdb-multiarch \
      stlink-tools
   ```
5. abuild this image
      NOTE : DEFAULT CONTAINER PASSWORD will be 'root'
   ```bash
   docker build -t libarm2u -f Dockerfile .
   ```
6. Create the container and mount the workspace direcotry
    ```bash
    docker run -dit --name libarm2u \
       -p  2222:22 \
       --mount type=bind,source=$(pwd)/workspace/,target=/workspace \
       libarm2u
   ```

