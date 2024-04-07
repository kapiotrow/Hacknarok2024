#include <cmath>


void get_rev(int x, int x_prev, int* x_dist, int* x_revs) {
  if (abs(x - x_prev) < 360 - abs(x - x_prev)){
    *x_dist += x - x_prev;
  }
  else {
    *x_dist += std::signbit(x_prev - x) * (360 - abs(x - x_prev));
  }

  if (abs(*x_dist) > 120){
    *x_revs += 1;
    //*x_dist =  *x_dist - std::signbit(*x_dist) * 360;
    *x_dist = 0;
  }

  // zwróć nowy revs i dist
}

int x, y, z, a, b, c;
int a_prev, b_prev, c_prev;
int a_dist=0, b_dist=0, c_dist=0;
int a_revs=0, b_revs=0, c_revs=0;

bool revolutions() {
  
  // Read compass values
  compass.read();

  // Return XYZ readings
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  a = compass.getAzimuth();
  b = compass.getAzimuth2();
  c = compass.getAzimuth3();

  Serial.print("\t\tX: ");
  Serial.print(a_revs);
  Serial.print(" : ");
  Serial.print(a);
  Serial.print("\t\tY: ");
  Serial.print(b_revs);
  Serial.print(" : ");
  Serial.print(b);
  Serial.print("\t\tZ: ");
  Serial.print(c_revs);
  Serial.print(" : ");
  Serial.print(c);
  Serial.println();

  get_rev(a, a_prev, &a_dist, &a_revs);
  get_rev(b, b_prev, &b_dist, &b_revs);
  get_rev(c, c_prev, &c_dist, &c_revs);

  a_prev = a;
  b_prev = b;
  c_prev = c;
  
  //delay(100);

  if (a_revs >= 3 || b_revs >= 3 || c_revs >= 3){
    return true;
  }
  else {
    return false;
  }
}
