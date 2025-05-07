#include <stdio.h>
#include <stdlib.h>
#include "extern.h"
#include "wofost.h"

void header_CO(FILE *fp_co)
{
    fprintf(fp_co,"Lat,Lon,SowingDay,GrowingDays,TSM1,TSM2,Avg,Adev,Stdev,Var,Skew,Curt,Seasons\n");
    //fprintf(fp,"Lat,Lon,Sowing,Length,WLV,LAI,Avg,Adev,Stdev,Var,Skew,Curt\n");
}

void Output_Calendar(FILE *fp_co) 
{
    float ave, adev, sdev, var, skew, curt, lngth;
    int mnth, dy, dekad, i;
    
    sscanf(Grid->start,"%2d-%2d",&mnth,&dy);
   
    if (mnth < 1 || mnth > 12) exit(0);
    if (dy < 1 || dy >31) exit (0);
     
    // convert sowing day to dekad
    dekad = (mnth -1) * 3;
    if (dy <= 10)
        dekad += 1;
    else if(dy <=20)
        dekad += 2;
    else
        dekad += 3;   
                  
    
    if (Crop->Seasons > 2) {
        lngth =0;
        for (i= 1; i <= Crop->Seasons; i++) {
            lngth = lngth + Grid->length[i];
    }
       
        lngth = lngth/Crop->Seasons;
               
        Moment(Grid->twso, Crop->Seasons, &ave, &adev, &sdev, &var, &skew, &curt);  
       
        fprintf(fp_co, "%4.2f, %4.2f, %6d, %6.0f, %4.0f, %4.0f, %6.0f, %6.0f, %6.0f, %9.0f, %5.2f, %5.2f %5d\n", 
        Latitude[Lat], 
        Longitude[Lon], 
        dekad,   //播种日期（旬）
        lngth,    //平均生长季长度
        Crop->prm.TempSum1,
        Crop->prm.TempSum2,
        ave,  // 平均值
        adev, // 平均偏差
        sdev, // 标准差
        var, // 方差
        skew, // 偏度
        curt,  // 峰度
        Crop->Seasons);  // 生长季数
    }
 }