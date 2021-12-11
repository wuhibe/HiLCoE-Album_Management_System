#include "header.h"
//do something about return of called functions
bool artistEditor(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum)
{
    int choice;
    bool check;

    while(true)
    {
        choice = editArtistMenu();
        if (choice == 1)
            check = addArtist(artistIds, names, genders, phones, emails, nArtist);
        else if (choice == 2)
            editArtist(artistIds, names, genders, phones, emails, nArtist);
        else if (choice == 3)
            deleteArtist(artistIds, names, genders, phones, emails, artistIdsRefs, albumIds, titles, recordFormats, datePublished, paths, nArtist, nAlbum);
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
//Check Edit Artist Menu - same issue in View artist Menu
int editArtistMenu()
{
    int choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    << "  Edit Artist Menu\n" << "\t1. Add Artist\n\t2. Edit Artist\n\t3. Delete Artist\n\t4. Back to Artist Menu\n\t5. Exit\n";
    cout << " >> ";
    //Back to previous menu NOT main menu
    cin >> choice;
    return choice;
}
//check return value
bool addArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int & nArtist)
{
    char name[40], gender, phone[11], email[80], postfix[4], artid[8] = "art-";

    lastArtistId++;
    itoa(lastArtistId, postfix, 10);
    strcat(artid, postfix);

    getArtistInfo(name, gender, phone, email);

    strcpy(names[nArtist], name);
    genders[nArtist] = gender;
    strcpy(phones[nArtist], phone);
    strcpy(emails[nArtist], email);
    strcpy(artistIds[nArtist], artid);
    nArtist++;
    sortArtist(artistIds, names, genders, phones, emails, nArtist);

    return true;
}
void getArtistInfo(char name[], char & gender, char phone[], char email[])
{
    getArtistName(name);
    gender = getArtistGender();
    getArtistPhone(phone);
    getArtistEmail(email);
}
void getArtistName(char name[])
{
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter Artist Name: ";
    cin.ignore();
    cin.getline(name, 39, '\n');
    if (!(validateName(name)))
    {
        cout << "\n\tInvalid Name.\n";
        getch();
    }
    }while(!(validateName(name)));
    formatName(name);
}
char getArtistGender()
{
    char gen;
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter Artist Gender: ";
    cin >> gen;
    if (!(validateGender(gen)))
    {
        cout << "\n\tInvalid Gender.\n";
        getch();
    }
	if (gen == 'm' || gen == 'f')
		gen = gen - 32;
    }while(!(validateGender(gen)));
    return gen;
}
void getArtistPhone(char phone[])
{
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter Artist Phone: ";
    cin >> phone;
    if (!(validatePhone(phone)))
    {
        cout << "\n\tInvalid Phone.\n";
        getch();
    }
    }while(!(validatePhone(phone)));
}
void getArtistEmail(char email[])
{
    do{
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Enter Artist Email: ";
    cin >> email;
    if (!(validateEmail(email)))
    {
        cout << "\n\tInvalid Email.\n";
        getch();
    }
    }while(!(validateEmail(email)));
}
bool validateName(const char name[])
{
    int i;
    if (strlen(name) < 2)
        return false;
    while(name[i] != '\0')
    {
        if (name[i] == ' ')
            {
				i++;
				continue;
			}
        else if ((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z'))
            return false;
        i++;
    }
    return true;
}
//Not implemented enough
void formatName(char name[])
{
    int i = 0;

    strlwr(name);
    name[0] = name[0] - 32;
    while(name[i] != '\0')
    {
        if (name[i] == ' ' && name[i + 1] != '\0')
            name[i + 1] = name[i + 1] - 32;
        i++;
    }
}
bool validateGender(char gender)
{
    switch (gender)
    {
    case 'm':
    case 'M':
    case 'F':
    case 'f':
        return true;
        break;
    default:
        return false;
        break;
    }
}
bool validatePhone(const char phone[])
{
    int i;
    while(phone[i] != '\0')
    {
        if (phone[i] < '0' || phone[i] > '9')
            return false;
        i++;
    }
    if (i != 10)
        return false;
    return true;
}
//***Find better way***
bool validateEmail(const char email[])
{
    int i;
    while(email[i] != '\0')
    {
        //Incomplete list and Implementation - I just gave up
        if ((email[i] < '0' || email[i] > '9') && (email[i] < 'A' || email[i] > 'Z') && (email[i] < 'a' || email[i] > 'z') &&
         email[i]!='@' && email[i] != '#' && email[i] != '.' && email[i] != '~' && email[i] != '-' && email[i] != '_')
            return false;
        i++;
    }
    return true;
}
//not yet implemented
void formatEmail(char email[])
{
    return;
}
//artistIds is a const * modified for convenience & forWhat(int) is unused variable
void editArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int nArtist)
{
    int noResult = 0, result[1000], select = 0;
    searchArtist(artistIds, names, nArtist, result, &noResult);
    if (noResult == 0)
    {
        cout << "\n Nothing found.\n";
        getch();
    }
    else
    {
        select = selectArtist(artistIds, names, genders, phones, emails, nArtist, result, noResult, 0);//forWhat is the last var. Dont know what to do with it.
        editArtistInfo(artistIds[select], names[select], genders[select], phones[select], emails[select]);
        sortArtist(artistIds, names, genders, phones, emails, nArtist);
    }
}
// IN Actual [declaration,definition, calling], there's no (gen, phones, emails, nartist) * added here for convenience
// Recheck once done
int selectArtist(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist, const int result[], int noResult, int forWhat)
{
    int choice;
    displaySearchResult(artistIds, names, genders, phones, emails, nArtist, result, noResult);
    do{
        cout << "Enter No of choice: ";
        cin >> choice;
        if (choice > noResult || choice < 1)
            cout << "\n  Invalid Choice. ";
    }while(choice > noResult || choice < 1);
    return result[choice - 1];
}
bool editArtistInfo(const char artistId[], char name[], char gender, char phone[], char email[])
{
    char choice;
    system("cls");
    cout << "\n\t Album Management System\n\n"
    <<  "  Do you wish to edit Name? [y/n] ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cout <<  "  Enter Artist Name: ";
        cin.ignore();
        cin.getline(name, 39, '\n');
    }
    cout << "  Do you wish to edit Gender? [y/n]";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cout <<  "  Enter Artist Gender: ";
        cin >> gender;
    }
    cout << "  Do you wish to edit Email? [y/n]";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cout <<  "  Enter Artist Email: ";
        cin >> email;
    }
    cout << "  Do you wish to edit Phone? [y/n]";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cout <<  "  Enter Artist Phone: ";
        cin >> phone;
    }
    return true;
}
//What is forWhat???
void deleteArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum)
{
    int result[1000], noResult, selectedId;
    searchArtist(artistIds, names, nArtist, result, &noResult);
    if (noResult == 0)
    {
        cout << "\n  Nothing found.\n";
        getch();
    }
    else if (noResult > 0)
    {
        selectedId = selectArtist(artistIds, names, genders, phones, emails, nArtist, result, noResult, 0);// what is forWhat
        removeArtist(artistIds, names, genders, phones, emails, selectedId, nArtist);//added genders
    }
}
//removeArtist didnt take genders parameter
void removeArtist(char artistId[][8], char name[][40], char genders[], char phone[][11], char email[][80], int selectedIdx, int & nArtist)
{
    int i = selectedIdx + 1;
    while(i < nArtist)
    {
        strcpy(name[i - 1], name[i]);
        strcpy(email[i - 1], email[i]);
        strcpy(phone[i - 1], phone[i]);
        strcpy(artistId[i - 1], artistId[i]);
        genders[i - 1] = genders[i];
        i++;
    }
    nArtist--;
}
//Not yet implemented
void removeArtistAllAlbums(const char artistId[], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nAlbum)
{
    return;
}
