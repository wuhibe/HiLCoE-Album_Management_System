#include "header.h"
//Test comment
//Second test
int main()
{
    char artistIds[1000][8], genders[1000], names[1000][40], phones[1000][11], emails[1000][80], artistIdRefs[1000][8], albumIds[1000][8], titles[1000][80], recordFormats[1000][20], datePublished[1000][11], paths[1000][100];
    int nArtist, nAlbum;
    
    welcome();
    loading(artistIds, names, genders, phones, emails, artistIdRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
    mainHandler(artistIds, names, genders, phones, emails, artistIdRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
    farewell();
    return 0;
}

void welcome()
{
    system("cls");
    cout << "\n\t Album Management System\n\n" << "\t\t WELCOME!!!\n\n\t";
    system("pause");
}

void mainHandler(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum)
{
    int choice;
    bool exit;

    while(true)
    {
        choice = mainMenu();
        if (choice == 1)
        {
            exit = artistManager(artistIds, names, genders, phones, emails, artistIdsRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
            if (exit == true)
                break;
            else
                continue;
        }
        else if (choice == 2)
        {
            cout << "hi";/*   Album Manager not implemented yet
            exit = albumManager();
            if (exit == true)
                break;
            else
                continue;*/
        }
        else if (choice == 3)
            break;
        else
        {
            cout << "  Invalid choice.\n  ";
            system("pause");
        }
    }
}
//Main menu
int mainMenu()
{
    int choice;

    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  Main Menu:\n" << "\t1. Manage Artist\n\t2. Manage Album\n\t3. Exit\n";
    cout << " >> ";
    cin >> choice;
    return choice;
}

void farewell()
{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "\t\t Goodbye!\n\n";
}
