/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_PROXY_HPP_
#define V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_PROXY_HPP_

#include <v1/commonapi/FCS_SLIF_IHBC_Status_ServiceProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/AttributeExtension.hpp>
#include <CommonAPI/Factory.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename ... _AttributeExtensions>
class FCS_SLIF_IHBC_Status_ServiceProxy
    : virtual public FCS_SLIF_IHBC_Status_Service,
      virtual public FCS_SLIF_IHBC_Status_ServiceProxyBase,
      virtual public _AttributeExtensions... {
public:
    FCS_SLIF_IHBC_Status_ServiceProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~FCS_SLIF_IHBC_Status_ServiceProxy();

    typedef FCS_SLIF_IHBC_Status_Service InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Returns the wrapper class that provides access to the attribute FCS_SLIF_IHBC_Status.
     */
    virtual FCS_SLIF_IHBC_StatusAttribute& getFCS_SLIF_IHBC_StatusAttribute() {
        return delegate_->getFCS_SLIF_IHBC_StatusAttribute();
    }



 private:
    std::shared_ptr< FCS_SLIF_IHBC_Status_ServiceProxyBase> delegate_;
};

typedef FCS_SLIF_IHBC_Status_ServiceProxy<> FCS_SLIF_IHBC_Status_ServiceProxyDefault;

namespace FCS_SLIF_IHBC_Status_ServiceExtensions {
    template <template <typename > class _ExtensionType>
    class FCS_SLIF_IHBC_StatusAttributeExtension {
     public:
        typedef _ExtensionType< FCS_SLIF_IHBC_Status_ServiceProxyBase::FCS_SLIF_IHBC_StatusAttribute> extension_type;
    
        static_assert(std::is_base_of<typename CommonAPI::AttributeExtension< FCS_SLIF_IHBC_Status_ServiceProxyBase::FCS_SLIF_IHBC_StatusAttribute>, extension_type>::value,
                      "Not CommonAPI Attribute Extension!");
    
        FCS_SLIF_IHBC_StatusAttributeExtension(FCS_SLIF_IHBC_Status_ServiceProxyBase& proxy): attributeExtension_(proxy.getFCS_SLIF_IHBC_StatusAttribute()) {
        }
    
        inline extension_type& getFCS_SLIF_IHBC_StatusAttributeExtension() {
            return attributeExtension_;
        }
    
     private:
        extension_type attributeExtension_;
    };

} // namespace FCS_SLIF_IHBC_Status_ServiceExtensions

//
// FCS_SLIF_IHBC_Status_ServiceProxy Implementation
//
template <typename ... _AttributeExtensions>
FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::FCS_SLIF_IHBC_Status_ServiceProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< FCS_SLIF_IHBC_Status_ServiceProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< FCS_SLIF_IHBC_Status_ServiceProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::~FCS_SLIF_IHBC_Status_ServiceProxy() {
}


template <typename ... _AttributeExtensions>
const CommonAPI::Address &FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> FCS_SLIF_IHBC_Status_ServiceProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace commonapi
} // namespace v1

namespace CommonAPI {
template<template<typename > class _AttributeExtension>
struct DefaultAttributeProxyHelper< ::v1::commonapi::FCS_SLIF_IHBC_Status_ServiceProxy,
    _AttributeExtension> {
    typedef typename ::v1::commonapi::FCS_SLIF_IHBC_Status_ServiceProxy<
            ::v1::commonapi::FCS_SLIF_IHBC_Status_ServiceExtensions::FCS_SLIF_IHBC_StatusAttributeExtension<_AttributeExtension>
    > class_t;
};
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_FCS__SLIF__IHBC__Status__Service_PROXY_HPP_
