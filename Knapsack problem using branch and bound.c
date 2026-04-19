#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int weight;
    int value;
    float ratio;
} Item;

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
} Node;

// Sort items by value/weight ratio in descending order
int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

// Calculate the maximum possible profit (upper bound) for a node
float calculateBound(Node u, int n, int W, Item items[]) {
    if (u.weight >= W) return 0;

    float profit_bound = (float)u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while (j < n && total_weight + items[j].weight <= W) {
        total_weight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    if (j < n) {
        profit_bound += (float)(W - total_weight) * items[j].ratio;
    }

    return profit_bound;
}

int main() {
    int i,n, W;

    printf("Enter the number of items: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("Enter the capacity of the knapsack: ");
    if (scanf("%d", &W) != 1) return 1;

    Item* items = malloc(n * sizeof(Item));
    for (i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(Item), compare);

    // Using a large enough array for the BFS queue
    Node* queue = malloc(10000 * sizeof(Node));
    int front = 0, rear = 0;

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = calculateBound(u, n, W, items);
    queue[rear++] = u;

    int maxProfit = 0;

    while (front < rear) {
        u = queue[front++];

        if (u.level == n - 1) continue;

        v.level = u.level + 1;

        // Case 1: Include the next item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        v.bound = calculateBound(v, n, W, items);
        if (v.bound > (float)maxProfit) {
            queue[rear++] = v;
        }

        // Case 2: Exclude the next item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > (float)maxProfit) {
            queue[rear++] = v;
        }
    }

    printf("\nMaximum Profit: %d\n", maxProfit);

    free(items);
    free(queue);
    return 0;
}
