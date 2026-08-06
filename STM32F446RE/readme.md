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
 
| **Memory Region**    | **Permission** |
|----------------------|----------------|
| Flash                | Read Only      |
| RAM                  | Read / Write   |
| Peripheral Registers | Privileged Access |
| Bootloader           | Protected      |  

If software tries to perform an illegal access (such as writing to a read-only region), the MPU can generate a fault, helping detect bugs and improving system reliability and security.

### 7. flash memory up to 512 Kbytes  
### 8. up to 128 Kbytes of SRAM , up to 4 Kbytes of backup SRAM  
### 9. extensive range of enhanced I/Os and peripherals connected to **two APB buses, two AHB buses and a 32-bit multi-AHB bus matrix**  

```text
                           Cortex-M4 CPU
                        (Up to 180 MHz)
                                │
                   I-Code / D-Code / System Bus
                                │
                ┌────────────────────────────────┐
                │       AHB Bus (HCLK)           │
                │      Up to 180 MHz             │
                └────────────────┬───────────────┘
                                 │
      ┌──────────────┬───────────┼───────────────┬─────────────┐
      │              │           │               │             │
   Flash          SRAM        GPIO            DMA           RCC
 (180 MHz)     (180 MHz)   (180 MHz)      (180 MHz)    (180 MHz)
                                 │
                     ┌───────────┴───────────┐
                     │                       │
              AHB-to-APB1 Bridge     AHB-to-APB2 Bridge
                     │                       │
       APB1 Bus (PCLK1)             APB2 Bus (PCLK2)
         Up to 45 MHz                Up to 90 MHz
                     │                       │
      ┌──────────────┴─────────────┐   ┌────┴─────────────┐
      │ USART2                     │   │ USART1           │
      │ USART3                     │   │ USART6           │
      │ UART4                      │   │ SPI1             │
      │ UART5                      │   │ SPI4             │
      │ SPI2                       │   │ ADC1             │
      │ SPI3                       │   │ ADC2             │
      │ I2C1                       │   │ ADC3             │
      │ I2C2                       │   │ TIM1             │
      │ I2C3                       │   │ TIM8             │
      │ CAN1                       │   │ SYSCFG           │
      │ CAN2                       │   │ SDIO             │
      │ DAC                        │   │                  │
      │ TIM2–TIM7                  │   │                  │
      └────────────────────────────┘   └──────────────────┘
```
    Step 1: CPU → AHB  
    The Cortex-M4 CPU communicates with the AHB bus.  
    Step 2: AHB → APB Bridge  
    The AHB bus contains AHB-to-APB bridges:  
    One bridge connects to APB1  
    Another bridge connects to APB2  
    These bridges convert AHB transactions into APB transactions.  
    Step 3: APB → Peripheral  
    The APB buses connect to the peripherals.  

#### Why Are There Two APB Buses?  
Using two APB buses allows the microcontroller to:  
-> Run high-speed peripherals (such as ADCs, SPI1, USART1) at higher clock rates on APB2.  
-> Run less speed-critical peripherals (such as I²C, CAN, DAC) at lower clock rates on APB1, reducing power consumption.  

#### Is APB connected directly to the CPU?  
No. The Cortex-M4 CPU communicates with the AHB bus. The AHB-to-APB bridges then connect the AHB bus to APB1 and APB2, allowing the CPU to access peripherals on   those buses. This architecture keeps the high-speed CPU and memory traffic separate from lower-speed peripheral communication.  

### 10. Three 12-bit ADCs  
    STM32F446RE has:  
    -> ADC1  
    -> ADC2  
    -> ADC3  
    │
    ├── SR          (Status Register)
    ├── CR1         (Control Register 1)
    ├── CR2         (Control Register 2)
    ├── SMPR1       (Sample Time Register 1)
    ├── SMPR2       (Sample Time Register 2)
    ├── JOFR1       (Injected Channel Offset Register 1)
    ├── JOFR2       (Injected Channel Offset Register 2)
    ├── JOFR3       (Injected Channel Offset Register 3)
    ├── JOFR4       (Injected Channel Offset Register 4)
    ├── HTR         (High Threshold Register)
    ├── LTR         (Low Threshold Register)
    ├── SQR1        (Regular Sequence Register 1)
    ├── SQR2        (Regular Sequence Register 2)
    ├── SQR3        (Regular Sequence Register 3)
    ├── JSQR        (Injected Sequence Register)
    ├── JDR1        (Injected Data Register 1)
    ├── JDR2        (Injected Data Register 2)
    ├── JDR3        (Injected Data Register 3)
    ├── JDR4        (Injected Data Register 4)
    └── DR          (Data Register)

    1. SR (Status Register)
        Stores the current status of the ADC

    | Bit         | Name                           |
    |-------------|--------------------------------|
    | **AWD**     | **Analog Watchdog Flag**       |
    | **EOC**     | **End Of Conversion**          | 
    | **JEOC**    | **Injected End Of Conversion** | 
    | **OVR**     | **Overrun**                    |


    1. AWD (Analog Watchdog Flag)
    --------------------------------
    Set when the ADC input voltage goes **above or below** the programmed threshold. Used for monitoring analog signals. 
    • Monitors the analog input voltage.
    • Compares the input with user-defined high and low thresholds.
    • If the voltage exceeds the limits, the AWD flag is set.
    • Can generate an interrupt to notify the CPU.
    
    Example:
    Threshold : 1.0 V – 3.0 V
    Input     : 3.4 V
    Result    : AWD = 1
    
    2. EOC (End Of Conversion)
    ---------------------------
    Set when a regular ADC conversion is completed and the converted data is available in the **ADC_DR** register. |\
    • Indicates that a regular ADC conversion has finished.
    • The converted digital value is stored in ADC_DR.
    • Software can now read the conversion result.
    
    Example:
    Start ADC Conversion
            ↓
    Conversion Complete
            ↓
    EOC = 1
            ↓
    Read ADC_DR
    
    
    3. JEOC (Injected End Of Conversion)
    --------------------------------------
     Set when an injected ADC conversion is completed and the converted data is available in the **ADC_JDRx** register. 
    • Indicates that an injected conversion has finished.
    • Result is stored in ADC_JDR1–ADC_JDR4.
    • Mainly used for high-priority ADC conversions.
    
    Example:
    Injected Trigger
            ↓
    Injected Conversion
            ↓
    JEOC = 1
            ↓
    Read ADC_JDRx
    
    
    4. OVR (Overrun)
    ------------------
     Set when a new conversion result is written before the previous data is read from **ADC_DR**. The old data is lost                  (overwritten). 
    • Occurs when ADC_DR is not read before the next conversion finishes.
    • The new conversion result overwrites the previous one.
    • The previous data is lost.
    
    Example:
    
    Conversion 1
    ADC_DR = 1024
    (Not Read)
    
    Conversion 2
    ADC_DR = 2048
    OVR = 1
    
    Result:
    1024 is lost.
    2048 remains in ADC_DR.
    
    
    

    
Each ADC has 12-bit resolution.  
What is 12-bit?  
A 12-bit ADC can represent:  2 ^ 12=4096  
->upto 4096 vales can determine.A 12-bit ADC uses 12 binary bits to represent an analog input voltage. It provides 2¹² = 4096 discrete levels, with digital output   values ranging from 0 to 4095. A higher resolution allows the ADC to distinguish smaller changes in the input voltage.   

<img width="1009" height="357" alt="image" src="https://github.com/user-attachments/assets/01b77d7a-86fc-4b04-b320-a3d4195db6eb" />

### 11. Two DACs
->DAC Channel 1  
->DAC Channel 2  

    DAC->DHR12R1 = 2048;  //You are accessing the Data Holding Register.
    This writes the value 2048 into the DAC Channel 1 Data Holding Register, causing the DAC to generate an analog voltage.
    DAC is a pointer to the DAC peripheral register structure.

    DAC Peripheral
    │
    ├── CR (Control Register) 
    |      -> Enable DAC Channel 1
    |      ->Enable DAC Channel 2
    |      ->Select trigger source
    |      ->Enable DMA
    |      ->Enable waveform generation
    |
    |        DAC->CR |= DAC_CR_EN1; //Enable DAC Channel 1.
    |
    ├── SWTRIGR (Software Trigger Register)
    |    Starts a DAC conversion by software.
    |
    |    DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1; //Start DAC Channel 1 conversion.
    |
    ├── DHR12R1 (12-bit Right-Aligned Data Holding Register for Channel 1)
    |
    |    DAC->DHR12R1 = 2048; //Store the value 2048 in the DAC Channel 1 data register.
    |                  CPU
    |                   │
    |                   │ writes 2048
    |                   ▼
    |                  DAC->DHR12R1 Register
    |                   │
    |                   ▼
    |                  DAC Hardware
    |                   │
    |                   ▼
    |                 Analog Voltage Output
    |
    |Voltage Calculation
    |The DAC output voltage is:The DAC output voltage is:
    |VOUT​=(Digital Value/ 2^12 -1 ) x  Vref
    |  =(2048​/4095)×3.3=1.65v
    |
    |
    ├── DHR12L1 (12-bit Left-Aligned Data Holding Register for Channel 1)
    |     Same function as DHR12R1, but the data is left-aligned inside the 16-bit register.
    |
    |    Right vs Left Alignment
    |    Suppose your 12-bit value is:  1010 1100 1111
    |    Right-aligned               :  0000 1010 1100 1111
    |    Left-aligned                :  1010 1100 1111 0000
    |    
    ├── DHR8R1 (8-bit Right-Aligned Data Holding Register for Channel 1)
    |
    |    Used when only 8-bit resolution is needed.
    |    DAC->DHR8R1 = 128;
    |
    ├── DHR12R2 (12-bit Right-Aligned Data Holding Register for Channel 2)
    |
    |      DAC->DHR12R2 = 3500;
    |
    ├── DHR12L2 (12-bit Left-Aligned Data Holding Register for Channel 2)
    |
    ├── DHR8R2 (8-bit Right-Aligned Data Holding Register for Channel 2)
    |
    ├── DOR1 (Data Output Register for Channel 1)
    |
    |    After the DAC converts the digital value to analog, this register reflects the current output data.
    |
    ├── DOR2 (Data Output Register for Channel 2).
    |
    └── SR (Status Register)
    |  
    |      Shows the current status of the DAC
    |      ->DMA underrun errors
    |      ->Channel status flags




