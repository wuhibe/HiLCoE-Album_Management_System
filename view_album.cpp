#include "header.h"
bool albumManager(const char artistIds[][8], const char artistNames[][40], int nArtist, char artistIdsRef[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datesPublished[][11], char paths[][100], int & nAlbum)
{
    int choice;
    bool exit;

    while(true)
    {
        choice = albumMenu();
        if (choice == 1)
        {
            exit = albumViewer(artistIds, artistNames, nArtist, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nAlbum);
            if (exit == true)
                break;
            else
                continue;
        }
        /*else if (choice == 2)
        {
            exit = albumEditor(artistIds, artistNames, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nAlbum);
            if (exit == true)
                break;
            else
                continue;
        }*/
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
int albumMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  Album Menu:\n" << "\t1. View Album\n\t2. Edit Album\n\t3. Back to Main Menu\n\t4. Exit\n";
    cout << " >> ";
    cin >> choice;
    return choice;
}
int viewAlbumMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  View Album Menu\n" << "\t1. Display All Albums\n\t2. Search Album by Artist\n\t3. Back to Album Menu\n\t4. Exit\n";
    cout << " >> ";
    cin >> choice;
    return choice;
}
bool albumViewer(const char artistIds[][8], const char artistNames[][40], int nArtist, const char artistIdsRef[][8], const char albumIds[][8], const char titles[][80], const char recordFormats[][20], const char datesPublished[][11], const char paths[][100], int nAlbum)
{
    int choice;
    bool exit;

    while(true)
    {
        choice = viewAlbumMenu();
        if (choice == 1)
            displayAllAlbums(artistIds, artistNames, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nArtist, nAlbum);
        else if (choice == 2)
            viewArtistAlbumsBySearch(artistIds, artistNames, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nArtist, nAlbum);
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

void displayAllAlbums(const char artistIds[][8], const char artistNames[][40], const char artistIdsRef[][8], const char albumIds[][8], const char titles[][80], const char recordFormats[][20], const char datesPublished[][11], const char paths[][100], int nArtist, int nAlbum)
{
    int nameindex = 0;
    system("cls");
    cout << "\n\t Album Management System\n\n";
    cout << setw(8) <<"\n AlbumID | "<< setw(20) << "Title" << setw(10) << "  | Artist Name   | " << setw(10) << "Artist ID" << setw(10) << " | Date published " << " | Format" << endl
        <<"******************************************************************************************\n";
        for (int i = 0; i < nAlbum; i++)
        {
            for (int j = 0; j < nArtist; j++) {
                if (strcmp(artistIdsRef[i],artistIds[j]) == 0){
                    nameindex = j;
                    break;
                }
            }
            cout << setw(8) << albumIds[i] << " | " << setw(20) << titles[i] << "  |   " <<  setw(10) << artistNames[nameindex] << "    | " << setw(10) << artistIds[nameindex] << "    |  " << setw(10) << datesPublished[i] << " |  " << recordFormats[i] << endl;
        }
    cout << endl;
    system("pause");
    return;
}

void viewArtistAlbumsBySearch(const char artistIds[][8], const char artistNames[][40], const char artistIdsRef[][8], const char albumIds[][8], const char titles[][80], const char recordFormats[][20], const char datesPublished[][11], const char paths[][100], int nArtist, int nAlbum)
{
    int noResult = 0, result[1000];

    searchArtist(artistIds, artistNames, nArtist, result, &noResult);
    displayAlbumSearchResult(artistIds, artistNames, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, result, nArtist, nAlbum, noResult);

    return;
}

void displayAlbumSearchResult(const char artistIds[][8], const char artistNames[][40], const char artistIdsRef[][8], const char albumIds[][8], const char titles[][80], const char recordFormats[][20], const char datesPublished[][11], const char paths[][100], const int result[], int nArtist, int nAlbum, int noResult)
{
    if (noResult == 0)
    {
        cout << "\n  Nothing Found !\n";
    }
    else
    {
        int nameindex;
        cout << setw(5) <<"\nNo |" << setw(9) <<" AlbumID | "<< setw(30) << "Title" << "  | Artist Name   | " << setw(10) << "Artist ID" << " | Date published " << " | Format" << endl
        <<"*******************************************************************************************************************************\n";
        for (int i = 0; i < noResult; i++)

        {
            for (int j = 0; j < nAlbum; j++) {
                if (strcmp(artistIdsRef[j],artistIds[result[i]]) == 0){

                    nameindex = j;
                    cout << setw(3) <<  i+1 << "|" << setw(9) << albumIds[nameindex] << " | " << setw(30) << titles[nameindex] << "  |   " << artistNames[result[i]] << "    | " << artistIds[result[i]] << " |  " << datesPublished[nameindex] << " |  " << recordFormats[nameindex] << endl;

                }
            }
        }
    }
    cout << endl;
    system("pause");
}
