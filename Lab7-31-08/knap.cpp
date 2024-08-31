#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

void solveknapsack(vector<Item> items, int capacity) {
    int current_weight = 0;
    double total_profit = 0.0;
    for (int i = 0; i < items.size(); i++) {
        if(current_weight + items[i].weight <= capacity) {
            current_weight += items[i].weight;
            total_profit += items[i].profit;
        } else {
            int remain = capacity - current_weight;
            total_profit += items[i].profit * ((double)remain / items[i].weight);
            break;
        }
    }
    cout << "Total Profit: " << total_profit << endl;
}

void knapsack(int capacity, vector<int> weights, vector<int> profit) {
    int n = weights.size();
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {weights[i], profit[i], (double)profit[i] / weights[i]};
    }
    // Strat 1: Non-increasing order of profit
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.profit > b.profit;
    });
    cout << "Knapsack by non-increasing order of profit:" << endl;
    solveknapsack(items, capacity);
    // Start 2: Non-decreasing order of weights
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.weight < b.weight;
    });
    cout << "Knapsack by non-increasing order of weight:" << endl;
    solveknapsack(items, capacity);
    // Strat 3: Non-increasing Order of ratio of Profit by Weight
    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.ratio > b.ratio;
    });
    cout << "Knapsack by non-increasing order of P/W ratio:" << endl;
    solveknapsack(items, capacity);
}

int main() {
    cout << "\n-----Problem 1-----\n";
    knapsack(20, {18, 15, 10}, {25, 24, 15});
    cout << "\n-----Problem 2-----\n";
    knapsack(25, {5, 15, 10, 12}, {25, 21, 15, 6});
    return 0;
}