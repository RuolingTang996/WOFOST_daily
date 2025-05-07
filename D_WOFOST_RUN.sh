#!/bin/bash
#-----------------------------Mail address-----------------------------
#SBATCH --mail-user=ruoling.tang@wur.nl
#SBATCH --mail-type=FAIL
#-----------------------------Output files-----------------------------
#SBATCH --output=/lustre/nobackup/WUR/ESG/tang043/work/China/WOFOST/output_%j.txt
#SBATCH --error=/lustre/nobackup/WUR/ESG/tang043/work/China/WOFOST/error_output_%j.txt
#-----------------------------Other information------------------------

#-----------------------------Required resources-----------------------
#SBATCH --time=200
#SBATCH --mem=250000

#-----------------------------Environment, Operations and Job steps----
#load modules
module load netcdf
#----------------------------Run WOFOST simulations-----------------------
# echo "Current directory: $(pwd)"
# ./wofost_Yp list_Guizhou_chili_Yp_0507.txt meteolist_WFDE5_CN_chili.txt 
# ./wofost_Yp list_Henan_chili_Yp_0507.txt meteolist_WFDE5_CN_chili.txt 
# ./wofost_Yp list_Yunnan_chili_Yp_0507.txt meteolist_WFDE5_CN_chili.txt 
# ./wofost_Yp list_Hunan_chili_Yp_0507.txt meteolist_WFDE5_CN_chili.txt 
./wofost_Yp list_Shandong_chili_Yp_0507.txt meteolist_WFDE5_CN_chili.txt 
# ./wofost_Yp list_Yangtze_mainrice_Yp.txt meteolist_WFDE5_Yangtze_mainrice.txt 
# ./wofost_Yp list_Yangtze_secondrice_Yp.txt meteolist_WFDE5_Yangtze_secondrice.txt 
# ./wofost_Yp list_Yangtze_springwheat_Yp.txt meteolist_WFDE5_Yangtze_springwheat.txt 
# ./wofost_Yp list_Yangtze_winterwheat_Yp.txt meteolist_WFDE5_Yangtze_winterwheat.txt 