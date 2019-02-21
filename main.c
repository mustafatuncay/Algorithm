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

int     b,c,y,i,j,x,R1,R2,R3;
double  TmpP1,TmpP,TmpX1,TmpX2,TmpJ1,TmpJ2,TmpJ3,CRValue,FValue,TmpTT2,TmpTT,TmpTT3,TmpTT4,TmpUF,F1,F2,n,TmpBig,TmpSmall,TmpAverage,RandX ;
double  a,Range1,Range2,Range1x,Range2x,TmpR1,TmpR2 ;

double MatrixA[100][30];
double MatrixF[100], MatrixF2[100],MatrixF3[100],MatrixV[30],MatrixU[30],Smallest[10],Smallestid[10] ;

const double CRMatrix[6] = {0.2, 0.5, 0.8, 0.85, 0.9, 0.95};
const double FMatrix[8]  = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

//srand(time(NULL));

printf("Enter a Problem Number (1,5,8,9,10) = ");
scanf("%d",&F);
printf("\n Enter the iteration = ");
scanf("%d",&iter);

F=1;
//iter= StrToInt(Txtiteration->Text)  ;

if (F == 1)
	{
	Range1=0;
	Range2=1;
	Range1x=-1;
	Range2x=1;
	}

	 //Series1->Clear();     grafikleri temizlemek için kullanılır
	 //Series2->Clear();
	 //Memo1->Clear();


	 for (a=0.01; a<1 ;a=0.01+a)
		{
		// Memo1->Lines->Add( a ) ; //printf benzeri bir kod
		 for (c = 1; c <= 5; ++c)
			{
				for (x = 0; x <= Population - 1; ++x)
					{
					 MatrixA[x][0] = randfrom(Range1,Range2);
					 for (i = 1; i <= Dimension - 1; ++i)
						 {
						  MatrixA[x][i] = randfrom(Range1x,Range2x);
						 }
					}

				 TmpUF=0; TmpTT=0; TmpTT2=0; TmpTT3=0;


				  if (F==1)  // 1. Problem
					 {
					 for (x = 0; x <= Population - 1; ++x)
						{
						  j=0; TmpTT=0; TmpTT3=0; TmpX1=MatrixA[x][0]; TmpJ1=0; TmpJ2=0;

						  for (i = 0; i <= Dimension - 1; ++i)
							 {
							  j=i+1;
							  if (j>1  &&  31>j && j % 2 != 0)     //J1
							   {
								 TmpJ1=TmpJ1+1;
								 TmpTT2= (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT=TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (j>1  &&  31>j && j % 2 == 0)   //J2
							   {
								 TmpJ2  =  TmpJ2+1;
								 TmpTT2 =  (MatrixA[x][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT3 =  TmpTT3 + (TmpTT2*TmpTT2);
							   }

							 }
							  MatrixF[x]  = a*(TmpX1 + (2/TmpJ1) * TmpTT)  +
										   (1-a)*( 1-  sqrt(TmpX1) + (2/TmpJ2) *TmpTT3);
						}

					 }


			 iteration = iter;
			 while (iteration>0)
				 {
					   R1=randfrom(0,Population) ;
					   R2=randfrom(0,Population) ;
					   R3=randfrom(0,Population) ;

					   CRValue = randfrom(0.1,0.95);
					   FValue  = randfrom(0.1,0.95);

					   for (x = 0; x <= Dimension - 1; ++x)
						   {
							MatrixV[x] = MatrixA[R1][x] + ( FValue*(MatrixA[R2][x]-MatrixA[R3][x] ) ) ;
						   }

					   for (x = 0; x <= Dimension - 1; ++x)
						   {
							RandX = randfrom(0,1);
							if (CRValue > RandX )
							   {

									if (x==0)
									  {
									   TmpR1=Range1; TmpR2=Range2;
									  }
									else
									   {
									   TmpR1=Range1x; TmpR2=Range2x;
									   }

									if (MatrixV[x]>TmpR2)
									   {
										MatrixU[x] = TmpR2 ;
									   }
										else if (MatrixV[x]<TmpR1)
										  {
										   MatrixU[x] = TmpR1;
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

						  j=0; TmpTT=0; TmpTT3=0; TmpX1=(MatrixU[0]); TmpJ1=0; TmpJ2=0;

						  for (x = 0; x <= Dimension - 1; ++x)
							 {
							  j=x+1;
							  if (j>1  &&  31>j && j % 2 != 0)     //J1
							   {
							
								 TmpJ1=TmpJ1+1;
								 TmpTT2 = (MatrixU[x] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT  = TmpTT + (TmpTT2*TmpTT2);
							   }

							  if (j>1  &&  31>j && j % 2 == 0)   //J2
							   {
								 TmpJ2=TmpJ2+1;
								 TmpTT2= (MatrixU[x] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								 TmpTT3=TmpTT3 + (TmpTT2*TmpTT2);
							   }

							 }

							  TmpUF = a*(TmpX1 + (2/TmpJ1) * TmpTT)  +
									  (1-a)*( 1- sqrt(TmpX1) + (2/TmpJ2) *TmpTT3);
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


						TmpSmall = MatrixF[0] ;  Tmpi=0;
						for (i= 0; i<=Population -1;++i)
							{
							 if (TmpSmall>MatrixF[i])
								{
								 Tmpi = i ;
								 TmpSmall = MatrixF[i] ;
								}
							}
						  //Smallest[c-1] = TmpSmall ;
						 // Smallestid[c-1] = TmpSmall ;

						if (F==1)  // 1. Problem
						   {
							j=0; TmpTT=0; TmpTT3=0; TmpX1=MatrixA[Tmpi][0]; TmpJ1=0; TmpJ2=0;
							
							for (i= 0; i<=Dimension-1; ++i)
							   {

								j=i+1;
								if (j>1  &&  31>j && j % 2 != 0)     //J1
								  {
								   TmpJ1  = TmpJ1+1;
								   TmpTT2 = (MatrixA[Tmpi][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								   TmpTT  = TmpTT + (TmpTT2*TmpTT2);
								  }

								if (j>1  &&  31>j && j % 2 == 0)   //J2
								  {
								   TmpJ2  = TmpJ2+1;
								   TmpTT2 = (MatrixA[Tmpi][i] - sin(6*M_PI*TmpX1 + ( j * M_PI) / 30)  );
								   TmpTT3 = TmpTT3 + (TmpTT2*TmpTT2);
								  }

							   }

							
							F1 = TmpX1 + (2/TmpJ1) * TmpTT ;
							F2 = 1- sqrt(TmpX1) + (2/TmpJ2) *TmpTT3;



							// Memo1->Lines->Add( FloatToStr(F1) +"  "+ FloatToStr(F2) ) ;  //Printf in benzeri bir kod
							//Series2->AddXY(F1,F2); //Grafik Çizimi için kullanılan kod




						   }


			}//c


		} //a



	 //for (a=0; a<=1 ;a=0.01+a)

		 // Series1->AddXY(a,1- sqrt(a));  //Grafik Çizimi için kullanılan kod



}

//---------------------------------------------------------------------------
