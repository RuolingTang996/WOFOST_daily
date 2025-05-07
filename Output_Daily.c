#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "extern.h"
#include "wofost.h"

void header_DO(FILE *fp_do)
{
    fprintf(fp_do,"Lat,Lon,Year,Day,DVS,TSM1,TSM2,LAI,TWSO,TWLV,TWST,TWRT,Nuptake,Puptake,Kuptake\n");

    
}

void Output_Daily(FILE *fp_do)
{      
         fprintf(fp_do,"%7.2f, %7.2f, %4d, %3d, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f\n",
                Latitude[Lat],
                Longitude[Lon],
                MeteoYear[Day],
                MeteoDay[Day],
                Crop->st.Development,
                Crop->prm.TempSum1,
                Crop->prm.TempSum2,
                Crop->st.LAI,
                Crop->st.storage, // Crop yield
                Crop->st.leaves,
                Crop->st.stems,
                Crop->st.roots,
                Crop->N_st.Uptake,
                Crop->P_st.Uptake,
                Crop->K_st.Uptake
            );
}