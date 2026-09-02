#include <iostream>
#include <string>
#include <climits>
using namespace std;

int nextProductId = 1001;

class Product
{
private:
    int id;
    string productName;
    double productPrice;
    int stock;

public:
    Product()
    {
        id = nextProductId++;
    }

    void acceptDetails()
    {
        string input;

        cout << "Enter Product Name: ";
        getline(cin, input);
        productName = input;

        cout << "Enter Price: ";
        getline(cin, input);
        productPrice = stod(input);

        cout << "Enter Quantity: ";
        getline(cin, input);
        stock = stoi(input);
    }

    double getTotalValue() const
    {
        return productPrice * stock;
    }

    void showDetails() const
    {
        cout << id << " "
             << productName << " "
             << productPrice << " "
             << stock << " "
             << getTotalValue() << endl;
    }

    bool checkLowStock(int limit) const
    {
        return stock < limit;
    }

    string getProductName() const
    {
        return productName;
    }
};

void showLowStock(Product products[], int count, int limit)
{
    for (int i = 0; i < count; i++)
    {
        if (products[i].checkLowStock(limit))
        {
            cout << products[i].getProductName() << " ";
        }
    }
}

double reorderCost(int quantity, double price)
{
    return quantity * price;
}

double reorderCost(double quantity, double price)
{
    return quantity * price;
}

double reorderCost(int quantity, double price, double tax)
{
    double amount = quantity * price;
    return amount + (amount * tax / 100);
}

double applyDiscount(double price, double discount = 10.0)
{
    double discountAmount = price * discount / 100;
    return price - discountAmount;
}

//We use a Product class to store product details like ID, name, price, and quantity. 
//An array of 5 objects is used to store multiple products. 
//Functions are used to calculate total value, display details, and check whether the product has low stock.


int main()
{
    const int totalProducts = 5;
    Product products[totalProducts];

    for (int i = 0; i < totalProducts; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====" << endl;
    cout << "ID Name Price Qty Total Value" << endl;

    for (int i = 0; i < totalProducts; i++)
    {
        products[i].showDetails();
    }

    int highestIndex = 0;

    for (int i = 1; i < totalProducts; i++)
    {
        if (products[i].getTotalValue() >
            products[highestIndex].getTotalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product: "
         << products[highestIndex].getProductName()
         << " "
         << products[highestIndex].getTotalValue()
         << " Rs" << endl;

    int limit = 10;

    cout << "Low Stock (Threshold: "
         << limit << "): ";

    showLowStock(products, totalProducts, limit);

    cout << endl;

    cout << "\nReorder Cost: "
         << reorderCost(10, 120) << endl;

    cout << "Reorder Cost: "
         << reorderCost(20.5, 200) << endl;

    cout << "Reorder Cost With Tax: "
         << reorderCost(45, 250, 10) << endl;

    cout << "Discounted Price: "
         << applyDiscount(2000, 20) << endl;

    return 0;
}

//We use function overloading so the same reorderCost() function can work with different types and numbers of parameters. 
//We also use a default argument in applyDiscount(), where 10% discount is automatically used if no discount is provided.