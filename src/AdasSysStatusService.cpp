// HelloWorldService.cpp
#include <iostream>
#include <thread>
#include <conio.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceStubDefault.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceProxyBase.hpp>
#include <v1/commonapi/FCS_SLIF_IHBC_Status_ServiceStubDefault.hpp>
#include <v1/commonapi/FCS_SLIF_IHBC_Status_ServiceProxyBase.hpp>

using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault> ADAS_SystStatus_Service =
    	std::make_shared<v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault>();
    runtime->registerService("local", "commonapi.ADAS_SystStatus_Service", ADAS_SystStatus_Service,"ADAS_SystStatus_Service");

    std::shared_ptr<v1_0::commonapi::FCS_SLIF_IHBC_Status_ServiceStubDefault> FCS_SLIF_IHBC_Status_Service =
    	std::make_shared<v1_0::commonapi::FCS_SLIF_IHBC_Status_ServiceStubDefault>();
    runtime->registerService("local", "commonapi.FCS_SLIF_IHBC_Status_Service", FCS_SLIF_IHBC_Status_Service,"FCS_SLIF_IHBC_Status_Service");

    std::cout << "Successfully Registered Service!" << std::endl;

    v1_0::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct set_data2;
    set_data2.setFCS_IHBC_LightDistribReq(v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_IHBC_LightDistribReq_Enum::HighBeamNotRecommended);
    set_data2.setFCS_IHBC_Status(v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_IHBC_Status_Enum::Active);

    v1_0::commonapi::ADAS_SystStatus_Service::ADAS_SystStatus_Struct set_data;
    set_data.setADCU_LateralControlStatus(v1::commonapi::ADAS_SystStatus_Service::ADCU_LateralControlStatus_Enum::Passive);
    set_data.setADCU_NOA_Status(v1::commonapi::ADAS_SystStatus_Service::ADCU_NOA_Status_Enum::Active);

    char userInput;
    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
        if (_kbhit()) { // 检查是否有键盘输入
            userInput = _getch(); // 获取键盘输入字符
            if (userInput == 'q' || userInput == 'Q') {
                break; // 如果用户输入了 'q' 或 'Q'，退出循环
            }
            if (userInput == 's' || userInput == 'S') {
                ADAS_SystStatus_Service->setADAS_SystStatusAttribute(set_data);
                FCS_SLIF_IHBC_Status_Service->setFCS_SLIF_IHBC_StatusAttribute(set_data2);

            }
            std::cout << "你输入了: " << userInput << std::endl;
        }
    }
    return 0;
 }