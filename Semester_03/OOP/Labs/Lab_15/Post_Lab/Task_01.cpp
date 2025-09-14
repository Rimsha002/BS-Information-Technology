#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

class Item
{
    string name;
    int price;
    int total_Quantity;

public:
    Item()
    {
        name = "";
        price = 0;
        total_Quantity = 0;
    }
    Item(string name, int price, int total_Quantity)
    {
        setName(name);

        this->price = price;
        this->total_Quantity = total_Quantity;
    }

    void setName(string name)
    {
        if (name.empty())
        {
            throw runtime_error("Invalid! Name cannot be empty");
        }

        if (name.length() > 20)
        {
            throw runtime_error("Invalid! Name cannot be more than 20 characters");
        }

        if (!isalpha(name[0]))
        {
            throw runtime_error("Invalid! Name must start with an alphabet");
        }

        this->name = name;
    }

    // Add an item to the Shopping Cart
    void additem()
    {
        string name1;
        int price1;
        int total_Quantity1;

        cout << "Enter the name: ";
        getline(cin, name1);
        cout << "Enter the price: ";
        cin >> price1;
        cout << "Enter the total quantity: ";
        cin >> total_Quantity1;

        ifstream infile;
        infile.open("Shopping_Cart.dat", ios::binary);

        infile.read((char *)this, sizeof(*this));
        if (this->name == name1)
        {
            throw runtime_error("Item already exists");
        }
        setName(name1);
        this->price = price1;
        this->total_Quantity = total_Quantity1;

        infile.close();

        ofstream outfile;
        outfile.open("Shopping_Cart.dat", ios::binary | ios::app);
        outfile.write((char *)this, sizeof(*this));
        outfile.close();

        cout << "Item added successfully" << endl;
    }

    //Remove item
    void removeitem()
    {
         ifstream infile("Shopping_Cart.dat", ios::binary);

        if (!infile.is_open())
        {
            throw runtime_error("Cart is empty or file cannot be opened");
            return;
        }

        string name1;
        cin.ignore();
        cout << "Enter the name of the item you want to remove: ";
        getline(cin, name1);

        cout << "How many items you want to remove: ";
        int count;
        cin >> count;

        ofstream Temp("Temp.dat", ios::binary);
       bool itemFound = false;
        while (infile.read((char *)this, sizeof(*this)))
        {
            if (this->name == name1)
            {
                itemFound = true;
                this->total_Quantity = this->total_Quantity - count;
               
                if (this->total_Quantity == 0)
                {
                    throw runtime_error("Sorry! Item is out of stock");
                }
            }
            Temp.write((char *)this, sizeof(*this));
        }
     
        infile.close();
        Temp.close();

        if (!itemFound)
        {
            throw runtime_error("Item not found");
        }

        remove("Shopping_Cart.dat");
        rename("Temp.dat", "Shopping_Cart.dat");

        cout << "Item removed successfully" << endl;
    }


    // Delete an item from the Shopping Cart
    void DeleteItem()
    {
        ifstream infile("Shopping_Cart.dat", ios::binary);

        if (!infile.is_open())
        {
            throw runtime_error("Cart is empty or file cannot be opened");
            return;
        }

        string name1;
        cin.ignore();
        cout << "Enter the name of the item you want to remove: ";
        getline(cin, name1);

        ofstream Temp("Temp.dat", ios::binary);
        bool itemFound = false;

        while (infile.read((char *)this, sizeof(*this)))
        {
            if (this->name == name1)
            {
                itemFound = true;
                // Skip writing this item to Temp
                if (this->total_Quantity == 0)
                {
                    throw runtime_error("Sorry! Item is out of stock");
                }
            }
            else
            {
                Temp.write((char *)this, sizeof(*this));
            }
        }

        infile.close();
        Temp.close();

        if (!itemFound)
        {
            throw runtime_error("Item not found");
        }

        remove("Shopping_Cart.dat");
        rename("Temp.dat", "Shopping_Cart.dat");

        cout << "Item removed successfully" << endl;
    }
  

    // View Content of the Shopping Cart
    void viewCart()
    {
        ifstream infile;
        infile.open("Shopping_Cart.dat", ios::binary);
        infile.read((char *)this, sizeof(*this));

        if (infile.eof())
        {
            throw runtime_error("Cart is empty");
            return;
        }
        if (!infile.is_open())
        {
            throw runtime_error("Cart is empty");
            return;
        }
        while (!infile.eof())
        {
            cout << "Name: " << this->name << endl;
            cout << "Price: " << this->price << endl;
            cout << "Total Quantity: " << this->total_Quantity << endl;
            cout << "--------------------------------" << endl;
            infile.read((char *)this, sizeof(*this));
        }
        infile.close();
    }

    // Total Cost of items in the Shopping Cart
    void totalCost()
    {
        ifstream infile;
        infile.open("Shopping_Cart.dat", ios::binary);
        infile.read((char *)this, sizeof(*this));

        if (infile.eof())
        {
            throw runtime_error("Cart is empty");
            return;
        }
        if (!infile.is_open())
        {
            throw runtime_error("Cart is empty");
            return;
        }

        int totalCost = 0;
        while (!infile.eof())
        {
            totalCost += this->price * this->total_Quantity;
            infile.read((char *)this, sizeof(*this));
        }
        cout << "Total Cost of all items (Rs.): " << totalCost << endl;
        infile.close();
    }
};

int main()
{
    cout << "--Welcome to the Shopping Cart--" << endl;
    Item item;

    int choice;

    do
    {
        cout << "\n-Select an option or -1 to quite-" << endl;
        cout << "1. Add an item to Cart" << endl;
        cout << "2. Remove an item from  Cart" << endl;
        cout << "3. Delete an item from Cart" << endl;
        cout << "4. View Content of Cart" << endl;
        cout << "5. Total Cost of items in Cart" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\n--Adding an item--" << endl;
            try
            {
                cin.ignore();
                item.additem();
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << "\n--Removing / Buy an item--" << endl;
            try
            {
                item.removeitem();
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }

            break;
        }
         case 3:
        {
            cout << "\n--Delete an item--" << endl;
            try
            {
                item.DeleteItem();
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }

            break;
        }
        case 4:
        {
            cout << "\n--Viewing Cart--" << endl
                 << endl;
            try
            {
                item.viewCart();
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 5:
        {
            cout << "\n--Total Cost--" << endl;
            try
            {
                item.totalCost();
            }
            catch (const runtime_error &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 6:
        {
            choice = -1;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }

    } while (choice != -1);

    cout << "\n---ByeBye---" << endl;
    return 0;
}