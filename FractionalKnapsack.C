#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    double value;
    double weight;
    double ratio; // Value-to-weight ratio
} Item;

// Comparison function for qsort to sort items by ratio in descending order
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemA->ratio > itemB->ratio) return -1;
    if (itemA->ratio < itemB->ratio) return 1;
    return 0;
}

// Function to solve the fractional knapsack problem
void fractionalKnapsack(double capacity, Item items[], int n) {
    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    // Sort items by their ratio in descending order
    qsort(items, n, sizeof(Item), compareItems);

    double totalProfit = 0.0;
    double currentWeight = 0.0;
    double solution[n]; // To store the fraction of each item taken

    // Initialize solution array with zeros
    for (int i = 0; i < n; i++) {
        solution[i] = 0.0;
    }

    // Greedily fill the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].value;
            solution[i] = 1.0;
        } else {
            // Take a fraction of the item
            double remainingCapacity = capacity - currentWeight;
            double fraction = remainingCapacity / items[i].weight;
            currentWeight += remainingCapacity;
            totalProfit += items[i].value * fraction;
            solution[i] = fraction;
            break; // Knapsack is full
        }
    }
    
    // Print the results
    printf("\n--- Results ---\n");
    printf("Final Profit: %.2f\n", totalProfit);
    printf("Optimal Solution (fraction of each item taken):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    double capacity;

    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    printf("Enter the value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("  Value: ");
        scanf("%lf", &items[i].value);
        printf("  Weight: ");
        scanf("%lf", &items[i].weight);
    }

    fractionalKnapsack(capacity, items, n);

    return 0;
}