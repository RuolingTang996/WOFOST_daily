#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "extern.h"
#include "wofost.h"

void header_AO(FILE *fp_ao)
{
    fprintf(fp_ao,"Lat,Lon,Year,Day,GrowingDays,TSM1,TSM2,DVS,LAI,Nuptake,Puptake,Kuptake,TWST,TWRT,TWLV,TWSO\n");
}

void Output_Annual(FILE *fp_ao)
{      
         fprintf(fp_ao,"%7.2f, %7.2f, %4d, %3d, %3d, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f\n",
               Latitude[Lat],
               Longitude[Lon],
               MeteoYear[Day],
               MeteoDay[Day],
               Crop->GrowthDay,
               Crop->prm.TempSum1,
               Crop->prm.TempSum2,
               Crop->st.Development,
               Crop->st.LAI,
               Crop->N_st.Uptake,
               Crop->P_st.Uptake,
               Crop->K_st.Uptake,
               Crop->st.stems,
               Crop->st.roots,
               Crop->st.leaves,
               Crop->st.storage // Crop yield
            );
}