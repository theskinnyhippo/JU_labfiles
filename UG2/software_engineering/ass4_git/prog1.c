#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct Product{
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

void addProduct(struct Product products[], int *productCount);
void displayProducts(struct Product products[], int productCount);
void updateInventory(struct Product products[], int productCount);
void deleteProduct(struct Product products[], int *productCount);
void buyProduct(struct Product products[], int productCount);

int main(){
    struct Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;
	int i;

    while(1){
        printf("\n1. Administrator\n");
        printf("2. Customer\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n1. Add Product\n");
                printf("2. Update Inventory\n");
                printf("3. Delete Product\n");
                printf("4. Display Products\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch(choice){
                    case 1:
                        addProduct(products, &productCount);
                        break;
                    case 2:
                        updateInventory(products, productCount);
                        break;
                    case 3:
                        deleteProduct(products, &productCount);
                        break;
                    case 4:
                        displayProducts(products, productCount);
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
                break;

            case 2:
                displayProducts(products, productCount);
                buyProduct(products, productCount);
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void addProduct(struct Product products[], int *productCount){
    if(*productCount >= MAX_PRODUCTS){
        printf("Cannot add more products. Limit reached.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &products[*productCount].id);
    printf("Enter product name: ");
    scanf("%s", products[*productCount].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*productCount].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*productCount].price);

    printf("Product added successfully.\n");
   (*productCount)++;
}

void displayProducts(struct Product products[], int productCount){
    printf("\nProduct List:\n");
    int i;
	printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for(i = 0; i < productCount; i++){
        printf("%-5d %-20s %-10d %-10.2f\n", products[i].id, products[i].name,
               products[i].quantity, products[i].price);
    }
}

void updateInventory(struct Product products[], int productCount){
    int id, choice, i;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    for(i = 0; i < productCount; i++){
        if(products[i].id == id){
            printf("1. Update name\n");
            printf("2. Update quantity\n");
            printf("3. Update price\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice){
                case 1:
                    printf("Enter new name: ");
                    scanf("%s", products[i].name);
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &products[i].quantity);
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &products[i].price);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }

            printf("Product updated successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void deleteProduct(struct Product products[], int *productCount){
    int id, i, j;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < *productCount; i++){
        if(products[i].id == id){
            for(j = i; j < *productCount - 1; j++){
                products[j] = products[j + 1];
            }
           (*productCount)--;
            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product not found.\n");
}

void buyProduct(struct Product products[], int productCount){
    int i, id, quantity;
    printf("Enter the product ID to buy: ");
    scanf("%d", &id);

    for(i = 0; i < productCount; i++){
        if(products[i].id == id){
            printf("Enter quantity to buy: ");
            scanf("%d", &quantity);

            if(quantity <= products[i].quantity){
                printf("Total cost: %.2f\n", quantity * products[i].price);
                products[i].quantity -= quantity;
                printf("Purchase successful.\n");
            } else{
                printf("Insufficient quantity.\n");
            }

            return;
        }
    }

    printf("Product not found.\n");
}

