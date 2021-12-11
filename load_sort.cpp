#include "header.h"
char nammes[6][40] = {"Teddy Afro", "Aster Aweke", "Eyob", "GIGI", "Rophnan", "GIGI"};
char gemders[6] = {'M', 'F', 'M', 'F', 'M', 'F'};
char artids[6][8] = {"art-101", "art-102", "art-103", "art-104", "art-105", "art-106"};
char phomes[6][11] = {"0912345678", "0987654321", "0976347678", "0926463639", "0932547698", "0978563412"};
char emmails[6][80] = {"teddy.afro@newmail.com", "aster.aweke@newmail.com", "eyob.artist@newmail.com", "gigi.shibabaw@newmail.com", "rophnan.sost@newmail.com", "ejigayehu.desalegn@newmail.com"};

void loading(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum)
{
    system("cls");
    cout << "\n\t Album Management System\n\n" << "\tLoading Please Wait...\n\n";
    loadArtist(artistIds, names, genders, phones, emails, nArtist);
    loadAlbum(artistIdRefs, albumIds, titles, recordFormats, datePublished, paths, nAlbum);
    return;
}
void loadArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int & nArtist)
{
    for(int i = 0; i < 6; i++)
    {
        strcpy(artistIds[i], artids[i]);
        strcpy(names[i],nammes[i]);
        genders[i] = gemders[i];
        strcpy(phones[i],phomes[i]);
        strcpy(emails[i],emmails[i]);
        nArtist++;
    }
    sortArtist(artistIds, names, genders, phones, emails, nArtist);
    return;
}
void sortArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int nArtist)
{
    int start;
    char tempid[8], tempname[40], tempgen, tempphone[11], tempmail[80];
    //selection sort algorithm

    if (nArtist < 2)
        return;
    for (int i = 0; i < nArtist; i++)
    {
        start = i;
        for (int j = i + 1; j < nArtist; j++)
        {
            int test = 0;
            while(true)
            {
                if (names[j][test] == names[start][test])
                {
                    test++;
                    continue;
                }
                else if (names[j][test] < names[start][test])
                    start = j;
                break;
            }
        }
        if (start != i)
        {
            //sort names
            strcpy(tempname, names[start]);
            strcpy(names[start], names[i]);
            strcpy(names[i], tempname);
            //affect ids
            strcpy(tempid, artistIds[start]);
            strcpy(artistIds[start], artistIds[i]);
            strcpy(artistIds[i], tempid);
            //affect genders
            tempgen = genders[start];
            genders[start] = genders[i];
            genders[i] = tempgen;
            //affect phones
            strcpy(tempphone, phones[start]);
            strcpy(phones[start], phones[i]);
            strcpy(phones[i], tempphone);
            //affect emails
            strcpy(tempmail, emails[start]);
            strcpy(emails[start], emails[i]);
            strcpy(emails[i], tempmail);            
        }
    }
}
//load and sort album not implemented yet
void loadAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nAlbum)
{
    sortAlbum(artistIdRefs, albumIds, titles, recordFormats, datePublished, paths, nAlbum);
    return;
}
void sortAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int nAlbum)
{
    return;
}
