void motor2(int speed)
{
  speed = speed * 2.55;
  if (speed >= 255)
  {
    speed = 255;
  }
  else if (speed <= -255)
  {
    speed = -255;
  }
  boolean inPin1;

  if (speed >= 0)
  {
    inPin1 = HIGH;
  }
  else if (speed < 0)
  { inPin1 = LOW;
    
   
    speed = speed * -1;
  }
  digitalWrite(BIN1, inPin1);
  analogWrite(PWMB, speed);
}
