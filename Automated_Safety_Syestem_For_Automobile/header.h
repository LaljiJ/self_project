
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define SET 1
#define CLEAR 0

extern void delay_ms(s16 ms);

/*-------------------------------------------------------*/

extern void io_write(u8 port,u8 pin,u8 val);
extern u8 io_read(u8 port,u8 pin);

/*-------------------------------------------------------*/

extern void lcd_cmd(u8 CMD);
extern void lcd_init();
extern void lcd_data(u8 CH);
extern void lcd_string(char *STRING);
extern void lcd_integer(s16 NUM);
extern void lcd_float(float FLOAT);
	
/*-------------------------------------------------------*/

extern void uart_init(u16 BAUD);
extern void uart_tx(u8 CH);
extern u8 uart_rx();

/*-------------------------------------------------------*/

extern u16 adc_read_POT();
extern u16 adc_read_LDR();

/*-------------------------------------------------------*/

void en_timer0_interrupt(void);







void get_range();
u8 ultrasonic();
void send_pulse();
