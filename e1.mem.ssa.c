extern int nd(void);

unsigned max_alloc = 500;
void *my_malloc(unsigned sz) {
  unsigned t = max_alloc;
  max_alloc += sz;
  return (void*)t;
}

int main() {
  int* mem = my_malloc(sizeof(int) * 2);
  int[] RAM;
  int *x = mem;
  int *y = mem + 4;
  assume(RAM[x] > RAM[y]);
  assume(RAM[x] > 0);
  if (nd()) {
    if (RAM[y] > 0) {
      RAM[x] = RAM[x] + RAM[y];
      RAM[y] = RAM[y]+1;
    } else {
      RAM[x] = RAM[x] - RAM[y];
      RAM[y] = RAM[y] - 1;
    }
  }
  assert(RAM[x] >= RAM[y]);
  free(mem);
  return 0;
}

int malloc_ex() {
  // what should be true about malloc?
  int *x = malloc(sizeof(int));
  int *y = malloc(sizeof(int));

  int z;
  int w;

  assert(x > y);
  assert(x < y);
  assert(x != y);

  assert(x != NULL);
  if (x && y) assert(x != y);
  assert(abs(x - y) > 4);

  assert(&z > x);
  assert(&z > &w);
}
