void fan() {
  
    for(int r = 1000; r <= 2000;  r++ )
  {
   
    esc.writeMicroseconds(r);
    delay(10);
  }
   for(int r = 2000; r >= 2000; r++)
  {
    
    esc.writeMicroseconds(r);
    delay(10);
  }
  
}
  
