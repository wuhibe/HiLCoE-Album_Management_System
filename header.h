#ifndef HEADER_H
#define HEADER_H

static int lastArtistId = 106, lastAlbumId;

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
using namespace std;

void welcome();
void loading(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100],int & nArtist, int & nAlbum);
void loadArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int & nArtist);
void sortArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int nArtist);
void sortAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int nAlbum);
void loadAlbum(char artistIdRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nAlbum);
void mainHandler(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum);
int mainMenu();
bool artistManager(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum);
int artistMenu();
bool artistViewer(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist);
int viewArtistMenu();
void displayAllArtist(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist);
void viewArtistBySearch(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist);
void searchArtist(const char artistIds[][8], const char names[][40], int nArtist, int result[], int * noResult);
void searchArtistById(const char artistIds[][8], int nArtist, const char targetId[], int result[], int * noResult);
void searchArtistByName(const char names[][40], int nArtist, const char targetName[], int result[], int * noResult);
void displaySearchResult(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist, const int result[], int noResult);
bool artistEditor(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum);
int editArtistMenu();
bool addArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int & nArtist);
void getArtistInfo(char name[], char & gender, char phones[], char emails[]);
void getArtistName(char name[]);
char getArtistGender();
void getArtistPhone(char phone[]);
void getArtistEmail(char email[]);
bool validateName(const char name[]);
void formatName(char name[]);
bool validateGender(char gender);
bool validatePhone(const char phone[]);
bool validateEmail(const char email[]);
void formatEmail(char email[]);
void editArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], int nArtist);
int selectArtist(const char artistIds[][8], const char names[][40], const char genders[], const char phones[][11], const char emails[][80], int nArtist, const int result[], int noResult, int forWhat);
bool editArtistInfo(const char artistId[], char name[], char gender, char phone[], char email[]);
void displayOneArtist(const char artistId[], const char name[], char gender, const char phone[], const char email[]);
void deleteArtist(char artistIds[][8], char names[][40], char genders[], char phones[][11], char emails[][80], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nArtist, int & nAlbum);
void removeArtist(char artistId[][8], char name[][40],  char genders[], char phone[][11], char email[][80], int selectedIdx, int & nArtist);
void removeArtistAllAlbums(const char artistId[], char artistIdsRefs[][8], char albumIds[][8], char titles[][80], char recordFormats[][20], char datePublished[][11], char paths[][100], int & nAlbum);

void farewell();
#endif