#include <iostream>
#include <vector>
using namespace std;

class Encryption{
    private:
    string * paragraph;
    string * encrypted;
    string * decrypted;
    int noOfLines;
    vector <int > key;

    public:
    Encryption(int lines)
    {
        this->noOfLines = lines;
        paragraph = new string[noOfLines];
        encrypted = new string[noOfLines];
        decrypted = new string[noOfLines];  
        key.resize(noOfLines);
    }
    void insertLines()
    {
        for(int i = 0; i < noOfLines; i++)
        {
            cout << "Enter line " << i+1 << ": ";
            cin >> paragraph[i]; 
            // getline(cin, paragraph[i]);
            // By using getline, Error occur in the program as it not allow to take line inupt from user
    
        
        }
    }
    void enterKeys()
    {
        int k;
        cout << "Enter key for\n";
         for(int i = 0; i < noOfLines; i++)
        {
            cout << "Line " << i+1 << ": ";
            cin >> key[i];
        }
    }

    void encrypt()
    {
        
        for(int i = 0; i < noOfLines; i++)
        {
            for(int j = 0; j < paragraph[i].length(); j++)
            {
                if(paragraph[i][j] + key[i] > 127)
                {
                    encrypted[i] += paragraph[i][j];
                }
                else
                {
                    encrypted[i] += paragraph[i][j] + key[i];
                }
            }
        }   

    }
    void decrypt()
    {
            for(int i = 0; i < noOfLines; i++)
            {
                for(int j = 0; j < encrypted[i].length(); j++)
                {
                    decrypted[i] += encrypted[i][j] - key[i];
                }
            }
    }

   void displayEncrypted()
   {
    cout << "\nEncrypted Paragraph is: ";
       for(int i = 0; i < noOfLines; i++)
       {
           cout << encrypted[i] << endl;
       }
   }
   void displayDecrypted()
   {
    cout << "\nDecrypted Paragraph is: ";
       for(int i = 0; i < noOfLines; i++)
       {
           cout << decrypted[i] << endl;
       }
   }


~Encryption() 
{
    delete [] paragraph;
}
};

int main()
{
    int lines;
    cout << "Enter number of lines: ";
    cin >> lines;
    class Encryption encrypt(lines);
    encrypt.insertLines();
    encrypt.enterKeys();
    encrypt.encrypt();
    encrypt.displayEncrypted();
    encrypt.decrypt();
    encrypt.displayDecrypted();

    return 0;
}