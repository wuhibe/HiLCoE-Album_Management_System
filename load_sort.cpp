#include "header.h"
char nammes[6][40] = {"Teddy Afro", "Aster Aweke", "Eyob", "GIGI", "Rophnan", "GIGI"};
char gemders[6] = {'M', 'F', 'M', 'F', 'M', 'F'};
char artids[6][8] = {"art-101", "art-102", "art-103", "art-104", "art-105", "art-106"};
char phomes[6][11] = {"0912345678", "0987654321", "0976347678", "0926463639", "0932547698", "0978563412"};
char emmails[6][80] = {"teddy.afro@newmail.com", "aster.aweke@newmail.com", "eyob.artist@newmail.com", "gigi.shibabaw@newmail.com", "rophnan.sost@newmail.com", "ejigayehu.desalegn@newmail.com"};

char albumids[8][8] = {"alb-101", "alb-102", "alb-103", "alb-104", "alb-105", "alb-106", "alb-107", "alb-108"};
char artistidrefs[8][8] = {"art-102", "art-101", "art-104", "art-101", "art-102", "art-103", "art-105", "art-106"};
char Titles[8][80] = {"Chewa", "Yasteseryal", "Tsehay", "Abugida", "Checheho", "Ende Kal", "Netsebrak", "Gigi"};
char recordformats[8][20] = {"CD", "Digital", "CD", "Digital", "CD", "Digital", "CD", "Digital"};//Random
char datespublished[8][11] = {"17/05/2005", "01/06/2001", "23/07/2011", "20/12/2010", "12/06/2008", "././1997", "13/07/2018", "././2001"};
char Paths[8][100] = {};//To be used on version 3

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

void loadAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nAlbum)
{
    for(int i = 0; i < 8; i++)
    {
        strcpy(albumIds[i], albumids[i]);
        strcpy(artistIdRefs[i], artistidrefs[i]);
        strcpy(titles[i], Titles[i]);
        strcpy(recordFormats[i], recordformats[i]);
        strcpy(datesPublished[i], datespublished[i]);
        strcpy(paths[i], Paths[i]);
        nAlbum++;
    }
    sortAlbum(artistIdRefs, albumIds, titles, recordFormats, datePublished, paths, nAlbum);
    return;
}
void sortAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int nAlbum)
{
    int start;
    char tempartid[8], tempalbid[8], temptitle[40], temprec[20], tempdate[11], temppath[80];
    if (nAlbum < 2)
        return;
    for (int i = 0; i < nAlbum; i++)
    {
        start = i;
        for (int j = i + 1; j < nAlbum; j++)
        {
            int test = 4;
            while(true)
            {
                if (artistIdRefs[j][test] == artistIdRefs[start][test])
                {
                    test++;
                    continue;
                }
                else if (artistIdRefs[j][test] < artistIdRefs[start][test])
                    start = j;
                break;
            }
        }
        if (start != i)
        {
            strcpy(tempartid, artistIdRefs[start]);
            strcpy(artistIdRefs[start], artistIdRefs[i]);
            strcpy(artistIdRefs[i], tempartid);

            strcpy(tempalbid, albumIds[start]);
            strcpy(albumIds[start], albumIds[i]);
            strcpy(albumIds[i], tempalbid);

            strcpy(temptitle, titles[start]);
            strcpy(titles[start], titles[i]);
            strcpy(titles[i], temptitle);

            strcpy(temprec, recordFormats[start]);
            strcpy(recordFormats[start], recordFormats[i]);
            strcpy(recordFormats[i], temprec);

            strcpy(tempdate, datePublished[start]);
            strcpy(datePublished[start], datePublished[i]);
            strcpy(datePublished[i], tempdate);

            strcpy(temppath, paths[start]);
            strcpy(paths[start], paths[i]);
            strcpy(paths[i], temppath);
        }
    }
    return;
}
