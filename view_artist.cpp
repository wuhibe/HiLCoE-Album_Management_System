#include "header.h"
bool artistManager(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum)
{
    int choice;
    bool exit;

    while(true)
    {
        choice = artistMenu();
        if (choice == 1)
        {
            exit = artistViewer(artistIds, names, genders, phones, emails, nArtist);
            if (exit == true)
                break;
            else
                continue;    
        }
        else if (choice == 2)
        {
            exit = artistEditor(artistIds, names, genders, phones, emails, artistIdsRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
            if (exit == true)
                break;
            else
                continue;    
        }
        else if (choice == 3)
            return false;
        else if (choice == 4)
            break;
        else
        {
            cout << "  Invalid choice.\n  ";
            system("pause");
        }
    }
    return true;
}
int artistMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  Artist Menu:\n" << "\t1. View Artist\n\t2. Edit Artist\n\t3. Back to Main Menu\n\t4. Exit\n";
    cout << " >> ";
    cin >> choice;
    return choice;
}
bool artistViewer(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist)
{
    int choice;
    bool exit;

    while(true)
    {
        choice = viewArtistMenu();
        if (choice == 1)
            displayAllArtist(artistIds, names, genders, phones, emails, nArtist);
        else if (choice == 2)
            viewArtistBySearch(artistIds, names, genders, phones, emails, nArtist);
        else if (choice == 3)
            return false;
        else if (choice == 4)
            break;
        else
        {
            cout << "  Invalid choice.\n  ";
            system("pause");
        }
    }
    return true;
}
//Check View Artist Menu
int viewArtistMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  View Artist Menu\n" << "\t1. Display All Artist\n\t2. View Artist By Search\n\t3. Back to Artist Menu\n\t4. Exit\n";
    cout << " >> ";
    //Back to previous menu NOT main menu
    cin >> choice;
    return choice;
}
void displayAllArtist(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist)
{
    system("cls");
    cout << "\n\t Album Management System\n\n";
    cout << setw(9) <<"\nArtistID | "<< setw(30) << "Names" <<"  | Gender | " << setw(10) << "Phones" << " | Emails" << endl
        <<"******************************************************************************************\n";
        for (int i = 0; i < nArtist; i++)
        {
            cout << setw(8) << artistIds[i] << " | " << setw(30) << names[i] << "  |   " << genders[i] << "    | " << phones[i] << " |  " << emails[i] << endl;
        }
    cout << endl;
    system("pause");
    return;
}
void viewArtistBySearch(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist)
{
    int noResult = 0, result[1000];
    searchArtist(artistIds, names, nArtist, result, &noResult);
    displaySearchResult(artistIds, names, genders, phones, emails, nArtist, result, noResult);
    return;
}
void searchArtist(const char artistIds[][8], const char names[][40], int nArtist, int result[], int * noResult)
{
    char str[40];
    system("cls");
    cout << "\n\t Album Management System\n\n" << "  Enter Name or ID: ";
    cin.ignore();
    cin.getline(str, 39, '\n');
    if (str[0] >= '0' && str[0] <= '9')
        searchArtistById(artistIds, nArtist, str, result, noResult);
    else
        searchArtistByName(names, nArtist, str, result, noResult);
}
void searchArtistById(const char artistIds[][8], int nArtist, const char targetId[], int result[], int * noResult)
{
    int j = 0;
    char artid[8] = "art-";
    strcat(artid, targetId);
    for(int i = 0; i < nArtist; i++)
    {
        if (strcmp(artistIds[i], artid) == 0)
        {
            result[j] = i;
            *noResult += 1;
            j++;
        }
    }
    return;
}
void searchArtistByName(const char names[][40], int nArtist, const char targetName[], int result[], int * noResult)
{
    int j = 0;
    char namme[40], str[40];

    strcpy(str, targetName);
    for(int i = 0; i < nArtist; i++)
    {
        strcpy(namme, names[i]);
        if (strcmp(strlwr(namme), strlwr(str)) == 0)
        {
            result[j] = i;
            *noResult += 1;
            j++;
        }
    }
    return;
}
void displaySearchResult(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist, const int result[], int noResult)
{
    if (noResult == 0)
    {
        cout << "\n  Nothing Found.\n";
    }
    else
    {
        cout << setw(5) <<"\nNo |"<< setw(9) <<" ArtistID | "<< setw(30) << "Names" <<"  | Gender | " << setw(10) << "Phones" << " | Emails" << endl
        <<"******************************************************************************************\n";
        for (int i = 0; i < noResult; i++)
        {
            cout << setw(3) <<  i+1 << "|" << setw(9) << artistIds[result[i]] << " | " << setw(30) << names[result[i]] << "  |   " << genders[result[i]] << "    | " << phones[result[i]] << " |  " << emails[result[i]] << endl;
        }
    }
    cout << endl;
    system("pause");
}

