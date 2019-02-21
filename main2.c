#include <stdio.h>
#include <stdlib.h>

#include <time.h>
double randfrom(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void main()
{
const int Population = 10;
const int Dimension = 10;
const int iteration = 100000;

int  a,b,c,y,i,x,R1,R2,R3,Tmpiteration;
double  CRValue,FValue,TmpTT2,TmpTT,TmpTT3,TmpUF,F1,F2,n,TmpBig,TmpSmall,TmpAverage ;
int  Range1=-10,Range2=10,z = 0 ;

double MatrixA[Population][Dimension];
double MatrixF[Population],MatrixV[Dimension],MatrixU[Dimension],Smallest[10] ;

const double CRMatrix[6] = {0.2, 0.5, 0.8, 0.85, 0.9, 0.95};
const double FMatrix[8]  = {0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};


  for (int a = 0; a <= 5; ++a) 
     {
      for (int b = 0; b <= 7; ++b)
         {
         for (int c = 1; c <= 10; ++c)
           { 
             CRValue = CRMatrix[a];  
             FValue  = FMatrix[b];
             srand(time(NULL));

                for (int i = 0; i <= Dimension - 1; ++i)
                    {
                     for (int x = 0; x <= Population - 1; ++x)
                         { 
                          MatrixA[x][i] = randfrom(Range1,Range2) ;
                         }
                 
                      }
                 TmpUF=0; TmpTT=0; TmpTT2=0; TmpTT3=0; 


                  //F1 Fonksiyon
                 for (int x = 0; x <= Population - 1; ++x)
                     {
                     TmpTT=0;
                     for (int i = 0; i <= Dimension - 1; ++i)
                         {
                         TmpTT=TmpTT+(MatrixA[x,i]*MatrixA[x,i]);
                         MatrixF[x]= TmpTT;
                         }
                     }

              while (Tmpiteration=!0) 
                    {
                       R1=randfrom(0,Population) ;
                       R2=randfrom(0,Population) ;
                       R3=randfrom(0,Population) ;
                       
                       for (int x = 0; x <= Dimension - x; ++x)
                           {
                            MatrixV[x] = MatrixA[R1,x] + ( FValue*(MatrixA[R2,x]-MatrixA[R3,x]) ) ;
                           }

                       for (int x = 0; x <= Dimension - x; ++x)    
                           {
                              if (CRValue > MatrixV[x]) 
                                {
                                   MatrixU[x] = MatrixV[x] ;
                                }
                              else 
                                {
                                   MatrixU[x] = MatrixA[R1,x];
                                }
                            }

                        TmpUF=0; TmpTT=0; TmpTT2=0; TmpTT3=0;

                         // F1 Fonksiyon
                        for (int x = 0; x <= Dimension - x; ++x)
                            {
                              TmpUF=TmpUF+(MatrixU[x]*MatrixU[x]);
                            }




             








                     }

     


            }
         }
    }   


}
/*          

  

               if (MatrixF[r1] > TmpUF) then begin
                   MatrixF[r1] := TmpUF ;  z:=z+1;
                   for x:=0 to Dimension-1 do MatrixA[r1,x] := MatrixU[x] ;
               end;

          

              Tmpiteration := Tmpiteration - 1 ;
         end;

        {
        AdvTMatrix.RowCount :=  population + 1 ;
        AdvAMatrix.RowCount :=  population + 1 ;
        AdvAMatrix.ColCount :=  dimension + 1 ;

        for x := 0 to dimension-1 do begin
        AdvTMatrix.Cells[3,x+1] := FloatToStr(MatrixU[x]);
        AdvTMatrix.Cells[2,x+1] := FloatToStr(MatrixV[x]);
        AdvAMatrix.ColWidths[x+1] := 200 ;
        for i:=0 to population-1 do AdvAMatrix.Cells[x+1,i+1] := FloatToStr(MatrixA[i,x]);
        end;

        for i:=0 to population-1 do AdvTMatrix.Cells[1,i+1] := FloatToStr(MatrixF[i]);

        AdvAMatrix.AutoNumberCol(0);
        AdvAMatrix.AutoNumberRow(0);
        AdvTMatrix.AutoNumberCol(0);
       }
       //////////////////////////////////////////////////////////////

        TmpSmall := MatrixF[0] ;
        for i:= 0 to Population -1 do begin
         if TmpSmall>MatrixF[i] then TmpSmall := MatrixF[i] ;
        end;

        Smallest[c-1]  := TmpSmall ;

      end; // C

      TmpSmall := Smallest[0] ; TmpAverage := 0 ;
      for i :=0 to 9 do begin
          if ( Smallest[i]<TmpSmall )then TmpSmall := Smallest[i] ;
          TmpAverage := TmpAverage + Smallest[i] ;
      end;
          TmpAverage := TmpAverage / 10  ;

      AdvAMatrix.RowCount := 9 ; AdvAMatrix.ColCount := 7 ;
      AdvBMatrix.RowCount := 9 ; AdvBMatrix.ColCount := 7 ;
      AdvAMatrix.Cells[a+1,b+1] := FloatToStr(TmpSmall);
      AdvBMatrix.Cells[a+1,b+1] := FloatToStr(TmpAverage) ;

      AdvAMatrix.ColWidths[a+1] := 200 ;
      AdvBMatrix.ColWidths[a+1] := 200 ;

    end; //b
   end; //a

 for a:=0 to 5 do begin
     AdvAMatrix.Cells[a+1,0] :=  FloatToStr(CRMatrix[a]) ;
     AdvBMatrix.Cells[a+1,0] :=  FloatToStr(CRMatrix[a]) ;
 end;
 for b:=0 to 7 do begin
    AdvAMatrix.Cells[0,b+1] :=  FloatToStr(FMatrix[b]) ;
    AdvBMatrix.Cells[0,b+1] :=  FloatToStr(FMatrix[b]) ;
 end;

    //////////////////////////////////////////////////////////////
  // showmessage(inttostr(z));
end;


*/
