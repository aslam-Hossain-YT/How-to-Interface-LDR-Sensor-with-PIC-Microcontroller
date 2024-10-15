sbit led_pin at RB1_bit;     //led connected to pin 1 of port B
#define ldr_theshold 512          //defines the threshold value for ldr

void main() {
ADCON1 = 0x80; //set the pin 0 of port A as analog input
TRISB1_bit = 0; //set the pin 1 of port B as output

led_pin = 0; //initially led as off condition

while(1) {
unsigned int ldr_value = ADC_Read(1); //read the ldr value from pin 0 of port A

if (ldr_value <  ldr_theshold) {
led_pin = 1;
}
else {
led_pin = 0;
}
delay_ms(500);
}

}