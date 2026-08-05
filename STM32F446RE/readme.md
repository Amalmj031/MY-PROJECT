## STM32F446RE
---------------

                  STM32F446RE

          +-----------------------+
          |   Cortex-M4 CPU       |
          |      32-bit RISC      |
          +----------+------------+
                     |
        -------------------------------
        |             |              |
      FPU           DSP            MPU
 (Float math)  (Signal processing) (Memory protection)

### -> Feature
#### 1. STM32F446xC/E devices This refers to the STM32F446 family of microcontrollers (such as STM32F446RE).
#### 2. Based on Arm Cortex-M4 The CPU (processor) inside the microcontroller is the Arm Cortex-M4.
#### 3. 32-bit The processor can process 32 bits (4 bytes) of data in one operation.  
-> It has 32-bit registers   
-> a 32-bit ALU  
-> a 32-bit data path.
#### 4. RISC (Reduced Instruction Set Computer) Uses a small, efficient instruction set. Most instructions execute quickly, often in a single clock cycle.
#### 5. Operating up to 180 MHz The processor can run at a maximum clock speed of 180 million cycles per second. 
#### 6. The Cortex-M4 core features  


 -> floating point unit (FPU) single precision supporting all Arm® single-precision data-processing instructions and data types.  
FPU = Floating Point Unit. (It is a dedicated hardware unit that performs decimal (floating-point) calculations.  
Without an FPU.  
float c = a * b; //The CPU performs the calculation using software libraries, which is slower.  
With an FPU.  
float temperature = 36.75f;  
float speed = 23.5f;  //The calculation is performed directly in hardware, making it much faster.  


 -> It also implements a full set of DSP instructions  
 DSP = Digital Signal Processing  
 DSP instructions are specialized instructions for fast mathematical operations used in:  

Audio processing  
Image processing  
Motor control  
Robotics  
Radar  
Communication systems  
sum += a[i] * b[i];  
The DSP instructions can perform this type of operation much faster than a general-purpose CPU.  

 -> a memory protection unit (MPU) that enhances application security.   
 The MPU lets you define rules about which parts of memory can be accessed.  
 -------------------------------------------------------------------------------

+-------------------------+----------------------+
| Memory Region           | Permission           |
+-------------------------+----------------------+
| Flash                   | Read Only            |
| RAM                     | Read / Write         |
| Peripheral Registers    | Privileged Access    |
| Bootloader              | Protected            |
+-------------------------+----------------------+  
If software tries to perform an illegal access (such as writing to a read-only region), the MPU can generate a fault, helping detect bugs and improving system reliability and security.


