    //     #include <iostream>
    //     using namespace std;
    //    int main()
       {

         // Menu
        int choice;
        do
        {
            cout << "Select the option or -1 to terminate" << endl;
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
                cout << "\n---Display Firm" << endl;

                break;
            }
            case 2:
            {

                break;
            }

            case 3:
            {

                break;
            }
            case 4:
            {

                break;
            }
            case 5:
            {
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

                break;
            }
            case 8:
            {

                break;
            }
            case 9:
            {

                break;
            }
            case 10:
            {

                break;
            }
            case 11:
            {

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

                v1.display();
                v_2.display();
                v_3 = v1.Union(v_2);
                v_3.display();
                break;
            }

            case 14:
            {
                cout << "\n---Intersection---" << endl;

                Vector<int> v2_intersection(size); 

                int s3 = size + size;
                Vector<int> v3(s3);

                cout << "Enter " << size << " elements for Vector 2 also: ";
                for (int i = 0; i < size; i++)
                {
                    cin >> element;
                    v2_intersection.push_back(element);
                }

                v3 = v1.intersection(v2_intersection);
                v3.display();
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
       