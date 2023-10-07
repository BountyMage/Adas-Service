// AdasSysStatusClient.cpp
#include <iostream>
#include <string>
#include <thread>
//#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceProxy.hpp>
#include <v1/commonapi/FCS_SLIF_IHBC_Status_ServiceProxy.hpp>

using namespace v1_0::commonapi;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<ADAS_SystStatus_ServiceProxy<>> myProxy =
    	runtime->buildProxy<ADAS_SystStatus_ServiceProxy>("local", "commonapi.ADAS_SystStatus_Service","client");
    
    std::shared_ptr<FCS_SLIF_IHBC_Status_ServiceProxy<>> myProxy2 =
    	runtime->buildProxy<FCS_SLIF_IHBC_Status_ServiceProxy>("local", "commonapi.FCS_SLIF_IHBC_Status_Service","client2");

    std::cout << "Checking availability!" << std::endl;
    while (!(myProxy->isAvailable() && myProxy2->isAvailable()))
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    CommonAPI::CallInfo info(1000);

    FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct rec_data2;
    myProxy2->getFCS_SLIF_IHBC_StatusAttribute().getValue(callStatus, rec_data2, &info);

    ADAS_SystStatus_Service::ADAS_SystStatus_Struct rec_data;
    myProxy->getADAS_SystStatusAttribute().getValue(callStatus, rec_data, &info);

    std::cout << "ADCU_NOA_Status: " << rec_data.getADCU_NOA_Status().toString() << "\n" << "ADCU_LateralControlStatus: " << rec_data.getADCU_LateralControlStatus().toString() << "\n";
    std::cout << "FCS_IHBC_LightDistribReq: " << rec_data2.getFCS_IHBC_LightDistribReq().toString() << "\n" << "FCS_IHBC_Status: " << rec_data2.getFCS_IHBC_Status().toString() << "\n";

    myProxy->getADAS_SystStatusAttribute().getChangedEvent().subscribe([&](const ADAS_SystStatus_Service::ADAS_SystStatus_Struct& rec_data) {
        std::cout << "Received change message for ADAS_SystStatus_Service" << std::endl;
        std::cout << "ADCU_NOA_Status: " << rec_data.getADCU_NOA_Status().toString() << "\n" 
            << "ADCU_LateralControlStatus: " << rec_data.getADCU_LateralControlStatus().toString() << "\n";
        });

    myProxy2->getFCS_SLIF_IHBC_StatusAttribute().getChangedEvent().subscribe([&](const FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct& rec_data2) {
        std::cout << "Received change message for ADAS_SystStatus_Service" << std::endl;
        std::cout << "FCS_IHBC_LightDistribReq: " << rec_data2.getFCS_IHBC_LightDistribReq().toString() << "\n"
            << "FCS_IHBC_Status: " << rec_data2.getFCS_IHBC_Status().toString() << "\n";
        });

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }

    return 0;
}