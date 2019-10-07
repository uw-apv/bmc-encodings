extern int nd(void);

int main() {
  int x, y;
  bool flag = true;
  flag = (x > y);
  flag = flag && (x > 0);
  if (nd()) {
    if (y > 0) {
      x = x + y;
      y++;
    } else {
      x = x - y;
      y--;
    }
    if (nd()) {
      if (y > 0) {
        x = x + y;
        y++;
      } else {
        x = x - y;
        y--;
      }
    }
  }
  flag = flag && !(x >= y);
  assume(flag);
  assert(0);
  return 0;
}
