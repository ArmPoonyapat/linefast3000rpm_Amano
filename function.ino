void view() {
  for (uint8_t i = 0; i < Unit_sensor; i++)
  {
    readsensor();
    Serial.print(sensor_pin[i]);
    Serial.print('\t');
  }
  //Serial.println(position());
  Serial.println(" ");
  delay(200);
}
void readsensor()
{
  sensor_pin[0] = adc.readADC(7);
  sensor_pin[1] = adc.readADC(6);
  sensor_pin[2] = adc.readADC(5);
  sensor_pin[3] = adc.readADC(4);
  sensor_pin[4] = adc.readADC(3);
  sensor_pin[5] = adc.readADC(2);
  sensor_pin[6] = adc.readADC(1);
  sensor_pin[7] = adc.readADC(0);
}
