#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> // std::copy

#include "RS485Interface.h"



 /**
 * @brief 将从逆变器提取到的数据还有电表的数据，整理保存到寄存器数组 Ivt_Display_Ro_Data与Ivt_Display_Rw_Data
 * 提取要显示的变量，假设modbus-tcp的网关寄存器名字为Display_Data
 * 这个函数接受逆变器数据与电表数据，无返回值。
 *
 * @param uint16_t* source 逆变器数据,源数据
 * @param uint16_t* Ivt_Display_Ro_Data  目标地址1
 * @param uint16_t* Ivt_Display_Rw_Data  目标地址2
 * @return int
 */

int Inverter::Get_Display_var(uint16_t* Ivt_Display_Ro_Data,uint16_t* Ivt_Display_Rw_Data,uint16_t* source) const  
{
    std::cout << "整理光伏板部分数据,   0x3130 至 0x3189 90个数,写至 *Inverter_Data " << std::endl;//DEBUG
    // PV 0x3130-0x3138
    std::copy(source,source+9,Ivt_Display_Ro_Data);

    //电池母线0x3140,0x3141
    Ivt_Display_Ro_Data[9] =source[9];
    Ivt_Display_Ro_Data[10]=source[10];
    //bus  0x3150,0x3151
    Ivt_Display_Ro_Data[11]=source[0x3150 -0x3130];
    Ivt_Display_Ro_Data[12]=source[0x3151 -0x3130];

    //0x3165 光伏总发电量/0x317D 电网总购电量/0x3167 电网总放电量/负载总耗电量/空调总耗电量
    Ivt_Display_Ro_Data[13]=source[0x3165 -0x3130];
    Ivt_Display_Ro_Data[14]=source[0x3166 -0x3130];

    Ivt_Display_Ro_Data[15]=source[0x317D -0x3130];
    Ivt_Display_Ro_Data[16]=source[0x317E -0x3130];

    Ivt_Display_Ro_Data[17]=source[0x3167 -0x3130];
    Ivt_Display_Ro_Data[18]=source[0x3168 -0x3130];
    //需要计算 负载总耗电量/空调总耗电量
    // Ivt_Display_Ro_Data[19]=source[0x3150 -0x3130];
    // Ivt_Display_Ro_Data[20]=source[0x3151 -0x3130];
    // Ivt_Display_Ro_Data[21]=source[0x3150 -0x3130];
    // Ivt_Display_Ro_Data[22]=source[0x3151 -0x3130];
    //适合首页显示 
    //0x3153 今日发电 原名光伏当天发电量
    Ivt_Display_Ro_Data[23]=source[0x3153 -0x3130];
    Ivt_Display_Ro_Data[24]=source[0x3154 -0x3130];
    //储能余剩,需要计算
    // Ivt_Display_Ro_Data[25]=source[0x3153 -0x3130];
    // Ivt_Display_Ro_Data[26]=source[0x3154 -0x3130];
    //今日用电,需要计算
    // Ivt_Display_Ro_Data[27]=source[0x3153 -0x3130];
    // Ivt_Display_Ro_Data[28]=source[0x3154 -0x3130];
    //0x316B 今日电网供电，原名电网当天购电量
    Ivt_Display_Ro_Data[29]=source[0x316B -0x3130];
    Ivt_Display_Ro_Data[30]=source[0x316C -0x3130];
    //今日空调用电,需要计算
    // Ivt_Display_Ro_Data[31]=source[0x3153 -0x3130];
    // Ivt_Display_Ro_Data[32]=source[0x3154 -0x3130];
    //今日其他负载用电,需要计算
    // Ivt_Display_Ro_Data[33]=source[0x3153 -0x3130];
    // Ivt_Display_Ro_Data[34]=source[0x3154 -0x3130];
    std::cout << "整理光伏板部分数据完成 " << std::endl;//DEBUG
    std::cout << "光伏板部分数据测试打印 test1" << std::endl;//DEBUG
    for(int i=0;i<35;i++)
    {//DEBUG
        std::cout << "test1 Ivt_Display_Ro_Data["<<i <<"]="<<Ivt_Display_Ro_Data[i]<< std::endl;//DEBUG
    }

    //读写部
    std::cout << "整理设置部分数据,     0x3400 至 0x3493 148个数,写至 *Inverter_Data+90" << std::endl;//DEBUG
    //0x340F 电池类型
    Ivt_Display_Rw_Data[0]=source[90 + 0x340F -0x3400];
    //0x3402 电池充电电流
    Ivt_Display_Rw_Data[1]=source[90 + 0x3402 -0x3400];
    //0x3404 电池放电功率调度
    Ivt_Display_Rw_Data[2]=source[90 + 0x3404 -0x3400];
    //0x3401 并网放电深度原名 并网DOD
    Ivt_Display_Rw_Data[3]=source[90 + 0x3401 -0x3400];
    //0x341E 离网放电深度
    Ivt_Display_Rw_Data[4]=source[90 + 0x341E -0x3400];
    //0x3493 并网回差
    Ivt_Display_Rw_Data[5]=source[90 + 0x3493 -0x3400];
    //0x3418 离网回差
    Ivt_Display_Rw_Data[6]=source[90 + 0x3418 -0x3400];
    //0x341B 铅酸电池AH
    Ivt_Display_Rw_Data[7]=source[90 + 0x341B -0x3400];
    //0x3470 铅酸电池恒压充电电压
    Ivt_Display_Rw_Data[8]=source[90 + 0x3470 -0x3400];
    //0x3410 铅酸电池浮充电压
    Ivt_Display_Rw_Data[9]=source[90 + 0x3410 -0x3400];
    //0x3412 铅酸电池充电保护电压
    Ivt_Display_Rw_Data[10]=source[90 + 0x3412 -0x3400];
    //0x341C 铅酸放电截止电压
    Ivt_Display_Rw_Data[11]=source[90 + 0x341C -0x3400];
    //0x3400 工作模式（三大）
    Ivt_Display_Rw_Data[12]=source[90];
    //0x3443 高级工作模式（三小）
    Ivt_Display_Rw_Data[13]=source[90 + 0x3443 -0x3400];
    std::cout << "整理设置部分数据完成 " << std::endl;//DEBUG
    std::cout << "设置部分数据测试打印 test2" << std::endl;//DEBUG
    for(int i=0;i<14;i++)
    {//DEBUG
        std::cout << "test2 Ivt_Display_Rw_Data["<<i <<"]="<<Ivt_Display_Rw_Data[i]<< std::endl;//DEBUG
    }
    std::cout << "整理削峰填谷设置部分数据, 0x3500 至 0x350f 16个数,写至 *Inverter_Data+240" << std::endl;//DEBUG
    //0x3500-0x3503     4   年/月// 日/保留// 时/分// 秒/星期
    //0x3504-0x350F     12  削峰填谷时间
    //一共16个数据
    std::copy(source+240,source+4+12+240,Ivt_Display_Rw_Data+14);
    std::cout << "整理削峰填谷设置部分数据整理完成" << std::endl;//DEBUG
    std::cout << "削峰填谷设置测试打印 test3" << std::endl;//DEBUG
    for(int i=14;i<30;i++)
    {//DEBUG
        std::cout << "test3 Ivt_Display_Rw_Data["<<i <<"]="<<Ivt_Display_Rw_Data[i]<< std::endl;//DEBUG
    }
    return 0;
}


// 主函数
int main() {

    Inverter Inverter1;
    uint16_t Inverter_Data[260]={12,34,45,78};
    
    for(int i=0;i<260;i++)
    {//DEBUG 生成一些测试数据
        Inverter_Data[i]=i*10;
    }
    // Inverter_Data[90]=123;
    // Inverter_Data[240]=132;

    std::cout << "int modbus_read_registers(modbus_t *ctx, 1 , 100, uint16_t *dest);" << std::endl;
    std::cout << "光伏板部分数据,   0x3130 至 0x3189 90个数,写至 *Inverter_Data" << std::endl;
    std::cout << "int modbus_read_registers(modbus_t *ctx, 1 , 100, uint16_t *dest);" << std::endl;
    std::cout << "设置部分数据,     0x3400 至 0x344F 80个数,写至 *Inverter_Data+90" << std::endl;
    std::cout << "int modbus_read_registers(modbus_t *ctx, 1 , 100, uint16_t *dest);" << std::endl;
    std::cout << "设置部分数据,     0x3450 至 0x3493 68个数,写至 *Inverter_Data+170" << std::endl;
    std::cout << "int modbus_read_registers(modbus_t *ctx, 1 , 100, uint16_t *dest);" << std::endl;
    std::cout << "削峰填谷部分数据,  0x3500 至 0x350f 16个数,写至 *Inverter_Data+240" << std::endl;
    Inverter1.Get_Display_var(Inverter1.Ivt_Display_Ro_Data,Inverter1.Ivt_Display_Rw_Data,Inverter_Data) ;//将要显示的数据写到网关寄存器，供屏幕读取
    
    uint16_t* a=NULL;
    a=Inverter1.Get_Ivt_Time(Inverter1.Ivt_Display_Ro_Data,Inverter1.Ivt_Display_Rw_Data);
    for(int i=0;i<4;i++)
    {//DEBUG
        std::cout <<i <<"a=" <<a[i]<<std::endl;
    }
    std::cout << "光伏发电量=" << Inverter1.Get_DailyPVGeneration(Inverter1.Ivt_Display_Ro_Data,Inverter1.Ivt_Display_Rw_Data)  << std::endl;
    return 0;
}