extern int nd(void);

unsigned max_alloc = 500;
void *my_malloc(unsigned sz) {
  unsigned t = max_alloc;
  max_alloc += sz;
  return (void*)t;
}

int main() {
  bool a;
  int* mem = my_malloc(sizeof(int) * 2);
  int[] RAM_0;
  int* x_0 = mem;
  int* y_0 = mem + 4;
  assume(RAM_0[x_0] > RAM_0[y_0]);
  assume(RAM_0[x_0] > 0);
  if (a) {
    if (RAM_0[y_0] > 0) {
      RAM_1[x_0] = RAM_0[x_0] + RAM_0[y_0];
      RAM_1[y_0] = RAM_0[y_0]+1;
    } else {
      RAM_2[x] = RAM_0[x] - RAM_0[y];
      RAM_2[y] = RAM_0[y] - 1;
    }
    RAM_3 = RAM_0[y_0] > 0 ? RAM_1 : RAM_2;
  }
  RAM_4 = a ? RAM_3 : RAM_0;
  assert(RAM_4[x_0] >= RAM_4[y_0]);
  free(mem);
  return 0;
}

constraints() {

  mem = my_malloc(sizeof(int) * 2);
  x_0 = mem;
  y_0 = mem + 4;

  RAM_1[x_0] = RAM_0[x_0] + RAM_0[y_0];
  RAM_10[y_0] = RAM_1[y_0]+1;
  RAM_2[x] = RAM_0[x] - RAM_0[y];
  RAM_20[y] = RAM_2[y] - 1;
  RAM_3 = RAM_0[y_0] > 0 ? RAM_10 : RAM_20;
  RAM_4 = a ? RAM_3 : RAM_0;
  assume(RAM_0[x_0] > RAM_0[y_0]);
  assume(RAM_0[x_0] > 0);
  assert(RAM_4[x_0] >= RAM_4[y_0]);
  free(mem);

}

lambda_constraints(){
    mem = my_malloc(sizeof(int) * 2);
    x_0 = mem;
    y_0 = mem + 4;

    RAM1 = lambda j :: j == x_0 ? RAM0[x0] + RAM0[y0] : RAM0[j];
    RAM_10 = lambda k :: k == y_0 ? RAM1[y0] + 1 : RAM0[j];
    RAM_2[x] = RAM_0[x] - RAM_0[y];
    RAM_20[y] = RAM_0[y] - 1;
    RAM_3 = RAM_0[y_0] > 0 ? RAM_10 : RAM_20;
    RAM_4 = a ? RAM_3 : RAM_0;
    assume(RAM_0[x_0] > RAM_0[y_0]);
    assume(RAM_0[x_0] > 0);
    assert(RAM_4[x_0] >= RAM_4[y_0]);
    free(mem);



} 
