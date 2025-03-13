#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "extern.h"
#include "wofost.h"

void header_DO(FILE *fp_do)
{
<<<<<<< HEAD
    fprintf(fp_do,"Lat,Lon,Year,Day,Dev_Stage,eff_Tsum,LAI,TWSO,TWLV,TWST,TWRT,Nuptake,Puptake,Kuptake\n");
=======
    fprintf(fp_do,"Lat,Lon,Year,GrowthDay,DVS,TWRT,TWST,TWLV,TWSO,LAI,NUptake,PUptake,KUptake,NamountRT,NamountST,NamountLV,NamountSO,PamountRT,PamountST,PamountLV,PamountSO,KamountRT,KmaountST,KamountLV,KamountSO,OxygenStress,NutrientStress\n");
>>>>>>> b7182ebb712baeaf7865b5b9d27d5bc6fc80186b
}

void Output_Daily(FILE *fp_do)
{      
<<<<<<< HEAD
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
=======
         fprintf(fp_do,"%7.2f\t%7.2f\t%4d\t%3d" // Lat, Lon, MeteoYear, MeteoDay
                "\t%4.2d" // GrowthDay
                "\t%4.2f" //DVS
                "\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f"  // TWRT, TWST, TWLV, TWSO, LAI
                "\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f\t%4.2f" //Nutrient uptake
                "\t%4.2f\t%4.2f\n", //stress factors
               Latitude[Lat],
               Longitude[Lon],
               MeteoYear[Day],
               MeteoDay[Day],
               Crop->GrowthDay,
               Crop->st.Development,
               Crop->st.roots,
               Crop->st.stems,
               Crop->st.leaves,
               Crop->st.storage,
               Crop->st.LAI,
               Crop->N_st.Uptake,
               Crop->P_st.Uptake,
               Crop->K_st.Uptake,
               Crop->N_st.roots,
               Crop->N_st.stems,
               Crop->N_st.leaves,
               Crop->N_st.storage,
               Crop->P_st.roots,
               Crop->P_st.stems,
               Crop->P_st.leaves,
               Crop->P_st.storage,
               Crop->K_st.roots,
               Crop->K_st.stems,
               Crop->K_st.leaves,
               Crop->K_st.storage,
               Crop->DaysOxygenStress,
               Crop->NutrientStress);
>>>>>>> b7182ebb712baeaf7865b5b9d27d5bc6fc80186b
}