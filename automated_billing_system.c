#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 1000
#define NAME_LEN 100

char products[MAX_PRODUCTS][NAME_LEN];  
int qty[MAX_PRODUCTS];                   
float price[MAX_PRODUCTS];              

int product_count = 0;

int find_product(char name[]) {
    for (int i = 0; i < product_count; i++) {
        if (strcmp(products[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_item() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Store is full, cannot add more products.\n");
        return;
    }
    char name[NAME_LEN];
    int quantity;
    float cost;

    printf("Enter product name: ");
    scanf("%s", name);

    int idx = find_product(name);
    if (idx != -1) {
        printf("Product exists. Updating quantity and price.\n");
        printf("Enter quantity to add: ");
        scanf("%d", &quantity);
        printf("Enter new price: ");
        scanf("%f", &cost);

        qty[idx] += quantity;
        price[idx] = cost;
    } else {
        strcpy(products[product_count], name);
        printf("Enter quantity: ");
        scanf("%d", &quantity);
        printf("Enter price: ");
        scanf("%f", &cost);

        qty[product_count] = quantity;
        price[product_count] = cost;
        product_count++;
    }
    printf("Item added/updated successfully.\n");
}

void update_item() {
    char name[NAME_LEN];
    printf("Enter product name to update: ");
    scanf("%s", name);

    int idx = find_product(name);
    if (idx == -1) {
        printf("Product not found in store.\n");
        return;
    }

    int new_qty;
    float new_price;
    printf("Enter new quantity: ");
    scanf("%d", &new_qty);
    printf("Enter new price: ");
    scanf("%f", &new_price);

    qty[idx] = new_qty;
    price[idx] = new_price;
    printf("Product updated successfully.\n");
}

void bill_total() {
    int n;
    printf("Enter number of different items to bill: ");
    scanf("%d", &n);

    float total_amt = 0;
    for (int i = 0; i < n; i++) {
        char name[NAME_LEN];
        int purchase_qty;
        printf("Enter product name %d: ", i + 1);
        scanf("%s", name);

        int idx = find_product(name);
        if (idx == -1) {
            printf("Product not found, skipping.\n");
            continue;
        }

        printf("Available quantity: %d\n", qty[idx]);
        printf("Enter quantity to buy: ");
        scanf("%d", &purchase_qty);

        if (purchase_qty > qty[idx]) {
            printf("Insufficient quantity available, skipping.\n");
            continue;
        }

        float amt = purchase_qty * price[idx];
        total_amt += amt;
        qty[idx] -= purchase_qty;
    }
    printf("Total bill amount: %.2f\n", total_amt);
}

void display_products() {
    printf("\nAvailable Products in Store:\n");
    printf("------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Product", "Quantity", "Price");
    for (int i = 0; i < product_count; i++) {
        printf("%-20s %-10d %-10.2f\n", products[i], qty[i], price[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("======Automated Billing System======\n");
        printf("1. Add Items\n");
        printf("2. Update Price and Quantity\n");
        printf("3. Bill Total Amount\n");
        printf("4. Display Available Products\n");
        printf("5. Exit\n");
        printf("=====================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item(); break;
            case 2: update_item(); break;
            case 3: bill_total(); break;
            case 4: display_products(); break;
            case 5: return 0;
            default: printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
