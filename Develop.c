#include <stdio.h>
#include "astro.h"
#include "extern.h"
#include "wofost.h"

/* ----------------------------------------------------------------------------*/
/*  function GetDevelopmentStage()                                             */
/*  Purpose: Calculation of the development stage as function of the effective */
/*  daily temperature, day length and the vernalization                        */
/*-----------------------------------------------------------------------------*/


/*Part 1. 选择CROPTYPE*, 这来自claude老师*/


void ProcessDevelopmentRate(int CropType) {
    if (CropType < 0 || CropType > 2) {
        printf("Error: Unsupported CropType %d\n", CropType);
        return;
    }

    switch(CropType) {
        case 0:
        case 1:
            DevelopmentRate();
            break;
        case 2:
            DevelopmentRate_Cabbage();
            break;
    }
}


void DevelopmentRate(void)
{
    float VernalizationFactor;

    if (Crop->st.Development  < 1.)
    {
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp)/Crop->prm.TempSum1;
        if (Crop->prm.IdentifyAnthesis == 1 || Crop->prm.IdentifyAnthesis == 2) 
            Crop->rt.Development = Crop->rt.Development *
                limit(0., 1., (PARDaylength - Crop->prm.CriticalDaylength)/(
                    Crop->prm.OptimumDaylength-Crop->prm.CriticalDaylength));
        
        /* Vernalization takes place */
        if (Crop->prm.IdentifyAnthesis == 2)
        {
            Crop->rt.vernalization = insw(Crop->st.Development - 0.3, Afgen(Crop->prm.VernalizationRate,&Temp), 0.);
            VernalizationFactor = limit(0., 1., 
                    (Crop->st.vernalization - Crop->prm.BaseVernRequirement)/
                    (Crop->prm.SatVernRequirement - Crop->prm.BaseVernRequirement));
            
	    Crop->rt.Development = Crop->rt.Development * insw(Crop->st.Development - 0.3, VernalizationFactor, 1.);
        }
    }
    else 
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp)/Crop->prm.TempSum2;  
}

//////////////////////////////////////以下是我最新的从chatgpt, deepseek, claude中发现的代码 【需要我自己一步步debug】///////////////////////////////////////////
/*Part 2. 保持原来的development.c代码， 但是加上解释*/
/*
void DevelopmentRate(void)  // 定义 DevelopmentRate 函数
{
    float VernalizationFactor;  // 定义春化因子 (VernalizationFactor)

    if (Crop->st.Development < 1.)  // 如果作物的发育阶段 Development 小于 1（即未成熟）
    {
        // 计算基础发育速率，使用温度和温度积 (DeltaTempSum)
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp) / Crop->prm.TempSum1;  

        // 如果 IdentifyAnthesis（控制开花机制）为 1 或 2，则考虑日长效应
        if (Crop->prm.IdentifyAnthesis == 1 || Crop->prm.IdentifyAnthesis == 2) 
        {
            // 计算日长效应 (Photoperiod Effect)，影响发育速率
            Crop->rt.Development *= limit(0., 1., 
                (PARDaylength - Crop->prm.CriticalDaylength) /  // 日长偏差
                (Crop->prm.OptimumDaylength - Crop->prm.CriticalDaylength));  // 最优日长与临界日长差值
        }

        // 春化作用 (Vernalization) 计算
        if (Crop->prm.IdentifyAnthesis == 2)  // 仅在 IdentifyAnthesis == 2 时进行春化计算
        {
            // 计算 vernalization (累积春化作用) 
            Crop->rt.vernalization = insw(Crop->st.Development - 0.3,  // 只有发育到 0.3 之前才计算
                                          Afgen(Crop->prm.VernalizationRate, &Temp), 0.);  // 通过温度计算春化速率

            // 计算春化因子 (VernalizationFactor)，受 BaseVernRequirement 和 SatVernRequirement 限制
            VernalizationFactor = limit(0., 1., 
                (Crop->st.vernalization - Crop->prm.BaseVernRequirement) /  // 当前春化 - 基础需求
                (Crop->prm.SatVernRequirement - Crop->prm.BaseVernRequirement));  // 总需求 - 基础需求

            // 在 Development < 0.3 之前，Development 乘以 VernalizationFactor 控制发育速率
            Crop->rt.Development *= insw(Crop->st.Development - 0.3, VernalizationFactor, 1.);
        }
    }
    else  // 当作物发育阶段 Development ≥ 1（进入生殖期）
    {
        // 使用 TempSum2 计算后续发育速率
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp) / Crop->prm.TempSum2;
    }
}
*/

/*Part 3. 新的caabage的development的公式，疑似最新版*/

void DevelopmentRate_Cabbage(void) 
{
    float VernalizationFactor;

    if (Crop->st.Development < 1.)
    {
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp) / Crop->prm.TempSum1;
        
        // 光周期影响白菜的heading阶段
        if (Crop->prm.IdentifyAnthesis == 1 || Crop->prm.IdentifyAnthesis == 2) 
        {
            Crop->rt.Development *= limit(0., 1., (PARDaylength - Crop->prm.CriticalDaylength) / 
                                (Crop->prm.OptimumDaylength - Crop->prm.CriticalDaylength));
        }
        
        // 春化影响白菜的bolting & flowering阶段
        if (Crop->prm.IdentifyAnthesis == 2)
        {
            Crop->rt.vernalization = insw(Crop->st.Development - 0.5, Afgen(Crop->prm.VernalizationRate, &Temp), 0.);
            
            VernalizationFactor = limit(0., 1., 
                    (Crop->st.vernalization - Crop->prm.BaseVernRequirement) / 
                    (Crop->prm.SatVernRequirement - Crop->prm.BaseVernRequirement));
            
            Crop->rt.Development *= insw(Crop->st.Development - 0.5, VernalizationFactor, 1.);
        }
    }
    else 
    {
        Crop->rt.Development = Afgen(Crop->prm.DeltaTempSum, &Temp) / Crop->prm.TempSum2;
    }
}
