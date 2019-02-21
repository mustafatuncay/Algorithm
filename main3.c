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
int iteration,iter,F,Tmpi;

int     b,c,y,i,x,R1,R2,R3;
double  TmpP1,TmpP,TmpX1,TmpX2,TmpJ1,TmpJ2,TmpJ3,CRValue,FValue,TmpTT2,TmpTT,TmpTT3,TmpTT4,TmpUF,F1,F2,n,TmpBig,TmpSmall,TmpAverage,RandX ;
double  a,Range1,Range2 ;

double MatrixA[Population][Dimension];
double MatrixF[Population], MatrixF2[Population],MatrixF3[Population],MatrixV[Dimension],MatrixU[Dimension],Smallest[10] ;

const double CRMatrix[6] = {0.2, 0.5, 0.8, 0.85, 0.9, 0.95};
const double FMatrix[8]  = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

printf("Enter a Problem Number (1,5,8,9,10) = ");
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


   //	for (int b = 0; b <=0; ++b) //7
   //		{

	 for (int a=0.01; a<1;a=a+0.01)  //5
		{

		 for (int c = 1; c <= 5; ++c)
			{

			//   CRValue = CRMatrix[a];
			//  FValue  = FMatrix[b];

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


				  if (F==1)  // 1. Problem
					 {
                     for (x = 0; x <= Population - 1; ++x)
                        {

						  TmpTT=0; TmpTT3=0; TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;
                          for (i = 0; i <= Dimension - 1; ++i)
                             {
							  if (i>1  &&  31>i && i % 2 != 0)     //J1
							   {
								 TmpJ1=TmpJ1+1;
								 TmpTT2= (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (i>1  &&  31>i && i % 2 == 0)   //J2
							   {
								 TmpJ2=TmpJ2+1;
								 TmpTT2= (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
							   }

                              }
							  //MatrixF[x]  = TmpX1 + (2/TmpJ1) * TmpTT ;
							  //MatrixF2[x] =  1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3;

							  MatrixF[x]  = a*(TmpX1 + (2/TmpJ1) * TmpTT)  +
										   (1-a)*( 1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3);



						 }

                     }
				  /*
				  else if (F == 2)  //2. Problem
					{
					  for (x=0; x<=Population -1; ++x)
						 {
						  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

						  for (i=0; i<=Dimension-2; ++i)
							 {
							  if (i>1  &&  31>i && i % 2 != 0)    //J1
								{
								 TmpJ1=TmpJ1+1;
								 TmpTT2 = (
										   MatrixA[x][i] -
										   ( 0.3 * (TmpX1*TmpX1) * cos(24*M_PI*TmpX1 + (4*i*M_PI)/30) + 0.6*TmpX1 ) *
										   cos(6*M_PI*TmpX1 + (i*M_PI)/30)
										   );

								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
								}

							  if (i>1  &&  31>i && i % 2 == 0)     //j2
								 {
								 TmpJ2=TmpJ2+1;
								 TmpTT2 = (
										   MatrixA[x][i] -
										   ( 0.3 * (TmpX1*TmpX1) * sin(24*M_PI*TmpX1 + (4*i*M_PI)/30) + 0.6*TmpX1 ) *
										   cos(6*M_PI*TmpX1 + (i*M_PI)/30)
										   );

								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
								 }

							 }
							  MatrixF[x]  = TmpX1 + (2/TmpJ1) * TmpTT ;
							  MatrixF2[x] =  1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3;
						 }

					}

			   else if (F == 3) //3. Problem
				 {
				   for (x=0; x<=Population-1;++x)
					 {

					 TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpY=0; TmpP=1; TmpJ1=0;

					   for (i=0; i<=Dimension-1; ++i)
						 {
						   TmpJ1=TmpJ1+1;
						   TmpY = MatrixA[x][i]-pow(TmpX1,(0.5(1+  ( 3*(i-2) / 30-2) ) ) ) ;
						   TmpP =TmpP* cos((20*TmpY*i*M_PI)/sqrt(i)) ;
						   TmpTT=TmpTT + (TmpY*TmpY);
						 }

					 MatrixF[x]  = TmpX1 + (2/TmpJ1) * ( (4*TmpTT) - (2*TmpP) + 2 ) ;
					 MatrixF2[x] = 1-sqrt(TmpX1) + (2/TmpJ2) *  ( (4*TmpTT) - (2*TmpP) + 2 );
					 }
				 }

				else if (F == 4) // 4. Problem
				 {
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i && i % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = TmpY / 1+ pow(exp,2*fabs(TmpY) ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (i>1  &&  31>i && i % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = TmpY / 1+ pow(exp,2*fabs(TmpY) ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 MatrixF[x]  = TmpX1 + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] =  1-(TmpX1*TmpX1) + (2/TmpJ2) * TmpTT3;
					}
				 }

				else if (F == 5) // 5. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i && i % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (i>1  &&  31>i && i % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = 2*TmpY*TmpY  - cos(4*M_PI*TmpY) + 1  ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 MatrixF[x]  = TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] = 1- TmpX1 +  ( (1/(2*10)) + 0.1 ) * fabs(sin(2*10*M_PI*TmpX1)) + (2/TmpJ1) * TmpTT3 ;
					}
				}

				else if (F == 6) // 6. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0];  TmpP=1; TmpP1=1; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i && i % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpP = TmpP * cos( (20*TmpY*M_PI) / sqrt(i) ) ;
							  TmpTT  = TmpTT + (TmpY*TmpY);
							  }

						   if (i>1  &&  31>i && i % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpP1 = TmpP1 * cos( (20*TmpY*M_PI) / sqrt(i) ) ;
							  TmpTT3  = TmpTT3 + (TmpY*TmpY);
							  }

						 }
						 MatrixF[x]  = TmpX1 +  max(0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ1) *  ( 4*TmpTT - 2*TmpP + 2);
						 MatrixF2[x] = 1- TmpX1 +  max(0, 2*( (1/2*10) +0.1) * sin (2*10*M_PI*TmpX1) )  +  (2/TmpJ1) *  ( 4*TmpTT2 - 2*TmpP1 + 2); ;
					}
				}

				else if (F == 7) // 7. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpTT=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i && i % 2 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = TmpY*TmpY  ;
							  TmpTT  = TmpTT + (TmpTT2);
							  }

						   if (i>1  &&  31>i && i % 2 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY   = MatrixA[x][i] -  sin(6*M_PI*TmpX1 + ((i*M_PI)/30) ) ;
							  TmpTT2 = TmpY*TmpY  ;
							  TmpTT3 = TmpTT3 + (TmpTT2);
							  }

						 }
						 MatrixF[x]  = pow(TmpX1,1/5) + (2/TmpJ1) * TmpTT ;
						 MatrixF2[x] = 1- pow(TmpX1,1/5) + (2/TmpJ1)  * TmpTT3 ;
					}
				}

				else if (F == 8) // 8. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpTT=0; TmpTT2=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpX2=MatrixA[x][1]; TmpJ1=0; TmpJ2=0; TmpJ3=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i &&  (i-1) % 3 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT  = TmpTT + (TmpY*TmpY) ;
                              }

						   if (i>1  &&  31>i && (i-2) % 3 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT2  = TmpTT2 + (TmpY*TmpY) ;
							  }

						   if (i>1  &&  31>i && i % 3 == 0) //J3
							  {
                              TmpJ3=TmpJ3+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT3  = TmpTT3 + (TmpY*TmpY) ;
							  }

						 }
						 MatrixF[x]  = cos(0.5*TmpX1*M_PI)*cos(0.5*TmpX2*M_PI)+2/TmpJ1 * TmpTT ;
						 MatrixF2[x] = cos(0.5*TmpX1*M_PI)*sin(0.5*TmpX2*M_PI)+2/TmpJ2 * TmpTT2 ;
						 MatrixF3[x] = sin(0.5*TmpX1*M_PI)+2/TmpJ3 * TmpTT3 ;
					}
				}

				else if (F == 9) // 9. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpY=0; TmpTT=0; TmpTT2=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpX2=MatrixA[x][1]; TmpJ1=0; TmpJ2=0; TmpJ3=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i &&  (i-1) % 3 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT  = TmpTT + (TmpY*TmpY) ;
							  }

						   if (i>1  &&  31>i && (i-2) % 3 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT2  = TmpTT2 + (TmpY*TmpY) ;
							  }

						   if (i>1  &&  31>i && i % 3 == 0) //J3
							  {
							  TmpJ3=TmpJ3+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT3  = TmpTT3 + (TmpY*TmpY) ;
							  }

						 }
						 MatrixF[x]  = 0.5* (max(0,(1+0.1) * (1-4*(2*TmpX1-1)*(2*TmpX1-1)) ) + 2*TmpX1 ) *TmpX2 + 2/TmpJ1  * TmpTT ;
						 MatrixF2[x] = 0.5* (max(0,(1+0.1) * (1-4*(2*TmpX1-1)*(2*TmpX1-1)) ) - 2*TmpX1 + 2 ) *TmpX2 + 2/TmpJ2  * TmpTT2 ;
						 MatrixF3[x] = 1-TmpX2 + 2/TmpJ3  * TmpTT3 ;
					}
				}

				else if (F == 10) // 10. Problem
				{
				  for (x=0; x<=Population-1; ++x)
					{
					  TmpY=0; TmpTT=0; TmpTT2=0; TmpTT3=0;  TmpX1=MatrixA[x][0]; TmpX2=MatrixA[x][1]; TmpJ1=0; TmpJ2=0; TmpJ3=0;

					  for (i=0; i<=Dimension-2; ++i)
						 {
						   if (i>1  &&  31>i &&  (i-1) % 3 != 0)  //J1
							  {
							  TmpJ1=TmpJ1+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT  = TmpTT + ( 4*(TmpY*TmpY) - cos(8*M_PI*TmpY) +1 ) ;
                              }

						   if (i>1  &&  31>i && (i-2) % 3 == 0) //J2
							  {
							  TmpJ2=TmpJ2+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT2  = TmpTT2 + ( 4*(TmpY*TmpY) - cos(8*M_PI*TmpY) +1 ) ;
							  }

						   if (i>1  &&  31>i && i % 3 == 0) //J3
							  {
							  TmpJ3=TmpJ3+1;
							  TmpY = MatrixA[x][i] - (2*TmpX2*sin(2*M_PI*TmpX1 + (i*M_PI) /30) ;
							  TmpTT3  = TmpTT3 + ( 4*(TmpY*TmpY) - cos(8*M_PI*TmpY) +1 ) ;
							  }

						 }
						 MatrixF[x]  = cos(0.5*TmpX1*M_PI)*cos(0.5*TmpX2*M_PI) + 2/TmpJ1  * TmpTT ;
						 MatrixF2[x] = cos(0.5*TmpX1*M_PI)*sin(0.5*TmpX2*M_PI) + 2/TmpJ2  * TmpTT2 ;
						 MatrixF3[x] = sin(0.5*TmpX1*M_PI) + 2/TmpJ3  * TmpTT3 ;
					}
				}  */

			  iteration = iter;//500000 ;
			  while (iteration>0)
					{
					   R1=randfrom(0,Population) ;
					   R2=randfrom(0,Population) ;
					   R3=randfrom(0,Population) ;

					   CRValue = randfrom(0.1,0.95);
					   FValue  = randfrom(0.1,0.95);

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
					   if (F==1)  // 1. Problem
						 {

						  TmpTT=0; TmpTT3=0; TmpX1=MatrixU[0]; TmpJ1=0; TmpJ2=0;
						  for (x = 0; x <= Dimension - 1; ++x)
							 {
							  if (x>1  &&  31>x && x % 2 != 0)     //J1
							   {
								 TmpJ1=TmpJ1+1;
								 TmpTT2= (MatrixU[x] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (x>1  &&  31>x && x % 2 == 0)   //J2
							   {
								 TmpJ2=TmpJ2+1;
								 TmpTT2= (MatrixU[x] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
							   }

							 }
							  //MatrixF[x]  = TmpX1 + (2/TmpJ1) * TmpTT ;
							  //MatrixF2[x] =  1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3;

							  TmpUF = a*(TmpX1 + (2/TmpJ1) * TmpTT)  +
									  (1-a)*( 1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3);

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
							for ( x=0; x<=Dimension-1; ++x)
							   {
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
						   for (x=0; x<=Dimension-1;++x)
							  {
							   MatrixA[R1][x] = MatrixU[x] ;
							  }
						  }

						--iteration ;

					} //iteration

				  //	printf("Geldi");

							TmpSmall = MatrixF[0] ;
							for (i= 0; i<=Population -1;++i)
								{
								 if (TmpSmall>MatrixF[i])
									{
									 Tmpi = i ;
									 TmpSmall = MatrixF[i] ;
									}
								}


						 if (F==1)  // 1. Problem
						   {
							TmpTT=0; TmpTT3=0; TmpX1=MatrixA[Tmpi][0]; TmpJ1=0; TmpJ2=0;
							for (i= 0; i<=Dimension-1; ++i)
							   {

								if (i>1  &&  31>i && i % 2 != 0)     //J1
								  {
								   TmpJ1=TmpJ1+1;
								   TmpTT2= (MatrixA[Tmpi][i] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								   TmpTT=TmpTT + (TmpTT2*TmpTT2);
								  }

								if (i>1  &&  31>i && i % 2 == 0)   //J2
								  {
								   TmpJ2=TmpJ2+1;
								   TmpTT2= (MatrixA[Tmpi][i] - sin(6*M_PI*TmpX1 + ( i * M_PI) / 30)  );
								   TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
								  }

							   }
							F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							F2 = 1-sqrt(TmpX1) + (2/TmpJ2) *TmpTT3;
							 //printf("%2.f  %2.f",F1,F2);
						   }


			}//c
   //		} // b
        } //a

}

