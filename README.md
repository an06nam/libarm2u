# About This Repo
This project is aim to rewrite libopencm3 from c to c++.

The changes within container path $HOME/workspace will affect the workspace directory will be saved within the repo workspace

   NOTE : DEFAULT CONTAINER PASSWORD will be 'root'

# Current Suported Chip

| Chip | Status | Boards |
| --- | --- | --- |
| stm32f0x0 variant | On Progress | [baite dev board](https://stm32-base.org/boards/STM32F030F4P6-Baite.html) |

   
## Generate and use the image
1. Clone this repo
   ```bash
   git clone https://github.com/an06nam/libopencm4.git
   cd libopencm4
   ```
2. Install Dependencies for flashing and debuggin the firmware
   ```bash
   sudo apt update && sudo apt install -y \
      build-essential \
      ca-certificates \
      openocd \
      gdb-multiarch \
      stlink-tools
   ```
4. abuild this image
   ```bash
   docker build -t libopencm4-toolchain -f Dockerfile .
   ```
5. Create the container and mount the workspace direcotry
    ```bash
    docker run -dit --name libopencm4-toolchain \
       -p  2222:22 \
       --mount type=bind,source=$(pwd)/workspace/,target=/workspace \
       libopencm4-toolchain
   ```

