#include "RS485Interface.h"

/**********************点表保持部分设置方法*****************************/

/*void Set_BattOfType     (uint16_t BattOfType)
{
    int rslt=modbus_write_register(mctx,,BattOfType);
}
void Set_ChrgCurr       (uint16_t ChrgCurr)
{
    int rslt=modbus_write_register(mctx,,ChrgCurr);
}
void Set_DschgPwrSchdl  (uint16_t DschgPwrSchdl)
{
    int rslt=modbus_write_register(mctx,,DschgPwrSchdl);
}
void Set_GrdDschgDpth   (uint16_t GrdDschgDpth)
{
    int rslt=modbus_write_register(mctx,,GrdDschgDpth);
}
void Set_OffGrdDschgDpt (uint16_t OffGrdDschgDpt)
{
    int rslt=modbus_write_register(mctx,,OffGrdDschgDpt);
}
void Set_GrdHyst        (uint16_t GrdHyst)
{
    int rslt=modbus_write_register(mctx,,GrdHyst);
}
void Set_OffGrdHyst     (uint16_t OffGrdHyst)
{
    int rslt=modbus_write_register(mctx,,OffGrdHyst);
}
void Set_LABattCap      (uint16_t LABattCap)
{
    int rslt=modbus_write_register(mctx,,LABattCap);
}
void Set_LABattCVCV     (uint16_t LABattCVCV)
{
    int rslt=modbus_write_register(mctx,,LABattCVCV);
}
void Set_LABattFCPV     (uint16_t LABattFCPV)
{
    int rslt=modbus_write_register(mctx,,LABattFCPV);
}
void Set_LABattCPV      (uint16_t LABattCPV)
{
    int rslt=modbus_write_register(mctx,,LABattCPV);
}
void Set_LABattDschgCV  (uint16_t LABattDschgCV)
{
    int rslt=modbus_write_register(mctx,,LABattDschgCV);
}
void Set_RunningMode    (uint16_t RunningMode)
{
    int rslt=modbus_write_register(mctx,,RunningMode);
}
void Set_Ad_RunningMode (uint16_t Ad_RunningMode)
{
    int rslt=modbus_write_register(mctx,,Ad_RunningMode);
}
void Set_Ivt_Time       (uint16_t* Ivt_Time_str)
{
    int rslt=modbus_write_registers(mctx,,4,);
}
void Set_XFTG_Time      (uint16_t* XFTG_Time_str)
{
    int rslt=modbus_write_registers(mctx,,12,);
}*/
/**********************点表保持部分获取方法*****************************/
uint16_t Inverter::Get_BattOfType     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[0];
}
uint16_t Inverter::Get_ChrgCurr       (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[1];
}
uint16_t Inverter::Get_DschgPwrSchdl  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[2];
}
uint16_t Inverter::Get_GrdDschgDpth   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[3];
}
uint16_t Inverter::Get_OffGrdDschgDpt (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[4];
}
uint16_t Inverter::Get_GrdHyst        (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[5];
}
uint16_t Inverter::Get_OffGrdHyst     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[6];
}
uint16_t Inverter::Get_LABattCap      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[7];
}
uint16_t Inverter::Get_LABattCVCV     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[8];
}
uint16_t Inverter::Get_LABattFCPV     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[9];
}
uint16_t Inverter::Get_LABattCPV      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[10];
}
uint16_t Inverter::Get_LABattDschgCV  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[11];
}
uint16_t Inverter::Get_RunningMode    (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[12];
}
uint16_t Inverter::Get_Ad_RunningMode(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Rw_Data[13];
}
uint16_t* Inverter::Get_Ivt_Time(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data)const
{
    static uint16_t S_Ivt_Time[4];
    std::copy(Ivt_Rw_Data+14,Ivt_Rw_Data+14+4+1,S_Ivt_Time);
    for(int i=0;i<4;i++)
    {
        std::cout <<i <<"=" <<S_Ivt_Time[i]<<std::endl;
    }
    return S_Ivt_Time;
}
uint16_t* Inverter::Get_XFTG_Time(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data)const
{
    static uint16_t S_XFTG_Time[12];
    std::copy(Ivt_Rw_Data+18,Ivt_Rw_Data+18+12+1,S_XFTG_Time);
    return S_XFTG_Time;
}

/**********************点表输入部分获取方法*****************************/
/**********************包括一部分电表数据整理计算*****************************/
uint16_t Inverter::Get_PV1Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[0];
}
uint16_t Inverter::Get_PV1Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[1];
}
uint16_t Inverter::Get_PV1Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[2];
}
uint16_t Inverter::Get_PV2Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[3];
}
uint16_t Inverter::Get_PV2Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[4];
}
uint16_t Inverter::Get_PV2Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[5];
}
uint16_t Inverter::Get_PV3Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[6];
}
uint16_t Inverter::Get_PV3Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[7];
}
uint16_t Inverter::Get_PV3Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[8];
}
uint16_t Inverter::Get_InvBattBusVoltage  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[9];
}
int16_t  Inverter::Get_InvBattBusCurrent  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[10];
}
uint16_t Inverter::Get_BUSPositiveVoltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[11];
}
int16_t  Inverter::Get_BUSNegativeVoltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return Ivt_Ro_Data[12];
}

uint32_t Inverter::Get_TotalPVGeneration(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return (Ivt_Ro_Data[13]<<16)+Ivt_Ro_Data[14];
}
uint32_t Inverter::Get_TotalGridCharge(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return (Ivt_Ro_Data[15]<<16)+Ivt_Ro_Data[16];
}
uint32_t Inverter::Get_TotalGridDischarge(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return (Ivt_Ro_Data[17]<<16)+Ivt_Ro_Data[18];
}
uint32_t Inverter::Get_TotalLoadConsumption(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[19]<<16)+Ivt_Ro_Data[20];
}
uint32_t Inverter::Get_TotalAirCdtConsumption(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[21]<<16)+Ivt_Ro_Data[22];
}
uint32_t Inverter::Get_DailyPVGeneration(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    //std::cout <<"var="<<Ivt_Ro_Data[23]<<"\t" << Ivt_Ro_Data[24] << std::endl;
    return (Ivt_Ro_Data[23]<<16)+Ivt_Ro_Data[24];
}
uint32_t Inverter::Get_StoreRemainingPwr(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[25]<<16)+Ivt_Ro_Data[26];
}
uint32_t Inverter::Get_DailyLoadCsmpt(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[27]<<16)+Ivt_Ro_Data[28];
}
uint32_t Inverter::Get_DailyGridCharge(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{
    return (Ivt_Ro_Data[29]<<16)+Ivt_Ro_Data[30];
}
uint32_t Inverter::Get_DailyAirCdtConsumption(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[31]<<16)+Ivt_Ro_Data[32];
}
uint32_t Inverter::Get_DailyElseConsumption(uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const
{//在整理数据函数Test_Dispalay_var里计算，在这直接使用了，不合乎规范
    return (Ivt_Ro_Data[33]<<16)+Ivt_Ro_Data[34];
}
