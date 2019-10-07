extern int nd(void);

unsigned max_alloc = 500;
void *my_malloc(unsigned sz) {
  unsigned t = max_alloc;
  max_alloc += sz;
  return t;
}

int main() {
  int* mem = my_malloc(sizeof(int) * 2);
  int *x = &mem[0];
  int *y = &mem[1];
  assume(*x > *y);
  assume(*x > 0);
  while (nd()) {
    if (*y > 0) {
      *x = *x + *y;
      *y = *y+1;
    } else {
      *x = *x - *y;
      *y = *y - 1;
    }
  }
  assert(*x >= *y);
  free(mem);
  return 0;
}

int malloc_ex() {
  // what should be true about malloc?
  int *x = malloc(sizeof(int));
  int *y = malloc(sizeof(int));

  int z;

  assert(x > y);
  assert(x < y);
  assert(x != y);

  assert(x != NULL);
  if (x && y) assert(x != y);
  assert(abs(x - y) > 4);

  assert(&z > x);
}
