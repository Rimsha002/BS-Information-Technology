#ifndef ORDER_H

#include <iostream>
// #include "Customer.h"
// #include "Date.h"
#include "Salesman.h" // saleman >> company >> medication class

using namespace std;

class Order
{
    static int order_ID;
    int customer_ID;
    string *bought_medicine;
    float total_amount;
    string payment_method;

    Date order_date;
    Medication medication;
    Salesman salesman;
    Pharma_Company company;

    friend istream &operator>>(istream &i, Order &order);
    friend ostream &operator<<(ostream &o, const Order &order);

public:
    Order()
    {
        order_ID++;
        customer_ID = 0;
        order_date = Date();
        bought_medicine = new string[10];
        salesman = Salesman();
        company = Pharma_Company();
        total_amount = 0;
        payment_method = "";
    }

    // Parametrize Constructor
    Order(int c_id, Date date, string *med, Salesman saleman, Pharma_Company p_comp, float t, string pay)
    {
        order_ID++;
        customer_ID = c_id;
        order_date = date;
        bought_medicine = med;
        salesman = saleman;
        company = p_comp;
        total_amount = t;
        payment_method = pay;
    }

    // Parametrize Constructor 2
    Order(float total_amount, int cust_id)
    {
        order_ID++;
        customer_ID = cust_id;
        setMedicine();  //Bought Medicines
        cin >> order_date;
        cin >> salesman;
 
        this->total_amount = total_amount;
        setPayment_Method();
    }

    // Copy Constructor
    Order(const Order &obj)
    {
        order_ID = obj.order_ID;
        customer_ID = obj.customer_ID;
        order_date = obj.order_date;
        bought_medicine = obj.bought_medicine;
        salesman = obj.salesman;
        company = obj.company;
        total_amount = obj.total_amount;
        payment_method = obj.payment_method;
    }

    // Setter
    void setOrder_ID(int id)
    {
        order_ID = id;
    }
    void setCustomer_ID(int c_id)
    {
        customer_ID = c_id;
    }
    void setOrder_date(Date o_date)
    {
        order_date = o_date;
    }
    void setMedicine()
    {
        bought_medicine = salesman.getSelected_Medicine();
    }

    void setSalesman(Salesman saleman)
    {
        salesman = saleman;
    }
    void setCompany(Pharma_Company pharma_c)
    {
        company = pharma_c;
    }
    void setTotal_Amount(float t)
    {
        total_amount = t;
    }
    void setPayment_Method()
    {
        cout << "\nPayment Methods: " << endl;
        cout << "1. Cash" << endl;
        cout << "2. Credit Card" << endl;
        cout << "3. Debit Card" << endl;
        cout << "Select option: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            payment_method = "Cash";
            break;
        case 2:
            payment_method = "Credit Card";
            break;
        case 3:
            payment_method = "Debit Card";
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    // Getter
    int getOrder_ID()
    {
        return order_ID;
    }
    int getCustomer_ID()
    {
        return customer_ID;
    }
    Date getOrder_date()
    {
        return order_date;
    }
    string *getMedicine()
    {
        return bought_medicine;
    }
    Medication &getMedication()
    {
        return medication;
    }
    Salesman getSalesman()
    {
        return salesman;
    }
    Pharma_Company getCompany()
    {
        return company;
    }

    float getTotal_Amount()
    {
        return total_amount;
    }
    string getPayment_Method()
    {
        return payment_method;
    }

    // Destructor
    ~Order()
    {
        delete[] bought_medicine;
    }

    // display
    void display()
    {
        cout << "\n\t---Order Information---\n"
             << endl;
        cout << "Order ID: " << order_ID << endl;
        cout << "Customer ID: " << customer_ID << endl;
        cout << "Order Date: " << order_date << endl;
        cout << "Bought Medicine: " << endl;
    
        int size = salesman.getSelectedSize();

        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << bought_medicine[i] << endl;
        }
        cout << salesman;
       
        cout << "Total Amount: " << total_amount << endl;
        cout << "Payment Method: " << payment_method << endl;
        cout << endl;
    }

    // Assignment Operator
    Order &operator=(const Order &obj)
    {
        order_ID = obj.order_ID;
        customer_ID = obj.customer_ID;
        order_date = obj.order_date;
        for (int i = 0; i < 10; i++)
        {
            bought_medicine[i] = obj.bought_medicine[i];
        }

        salesman = obj.salesman;
        company = obj.company;
        total_amount = obj.total_amount;
        payment_method = obj.payment_method;

        return *this;
    }
};

int Order::order_ID = 0;

istream &operator>>(istream &i, Order &order)
{
    cout << "\n````Enter Order Details````" << endl;
    cout << "Enter Customer ID: ";
    i >> order.customer_ID;
    order.setMedicine();

    i >> order.order_date;
    i >> order.salesman;
 
    cout << "Enter Total Amount: ";
    i >> order.total_amount;
    order.setPayment_Method();

    return i;
}

ostream &operator<<(ostream &o, const Order &order)
{
    o << "\n---Order Information---\n"
      << endl;
    o << "Order ID: " << order.order_ID << endl;
    o << "Customer ID: " << order.customer_ID << endl;
    o << "Order Date: " << order.order_date << endl;
    o << "Bought Medicine: " << endl;
    for (int i = 0; i < 10; i++)
    {
        o << i + 1 << ". " << order.bought_medicine[i] << endl;
    }
    o << "Salesman: " << order.salesman << endl;
    o << "Total Amount: " << order.total_amount << endl;
    o << "Payment Method: " << order.payment_method << endl;
    o << endl;

    return o;
}

#endif