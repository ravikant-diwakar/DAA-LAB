#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int item_id;
  float item_profit;
  float item_weight;
  float profit_weight_ratio;
} ITEM;

void swap(ITEM *a, ITEM *b) {
  ITEM temp = *a;
  *a = *b;
  *b = temp;
}

void sort(ITEM *items, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (items[i].profit_weight_ratio < items[j].profit_weight_ratio) {
        swap(&items[i], &items[j]);
      }
    }
  }
}

void fractionalKnapsack(ITEM *items, int n, int capacity) {
  float total_profit = 0.0;
  float total_weight = 0.0;

  for (int i = 0; i < n; i++) {
    if (total_weight + items[i].item_weight <= capacity) {
      total_profit += items[i].item_profit;
      total_weight += items[i].item_weight;
    } else {
      float fraction = (capacity - total_weight) / items[i].item_weight;
      total_profit += fraction * items[i].item_profit;
      total_weight += fraction * items[i].item_weight;
      break;
    }
  }

  printf("Item No\tProfit\tWeight\tAmount to be taken\n");

  for (int i = 0; i < n; i++) {
    float amount = items[i].item_weight;
    if (total_weight < capacity) {
      if (total_weight + items[i].item_weight <= capacity) {
        amount = items[i].item_weight;
      } else {
        amount = capacity - total_weight;
      }
    }

    printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, amount);
    total_weight -= amount;
  }

  printf("Maximum profit: %.6f\n", total_profit);
}

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  ITEM items[n];

  for (int i = 0; i < n; i++) {
    printf("Enter the profit and weight of item no %d: ", i + 1);
    scanf("%f %f", &items[i].item_profit, &items[i].item_weight);

    items[i].item_id = i + 1;
    items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
  }

  int capacity;
  printf("Enter the capacity of knapsack: ");
  scanf("%d", &capacity);

  sort(items, n);

  fractionalKnapsack(items, n, capacity);

  return 0;
}
