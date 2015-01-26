/*

David Walker
Comp-1108 Project 1

*/

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

void openDataFile( ifstream& gradeDataFile );
void getNames( ifstream& gradeDataFile, char studentNames[][20] );
float avgGrades( ifstream& gradeDataFile );

int main(void)
{
    ifstream gradeDataFile( "grades.dat" );
    char studentNames[12][20] = {0};

    openDataFile( gradeDataFile );
    getNames( gradeDataFile, studentNames );
    
    for( int i = 0; i < 6; i++ )
    {
        cout << fixed << setprecision(2) << studentNames[i*2] << ", " << studentNames[i*2+1] << '\t' << avgGrades(gradeDataFile) << endl;
    }
    
    gradeDataFile.close();
}

void openDataFile( ifstream& gradeDataFile )
{
    if( gradeDataFile.fail() )
    {
        cout << "Error opening file." << endl;
        exit( 1 );
    }
}

void getNames( ifstream& gradeDataFile, char studentNames[][20] )
{    
    int arraySlot = 0;
    
    while( arraySlot < 13 )
    {
        gradeDataFile >> studentNames[arraySlot];
        arraySlot++;
    }
}

float avgGrades( ifstream& gradeDataFile )
{    
    float gradesAvg;
    float g1,g2,g3,g4,g5,g6 = 0;
    
    gradeDataFile >> g1 >> g2 >> g3 >> g4 >> g5 >> g6;
    gradesAvg = (g1+g2+g3+g4+g5+g6)/6;
    
    return gradesAvg;
}