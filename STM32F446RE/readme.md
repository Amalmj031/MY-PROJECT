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

      -> 1. SR (Status Register)
        Stores the current status of the ADC

    | Bit         | Name                           |
    |-------------|--------------------------------|
    | **AWD**     | **Analog Watchdog Flag**       |
    | **EOC**     | **End Of Conversion**          | 
    | **JEOC**    | **Injected End Of Conversion** | 
    | **OVR**     | **Overrun**                    |


    o-> AWD (Analog Watchdog Flag)
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
    
    o-> EOC (End Of Conversion)
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
    
    
    o-> JEOC (Injected End Of Conversion)
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
    
    
    o-> OVR (Overrun)
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

    -> 2.  CR1 (Control Register 1)
    Controls the ADC operating mode
    | Bit(s)             |             Name     |                                      Description                                      |
    |--------------------|----------------------|---------------------------------------------------------------------------------------|
    | 26:25              | **RES**              | Selects the ADC conversion resolution (12-bit, 10-bit, 8-bit, or 6-bit).              |
    | 24                 | **OVRIE**            | Enables interrupt generation when an overrun (OVR) occurs.                            |
    | 23                 | **EOCIE**            | Enables interrupt generation when a regular conversion completes (EOC).               |
    | 22                 | **AWDIE**            | Enables interrupt generation when the Analog Watchdog detects an out-of-range signal. |
    | 15                 | **SCAN**             | Enables Scan mode for converting multiple ADC channels sequentially.                  |
    | 9                  | **AWDSGL**           | Enables Analog Watchdog on a single selected channel.                                 |
    | 8                  | **JAUTO**            | Automatically starts injected conversions after regular conversions.                  |
    | 7                  | **DISCEN**           | Enables Discontinuous mode for regular conversions.                                   |
    | 6                  | **JDISCEN**          | Enables Discontinuous mode for injected conversions.                                  |
    | 5                  | **DISCNUM[2:0]**     | Selects the number of conversions in each discontinuous group.                        |
    | 4                  | **JAWDEN**           | Enables Analog Watchdog monitoring for injected channels .                            |
    | 3                  | **AWDEN**            | Enables Analog Watchdog monitoring for regular channels.                              |


    o-> RES (Resolution)
    -------------------
    Selects the ADC conversion resolution.
    
    00 → 12-bit (0–4095)
    01 → 10-bit (0–1023)
    10 → 8-bit  (0–255)
    11 → 6-bit  (0–63)
    
    Higher resolution provides better accuracy but may require slightly longer conversion times.
  

    o-> OVRIE (Overrun Interrupt Enable)
    -----------------------------------
    • Enables an interrupt when an overrun occurs.
    • Requires the OVR interrupt to be enabled in the NVIC.
    
                              Enable the OVR interrupt in ADC_CR1
                              ADC1->CR1 |= ADC_CR1_OVRIE;
                              Enable the ADC interrupt in the NVIC
                              NVIC_EnableIRQ(ADC_IRQn);
                              Write the ADC interrupt handler
                              void ADC_IRQHandler(void)
                              {
                                  if (ADC1->SR & ADC_SR_OVR)
                                  {
                                      // Handle overrun
                                    // Clear OVR flag
                                 ADC1->SR &= ~ADC_SR_OVR;
                                  }
                              }
    
    0 → Interrupt disabled
    1 → Interrupt enabled

            ADC Conversion
              │
              ▼
        Result stored in ADC_DR
              │
              ▼
        Did software read ADC_DR?
              │
          ┌───┴────┐
          │        │
         Yes       No
          │        │
          ▼        ▼
        Next     Next conversion
        conversion completes
                   │
                   ▼
         Old data overwritten
                   │
                   ▼
              OVR flag = 1
                   │
                   ▼
        Is OVRIE = 1?
              │
         ┌────┴────┐
         │         │
        No        Yes
         │         │
         ▼         ▼
        No       ADC requests
        interrupt interrupt
                   │
                   ▼
        Is ADC IRQ enabled in NVIC?
                   │
              ┌────┴────┐
              │         │
             No        Yes
              │         │
              ▼         ▼
        No interrupt  ADC_IRQHandler()
                      executes
    
    
    o-> EOCIE (End Of Conversion Interrupt Enable)
    ---------------------------------------------
    • Generates an interrupt after each regular conversion completes.
    
    0 → Interrupt disabled
    1 → Interrupt enabled
    Start ADC Conversion
        │
            ▼
    ADC Converts Analog Signal
            │
            ▼
    Conversion Complete
            │
            ▼
    Store Result in ADC_DR
            │
            ▼
    Set EOC Flag = 1
            │
            ▼
    Is EOCIE = 1?
            │
       ┌────┴────┐
       │         │
      No        Yes
       │         │
       ▼         ▼
    No       ADC requests
    interrupt interrupt
                 │
                 ▼
    Is ADC IRQ enabled in NVIC?
                 │
            ┌────┴────┐
            │         │
           No        Yes
            │         │
            ▼         ▼
    No interrupt  ADC_IRQHandler()
                  executes

    Step 1: Enable EOC Interrupt
    ADC1->CR1 |= ADC_CR1_EOCIE;
    Step 2: Enable ADC Interrupt in NVIC
    NVIC_EnableIRQ(ADC_IRQn);
    Step 3: Start ADC Conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;
    Step 4: Interrupt Handler
    void ADC_IRQHandler(void)
    {
        if (ADC1->SR & ADC_SR_EOC)
        {
            uint16_t value = ADC1->DR;   // Reading ADC_DR clears the EOC flag
    
            // Process the ADC value
        }
    }

    What is the purpose of the EOCIE bit in the STM32F446RE ADC?


    The EOCIE (End Of Conversion Interrupt Enable) bit enables the ADC to generate an interrupt when a regular ADC conversion
    is complete. After the conversion result is stored in ADC_DR and the EOC flag is set, the ADC requests an interrupt.
    If the ADC interrupt is enabled in the NVIC, the processor automatically executes ADC_IRQHandler(),
    allowing the software to read the conversion result without polling.
    
    o-> AWDIE (Analog Watchdog Interrupt Enable)
    -------------------------------------------
    •Enables an interrupt when the Analog Watchdog (AWD) detects that the input voltage is outside the programmed threshold rang

    Step 1: Set Thresholds
    ADC1->HTR = 3000;    // High threshold
    ADC1->LTR = 1000;    // Low threshold
    Step 2: Enable Analog Watchdog
    ADC1->CR1 |= ADC_CR1_AWDEN;
    Step 3: Enable Analog Watchdog Interrupt
    ADC1->CR1 |= ADC_CR1_AWDIE;
    Step 4: Enable ADC Interrupt in NVIC
    NVIC_EnableIRQ(ADC_IRQn);
    Step 5: Interrupt Handler
      void ADC_IRQHandler(void)
    {
        if (ADC1->SR & ADC_SR_AWD)
        {
            // Analog input is outside the threshold range
    
            // Clear the AWD flag
            ADC1->SR &= ~ADC_SR_AWD;
        }
    }
    
    
    0 → Disabled
    1 → Enabled

    Why use AWDIE?

    Instead of continuously checking whether a sensor value is too high or too low, you can let the ADC hardware monitor it.

    Examples:
    🌡️ Temperature exceeds a safe limit
    🔋 Battery voltage becomes too low
    ⚙️ Motor current exceeds a limit
    📈 Pressure sensor goes out of range
    💧 Water level crosses a threshold
    
    o-> SCAN (Scan Mode)
    -------------------
    • Converts multiple ADC channels automatically in sequence.
    
    0 → Single channel conversion
    1 → Scan multiple channels
    Why is SCAN Mode Needed?

    Suppose you have three sensors connected to the ADC:
    
    PA0 → ADC Channel 0 (Temperature)
    PA1 → ADC Channel 1 (Light)
    PA2 → ADC Channel 2 (Potentiometer)
    Without Scan Mode, you must manually select each channel and start a conversion for every sensor.
    With Scan Mode enabled, the ADC automatically converts all configured channels one after another.

       What is the purpose of the SCAN bit in the STM32F446RE ADC?
    
      Answer:
      The SCAN bit enables scan mode, allowing the ADC to convert multiple channels automatically in a predefined sequence.
      The sequence is configured using the SQR1, SQR2, and SQR3 registers. When scan mode is disabled, the ADC converts only
      one channel per conversion sequence. When enabled, it steps through each configured channel automatically without requiring
      software to change the channel after every conversion.
    
    o-> AWDSGL (Analog Watchdog Single Channel)
    ------------------------------------------
    The AWDSGL bit determines which ADC channels are monitored by the Analog Watchdog (AWD).
    0 → Watch all ADC channels
    1 → Watch only the selected channel

    Enable Analog Watchdog:
    ADC1->CR1 |= ADC_CR1_AWDEN;
    Monitor only one channel:  
    ADC1->CR1 |= ADC_CR1_AWDSGL;
    Select ADC Channel 2:
    ADC1->CR1 &= ~(0x1F);      // Clear AWDCH bits
    ADC1->CR1 |= 2;            // Select Channel 2

      
      Relationship with Other Bits
      ──────────────────────────────────────────────────────────────────────
      
      AWDSGL
      -------
      Selects whether the Analog Watchdog monitors
      one ADC channel or all ADC channels.
      
      AWDCH[4:0]
      ----------
      Specifies which ADC channel is monitored when
      AWDSGL = 1.
      
      AWDEN
      ------
      Enables the Analog Watchdog for regular ADC channels.
      
      JAWDEN
      -------
      Enables the Analog Watchdog for injected ADC channels.
      
      AWDIE
      ------
      Enables an interrupt when the Analog Watchdog
      detects that the ADC input is outside the
      programmed high or low threshold.
     ──────────────────────────────────────────────────────────────────────
    
        
    7. JAUTO (Automatic Injected Conversion)
    ----------------------------------------
    The STM32 ADC supports two conversion groups:
    0 → Regular and injected conversions are independent.
    1 → Injected conversion starts automatically after the regular conversion.
    
    
    What are Regular and Injected Conversions?
    
    Conversion                  Type	Purpose
    ---------------           -----------------
     Regular Group              Used for normal ADC conversions (continuous sensor readings).
     Injected Group             Used for high-priority conversions that may need immediate attention.
     
     Enable automatic injected conversion:
     ADC1->CR1 |= ADC_CR1_JAUTO;

 
    
    o-> DISCEN (Regular Discontinuous Mode)
    --------------------------------------
    
    Breaks a sequence of regular conversions into smaller groups.
    
    0 → Disabled
    1 → Enabled
    
    9. JDISCEN (Injected Discontinuous Mode)
    ----------------------------------------
    Enables discontinuous mode for injected conversions.
    
    0 → Disabled
    1 → Enabled
    
    10. DISCNUM[2:0]
    ----------------
    Selects the number of conversions performed in each discontinuous group.
    
    Example:
    DISCNUM = 000 → 1 conversion
    DISCNUM = 001 → 2 conversions
    ...
    DISCNUM = 111 → 8 conversions
    
    11. JAWDEN
    ----------
    Enables the Analog Watchdog for injected channels.
    
    0 → Disabled
    1 → Enabled
    
    12. AWDEN
    ---------
    Enables the Analog Watchdog for regular channels.
    
    0 → Disabled
    1 → Enabled

    
    
    
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

    | **Bit**   | **Name**                    |                  **Description**                                                         |
    |:----------|-----------------------------|------------------------------------------------------------------------------------------|
    | **AWD**   | Analog Watchdog Flag        | Set when the ADC input voltage goes **above the High Threshold (HTR)** or **below the Low                                                     Threshold (LTR)**. Indicates that the analog input is outside the programmed range. |
    | **EOC**   | End Of Conversion           | Set when a **regular ADC conversion** is complete and the converted result is available in the                                               **ADC_DR** (Data Register). |
    | **JEOC**  | Injected End Of Conversion  | Set when an **injected ADC conversion** is complete and the converted result is available in                                                  the **ADC_JDRx** (Injected Data Register). |


### 12. RTC = Real-Time Clock
It is a dedicated peripheral that continuously counts:

->Seconds
->Minutes
->Hours
->Day
->Date
->Month
->Year

    Why is it called "Low-Power RTC"?

    The RTC is designed to consume very little power (typically a few microamps), so it can continue 
    operating while the rest of the  microcontroller is in Sleep, Stop, or Standby mode.

                   STM32F446RE

         +----------------------+
         |      Cortex-M4       |
         |        CPU           |
         +----------+-----------+
                    |
        CPU enters Standby Mode
                    |
                    X  (CPU stops)
                    |
        +----------------------+
        |        RTC           |  ✓ Still Running
        +----------------------+
                    |
          Keeps Time & Date


RTC Peripheral  
0x40002800  
│  
├── TR       (Time Register)  
├── DR       (Date Register)  
├── CR       (Control Register)  
├── ISR      (Initialization & Status Register)  
├── PRER     (Prescaler Register)  
├── WUTR     (Wakeup Timer Register)  
├── ALRMAR   (Alarm A Register)   
├── ALRMBR   (Alarm B Register)  
├── WPR      (Write Protection Register)  
├── SSR      (Sub-Second Register)  
└── SHIFTR   (Shift Control Register)  

#define RTC_BASE  (0x40002800UL)  

#define RTC ((RTC_TypeDef *) RTC_BASE)  

RTC is a pointer to the RTC peripheral's base address.  

RTC->TR;        // Time Register  
RTC->DR;        // Date Register  
RTC->CR;        // Control Register  
RTC->ISR;       // Initialization & Status Register  
RTC->PRER;      // Prescaler Register  
RTC->ALRMAR;    // Alarm A Register  
RTC->WUTR;      // Wake-up Timer Register  

    
### 13. Twelve general-purpose 16-bit timers  
STM32F446RE contains 12 timer peripherals, and most of them have a 16-bit counter that can count from 0 to 65,535.  

<img width="988" height="912" alt="image" src="https://github.com/user-attachments/assets/5601ee49-985a-40a4-975c-22e54e9e21c4" />  

STM32F446RE Timers  

Advanced Timers (16-bit)  
├── TIM1  
└── TIM8  
Used for:  

->Motor control  
->Complementary PWM  
->Dead-time insertion  
->Break input  

General-Purpose Timers (32-bit)  
├── TIM2  
└── TIM5  
Used for:  

->Long delays  
->Frequency measurement  
->Event counting  
->PWM generation  

General-Purpose Timers (16-bit)  
├── TIM3  
├── TIM4  
├── TIM9  
├── TIM10  
├── TIM11  
├── TIM12  
├── TIM13  
└── TIM14  
Used for:  

->Delay generation  
->PWM  
->Input Capture  
->Output Compare  
->Periodic interrupts  

Basic Timers (16-bit)  
├── TIM6  
└── TIM7  
Used for:  

->Simple time base generation  
->DAC triggering  
->Periodic interrupts  
->No input/output channels  


Why is it called a 16-bit Timer?  

The timer has a 16-bit counter register (CNT).  
A 16-bit register can store:  
0000 0000 0000 0000 = 0  

to  

1111 1111 1111 1111 = 65535  
0 → 65535  
After reaching 65535, it overflows and starts again from 0.  

```text
================ STM32 TIMER (TIMx) REGISTERS ================

1. CR1 (Control Register 1)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
CEN          Counter Enable
             0 = Stop Timer
             1 = Start Timer

UDIS         Update Disable
             Disable Update Event

URS          Update Request Source
             Select Update Source

OPM          One Pulse Mode
             Timer Stops After One Update Event

DIR          Counter Direction
             0 = Up Counter
             1 = Down Counter

ARPE         Auto Reload Preload Enable
             Buffer ARR Register

CKD[1:0]     Clock Division
             Select Timer Clock Division


==============================================================

2. PSC (Prescaler Register)
--------------------------------------------------------------
PSC[15:0]    Prescaler Value

Formula:
Timer Clock = Input Clock / (PSC + 1)

Example:
PSC = 179

180MHz/(179+1)=1MHz


==============================================================

3. ARR (Auto Reload Register)
--------------------------------------------------------------
ARR[15:0]    Auto Reload Value

Purpose
-------
Maximum Counter Value

Example

ARR = 999

Counter

0 → 999 → Overflow


==============================================================

4. CNT (Counter Register)
--------------------------------------------------------------
CNT[15:0]    Current Counter Value

Purpose
-------
Stores Current Timer Count

Example

CNT = 245

Means Timer counted 245 pulses.


==============================================================

5. SR (Status Register)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
UIF          Update Interrupt Flag

CC1IF        Capture Compare Channel 1 Flag

CC2IF        Capture Compare Channel 2 Flag

CC3IF        Capture Compare Channel 3 Flag

CC4IF        Capture Compare Channel 4 Flag

TIF          Trigger Interrupt Flag

CC1OF        Capture Compare 1 Overcapture Flag


==============================================================

6. DIER (DMA / Interrupt Enable Register)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
UIE          Update Interrupt Enable

CC1IE        Capture Compare 1 Interrupt

CC2IE        Capture Compare 2 Interrupt

CC3IE        Capture Compare 3 Interrupt

CC4IE        Capture Compare 4 Interrupt

TIE          Trigger Interrupt Enable

UDE          Update DMA Request Enable


==============================================================

7. EGR (Event Generation Register)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
UG           Update Generation

CC1G         Capture Compare 1 Generation

CC2G         Capture Compare 2 Generation

CC3G         Capture Compare 3 Generation

CC4G         Capture Compare 4 Generation

TG           Trigger Generation

Purpose
-------
Force Software Event


==============================================================

8. CCMR1 (Capture Compare Mode Register 1)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
CC1S         Capture Compare 1 Selection

OC1M         Output Compare 1 Mode

OC1PE        Output Compare Preload Enable

OC1FE        Fast Enable

CC2S         Capture Compare 2 Selection

OC2M         Output Compare 2 Mode

OC2PE        Output Compare Preload Enable

Used For
--------
PWM
Input Capture
Output Compare


==============================================================

9. CCMR2 (Capture Compare Mode Register 2)
--------------------------------------------------------------
Contains Same Fields For

Channel 3

Channel 4

Used For

PWM

Input Capture

Output Compare


==============================================================

10. CCER (Capture Compare Enable Register)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
CC1E         Enable Channel 1 Output

CC1P         Channel 1 Output Polarity

CC2E         Enable Channel 2 Output

CC2P         Channel 2 Output Polarity

CC3E         Enable Channel 3 Output

CC3P         Channel 3 Output Polarity

CC4E         Enable Channel 4 Output

CC4P         Channel 4 Output Polarity


==============================================================

11. CCR1 (Capture Compare Register 1)
--------------------------------------------------------------
CCR1[15:0]

Stores

PWM Duty Cycle

Capture Value

Output Compare Value


CCR2
--------------------------------------------------------------
Same Function For Channel 2


CCR3
--------------------------------------------------------------
Same Function For Channel 3


CCR4
--------------------------------------------------------------
Same Function For Channel 4


==============================================================

12. BDTR (Break and Dead-Time Register)
(TIM1 & TIM8 Only)
--------------------------------------------------------------
Bit Name     Description
--------------------------------------------------------------
DTG          Dead Time Generator

LOCK         Lock Configuration

OSSI         Off-State Selection Idle Mode

OSSR         Off-State Selection Run Mode

BKE          Break Enable

BKP          Break Polarity

AOE          Automatic Output Enable

MOE          Main Output Enable

Purpose
-------
Used For

Motor Control

Complementary PWM

Dead Time

Break Protection


==============================================================
```


### 14.Two general-purpose 32-bit timers  
32-bit General-Purpose Timers  

├── TIM2  
└── TIM5  
```text
==================== 32-BIT GENERAL-PURPOSE TIMERS ====================

Timers
-------
TIM2
TIM5

Counter Width
-------------
32-bit

Counter Range
-------------
0 → 4,294,967,295 (2^32 - 1)

Main Registers
--------------

CR1     - Control Register 1
          • Start/Stop Timer
          • Up/Down Counter
          • One Pulse Mode

PSC     - Prescaler Register
          • Divides Timer Clock

ARR     - Auto Reload Register
          • Maximum Counter Value

CNT     - Counter Register
          • Stores Current Count
          • 32-bit Counter

SR      - Status Register
          • Update Flag
          • Capture Compare Flags

DIER    - DMA / Interrupt Enable Register
          • Enable Interrupts
          • Enable DMA

CCR1    - Capture Compare Register 1
CCR2    - Capture Compare Register 2
CCR3    - Capture Compare Register 3
CCR4    - Capture Compare Register 4

          • PWM Duty Cycle
          • Input Capture
          • Output Compare

CCMR1   - Capture Compare Mode Register 1
CCMR2   - Capture Compare Mode Register 2

CCER    - Capture Compare Enable Register

EGR     - Event Generation Register

Applications
------------
✓ Long Delay Generation
✓ PWM Generation
✓ Frequency Measurement
✓ Pulse Width Measurement
✓ Event Counting
✓ Encoder Interface
✓ Input Capture
✓ Output Compare

Example
-------

Timer Clock = 1 MHz

PSC = 179

ARR = 999999

Timer Overflow

0 → 999999 → Overflow

Useful For

• Long Time Delays
• High Resolution Timing
• Large Event Counting

=======================================================================
```

### 15. Up to four I2Cs

```text
==================== I2C (Inter-Integrated Circuit) ====================

STM32F446RE I2C Peripherals

├── I2C1
├── I2C2
├── I2C3
└── I2C4

Purpose
-------
I2C is a synchronous serial communication protocol used to communicate
with low-speed peripherals using only two wires.

Communication Lines
-------------------
SCL  - Serial Clock Line
SDA  - Serial Data Line

Features
--------
✓ Two-wire communication
✓ Master/Slave operation
✓ Multi-master support
✓ 7-bit and 10-bit addressing
✓ Supports Standard, Fast and Fast+ modes
✓ Acknowledge (ACK/NACK)
✓ Interrupt support
✓ DMA support

Communication Speed
-------------------
Standard Mode     : 100 kHz
Fast Mode         : 400 kHz
Fast Mode Plus    : 1 MHz

Applications
------------
✓ EEPROM
✓ RTC (Real-Time Clock)
✓ Temperature Sensors
✓ LCD/OLED Displays
✓ Accelerometer
✓ Gyroscope
✓ Pressure Sensors
✓ Battery Management ICs

=======================================================================
```

What does "Up to four I2Cs" mean?  

Answer:  
It means the STM32F446RE includes four independent I²C peripherals: I2C1, I2C2, I2C3, and I2C4. Each peripheral can communicate with I²C-compatible devices using only two wires (SDA and SCL).  

Why is I²C popular?  

Answer:  
I²C uses only two wires regardless of the number of connected devices. Multiple slaves can share the same bus by using unique addresses, making it   simple and efficient for connecting sensors, EEPROMs, RTCs, and displays  


### 16. 4 SPI peripherals and 3 I2S peripherals

```text
==================== SPI & I2S PERIPHERALS ====================

SPI Peripherals
---------------
SPI1
SPI2
SPI3
SPI4

Purpose
-------
SPI (Serial Peripheral Interface) is a high-speed synchronous
communication protocol used for communicating with external devices.

Communication Lines
-------------------
SCK   - Serial Clock
MOSI  - Master Out Slave In
MISO  - Master In Slave Out
NSS   - Slave Select (Chip Select)

Applications
------------
✓ LCD Displays
✓ SD Cards
✓ Flash Memory
✓ Sensors
✓ ADC/DAC
✓ Ethernet Modules

Communication Speed
-------------------
Up to several MHz depending on peripheral clock.

==============================================================

I2S Peripherals
---------------
SPI2 → I2S2
SPI3 → I2S3
SPI4 → I2S4

Purpose
-------
I2S (Inter-IC Sound) is a digital audio communication protocol.

Used For
--------
✓ Audio Codec
✓ Microphones
✓ Speakers
✓ Digital Amplifiers
✓ Audio Processors

Communication Lines
-------------------
CK      - Serial Clock
WS      - Word Select (Left/Right Channel)
SD      - Serial Data
MCK     - Master Clock (Optional)

Audio Formats
-------------
16-bit
24-bit
32-bit

Audio Sample Rates
------------------
8 kHz
16 kHz
22.05 kHz
44.1 kHz
48 kHz
96 kHz
192 kHz

Clock Source
------------
1. Internal Audio PLL (PLLI2S)
   • Dedicated clock for audio
   • High accuracy
   • Low jitter

2. External Clock
   • Used when synchronization with another
     audio device is required.

Applications
------------
✓ MP3 Player
✓ Voice Recorder
✓ Bluetooth Audio
✓ Home Theatre
✓ Digital Audio Streaming

==============================================================
```

What is I2S?  

I2S = Inter-IC Sound  

I2S is a communication protocol specifically designed for digital audio data.  

Unlike SPI, which is a general-purpose communication protocol, I2S is optimized for transmitting audio samples.  

The STM32F446RE datasheet says it has "4 SPI peripherals and 3 I2S peripherals." Does it have 7 separate peripherals?  

Answer:  
No. The STM32F446RE has 4 SPI hardware peripherals: SPI1, SPI2, SPI3, and SPI4. Among them, SPI2, SPI3,and SPI4   
can be configured to operate in I2S   mode for digital audio communication. Therefore, the "3 I2S peripherals" are not additional hardware;  
they are alternate operating modes of three   of the SPI peripherals.  

### 16. Four USARTs plus two UARTs

    4 USART + 2 UART = 6 Serial Communication Peripherals
    
STM32F446RE Serial Peripherals  

USART Peripherals  
USART1  
USART2  
USART3  
USART6  

These support:  

Asynchronous mode  
Synchronous mode  
UART Peripherals  
UART4  
UART5  

These support:  

Asynchronous mode only  

             STM32F446RE

        ┌────────────────────┐
        │    USART1          │
        │    USART2          │
        │    USART3          │
        │    USART6          │
        └────────────────────┘

        ┌────────────────────┐
        │     UART4          │
        │     UART5          │
        └────────────────────┘

USART Register Block

    USART1
    │
    ├── SR      (Status Register)
    ├── DR      (Data Register)
    ├── BRR     (Baud Rate Register)
    ├── CR1     (Control Register 1)
    ├── CR2     (Control Register 2)
    ├── CR3     (Control Register 3)
    ├── GTPR    (Guard Time & Prescaler Register)

UART Register Block

    UART4
    │
    ├── SR
    ├── DR
    ├── BRR
    ├── CR1
    ├── CR2
    ├── CR3
    └── GTPR

### 17. An USB OTG full-speed and an USB OTG high-speed with full-speed capability (with the ULPI), both with dedicated power rails allowing to use          them throughout the whole power range  

### 18. Two CANs  

### 19. Two SAIs serial audio interfaces: to achieve audio class accuracy, the SAIs can be
clocked via a dedicated internal audio PLL

### 20.SDIO/MMC interface  

SDIO/MMC Interface  

This means the STM32F446RE has a dedicated SDIO peripheral that can communicate with:  

SD Cards (Secure Digital Cards)  
MMC Cards (MultiMedia Cards)  

### 21. Camera interface

### 22. HDMI-CEC







