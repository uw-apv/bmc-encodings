extern int nd(void);

int main() {
  bool a, b = nd();
  int x_0 = nd(), y_0 = nd();

  bool flag_0 = (x_0 > y_0) && (x_0 > 0);
  if (a) {
    if (y_0 > 0) {
      x_1 = x_0 + y_0;
      y_1 = y_0 + 1;
    } else {
      x_2 = x_0 - y_0;
      y_2 = y_0 - 1;
    }
    x_3 =  y_0 > 0 ? x_1 : x_2;
    y_3 =  y_0 > 0 ? y_1 : y_2;
    if (b) {
      if (y_3 > 0) {
        x_4 = x_3 + y_3;
        y_4 = y_3 + 1;
      } else {
        x_5 = x_3 - y_3;
        y_5 = y_3 - 1;
      }
      x_6 =  y_3 > 0 ? x_4 : x_5;
      y_6 =  y_3 > 0 ? y_4 : y_5;
    }
    x_7 = b ? x_6 : x_3;
    y_7 = b ? y_6 : y_3;
  }
  x_8 = a ? x_7 : x_0;
  y_8 = a ? y_7 : y_0;
  flag_1 = flag_0 && !(x_8 >= y_8);
  assume(flag_1);
  assert(0);
  return 0;
}

void constraints() {
  isSat (flag_0 = (x_0 > y_0) && (x_0 > 0) &&
         x_1 = x_0 + y_0 &&
         y_1 = y_0 + 1 &&
         x_2 = x_0 - y_0 &&
         y_2 = y_0 - 1 &&
         x_3 =  y_0 > 0 ? x_1 : x_2 &&
         y_3 =  y_0 > 0 ? y_1 : y_2 &&
         x_4 = x_3 + y_3 &&
         y_4 = y_3 + 1 &&
         x_5 = x_3 - y_3 &&
         y_5 = y_3 - 1 &&
         x_6 =  y_3 > 0 ? x_4 : x_5 &&
         y_6 =  y_3 > 0 ? y_4 : y_5 &&
         x_7 = b ? x_6 : x_3 &&
         y_7 = b ? y_6 : y_3 &&
         x_8 = a ? x_7 : x_0 &&
         y_8 = a ? y_7 : y_0 &&
         flag_1 = flag_0 && !(x_8 >= y_8) &&
         flag_1);
}
