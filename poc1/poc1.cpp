#include <iostream>

#define WIDTH2D 10
#define HEIGHT2D 5

#define WIDTH3D 8
#define HEIGHT3D 10
#define DEPTH3D 15

void initArrays( int PsuedoArray2[], int Array2[][ WIDTH2D ], int PsuedoArray3[], int Array3[][ HEIGHT3D ][ WIDTH3D ] );
void debugArrays( int PsuedoArray2[], int Array2[][ WIDTH2D ], int PsuedoArray3[], int Array3[][ HEIGHT3D ][ WIDTH3D ] );

void get2dElement(int height, int width, int PsuedoArray2[], int Array2[][ WIDTH2D ]);
void get3dElement(int depth, int height, int width, int PsuedoArray3[], int Array3[][ HEIGHT3D ][ WIDTH3D ]);

using namespace std;

int main()
{
 int PsuedoArray2[ HEIGHT2D * WIDTH2D ];
 int Array2[ HEIGHT2D ][ WIDTH2D ];
 
 int PsuedoArray3[ DEPTH3D * HEIGHT3D * WIDTH3D ];
 int Array3[ DEPTH3D ][ HEIGHT3D ][ WIDTH3D ];
 
 int width;
 int height;
 int depth;
 
 initArrays(PsuedoArray2, Array2, PsuedoArray3, Array3);
 
 width, height, depth = 0;
 cout<<"2d array element to check: ( ex: 0 1 will return 10)";
 cin>>width>>height;
 get2dElement(height, width, PsuedoArray2, Array2);
 
 width, height, depth = 0;
 cout<<"3d array element to check: ( ex: 0 0 1 will return 8 )";
 cin>>depth>>width>>height;
 get3dElement(depth, height, width, PsuedoArray3, Array3);
 
}

void initArrays( int PsuedoArray2[], int Array2[][ WIDTH2D ], int PsuedoArray3[], int Array3[][ HEIGHT3D ][ WIDTH3D ] )
{
 int count2d = 0;
 int count3d = 0;
 
 for( int i = 0; i < HEIGHT2D; i++ )
 {
  for( int j = 0; j < WIDTH2D; j++)
  {
   PsuedoArray2[WIDTH2D*i+j] = count2d;
   Array2[i][j] = count2d;
   
   count2d++;
  }
 }
 
 for( int i = 0; i < DEPTH3D; i++ )
 {
  for( int j = 0; j < HEIGHT3D; j++)
  {
   for( int k = 0; k < WIDTH3D; k++)
   {
    PsuedoArray3[i * WIDTH3D * HEIGHT3D + j * WIDTH3D + k] = count3d;
    Array3[i][j][k] = count3d;
   
    count3d++;
   }
  }
 }
}

void get2dElement(int height, int width, int PsuedoArray2[], int Array2[][ WIDTH2D ])
{
	cout << "Psuedo 2d Array Result: "<<PsuedoArray2[WIDTH2D*height+width]<<endl;
    cout << "Real 2d Array Result: "<<Array2[height][width]<<endl;
}

void get3dElement(int depth, int height, int width, int PsuedoArray3[], int Array3[][ HEIGHT3D ][ WIDTH3D ])
{
	cout << "Psuedo 3d Array Result: "<<PsuedoArray3[depth * WIDTH3D * HEIGHT3D + height * WIDTH3D + width]<<endl;
    cout << "Real 3d Array Result: "<<Array3[depth][height][width]<<endl;
}
