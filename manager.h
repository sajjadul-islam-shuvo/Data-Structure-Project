#include <bits/stdc++.h>
#include "animation.h"

#ifndef manager
#define manager

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

struct product
{
    int proId;
    string proName;
    double proPrice;
    int proNum;
    product *next;
} *head = nullptr;

void saveNewProductToFile(product *temp);
void saveAllProductToFile();
void loadProductFromFile();
void deleteList();

//=================================================================
//========================= Count Product =========================
//=================================================================
int countProduct()
{
    product *temp = head;

    if (head == nullptr)
        return 0;
    int i;
    for (i = 0; temp != nullptr; i++)
    {
        temp = temp->next;
    }
    return i;
}

void deleteList()
{
    //Clear List
    product *temp = head;
    while (temp != nullptr)
    {
        product *deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
    head = nullptr;     //indicate an empty list
}

//=================================================================
//========================== Add Product ==========================
//=================================================================
void addProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                       Add New Product                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head, *newNode;
    newNode = new product; // new mamory allocation & object creation

    gotoxy(15, 6);
    cout << "Enter Product Info . . .";

    gotoxy(20, 8);
    cout << "Product Name     : ";
    cin.ignore();
    getline(cin, newNode->proName);
    gotoxy(20, 9);
    cout << "Product ID       : ";
    cin >> newNode->proId;
    gotoxy(20, 10);
    cout << "Product Price    : ";
    cin >> newNode->proPrice;
    gotoxy(20, 11);
    cout << "Product Quantity : ";
    cin >> newNode->proNum;

    saveNewProductToFile(newNode);

    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    gotoxy(25, 14);
    cout << "Product \"" << newNode->proName << "\" is added Successfully";
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

//=================================================================
//======================= Display Products ========================
//=================================================================
void displayProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                   Displaying All Products                     |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head;
    int totalProduct = 0;

    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "No Product is Found . . . \n\n\n\n\n\n";
    }
    else
    {
        gotoxy(15, 7);
        cout << "Existing Product are:";
        gotoxy(12, 9);
        cout << left;
        cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
        gotoxy(12, 10);
        cout << "======================================================================\n";
        int yPos = 11;
        while (temp != nullptr)
        {
            gotoxy(12, yPos);
            cout << left;
            cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;

            temp = temp->next;
            totalProduct++;
            yPos++;
        }
        gotoxy(12, yPos);
        cout << "______________________________________________________________________\n";
        gotoxy(30, yPos + 1);
        cout << "Total Products in our Store : " << totalProduct << endl << endl;
    }
}

//=================================================================
//======================== Modify Product =========================
//=================================================================
void modifyProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                         Modify Product                        |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head;
    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "Store is Empty . . ." << endl;
    }
    else
    {
        int id;
        gotoxy(20, 7);
        cout << "Enter Product's ID : ";
        cin >> id;

        while (temp != nullptr)
        {
            if (temp->proId == id)
            {
                gotoxy(12, 9);
                cout << left;
                cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
                gotoxy(12, 10);
                cout << "======================================================================\n";
                gotoxy(12, 11);
                cout << left;
                cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;

                gotoxy(25, 13);
                cout << "Enter Modify Product Info : \n";
                gotoxy(30, 14);
                cout << "New Product ID       : ";
                cin >> temp->proId;
                gotoxy(30, 15);
                cout << "New Product Name     : ";
                cin.ignore();
                getline(cin, temp->proName);
                gotoxy(30, 16);
                cout << "New Product Price    : ";
                cin >> temp->proPrice;
                gotoxy(30, 17);
                cout << "New Product Quantity : ";
                cin >> temp->proNum;
                gotoxy(30, 19);
                cout << "Product \" " << temp->proName << " \" is modified" << endl;

                saveAllProductToFile();
                loadProductFromFile();
                break;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            gotoxy(20, 21);
            cout << "No Product Found";
        }
    }
    gotoxy(30, 21);
    system("pause");
    system("cls");
}

//=================================================================
//======================== Delete Product =========================
//=================================================================
void deleteProduct()
{
    system("cls");

    gotoxy(15, 2);
    cout << "+---------------------------------------------------------------+";
    gotoxy(15, 3);
    cout << "|                        Delete Product                         |";
    gotoxy(15, 4);
    cout << "+---------------------------------------------------------------+";

    product *temp = head, *prev = nullptr;

    if (head == nullptr)
    {
        gotoxy(34, 7);
        cout << "Store is Empty . . .";
    }
    else
    {
        int id;
        gotoxy(20, 7);
        cout << "Enter Product's ID : ";
        cin >> id;
        bool idExist = false;

        while (temp != nullptr)
        {
            if (temp->proId == id)
            {
                idExist = true;
                gotoxy(12, 9);
                cout << left;
                cout << setw(15) << "Product ID" << setw(30) << "Product Name" << setw(15) << "Price" << setw(10) << "Quantity" << endl;
                gotoxy(12, 10);
                cout << "======================================================================\n";
                gotoxy(12, 11);
                cout << left;
                cout << setw(15) << temp->proId << setw(30) << temp->proName << setw(15) << temp->proPrice << setw(10) << temp->proNum << endl;
                gotoxy(25, 13);
                cout << "Are sure!!! You want to delete \" " << temp->proName << " \" \n";
                gotoxy(30, 15);
                cout << "[Enter]";
                gotoxy(60, 15);
                cout << "[Cancel]";
            inputagain:
                char input = getch();
                if (input == 8)
                {
                    gotoxy(30, 17);
                    cout << "You have canceled Deletion of \" " << temp->proName << " \" \n";
                    for (int i = 3; i >= 0; i--)
                    {
                        Sleep(500);
                        gotoxy(45, 20);
                        cout << "===" << i << "===";
                        Sleep(500);
                        gotoxy(45, 20);
                        cout << "---" << " " << "---";
                    }
                    system("cls");
                    return;
                }
                else if (input == 13)
                {
                    break;
                }
                else 
                {
                    goto inputagain;
                }
            }
            temp = temp->next;
        }
        if (!idExist)
        {
            gotoxy(30, 17);
            cout << "Product ID \" " << id << " \" is Not Found\n";
        }
        temp = head;
        if (head->proId == id)
        {
            gotoxy(25, 17);
            cout << "Product \" " << head->proName << " \" is deleted Successfully\n";
            head = head->next;
            delete temp;
        }
        else
        {
            while (temp != nullptr)
            {
                if (temp->proId == id)
                {
                    gotoxy(25, 17);
                    cout << "Product \" " << temp->proName << " \" is deleted Successfully\n";
                    prev->next = temp->next;
                    delete temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
    saveAllProductToFile();
    loadProductFromFile();
    gotoxy(30, 21);
    system("pause");
    system("cls");
}


//==============================================================
//=========================File Handeling=======================
//==============================================================

void saveNewProductToFile(product *temp)
{
    ofstream file("p.csv", ios::app); //ios::app (append) to go to the last fo the file.
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else 
    {
        file << temp->proId << "," << temp->proName << "," << temp->proPrice << "," << temp->proNum << endl;
    }
    file.close();
}

void saveAllProductToFile()
{
    ofstream file("p.csv");
    if (!file.is_open())
    {
        cout << "File is unable to open.\n";
    }
    else 
    {
        if (file.tellp() == 0)
        {
            file << "ID,Name,Price,Quantity\n";
        }
        product *temp = head;
        while (temp != nullptr)
        {
            file << temp->proId << "," << temp->proName << "," << temp->proPrice << "," << temp->proNum << endl;
            temp = temp->next;
        }
    }
    file.close();
}

void loadProductFromFile()
{
    deleteList();
    ifstream file("p.csv");
    if (!file.is_open())
    {
        cout << "Unable to open File.\n";
    }
    else 
    {
        string line;
        bool headerskipped = false;
        while (getline(file, line))
        {
            if (!headerskipped)
            {
                headerskipped = true;
                continue;
            }
            istringstream ss(line);
            string sid, sname, sprice, snum;
            if (getline(ss, sid, ',') && getline(ss, sname, ',') && getline(ss, sprice, ',') && getline(ss, snum))
            {
                int iid, inum;
                double dprice;
                istringstream(sid) >> iid;          //Convert string to integer
                istringstream(sprice) >> dprice;    //Convert string to double
                istringstream(snum) >> inum;        //Convert string to integer

                product *newNode = new product{iid, sname, dprice, inum, nullptr};
                if (!head)
                {
                    head = newNode;
                }
                else 
                {
                    product *temp = head;
                    while (temp->next)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
        }
    }
    file.close();
}

#endif