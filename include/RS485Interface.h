// RS485Interface.h

#pragma once
#include <iostream>
#include <algorithm>
//#include "HardwareInterface.h"
class RS485Interface{// : public HardwareInterface {
public:
    //void initialize(const std::string& config) override;

    //int sendData(const void* data, size_t length) override;

    //void receiveData(void) override;

private:
    int baudrate_;
    int databits_;
    int stopbits_;
    //std::string parity_;
};
class Inverter{// : public Device{
public:
    
    uint16_t Ivt_Display_Ro_Data[40]; //逆变器部分只读数据，根据需要设为全局变量
    uint16_t Ivt_Display_Rw_Data[40];//逆变器部分读写数据，根据需要设为全局变量
    //void parseFrame(const void* data, size_t length) override;
    
    //设置逆变器参数
    // void Set_BattOfType     (uint16_t BattOfType);  
    // void Set_ChrgCurr       (uint16_t ChrgCurr);
    // void Set_DschgPwrSchdl  (uint16_t DschgPwrSchdl);
    // void Set_GrdDschgDpth   (uint16_t GrdDschgDpth);
    // void Set_OffGrdDschgDpt (uint16_t OffGrdDschgDpt);
    // void Set_GrdHyst        (uint16_t GrdHyst);
    // void Set_OffGrdHyst     (uint16_t OffGrdHyst);
    // void Set_LABattCap      (uint16_t LABattCap);
    // void Set_LABattCVCV     (uint16_t LABattCVCV);
    // void Set_LABattFCPV     (uint16_t LABattFCPV);
    // void Set_LABattCPV      (uint16_t LABattCPV);
    // void Set_LABattDschgCV  (uint16_t LABattDschgCV);
    // void Set_RunningMode    (uint16_t RunningMode); 
    // void Set_Ad_RunningMode (uint16_t Ad_RunningMode);
    // void Set_Ivt_Time       (uint16_t* Ivt_Time_str);
    // void Set_XFTG_Time      (uint16_t* XFTG_Time_str); 
    //提取要显示的变量
    int Get_Display_var(uint16_t* dest1,uint16_t* dest2,uint16_t* source) const;//提取要显示的变量
    //逆变器R/W参数的提取
    uint16_t Get_BattOfType     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_ChrgCurr       (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_DschgPwrSchdl  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_GrdDschgDpth   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_OffGrdDschgDpt (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_GrdHyst        (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_OffGrdHyst     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_LABattCap      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_LABattCVCV     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_LABattFCPV     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_LABattCPV      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_LABattDschgCV  (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_RunningMode    (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_Ad_RunningMode (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;   
    uint16_t* Get_Ivt_Time      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data)const;
    uint16_t* Get_XFTG_Time     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data)const;
    //逆变器RO参数的提取
    uint16_t Get_PV1Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV1Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV1Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV2Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV2Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV2Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV3Voltage (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV3Current (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_PV3Power   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint16_t Get_InvBattBusVoltage      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    int16_t  Get_InvBattBusCurrent      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint16_t Get_BUSPositiveVoltage     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    int16_t  Get_BUSNegativeVoltage     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_TotalPVGeneration      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_TotalGridCharge        (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;  
    uint32_t Get_TotalGridDischarge     (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_TotalLoadConsumption   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_TotalAirCdtConsumption (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const;
    uint32_t Get_DailyPVGeneration      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_StoreRemainingPwr      (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_DailyLoadCsmpt         (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_DailyGridCharge        (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_DailyAirCdtConsumption (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
    uint32_t Get_DailyElseConsumption   (uint16_t* Ivt_Ro_Data,uint16_t* Ivt_Rw_Data) const; 
private:
    //R/W变量 对应点表保持部分
    uint16_t BattOfType;//电池类型
    uint16_t ChrgCurr;//电池充电电流 Battery Charging Current
    uint16_t DschgPwrSchdl;//电池放电功率调度Battery Discharge Power Schedule
    uint16_t GrdDschgDpth;//电网放电深度Grid Discharge Depth
    uint16_t OffGrdDschgDpth;//离网放电深度Off Grid Discharge Depth
    uint16_t GrdHyst;//并网回差Grid Hysteresis
    uint16_t OffGrdHyst;//离网回差Off-grid Hysteresis
    uint16_t LABattCap;//铅酸电池AH Lead-acid Battery Capacity (Ah)
    uint16_t LABattCVCV;//铅酸电池恒压充电电压Lead-acid Battery Constant Voltage Charging Voltage
    uint16_t LABattFCPV;//铅酸电池浮充电压Lead-acid Battery Float Charge Protection Voltage
    uint16_t LABattCPV;//铅酸电池充电保护电压Lead-acid Battery Charge Protection Voltage
    uint16_t LABattDschgCV;//铅酸电池放电截止电压Lead-acid Battery Discharge Cut-off Voltage
    uint16_t RunningMode;//运行模式
    uint16_t Advanced_RunningMode;//高级运行模式
    uint16_t Ivt_Time[4];   //逆变器时间
    uint16_t XFTG_Time[12];     //削峰填谷时间
    //RO变量 对应点表输入部分
    uint16_t PV1Voltage;    // PV1电压, PV1 Voltage
    uint16_t PV1Current;    // PV1电流, PV1 Current
    uint16_t PV1Power;      // PV1功率, PV1 Power
    uint16_t PV2Voltage;    // PV2电压, PV2 Voltage
    uint16_t PV2Current;    // PV2电流, PV2 Current
    uint16_t PV2Power;      // PV2功率, PV2 Power
    uint16_t PV3Voltage;    // PV3电压, PV3 Voltage
    uint16_t PV3Current;    // PV3电流, PV3 Current
    uint16_t PV3Power;      // PV3功率, PV3 Power
    uint16_t InvBattBusVoltage;     // 逆变器电池端母线电压, Inverter Battery Bus Voltage
    int16_t  InvBattBusCurrent;     // 逆变器电池端母线电流, Inverter Battery Bus Current
    uint16_t BUSPositiveVoltage;    // BUS正端电压, BUS Positive Voltage
    int16_t  BUSNegativeVoltage;    // BUS负端电压, BUS Negative Voltage

    uint32_t TotalPVGeneration;     // 光伏总发电量, Total Photovoltaic Generation
    uint32_t TotalGridCharge;       //电网总购电量
    uint32_t TotalGridDischarge;    // 电网总放电量, Total Grid Discharge
    uint32_t TotalLoadConsumption;  // 负载总耗电量, Total Load Consumption
    uint32_t TotalAirCdtConsumption;//空调总耗电量

    uint32_t DailyPVGeneration;     // 光伏当天电量, Photovoltaic Generation
    uint32_t StoreRemainingPwr;     //储能余剩电量
    uint32_t DailyLoadCsmpt;        // 负载当天用电量, Daily Load Consumption
    uint32_t DailyGridCharge;       // 电网当天购电量, Daily Grid Purchase
    uint32_t DailyAirCdtConsumption;// 空调当天用电量, Air contidioner Grid Consumption
    uint32_t DailyElseConsumption;  // 其他当天用电量, Daily else Consumption


};
