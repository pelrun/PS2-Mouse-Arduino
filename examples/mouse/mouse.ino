/**
 * Reads X/Y values from a PS/2 mouse connected to an Arduino
 * using the PS2Mouse library available from
 *   http://github.com/kristopher/PS2-Mouse-Arduino/
 * Original by Kristopher Chambers <kristopher.chambers@gmail.com>
 * Updated by Jonathan Oxer <jon@oxer.com.au>
 */

#include <PS2Mouse.h>
#define MOUSE_DATA 3
#define MOUSE_CLOCK 2

PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);

int x, y, z;

/**
 * Setup
 */
void setup()
{
  mouse.initialize();
  mouse.enable_scrollwheel();
  Serial.begin(38400);
}

/**
 * Main program loop
 */
void loop()
{
  int data[3];
  mouse.report(data);
  x += data[1];
  y += data[2];
  z += data[3];

  if (mouse.is_pressed(LEFT))
  {
    Serial.print("L");    
  }
  if (mouse.is_pressed(MIDDLE))
  {
    Serial.print("M");    
  }
  if (mouse.is_pressed(RIGHT))
  {
    Serial.print("R");    
  }
  
  Serial.print(":");
  Serial.print(x); // X Movement Data
  Serial.print(",");
  Serial.print(y); // Y Movement Data
  Serial.print(",");
  Serial.print(z); // Z Movement Data
  Serial.println();
}
