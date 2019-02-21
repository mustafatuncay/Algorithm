#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void main()
{
const int Population = 100;
const int Dimension = 30;
int iteration,iter,F;

int     a,b,c,y,i,x,R1,R2,R3;
double  CRValue,FValue,TmpTT2,TmpTT,TmpTT3,TmpUF,F1,F2,n,TmpBig,TmpSmall,TmpAverage,RandX ;
double     Range1,Range2 ;

double MatrixA[Population][Dimension];
double MatrixF[Population],MatrixV[Dimension],MatrixU[Dimension],Smallest[10] ;

const double CRMatrix[6] = {0.2, 0.5, 0.8, 0.85, 0.9, 0.95};
const double FMatrix[8]  = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

printf("Enter a Function Number (1,5,8,9,10) = ");
scanf("%d",&F);
printf("\n Enter the iteration = ");
scanf("%d",&iter);

 if (F == 1) {
       Range1=-100;
       Range2=100;
       }
        else if (F == 5) {
        Range1=-30;
        Range2=30;
        }
         else if (F == 8) {
         Range1=-500;
         Range2=500;
         }
          else if (F == 9) {
          Range1=-5.12;  //-5.12
          Range2=5.12;    //5.12
          }
            else if (F == 10) {
            Range1=-32;
            Range2=32;
            }




  for (int a = 0; a <= 5; ++a)  //5
     {
      for (int b = 0; b <= 7; ++b) //7
         {
         for (int c = 1; c <= 1; ++c)
           {
             CRValue = CRMatrix[a];
             FValue  = FMatrix[b];

 	     srand(time(NULL));

                for (i = 0; i <= Dimension - 1; ++i)
                    {
                     for (x = 0; x <= Population - 1; ++x)
                         {
                          MatrixA[x][i] = randfrom(Range1,Range2);
                          //printf("%.2f   ",MatrixA[x][i]);
                         }
                      }
                 TmpUF=0; TmpTT=0; TmpTT2=0; TmpTT3=0;


                  if (F==1) { //F1 Fonksiyon
                     for (x = 0; x <= Population - 1; ++x)
                        {
                        TmpTT=0;
                        for (i = 0; i <= Dimension - 1; ++i)
                            {
                            TmpTT=TmpTT + (MatrixA[x][i]*MatrixA[x][i]);
                            }
                        MatrixF[x]=TmpTT;
                         }
                  }
                  else if (F == 5) { //F5 Fonksiyon
                      for (x=0; x<=Population -1; ++x) {
                          TmpTT=0;
                          for (i=0; i<=Dimension-2; ++i) {
                              F1 = MatrixA[x][i+1] ; F2 = MatrixA[x][i] ;
                              TmpTT=TmpTT+(
                              100 * ( (F1- (F2*F2)) * (F1- (F2*F2)) )  + ( (F2-1) *(F2-1) )
                              );
                          }
                          MatrixF[x] = TmpTT;
                      }
                  }
              else if (F == 8) { //F8 Fonksiyon
                   for (x=0; x<=Population-1;++x) {
                       TmpTT=0;
                       for (i=0; i<=Dimension-1; ++i) {
                           F1 = MatrixA[x][i] ;
                           TmpTT=TmpTT+(
                           -1 * F1 *  sin(  ( sqrt(abs(F1)) ) )
                            );
                       }
                       MatrixF[x]= TmpTT;
                    }
              }
                else if (F == 9) { //F9 Fonksiyon
                 for (x=0; x<=Population-1; ++x) {
                     TmpTT=0;
                     for (i=0; i<=Dimension-1; ++i) {
                         F1 = MatrixA[x][i] ;
                         TmpTT=TmpTT+(
                          ( F1 * F1 ) - ( 10 *  cos(( 2*M_PI*F1 ) ) ) + 10
                         );
                      }
                      MatrixF[x]= TmpTT;
                  }
                }
                  else if (F == 10) { //F10 Fonksiyon
                   for (x=0; x<=Population-1; ++x) {
                     TmpTT=0; TmpTT2=0; TmpTT3=0;
                    for (i=0; i<=Dimension-1; ++i) {
                           F1 = MatrixA[x][i] ;
                           TmpTT=TmpTT+( F1*F1) ;
                           TmpTT2=TmpTT2+( cos((2 * M_PI * F1) ) ) ;
                    }
                       n=Dimension;
                       TmpTT3 = -20 * exp (-0.2 * sqrt ( 1/n * TmpTT ) ) - exp (1/n * TmpTT2 ) + 20 + exp(1) ;

                    MatrixF[x]= TmpTT3 ;
                   }
                  }








              iteration = iter;//500000 ;
              while (iteration>0)
                    {
                       R1=randfrom(0,Population) ;
                       R2=randfrom(0,Population) ;
                       R3=randfrom(0,Population) ;

                       //printf("%d  %d   %d ",R1,R2,R3);



                       for (int x = 0; x <= Dimension - 1; ++x)
                           {
                            MatrixV[x] = MatrixA[R1][x] + ( FValue*(MatrixA[R2][x]-MatrixA[R3][x] ) ) ;
                           }

                       for (int x = 0; x <= Dimension - 1; ++x)
                           {
                            RandX =  randfrom(0,1);
                            if (CRValue > RandX ) 
                               {                                    
                                    if (MatrixV[x]>Range2)
                                       { 
                                        MatrixU[x] = Range2 ;
                                       }
                                        else if (MatrixV[x]<Range1) 
                                          {
                                           MatrixU[x] = Range1;
                                          }
                                           else 
                                            {
                                             MatrixU[x] = MatrixV[x] ;
                                            }
                                          

                                }
                                else {
                                     MatrixU[x] = MatrixA[R1][x];
                                     }

                           }

                        TmpUF=0; TmpTT=0; TmpTT2=0; TmpTT3=0;

                        if ( F == 1) { // F1 Fonksiyon
                           for (int x = 0; x <= Dimension - 1; ++x)
                               {
                              TmpUF=TmpUF+(MatrixU[x])*(MatrixU[x]);
                               }
                        }
                        else if ( F == 5) { // F5 Fonksiyon
                             for (x=0; x<=Dimension-2; ++x) {
                                 F1 = MatrixU[x+1]; F2 = MatrixU[x] ;
                                 TmpUF=TmpUF+(
                                 100 * ( (F1- (F2*F2)) * (F1- (F2*F2)) )  + ( (F2-1) *(F2-1) )
                                 );
                             }
                        }
                       else if ( F == 8 ) { // F8 Fonksiyon
                            for (x=0; x<=Dimension-1; ++x) {
                                F1 = MatrixU[x];
                                TmpUF=TmpUF+(
                                -1 * F1 *  sin(  ( sqrt(abs(F1)) ) )
                                );
                             }
                       }
                       else if ( F == 9 ) { // F9 Fonksiyon
                            for ( x=0; x<=Dimension-1; ++x) {
                                F1 = MatrixU[x];
                                TmpUF=TmpUF+(
                                ( F1 * F1 ) - ( 10 *  cos(( 2*M_PI*F1 ) ) ) + 10
                                );
                             }
                       }
                       else if ( F == 10 ) { // F10 Fonksiyon
                            for (x=0; x<=Dimension-1; ++x) {
                                F1 = MatrixU[x];
                                TmpTT=TmpTT+( F1*F1) ;
                                TmpTT2=TmpTT2+( cos((2 * M_PI * F1) ) ) ;
                            }
                            n=Dimension ;
                            TmpUF = -20 * exp (-0.2 * sqrt ( 1/n * TmpTT ) ) - exp (1/n * TmpTT2 ) + 20 + exp(1) ;
                       }







                        if (MatrixF[R1] > TmpUF)
                          {
                           MatrixF[R1] = TmpUF ;
                           for (x=0; x<=Dimension-1;++x) {
                               MatrixA[R1][x] = MatrixU[x] ;
                            }
                          }

                        --iteration ;
/*

        for (x= 0; x<=Dimension-1; ++x) {
        //    printf("%.10f   ",MatrixU[x]);
        }
     //   printf("\n\n");

        for (x=0; x<=Dimension-1; ++x) {
         //   printf("%.10f  ",MatrixV[x]);
        }
       // printf("\n\n");

        for (x=0; x<=Dimension-1; ++x) {
            for (i=0; i<=Population-1; ++i) {
         //      printf("%.2f  ",MatrixA[i][x]);
            }
         //  printf("\n\n");
        }


        for (i=0; i<=Population-1; ++i) {
           printf("%.10f  \n",MatrixF[i]);
        }
*/
if  ((iteration%1000000)==0) {

        TmpSmall = MatrixF[0] ;
        for (i= 0; i<=Population -1;++i)
            {
             if (TmpSmall>MatrixF[i])
                 TmpSmall = MatrixF[i] ;
            }

        Smallest[c-1] = TmpSmall ;


 //     TmpSmall = Smallest[0] ; TmpAverage = 0 ;
/*
     for (i=0;i<=9;++i)
          {
            if ( Smallest[i]<TmpSmall )
               TmpSmall = Smallest[i] ;
            TmpAverage = TmpAverage + Smallest[i] ;
          }
          TmpAverage = TmpAverage / 10  ;
*/

   printf("%.20f        ", TmpSmall);
   printf("%.2f  %.2f \n", CRMatrix[a],FMatrix[b]);
   }



}
}//c
        } // b
      } //a


}

