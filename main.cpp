//Author : Hager Mosaad  20160272
//Purpose : practice on "operator overloading"



#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

struct maax
{
    int row , col ;
    int* num ;
};
istream& operator>>( istream& is , maax& m );      //for input

ostream& operator<< (ostream& os , maax& m );      //for output

maax& operator+ ( maax m1 , maax m2 );          //for adding two matrices if the same dimensions

maax& operator- ( maax m1 , maax m2 );          //for subtracting two matrices if the same dimensions

maax& operator* ( maax m1 , maax m2 );          //for multiplying two matrices if #col of max1 equal #rows of max2

maax& operator+ ( maax m1 , int n );             //for adding a scalar to the matrix

maax& operator- ( maax m1 , int n );             //for subtracting a scalar from the matrix

maax& operator* ( maax m1 , int n );             //for multiplying a scalar by the matrix

//___________________________________________________________________________________________


maax& operator+= ( maax& m1 , maax m2 );
//maax& operator-= ( maax m1 , maax m2 );
maax& operator+= ( maax& m1 , int n );
void operator++ (maax& m1);



int main()
{
    maax m1 , m2 ;

    cout<<endl<<"***************************hello********************************"<<endl<<endl;

    cin>> m1 >> m2 ;
    cout<<"------------------------------------------------"<<endl;
    cout << endl << "matrix__1 is:  " << m1 << endl;
    cout << endl << "matrix__2 is:  " << m2 << endl;
    int f =1;
    while ( f==1 )
    {
    cout<<"enter your choice : 1__add , 2__sub , 3__multiply , 4__Add a scalar , 5__Subtract a scalar"
    <<", 6__Multiple by scalar "<<
    " , 7__add m2 on m1 , 8__sub m2 from m1 , 9__add scalar to m1 , 11__increment m1"<<endl<<endl;
    int c ;
    cin>>c;

    if ( c == 1)
       {cout << endl << "matrix_1 plus matrix_2 is:  " << (m1+m2) << endl;}
    if ( c == 2)
       {cout << endl << "matrix_1 minus matrix_2 is:  " << (m1-m2) << endl;}
    if (c == 3)
       //cout << endl << "matrix_1 multiply matrix_2 is:  " << (m1*m2) << endl;
     if ( c == 4)
       {
        cout <<endl << "enter the number you want to add to matrix1"<<endl;
        int v ;
        cin>>v;
        cout <<endl << "matrix_1 plus "<< v <<" is:  " << (m1+v) << endl;
       }
     if ( c == 5)
       {
        cout <<endl << "enter the number you want to sub from matrix1"<<endl;
        int b ;
        cin>>b;
        cout <<endl << "matrix_1 minus "<< b <<" is:  " << (m1-b) << endl;
       }
       if ( c == 6)
       {
        cout <<endl << "enter the number you want to multiply by matrix1"<<endl;
        int t ;
        cin>>t;
        cout <<endl << "matrix_1 multiple by "<< t <<" is:  " << (m1*t) << endl;
       }
       if ( c == 7)
       {cout << endl << "matrix_1 plus matrix_2 is:  " << (m1+=m2) << endl;}
       /*if ( c == 8)
       {cout << endl << "matrix_1 sub matrix_2 is:  " << (m1-=m2) << endl;}*/

       if ( c == 9)
       {cout <<endl << "enter the number you want to add to matrix1"<<endl;
        int g ;
        cin>>g;
        cout << endl << "matrix_1 plus matrix_2 is:  " << (m1+=g) << endl;}
       if ( c == 11)
       {cout << endl << "matrix_1 ++ is:  " << ++m1 << endl;}

        cout<<"enter 1 to continue "<<endl<<endl;
        cin>>f;

       }

     return 0;
}

//for input

istream& operator >>( istream& is , maax& m )
{   cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
    cout<<"enter the number of rows and columns:  "<<endl;
    cin>> m.row >> m.col ;
    cout<<"=========================================="<<endl;
    m.num = new int [m.row * m.col];
    for (int i=0 ; i<m.row ; i++)
    {
        cout<<"enter the data of row __"<<i+1<<" : "<<endl;
        for (int k=0 ; k<m.col ; k++)
        {
            cin>>m.num[i * m.col + k];
        }
    }
}
//for output

ostream& operator<< (ostream& os , maax& m )
{
    cout<<"The matrix of the result is: "<<endl;
    for (int i=0 ; i<m.row ; i++)
    {   cout<<endl;
        for (int k=0 ; k<m.col ; k++)

            {cout<<setw(5)<<m.num[i*m.col+k]<<" ";}

    }
    return os ;
}

//for adding two matrices

maax& operator+ ( maax m1 , maax m2 )
{   assert ( m1.row == m2.row && m1.col == m2.col );

    maax* ptrmx = new maax ;
    ptrmx->row =m1.row;
    ptrmx->col =m1.col;
    ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

    for( int i=0 ; i<m1.row*m1.col ; i++ )
       {
        ptrmx->num[i] = m1.num[i] + m2.num[i] ;
       }
    return *ptrmx ;

}

//for subtract two matrices

maax& operator- ( maax m1 , maax m2 )
{   assert ( m1.row == m2.row && m1.col == m2.col );

    maax* ptrmx = new maax ;
    ptrmx->row =m1.row;
    ptrmx->col =m1.col;
    ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

    for( int i=0 ; i<m1.row*m1.col ; i++ )
       {
        ptrmx->num[i] = m1.num[i] - m2.num[i] ;
       }
    return *ptrmx ;

}
/*maax& operator* ( maax m1 , maax m2 )
{   assert (m1.row == m2 .col);
    //prod[i+j] = prod[i+j] + A[i] * B[j]
    maax* ptrmx = new maax ;
    ptrmx->row =m1.row;
    ptrmx->col =m2.col;
    ptrmx->num =new int [m1.col*m2.row];     //num = the pointer

    for( int i=0 ; i<m1.row ; i++ )
       {
         for(int j=0 ; j<m2.col ; j++)
           {
             for(int k=0 ; k<m1.col;k++)
              {
                 ptrmx->num[i] += m1.num[k]* m2.num[k];
              }
           }
        ptrmx->num[i] = m1.num[i] + m1[i] * m2[k] ;
       }
    return *ptrmx ;
}*/

//for add a scalar to a matrix

maax& operator+ (maax m , int n )
{   cout<<"______________________________________________"<<endl;
    maax*ptrmx = new maax ;
    ptrmx->row = m.row ;
    ptrmx->col = m.col ;
    ptrmx->num = new int [m.row*m.col] ;
    for (int i=0 ; i<m.row*m.col ; i++)
    {
        ptrmx->num[i] = m.num[i];
    }
    for (int i=0 ; i<m.row*m.col ; i++)
    {
       ptrmx->num[i]=ptrmx->num[i]+n ;
    }
    return *ptrmx;

}

//for subtract a scalar from a matrix

maax& operator- (maax m , int n )
{   cout<<"/////////////////////////////////"<<endl;
    maax*ptrmx = new maax ;
    ptrmx->row = m.row ;
    ptrmx->col = m.col ;
    ptrmx->num = new int [m.row*m.col] ;
    for (int i=0 ; i<m.row*m.col ; i++)
    {
        ptrmx->num[i] = m.num[i];
    }
    for (int i=0 ; i<m.row*m.col ; i++)
    {
       ptrmx->num[i]=ptrmx->num[i]-n ;
    }
    return *ptrmx;

}

//for multiply a scalar by a matrix

maax& operator* (maax m , int n )
{   cout<<"/////////////////////////////////"<<endl;
    maax*ptrmx = new maax ;
    ptrmx->row = m.row ;
    ptrmx->col = m.col ;
    ptrmx->num = new int [m.row*m.col] ;
    for (int i=0 ; i<m.row*m.col ; i++)
    {
        ptrmx->num[i] = m.num[i];
    }
    for (int i=0 ; i<m.row*m.col ; i++)
    {
       ptrmx->num[i]=ptrmx->num[i]*n ;
    }
    return *ptrmx;

}
//_________________________________________________________________-
maax& operator+= ( maax& m1 , maax m2 )
{

    maax* ptrmx = new maax ;
    ptrmx->row =m1.row;
    ptrmx->col =m1.col;
    ptrmx->num =new int [m1.row*m1.col];     //num = the pointer

    for( int i=0 ; i<m1.row*m1.col ; i++ )
       {
        ptrmx->num[i] = m1.num[i] + m2.num[i] ;
       }
    return *ptrmx ;

}

maax& operator+= (maax& m , int n )
{   cout<<"______________________________________________"<<endl;
    maax*ptrmx = new maax ;
    ptrmx->row = m.row ;
    ptrmx->col = m.col ;
    ptrmx->num = new int [m.row*m.col] ;

    for (int i=0 ; i<m.row*m.col ; i++)
    {
       m.num[i]=m.num[i]+n ;
    }
    for (int i=0 ; i<m.row*m.col ; i++)
    {
        ptrmx->num[i] = m.num[i];
    }
    return *ptrmx;

}

void operator++ (maax& m1)
{
    cout<<"______________________________________________"<<endl;
    maax*ptrmx = new maax ;
    ptrmx->row = m.row ;
    ptrmx->col = m.col ;
    ptrmx->num = new int [m.row*m.col] ;

    for (int i=0 ; i<m.row*m.col ; i++)
    {
       m.num[i]=m.num[i]+1 ;
    }
    for (int i=0 ; i<m.row*m.col ; i++)
    {
        ptrmx->num[i] = m.num[i];
    }
    return *ptrmx;

}
