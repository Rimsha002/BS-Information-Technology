#include <iostream>
#include "My_vector.h"
#include <algorithm>

using namespace std;
int main()
{

    cout << "\n\n******* Welcome to My Vector Program *******" << endl
         << endl;
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    try
    {
        Vector<int> v1(size);
        Vector<int> v2(size);
        Vector<int> v3(size);

        int element;
        cout << "Enter elements in Vector 1'array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> element;
            v1.push_back(element);
        }

        int choice;
        do
        {
            cout << "\n\n\tSelect the option or -1 to terminate" << endl;
            cout << "1. Get current size" << endl;
            cout << "2. Get Max-size" << endl;
            cout << "3. Resize by Push_back" << endl;
            cout << "4. Resize by Pop back" << endl;
            cout << "5. Is Empty" << endl;
            cout << "6. Is Full" << endl;
            cout << "7. Get Element at index" << endl;
            cout << "8. Erase Element" << endl;
            cout << "9. Swap" << endl;
            cout << "10. Insert" << endl;
            cout << "11. Sort" << endl;
            cout << "12. Move" << endl;
            cout << "13. Union" << endl;
            cout << "14. Intersection" << endl;
            cout << "15. Unique" << endl;
            cout << "16. Count of Element" << endl;
            cout << "17. Find Subset" << endl;
            cout << "18. Search key value" << endl;
            cout << "19. Overload the Operator" << endl;
            cout << "20. Display" << endl;

            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice == -1)
            {
                break;
            }

            switch (choice)
            {
            case 1:
            {
                cout << "\n---Current size---" << endl;
                int current_Size;

                current_Size = v1.size();
                cout << "Current size of Vecter is: " << current_Size;

                break;
            }
            case 2:
            {
                cout << "\n---Max-size---" << endl;
                int max_Size;

                max_Size = v1.getMaxSize();
                cout << "Max-Size of Vecter is: " << max_Size;
                break;
            }

            case 3:
            {
                cout << "\n---Resize by Push Back---" << endl;
                cout << "Original Size of Vector-1 is: " << v1.size() << endl;
                cout << "How many values to want to push? " << endl;
                int num;
                cin >> num;
                int range = num + v1.size();

                cout << "Enter elements: " << endl;
                for (int i = v1.size(); i < range; i++)
                {
                    cin >> element;
                    v1.push_back(element);
                }

                cout << "\n-- New Vector-2 has: ";
                v1.display();

                break;
            }
            case 4:
            {
                cout << "\n---Resize by Pop_Back---" << endl;
                cout << "Original Size of Vector-1 is: " << size << endl;
                cout << "How many values want to pop? " << endl;
                int num;
                cin >> num;

                for (int i = 0; i < num; i++)
                {
                    int pop_element;
                    pop_element = v1.pop_back();
                    cout << "\nPoping Element is: " << pop_element << endl;
                }

                cout << "\nNew Vector has: ";
                v1.display();

                break;
            }
            case 5:
            {
                cout << "\n---Is Empty---" << endl;
                if (v1.is_empty())
                {
                    cout << "Vector is empty" << endl;
                }
                else
                {
                    cout << "Vector is not empty" << endl;
                }
                break;
            }
            case 6:
            {
                cout << "\n---Is Full---" << endl;
                if (v1.is_full())
                {
                    cout << "Vector is full" << endl;
                }
                else
                {
                    cout << "Vector is not full" << endl;
                }
                break;
            }
            case 7:
            {
                cout << "\n---Get Element at index---" << endl;
                int index;
                int element;

                cout << "\nEnter Index of: ";
                cin >> index;

                element = v1.at(index);
                cout << "Element at " << index << " index is: " << element << endl;

                break;
            }
            case 8:
            {
                cout << "\n---Erase Element---" << endl;
                cout << "\nOriginal Vector is: " << endl;
                v1.display();

                int index;
                int element;

                cout << "\nEnter Index of element: ";
                cin >> index;

                element = v1.erase(index);
                cout << "Done! Removed element is: " << element << endl;
                cout << "New Vector is: " << endl;
                v1.display();

                break;
            }
            case 9:
            {
                cout << "\n---Swap---" << endl;

                cout << "\n\nEnter Data for Vector-1 : " << endl;
                int s;
                cout << "Enter size: ";
                cin >> s;
                Vector<int> v2(s);

                cout << "Enter elements: ";
                for (int i = 0; i < s; i++)
                {
                    cin >> element;
                    v2.push_back(element);
                }

                cout << "\n\nEnter Data for Vector-2 also: " << endl;
                int s1;
                cout << "Enter size: ";
                cin >> s1;

                Vector<int> v3(s1);
                cout << "Enter elements: ";
                for (int i = 0; i < s1; i++)
                {
                    cin >> element;
                    v3.push_back(element);
                }

                cout << "\n\t Before" << endl;
                cout << "Vector 1: " << endl;
                v2.display();
                cout << "\n\nVector 2: " << endl;
                v3.display();

                v2.swap(v3);

                cout << "\n\t After swaping" << endl;
                cout << "Vector 1: " << endl;
                v2.display();
                cout << "\nVector 2: " << endl;
                v3.display();
                break;
            }

            case 10:
            {
                cout << "\n---Insert---" << endl;
                int index;
                int element;

                cout << "\nOriginal array is: " << endl;
                v1.display();

                cout << "\nEnter Index : ";
                cin >> index;
                cout << "Enter the element to insert: ";
                cin >> element;
                v1.insert(index, element);

                cout << "\nNew array is: " << endl;
                v1.display();

                break;
            }
            case 11:
            {
                cout << "\n---Sort---" << endl;

                v1.sort();

                break;
            }

            case 12:
            {
                cout << "\n---Move---" << endl;
                cout << "\nHow many number to move?: ";
                int num;
                cin >> num;
                v1.move(num);

                v1.display();
                break;
            }
            case 13:
            {
                cout << "\n---Union---" << endl;

                int s2;
                cout << "Enter size for Vector 2: ";
                cin >> s2;
                Vector<int> v_2(s2);

                int s3 = size + s2;
                Vector<int> v_3(s3);

                cout << "Enter elements for Vector 2 also: ";
                for (int i = 0; i < s2; i++)
                {
                    cin >> element;
                    v_2.push_back(element);
                }
             
                v1.Union(v_2);
               
                break;
            }

            case 14:
            {
                cout << "\n---Intersection---" << endl;

                  int s2;
                cout << "Enter size for Vector 2: ";
                cin >> s2;
                Vector<int> v2_intersection(s2);

                int s3 = size + s2;
                Vector<int> v3(s3);

                cout << "Enter " << s2 << " elements for Vector 2 also: ";
                for (int i = 0; i < s2; i++)
                {
                    cin >> element;
                    v2_intersection.push_back(element);
                }

              v1.intersection(v2_intersection);
        
                break;
            }

            case 15:
            {
                cout << "\n---Unique Values---" << endl;
                v1.unique();
                break;
            }
            case 16:
            {
                cout << "\n---Count of Element---" << endl;
                int e;
                cout << "\nEnter Element to be count: ";
                cin >> e;
                int count = v1.count(e);
                cout << "   It's count is : " << count << endl;
                break;
            }
            case 17:
            {
                cout << "\n---Find Subset---" << endl;
                int size2;
                cout << "\nEnter size for Vector 2: ";
                cin >> size2;

                Vector<int> v2(size2);
                cout << "\nEnter elements in it's array: ";
                for (int i = 0; i < size2; i++)
                {
                    cin >> element;
                    v2.push_back(element);
                }

                cout << "\n\nVector 1 is: ";
                v1.display();

                if (v1.subset(v2))
                {
                    cout << "\nV2 is subset of V1" << endl;
                }
                else
                {
                    cout << "\nV2 is not subset of V1" << endl;
                }
                break;
            }
            case 18:
            {
                cout << "\n---Search key Value---" << endl;

                int k;
                cout << "\nEnter Key to search: ";
                cin >> k;
                if (v1.search(k))
                {
                    cout << "Congratulation key is found" << endl;
                }
                else
                {
                    cout << "key is not found" << endl;
                }
                break;
            }
            case 19:
            {
                cout << "\n---Overloading Operator---" << endl;

                int size2;
                cout << "\nEnter size for Vector 2: ";
                cin >> size2;
                Vector<int> v2(size2);

                cout << "\nEnter elements in it's array: ";
                for (int i = 0; i < size2; i++)
                {
                    cin >> element;
                    v2.push_back(element);
                }

                char choose;
                do
                {
                    cout << "\nWhich operator you want to overload? " << endl;
                    cout << "a. + operator" << endl;
                    cout << "b. - operator" << endl;
                    cout << "c. >> Extraction" << endl;
                    cout << "d. <<  Insertion" << endl;
                    cout << "e. == Equality" << endl;
                    cout << "f. > Greater than v1 > v2" << endl;
                    cout << "g. < Less than v1 < v2" << endl;
                    cout << "h. = Assignment" << endl;
                    cout << "i. [] index" << endl;
                    cout << "\nEnter your choice or 'q' to exit: ";
                    cin >> choose;

                    if (choose == 'q')
                    {
                        break;
                    }

                    switch (choose)
                    {
                    case 'a':
                    {
                        cout << "\n\t + operator" << endl;

                        int s3 = size + size2;
                        Vector<int> v3(s3);
                        v3 = v1 + v2;
                        v3.display();

                        break;
                    }
                    case 'b':
                    {
                        cout << "\n\t - operator" << endl;
                        int s3 = size + size2;
                        Vector<int> v3(s3);

                        v3 = v1 - v2;
                        v3.display();

                        break;
                    }

                    case 'c':
                    {
                        cout << "\n\t >> Extraction" << endl;

                        // Vector<int> v3(size);
                        cin >> v2;
                        // v1 = v3;
                        v2.display();

                        break;
                    }
                    case 'd':
                    {
                        cout << "\n\t << Insertion Operator" << endl;
                        cout << v2;
                        break;
                    }
                    case 'e':
                    {
                        cout << "\n\t == Equality" << endl;

                        if (v1.isEqual(v2))
                        {
                            cout << "Both are equal" << endl;
                        }
                        else
                        {
                            cout << "Not Equal" << endl;
                        }

                        break;
                    }
                    case 'f':
                    {
                        cout << "\n\t > Greater than" << endl;
                        if (v1.isGreater(v2))
                        {
                            cout << "V1 is greater than V2" << endl;
                        }
                        else
                        {
                            cout << "Not greater" << endl;
                        }

                        break;
                    }
                    case 'g':
                    {
                        cout << "\n\t < Less Than" << endl;
                        if (v1.isLess(v2))
                        {
                            cout << "V1 is Lesser than V2" << endl;
                        }
                        else
                        {
                            cout << "Not Lesser" << endl;
                        }
                        break;
                    }
                    case 'h':
                    {
                        cout << "\n\t = Assignment" << endl;
                        v3 = v1;

                        cout << "Vector 1 is assiging to Vector 3: " << endl;
                        v3.display();
                        break;
                    }
                    case 'i':
                    {
                        cout << "\n\t [] index" << endl;
                        int index;
                        cout << "\nEnter Index of: ";
                        cin >> index;

                        element = v1[index];
                        cout << "Element at " << index << " index is: " << element << endl;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice" << endl;
                        cout << "Select again: ";
                        break;
                    }
                    }
                } while (choose != 'q' && (choose < 'a' || choose > 'i'));

                break;
            }

            case 20:
            {
                v1.display();
                break;
            }

            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
            }
        } while (choice != -1);
    }
    catch (const char *msg)
    {
        cout << "Error! " << msg << endl;
    };

    return 0;
}