/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_STUB_DEFAULT_HPP_
#define V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_STUB_DEFAULT_HPP_


#include <CommonAPI/Export.hpp>

#include <v1/commonapi/FCS_SLIF_IHBC_Status_ServiceStub.hpp>
#include <cassert>
#include <sstream>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v1 {
namespace commonapi {

/**
 * Provides a default implementation for FCS_SLIF_IHBC_Status_ServiceStubRemoteEvent and
 * FCS_SLIF_IHBC_Status_ServiceStub. Method callbacks have an empty implementation,
 * remote set calls on attributes will always change the value of the attribute
 * to the one received.
 *
 * Override this stub if you only want to provide a subset of the functionality
 * that would be defined for this service, and/or if you do not need any non-default
 * behaviour.
 */
class COMMONAPI_EXPORT_CLASS_EXPLICIT FCS_SLIF_IHBC_Status_ServiceStubDefault
    : public virtual FCS_SLIF_IHBC_Status_ServiceStub {
public:
    COMMONAPI_EXPORT FCS_SLIF_IHBC_Status_ServiceStubDefault()
        : remoteEventHandler_(this),
          interfaceVersion_(FCS_SLIF_IHBC_Status_Service::getInterfaceVersion()) {
    }

    COMMONAPI_EXPORT const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return interfaceVersion_;
    }

    COMMONAPI_EXPORT FCS_SLIF_IHBC_Status_ServiceStubRemoteEvent* initStubAdapter(const std::shared_ptr< FCS_SLIF_IHBC_Status_ServiceStubAdapter> &_adapter) {
        CommonAPI::Stub<FCS_SLIF_IHBC_Status_ServiceStubAdapter, FCS_SLIF_IHBC_Status_ServiceStubRemoteEvent>::stubAdapter_ = _adapter;
        return &remoteEventHandler_;
    }

    COMMONAPI_EXPORT virtual const ::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct &getFCS_SLIF_IHBC_StatusAttribute() {
        return fCS_SLIF_IHBC_StatusAttributeValue_;
    }
    COMMONAPI_EXPORT virtual const ::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct &getFCS_SLIF_IHBC_StatusAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
        (void)_client;
        return getFCS_SLIF_IHBC_StatusAttribute();
    }
    COMMONAPI_EXPORT virtual void setFCS_SLIF_IHBC_StatusAttribute(::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct _value) {
        const bool valueChanged = trySetFCS_SLIF_IHBC_StatusAttribute(std::move(_value));
        if (valueChanged) {
            fireFCS_SLIF_IHBC_StatusAttributeChanged(fCS_SLIF_IHBC_StatusAttributeValue_);
        }
    }


protected:
    COMMONAPI_EXPORT virtual bool trySetFCS_SLIF_IHBC_StatusAttribute(::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct _value) {
        if (!validateFCS_SLIF_IHBC_StatusAttributeRequestedValue(_value))
            return false;

        bool valueChanged;
        std::shared_ptr<FCS_SLIF_IHBC_Status_ServiceStubAdapter> stubAdapter = CommonAPI::Stub<FCS_SLIF_IHBC_Status_ServiceStubAdapter, FCS_SLIF_IHBC_Status_ServiceStubRemoteEvent>::stubAdapter_.lock();
        if(stubAdapter) {
            stubAdapter->lockFCS_SLIF_IHBC_StatusAttribute(true);
            valueChanged = (fCS_SLIF_IHBC_StatusAttributeValue_ != _value);
            fCS_SLIF_IHBC_StatusAttributeValue_ = std::move(_value);
            stubAdapter->lockFCS_SLIF_IHBC_StatusAttribute(false);
        } else {
            valueChanged = (fCS_SLIF_IHBC_StatusAttributeValue_ != _value);
            fCS_SLIF_IHBC_StatusAttributeValue_ = std::move(_value);
        }

       return valueChanged;
    }
    COMMONAPI_EXPORT virtual bool validateFCS_SLIF_IHBC_StatusAttributeRequestedValue(const ::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct &_value) {
        (void)_value;
        return true;
    }
    class COMMONAPI_EXPORT_CLASS_EXPLICIT RemoteEventHandler: public virtual FCS_SLIF_IHBC_Status_ServiceStubRemoteEvent {
    public:
        COMMONAPI_EXPORT RemoteEventHandler(FCS_SLIF_IHBC_Status_ServiceStubDefault *_defaultStub)
            : 
              defaultStub_(_defaultStub) {
        }


    private:
        FCS_SLIF_IHBC_Status_ServiceStubDefault *defaultStub_;
    };
protected:
    FCS_SLIF_IHBC_Status_ServiceStubDefault::RemoteEventHandler remoteEventHandler_;

private:

    ::v1::commonapi::FCS_SLIF_IHBC_Status_Service::FCS_SLIF_IHBC_Status_Struct fCS_SLIF_IHBC_StatusAttributeValue_ {};

    CommonAPI::Version interfaceVersion_;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_STUB_DEFAULT
