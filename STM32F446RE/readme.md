## STM32F446RE
---------------
### -> Feature
#### 1. STM32F446xC/E devices This refers to the STM32F446 family of microcontrollers (such as STM32F446RE).
#### 2. Based on Arm Cortex-M4 The CPU (processor) inside the microcontroller is the Arm Cortex-M4.
#### 3. 32-bit The processor can process 32 bits (4 bytes) of data in one operation. It has 32-bit registers, a 32-bit ALU, and a 32-bit data path.
#### 4. RISC (Reduced Instruction Set Computer) Uses a small, efficient instruction set. Most instructions execute quickly, often in a single clock cycle.
#### 5. Operating up to 180 MHz The processor can run at a maximum clock speed of 180 million cycles per second. 
#### 6. The Cortex-M4 core features afloating point unit (FPU) single precision supporting all Arm® single-precision data-processing instructions and data types. It also implements a full set of DSP instructions and a memory protection unit (MPU) that enhances application security. 

FPU = Floating Point Unit. (It is a dedicated hardware unit that performs decimal (floating-point) calculations.  
Without an FPU.  
float c = a * b; //The CPU performs the calculation using software libraries, which is slower.  
With an FPU.  
float temperature = 36.75f;  
float speed = 23.5f;  //The calculation is performed directly in hardware, making it much faster.  

