#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

float train[][2] = {
  {0, 0},
  {1, 2},
  {2, 4},
  {3, 6},
  {4, 8},
  {5, 10},
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float () {
  return (float)rand() / (float)RAND_MAX;
}

float cost(float w) {
  float result = 0.0f;

  for (size_t i = 0; i < train_count; ++i) {
    float x = train[i][0];
    float y = x*w;

    float diff = train[i][1] - y;
    result += diff*diff;
  }

  return result/train_count;
}

int main () {
  srand(time(0));
  float w = rand_float()*10.0f;
  //float w = 2.0f;

  float eps = 1e-3;
  float rate = 1e-3;

  for (int i = 0; i < 500; ++i) {
    float dcost = (cost(w + eps) - cost(w)) / eps;
    w -= rate*dcost;

    printf("cost(w = %f) => %f\n", w, cost(w));
  }
  printf("--------------------------");
  printf("w: %f\n", w);

	return 0;
}
