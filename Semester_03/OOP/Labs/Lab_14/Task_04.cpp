#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeData(ofstream &outFile);
void readData(ifstream &inFile);

void writeData(ofstream &outFile)
{
    string name;
    string msg;
    outFile.open("Chat.txt", ios::out);
    cout << "enter the name:";
    cin >> name;
    outFile << "Name:" << name;

    cout << "Enter the message:";
    getline(cin, msg);
    outFile << msg;
    cout << "Write successfully" << endl;
}
void readData(ifstream &inFile)
{
    string name;
    string msg;

    inFile.open("Chat.txt", ios::in);
    if (!inFile)
    {
        cout << "File not found" << endl;
        return;
    }
    inFile >> name >> msg;
    cout << "Name: " << name << endl;
    cout << "Message: " << msg << endl;
}

int main()
{
    ofstream outFile;

    string line;

    cout << "\n----Welcome to Chat Box-----" << endl;

    cout << "Enter your name: ";
    getline(cin, line);

    // cout << "Enter Message that you want to store: " << endl;
    // getline(cin,msg);

    ChatBox chatbox;
    chatbox.writeData(outFile);
    outFile.close();

    ifstream inFile;
    chatbox.readData(inFile);
    inFile.close();

    return 0;
}