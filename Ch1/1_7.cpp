/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}

/*******************************************************
 * 1_7.cpp:3:3: error: empty character constant
 * ''cannot nest'' is considered source code,
 *  ^~~~~~~~
 * 1_7.cpp:3:16: error: empty character constant
 * * ''cannot nest'' is considered source code,
 *                ^~
 * 1_7.cpp:2:23: error: ‘cannot’ does not name a type
 * * comment pairs /*  cannot nest.
 */