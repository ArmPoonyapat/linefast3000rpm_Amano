#include <MCP3008.h>
#include <Servo.h>
#define CS_PIN 4
#define CLOCK_PIN 0
#define MOSI_PIN 2
#define MISO_PIN 1
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);
int i = 0;
#define PWMA  3  //   motor L
#define AIN1  12
#define PWMB  11  //   motor R
#define BIN1  13
Servo esc;

uint8_t Unit_sensor = 8;
uint16_t sensor_pin[8];
uint16_t Black_sensor_values[] = {220  , 275 , 266 , 218 , 325 , 200 , 270 , 212  };
uint16_t White_sensor_values[] = {994  , 996 , 995 , 995 , 996 , 994 , 995 , 995  };
uint32_t Last_Position;
int  power, base, error, last_error, L_motor, R_motor, r, RL_motor;
int c1 = 0, cou = 0;

int position()
{
  readsensor();
  bool In_line = false;
  long Average = 0, sum = 0;
  for (uint8_t i = 0; i < Unit_sensor ; i++)
  {
    long value = map(long(sensor_pin[i]), Black_sensor_values[i], White_sensor_values[i], 1000, 0);
    if (value > 200)
    {
      In_line = true;
    }
    if (value > 50)
    {
      Average += (long)value * (i * 1000);
      sum += value;
    }
  }
  if (!In_line)
  {
    if (Last_Position < (Unit_sensor - 1) * 1000 / 2)
    {
      return 0;
    }
    else
    {
      return (Unit_sensor - 1) * 1000;
    }
  }
  Last_Position = Average / sum;
  return Last_Position;
}

void setup() {

  Serial.begin(9600);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);

  esc.attach(10); //Set I/O PWM
  for ( i =  i; i < 50; i++)
  {
    esc.write(i);
    delay(120);
  }
  while (true) {
    if (analogRead(A2) > 932)
    {
      break;
    }
  }
  delay(1000);
}
void loop() {

  //seeerror();
  //view();
  //      esc.write(75);                                                        //พี่อามน่ารักมากกกกกค่าาาาาาาาาา จุ๊บๆๆๆๆๆๆๆ
  //      times(20, 0.02, 0.35, 3000); //850
  //      esc.write(75);
  ////////////////////////////////////////////////////////////////////////////////////////////

  //  esc.write(95);
  //  times(25, 0.041, 0.49, 5000); //ตรง
  //  esc.write(95);
  //  times(25, 0.041, 0.49, 5000); //ตรง
  //  esc.write(95);
  //  times(25, 0.041, 0.49, 1000); //ตรง
  //  esc.write(95);
  //  times(20, 0.025, 0.35, 3000); //โค้งเล็ก
  //    esc.write(95);
  //    times(20, 0.035, 0.35, 2000); //ฉากยึกๆ
  //  esc.write(95);
  //  times(20, 0.035, 0.335
  //  , 4000); //สี่เหลี่ยมยึกๆ
  //  esc.write(95);
  /////////////////////////////////////////////////////////////////////////////////////////////

  esc.write(95);
  times(30, 0.041, 0.49, 2000); //ตรง
  esc.write(95);
  //  times(20, 0.041, 0.49, 400); //ตรง
  //  esc.write(95);
  //  times(30, 0.041, 0.49, 900); //ตรง
  //  esc.write(95);
  //  times(15, 0.035, 0.35, 900); //ฉากยึกๆ
  //  esc.write(95);
  //  times(25, 0.025, 0.35, 3000); //โค้งเล็ก
  //  esc.write(95);
  //  times(30, 0.041, 0.49, 2000); //ตรง
  //  esc.write(95);
  //  times(25, 0.039, 0.35, 1800); //ฉากยึกๆ
  //  esc.write(95);
  //  times(30, 0.041, 0.45, 4200); //ตรง
  //  esc.write(90);
  //  times(25, 0.069, 0.45, 3500); //ฉากยึกๆ
  //  esc.write(90);
  //  times(25, 0.069, 0.45, 5000);
  //  esc.write(90);

  //  times(25, 0.041, 0.49, 4000); //ตรง
  //  esc.write(95);


  //    times(20, 0.035, 0.35, 2000); //ฉากยึกๆ
  //  esc.write(95);




  //////////////////////////////////////////////////////////////////////////////////////////////
  //  times(35, 0.02, 0.35, 200); //850
  //  esc.write(95);
  //  times(15, 0.02, 0.35, 900); //850
  //  esc.write(95);

  //  times(35, 0.02, 0.35, 190); //850
  //  esc.write(95);
  //  times(15, 0.02, 0.35, 1200); //850
  //  esc.write(95);
  //  times(20, 0.02, 0.35, 2800); //850
  //  esc.write(100);
  //
  //  times(35, 0.02, 0.35, 280); //850
  //  esc.write(95);
  //  times(20, 0.02, 0.35, 700); //850
  //  esc.write(95);
  //  times(20, 0.028, 0.35, 2000); //850
  //  esc.write(95);

  /////////////////////////////////////////////////////////////////////////

  motor1(0);
  motor2(0);
  esc.write(0);
  delay(1000000);
  delay(1000000);
  delay(1000000);
  delay(1000000);
  delay(1000000);
  delay(1000000);

}
