#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "extern.h"
#include "wofost.h"

void header_AO(FILE *fp_ao)
{
    fprintf(fp_ao,"Lat,Lon,Year,Day,LAI,TWSO,TWLV,TWST,TWRT,GrowthDay,DVS_harvest,N_Uptake,P_Uptake,NamountSO,PamountSO\n");
}

void Output_Annual(FILE *fp_ao)
{      
         fprintf(fp_ao,"%7.2f, %7.2f, %4d, %3d , %4.2f, %4.2f, %4.2f, %4.2f, %4.2f, %4.2d, %4.2f, %4.2f, %4.2f, %4.2f, %4.2f\n",
               Latitude[Lat],
               Longitude[Lon],
               MeteoYear[Day],
               MeteoDay[Day],
               Crop->st.LAI,
               Crop->st.storage, // Crop yield
               Crop->st.leaves,
               Crop->st.stems,
               Crop->st.roots,
               Crop->GrowthDay,
               Crop->prm.DevelopStageHarvest,
               Crop->N_st.Uptake,
               Crop->P_st.Uptake,
               Crop->N_st.storage,//For grains
               Crop->P_st.storage//For grains
            );
}