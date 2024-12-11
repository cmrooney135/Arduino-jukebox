#ifndef MUSIC_DATA_H
#define MUSIC_DATA_H
 
#include <avr/pgmspace.h> // Required for PROGMEM
 
// Structure to store song information
struct Song {
    uint8_t index;
    const char* name;
    const char* album;
    const char* artist;
    const char* year;
};
 
// Song Data in PROGMEM
const char name_0[] PROGMEM = "A Horse with No Name";
const char album_0[] PROGMEM = "America";
const char artist_0[] PROGMEM = "America";
const char year_0[] PROGMEM = "1971";
 
const char name_1[] PROGMEM = "Baba O'Riley";
const char album_1[] PROGMEM = "Who's Next";
const char artist_1[] PROGMEM = "The Who";
const char year_1[] PROGMEM = "1971";
 
const char name_2[] PROGMEM = "Blackbird";
const char album_2[] PROGMEM = "Blackbird";
const char artist_2[] PROGMEM = "The Beatles";
const char year_2[] PROGMEM = "1968";
 
const char name_3[] PROGMEM = "Blues Run the Game";
const char album_3[] PROGMEM = "Outtakes";
const char artist_3[] PROGMEM = "Simon & Garfunkel";
const char year_3[] PROGMEM = "1965";
 
const char name_4[] PROGMEM = "Brandy";
const char album_4[] PROGMEM = "Looking Glass";
const char artist_4[] PROGMEM = "Looking Glass";
const char year_4[] PROGMEM = "1972";
 
const char name_5[] PROGMEM = "Bridge Over Troubled Water";
const char album_5[] PROGMEM = "Bridge Over Troubled Water";
const char artist_5[] PROGMEM = "Simon & Garfunkel";
const char year_5[] PROGMEM = "1969";
 
const char name_6[] PROGMEM = "Does Your Mother Know";
const char album_6[] PROGMEM = "Voulez Vous";
const char artist_6[] PROGMEM = "ABBA";
const char year_6[] PROGMEM = "1979";
 
 const char name_7[] PROGMEM = "Don't Worry Baby";
const char album_7[] PROGMEM = "Shut Down Vol 2";
const char artist_7[] PROGMEM = "The Beach Boys";
const char year_7[] PROGMEM = "1964";
 
const char name_8[] PROGMEM = "Dreams";
const char album_8[] PROGMEM = "Rumors";
const char artist_8[] PROGMEM = "Fleetwood Mac";
const char year_8[] PROGMEM = "1977";
 
const char name_9[] PROGMEM = "Everybody Wants to Rule the World";
const char album_9[] PROGMEM = "Songs From the Big Chair";
const char artist_9[] PROGMEM = "Tears for Fears";
const char year_9[] PROGMEM = "1985";
 
const char name_10[] PROGMEM = "Girls on Film";
const char album_10[] PROGMEM = "Duran Duran";
const char artist_10[] PROGMEM = "Duran Duran";
const char year_10[] PROGMEM = "1981";
 
const char name_11[] PROGMEM = "Graceland";
const char album_11[] PROGMEM = "Graceland";
const char artist_11[] PROGMEM = "Paul Simon";
const char year_11[] PROGMEM = "1986";
 
const char name_12[] PROGMEM = "Harvest Moon";
const char album_12[] PROGMEM = "Harvest Moon";
const char artist_12[] PROGMEM = "Neil Young";
const char year_12[] PROGMEM = "1992";
 
const char name_13[] PROGMEM = "In My Room";
const char album_13[] PROGMEM = "Surfer Girl";
const char artist_13[] PROGMEM = "The Beach Boys";
const char year_13[] PROGMEM = "1963";
 
const char name_14[] PROGMEM = "Linger";
const char album_14[] PROGMEM = "Everybody Else is Doing it So Why Cant We?";
const char artist_14[] PROGMEM = "The Cranberries";
const char year_14[] PROGMEM = "1993";
 
const char name_15[] PROGMEM = "Maneater";
const char album_15[] PROGMEM = "H2O";
const char artist_15[] PROGMEM = "Hall & Oates";
const char year_15[] PROGMEM = "1982";
 
const char name_16[] PROGMEM = "My Sweet Lord";
const char album_16[] PROGMEM = "All Things Must Pass";
const char artist_16[] PROGMEM = "George Harrison";
const char year_16[] PROGMEM = "1970";
 
const char name_17[] PROGMEM = "Norwegian Wood";
const char album_17[] PROGMEM = "Rubber Soul";
const char artist_17[] PROGMEM = "The Beatles";
const char year_17[] PROGMEM = "1965";
 
const char name_18[] PROGMEM = "Operator";
const char album_18[] PROGMEM = "You Don't Mess Around With Jim";
const char artist_18[] PROGMEM = "Jim Croce";
const char year_18[] PROGMEM = "1972";
 
const char name_19[] PROGMEM = "Ramble On";
const char album_19[] PROGMEM = "Led Zeppelin II";
const char artist_19[] PROGMEM = "Led Zeppelin";
const char year_19[] PROGMEM = "1969";
 
const char name_20[] PROGMEM = "Rikki Don't Lose That Number";
const char album_20[] PROGMEM = "Pretzel Logic";
const char artist_20[] PROGMEM = "Steely Dan";
const char year_20[] PROGMEM = "1974";
 
const char name_21[] PROGMEM = "Ring of Fire";
const char album_21[] PROGMEM = "The Best of Johnny Cash";
const char artist_21[] PROGMEM = "Johnny Cash";
const char year_21[] PROGMEM = "1963";
 
const char name_22[] PROGMEM = "Running Up That Hill";
const char album_22[] PROGMEM = "Hounds of Love";
const char artist_22[] PROGMEM = "Kate Bush";
const char year_22[] PROGMEM = "1985";
 
const char name_23[] PROGMEM = "Smooth Operator";
const char album_23[] PROGMEM = "Diamond Life";
const char artist_23[] PROGMEM = "Sade";
const char year_23[] PROGMEM = "1984";
 
const char name_24[] PROGMEM = "Stairway to Heaven";
const char album_24[] PROGMEM = "Led Zeppelin IV";
const char artist_24[] PROGMEM = "Led Zeppelin";
const char year_24[] PROGMEM = "1971";
 
const char name_25[] PROGMEM = "Still Crazy After All These Years";
const char album_25[] PROGMEM = "Still Crazy After All These Years";
const char artist_25[] PROGMEM = "Paul Simon";
const char year_25[] PROGMEM = "1975";
 
const char name_26[] PROGMEM = "Subterranean Homesick Blues";
const char album_26[] PROGMEM = "Bringing it all Back Home";
const char artist_26[] PROGMEM = "Bob Dylan";
const char year_26[] PROGMEM = "1965";
 
const char name_27[] PROGMEM = "Tainted Love";
const char album_27[] PROGMEM = "Nonstop Erotic Cabaret";
const char artist_27[] PROGMEM = "Soft Cell";
const char year_27[] PROGMEM = "1981";
 
const char name_28[] PROGMEM = "Take Me Home Country Roads";
const char album_28[] PROGMEM = "Poems Prayers & Promises";
const char artist_28[] PROGMEM = "John Denver";
const char year_28[] PROGMEM = "1971";
 
const char name_29[] PROGMEM = "The Boxer";
const char album_29[] PROGMEM = "Bridge Over Troubled Water";
const char artist_29[] PROGMEM = "Simon & Garfunkel";
const char year_29[] PROGMEM = "1969";
 
const char name_30[] PROGMEM = "Till There Was You";
const char album_30[] PROGMEM = "With the Beatles";
const char artist_30[] PROGMEM = "The Beatles";
const char year_30[] PROGMEM = "1963";
 
const char name_31[] PROGMEM = "Tiny Dancer";
const char album_31[] PROGMEM = "Madman Across the Water";
const char artist_31[] PROGMEM = "Elton John";
const char year_31[] PROGMEM = "1971";
 
const char name_32[] PROGMEM = "Ventura Highway";
const char album_32[] PROGMEM = "Homecoming";
const char artist_32[] PROGMEM = "America";
const char year_32[] PROGMEM = "1972";
 
const char name_33[] PROGMEM = "Yellow Submarine";
const char album_33[] PROGMEM = "Yellow Submarine";
const char artist_33[] PROGMEM = "The Beatles";
const char year_33[] PROGMEM = "1968";
 
const char name_34[] PROGMEM = "You're So Vain";
const char album_34[] PROGMEM = "No Secrets";
const char artist_34[] PROGMEM = "Carly Simon";
const char year_34[] PROGMEM = "1972";
 
const char name_35[] PROGMEM = "Zombie";
const char album_35[] PROGMEM = "No Need to Argue";
const char artist_35[] PROGMEM = "The Cranberries";
const char year_35[] PROGMEM = "1994";
 
// Array of Song structures stored in PROGMEM
const Song musicLibrary[] PROGMEM = {
    {0, name_0, album_0, artist_0, year_0},
    {1, name_1, album_1, artist_1, year_1},
    {2, name_2, album_2, artist_2, year_2},
    {3, name_3, album_3, artist_3, year_3},
    {4, name_4, album_4, artist_4, year_4},
    {5, name_5, album_5, artist_5, year_5},
    {6, name_6, album_6, artist_6, year_6},
    {7, name_7, album_7, artist_7, year_7},
    {8, name_8, album_8, artist_8, year_8},
    {9, name_9, album_9, artist_9, year_9},
    {10, name_10, album_10, artist_10, year_10},
    {11, name_11, album_11, artist_11, year_11},
    {12, name_12, album_12, artist_12, year_12},
    {13, name_13, album_13, artist_13, year_13},
    {14, name_14, album_14, artist_14, year_14},
    {15, name_15, album_15, artist_15, year_15},
    {16, name_16, album_16, artist_16, year_16},
    {17, name_17, album_17, artist_17, year_17},
    {18, name_18, album_18, artist_18, year_18},
    {19, name_19, album_19, artist_19, year_19},
    {20, name_20, album_20, artist_20, year_20},
    {21, name_21, album_21, artist_21, year_21},
    {22, name_22, album_22, artist_22, year_22},
    {23, name_23, album_23, artist_23, year_23},
    {24, name_24, album_24, artist_24, year_24},
    {25, name_25, album_25, artist_25, year_25},
    {26, name_26, album_26, artist_26, year_26},
    {27, name_27, album_27, artist_27, year_27},
    {28, name_28, album_28, artist_28, year_28},
    {29, name_29, album_29, artist_29, year_29},
    {30, name_30, album_30, artist_30, year_30},
    {31, name_31, album_31, artist_31, year_31},
    {32, name_32, album_32, artist_32, year_32},
    {33, name_33, album_33, artist_33, year_33},
    {34, name_34, album_34, artist_34, year_34},
    {35, name_35, album_35, artist_35, year_35},
};
 
// Total number of songs in the library
const uint8_t musicLibrarySize = sizeof(musicLibrary) / sizeof(musicLibrary[0]);
 
#endif // MUSIC_DATA_H
