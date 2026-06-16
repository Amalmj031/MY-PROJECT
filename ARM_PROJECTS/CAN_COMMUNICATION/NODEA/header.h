
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct CAN1_MSG
{
	u32 id;
	u32 byteA;
	u32 byteB;
	u8 rtr;
	u8 dlc;
	u8 ff;
} CAN1;

extern void delay_ms(u32);
extern void delay_sec(u32);

extern void CAN1_init(void);
extern void CAN1_tx(CAN1);

extern void uart0_init(u32 baud);
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern void uart0_tx_string(const char *p);
