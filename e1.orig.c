extern int nd(void);

int main() {
  int x, y;
  assume(x > y);
  assume(x > 0);
  while (nd()) {
    if (y > 0) {
      x = x + y;
      y++;
    } else {
      x = x - y;
      y--;
    }
  }
  assert(x >= y);
  return 0;
}
