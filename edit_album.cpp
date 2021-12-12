#include "header.h"
//do something about return of called functions
bool albumEditor(const char artistIds[][8], const char artistNames[][40], int nArtist, char artistIdsRef[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datesPublished[][11], char paths[][100], int &nAlbum)
{
    int choice;
    bool check;

    while(true)
    {
        choice = editAlbumMenu();
        if (choice == 1)
            check = addAlbum(artistIds, artistNames, nArtist, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nAlbum);
        /*else if (choice == 2)
            editAlbum(artistIds, names, genders, phones, emails, nArtist);
        else if (choice == 3)
            deleteAlbum(artistIds, names, genders, phones, emails, artistIdsRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
        */
        else if (choice == 4)
            return false;
        else if (choice == 5)
            break;
        else
        {
            cout << "  Invalid choice.\n  ";
            system("pause");
        }
    }
    return true;
}

int editAlbumMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  Edit Album Menu\n" << "\t1. Add Album\n\t2. Edit Album\n\t3. Delete Album\n\t4. Back to Album Menu\n\t5. Exit\n";
    cout << " >> ";
    cin >> choice;
    return choice;
}

bool addAlbum(const char artistIds[][8], const char artistNames[][40], int nArtist, char artistIdsRef[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datesPublished[][11], char paths[][100], int &nAlbum)
{
    char title[80], datePublished[11], recordFormat[20], path[100], postfix[4], albid[8] = "alb-";
    char genders[100] = "-", phones[100][11] = {"----------"}, emails[100][80] = {"---------------------"};
    int select, noResult = 0, result[1000];


    lastAlbumId++;
    itoa(lastAlbumId, postfix, 10);
    strcat(albid, postfix);

    getAlbumInfo(title, recordFormat, datePublished, path);
    searchArtist(artistIds, artistNames, nArtist, result, &noResult);

    if (noResult == 0)
    {
        cout << "\n Nothing found.\n";
        getch();
        return false;
    }
    select = selectArtist(artistIds, artistNames, genders, phones, emails, nArtist, result, noResult, 0);
    strcpy(artistIdsRef[nAlbum], artistIds[select]);
    strcpy(titles[nAlbum], title);
    strcpy(albumIds[nAlbum], albid);
    strcpy(datesPublished[nAlbum], datePublished);
    strcpy(recordFormats[nAlbum], recordFormat);
    strcpy(paths[nAlbum], path);
    nAlbum++;
    sortAlbum(artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nAlbum);

    return true;
}

void getAlbumInfo (char title[], char recordFormat[], char datePublished[], char path[]) {
    getAlbumTitle(title);
    getAlbumRecordFormat(recordFormat);
    getAlbumDate(datePublished);
    getAlbumPath(path);
}

void getAlbumTitle (char title[]) {
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter Album Name: ";
    cin.ignore();
    cin.getline(title, 79, '\n');
    if (!(validateAlbumTitle(title)))
    {
        cout << "\n\tInvalid Title.\n";
        getch();
    }
    }while(!(validateAlbumTitle(title)));
    formatAlbumTitle(title);
}

void getAlbumRecordFormat(char albumFormat[]) {
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter the Album Format at release (CD or Digital): ";
    //cin.ignore();
    cin.getline(albumFormat, 19, '\n');
    if (!(validateAlbumFormat(albumFormat)))
    {
        cout << "\n\tInvalid Format.\n";
        getch();
    }
    }while(!(validateAlbumFormat(albumFormat)));
    formatAlbumFormat(albumFormat);
}

void getAlbumDate (char albumDate[]) {
    unsigned int day, month, year;
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter the date of release (Day): ";
    //cin.ignore();
    cin >> day;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter the date of release (Month): ";
    cin >> month;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter the date of release (Year): ";
    cin >> year;
    if (!(validateAlbumDate(day, month, year)))
    {
        cout << "\n\tInvalid Date.\n";
        getch();
    }
    }while(!(validateAlbumDate(day, month, year)));
    formatAlbumDate(albumDate, day, month, year);
}

void getAlbumPath (char albumPath[]) {
    //Version 3
}

bool validateAlbumTitle (const char albumTitle[]) {
    int i;
    if (strlen(albumTitle) < 2)
        return false;
    while(albumTitle[i] != '\0')
    {
        if (albumTitle[i] == ' ')
            {
				i++;
				continue;
			}
        else if ((albumTitle[i] < 'A' || albumTitle[i] > 'Z') && (albumTitle[i] < 'a' || albumTitle[i] > 'z'))
            return false;
        i++;
    }
    return true;
}

void formatAlbumTitle (char albumTitle[]) {
    int i = 0;

    strlwr(albumTitle);
    albumTitle[0] = albumTitle[0] - 32;
    while(albumTitle[i] != '\0')
    {
        if (albumTitle[i] == ' ' && albumTitle[i + 1] != '\0')
            albumTitle[i + 1] = albumTitle[i + 1] - 32;
        i++;
    }
}

bool validateAlbumFormat (char albumFormat[]) {//Parameter is const in pdf but strlwr has to be called to compare with only two possible inputs
    strlwr(albumFormat);
    if ((strcmp(albumFormat, "cd") == 0) || (strcmp(albumFormat, "digital") == 0)) {
        return true;
    }
    return false;
}

void formatAlbumFormat(char albumFormat[]) {//Something's wrong here
    if (strcmp(albumFormat, "cd") == 0) {
        albumFormat = "CD";
    }
    else {
        albumFormat = "Digital";
    }
}

bool validateAlbumDate(unsigned int day, unsigned int month, unsigned int year) {
    if ((month > 12) || (month = 0) || (year == 0) || (day == 0)) {
        return false;
    }
    if (year > 2021) {
        return false;
    }
    if ((year <= 1900) && (year >= 100)) {
        return false;
    }
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if (day > 30) {
            return false;
        }
    }
    else if ((month == 2) && ((day > 29))) {
        return false;
    }
    else if (day > 31) {
        return false;
    }
    return true;
}

void formatAlbumDate(char albumDate[], unsigned int day, unsigned int month, unsigned int year) {
    char daystr[10], monthstr[10], yearstr[10], slash[10] = "/";
    itoa(day, daystr, 10);
    itoa(month, monthstr, 10);
    if (year < 100) {
        if (year > 21) {
            year += 1900;
        } else {
            year += 2000;
        }
    }
    itoa(year, yearstr, 10);
    strcat(albumDate, daystr);
    strcat(albumDate, slash);
    strcat(albumDate, monthstr);
    strcat(albumDate, slash);
    strcat(albumDate, yearstr);
}

bool validateAlbumPath(const char albumPath[]) {
    return true;
    //Version 3
}

void formatAlbumPath(char albumFormat[]) {
    //Version 3
}

void editAlbum(const char artistIds[][8], const char artistNames[][40], int nArtist, char artistIdsRef[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datesPublished[][11], char paths[][100], int nAlbum){
    int noResult = 0, result[1000], selectArt, selectAlb;
    char genders[100] = {"-"}, phones[100][11] = {"---------"}, emails[100][80] = {"--------------"};

    searchArtist(artistIds, artistNames, nArtist, result, &noResult);
    if (noResult == 0)
    {
        cout << "\n Nothing found.\n";
        getch();
    }
    else
    {
        selectArt = selectArtist(artistIds, artistNames, genders, phones, emails, nArtist, result, noResult, 0);//forWhat is the last var. Dont know what to do with it.
        //selectAlb = selectAlbum(artistIds, artistNames, artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, result, noResult, forWhat)
        editAlbumInfo(artistIdsRef[selectAlb], albumIds[selectAlb], titles[selectAlb], recordFormats[selectAlb], datesPublished[selectAlb], paths[selectAlb]);
        sortAlbum(artistIdsRef, albumIds, titles, recordFormats, datesPublished, paths, nAlbum);
    }
}

void selectAlbum(const char artistId[], const char artistName[], const char artistIdsRef[][8], const char albumIds[][8], const char titles[][80], const char recordFormats[][20], const char datesPublished[][11], const char paths[][100], const int result[], int noResult, int forWhat ) {

}

bool editAlbumInfo(const char artistIdsRef[], const char albumIds[], char titles[], char recordFormats[], char datesPublished[], char paths[]) {
    return true;
}


