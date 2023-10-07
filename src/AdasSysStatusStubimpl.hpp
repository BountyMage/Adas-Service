// HelloWorldStubImpl.hpp
#ifndef ADASSYSSTATUSSTUBIMPL_H_
#define ADASSYSSTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ADAS_SystStatus_ServiceStubDefault.hpp>

class AdasSysStatusStubimpl: public v1_0::commonapi::ADAS_SystStatus_ServiceStubDefault {
public:
    AdasSysStatusStubimpl();
    virtual ~AdasSysStatusStubimpl();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sayHelloReply_t _return);
};
#endif /* HELLOWORLDSTUBIMPL_H_ */