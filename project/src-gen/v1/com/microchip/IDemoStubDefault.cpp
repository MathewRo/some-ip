/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201808092327.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1/com/microchip/IDemoStubDefault.hpp>
#include <assert.h>

namespace v1 {
namespace com {
namespace microchip {

IDemoStubDefault::IDemoStubDefault():
        remoteEventHandler_(this),
        interfaceVersion_(IDemo::getInterfaceVersion()) {
}

const CommonAPI::Version& IDemoStubDefault::getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
    (void)_client;
    return interfaceVersion_;
}

IDemoStubRemoteEvent* IDemoStubDefault::initStubAdapter(const std::shared_ptr< IDemoStubAdapter> &_adapter) {
    CommonAPI::Stub<IDemoStubAdapter, IDemoStubRemoteEvent>::stubAdapter_ = _adapter;
    return &remoteEventHandler_;
}

 const bool& IDemoStubDefault::getAttribBoolAttribute() {
     return attribBoolAttributeValue_;
 }

 const bool& IDemoStubDefault::getAttribBoolAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
     (void)_client;
     return getAttribBoolAttribute();
 }

 void IDemoStubDefault::setAttribBoolAttribute(bool _value) {
     std::shared_ptr<IDemoStubAdapter> stubAdapter = CommonAPI::Stub<IDemoStubAdapter,
     IDemoStubRemoteEvent>::stubAdapter_.lock();
     if(stubAdapter) {
         stubAdapter->lockAttribBoolAttribute(true);
         const bool valueChanged = (attribBoolAttributeValue_ != _value);
         if (valueChanged) {
             attribBoolAttributeValue_ = std::move(_value);
             fireAttribBoolAttributeChanged(attribBoolAttributeValue_);
         }
         stubAdapter->lockAttribBoolAttribute(false);
     } else {
         const bool valueChanged = trySetAttribBoolAttribute(std::move(_value));
         if (valueChanged) {
             fireAttribBoolAttributeChanged(attribBoolAttributeValue_);
         }
     }
}

 bool IDemoStubDefault::trySetAttribBoolAttribute(bool _value) {
     if (!validateAttribBoolAttributeRequestedValue(_value))
         return false;

     bool valueChanged;
     std::shared_ptr<IDemoStubAdapter> stubAdapter = CommonAPI::Stub<IDemoStubAdapter, IDemoStubRemoteEvent>::stubAdapter_.lock();
     if(stubAdapter) {
         stubAdapter->lockAttribBoolAttribute(true);
         valueChanged = (attribBoolAttributeValue_ != _value);
         attribBoolAttributeValue_ = std::move(_value);
         stubAdapter->lockAttribBoolAttribute(false);
     } else {
         valueChanged = (attribBoolAttributeValue_ != _value);
         attribBoolAttributeValue_ = std::move(_value);
     }

     return valueChanged;
 }

 bool IDemoStubDefault::validateAttribBoolAttributeRequestedValue(const bool &_value) {
     (void)_value;
     return true;
 }

 void IDemoStubDefault::setAttribBoolAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value) {
     (void)_client;
     setAttribBoolAttribute(_value);
 }

 void IDemoStubDefault::onRemoteAttribBoolAttributeChanged() {
     // No operation in default
 }

 void IDemoStubDefault::RemoteEventHandler::onRemoteAttribBoolAttributeChanged() {
     assert(defaultStub_ !=NULL);
     defaultStub_->onRemoteAttribBoolAttributeChanged();
 }

 bool IDemoStubDefault::RemoteEventHandler::onRemoteSetAttribBoolAttribute(bool _value) {
     assert(defaultStub_ !=NULL);
     return defaultStub_->trySetAttribBoolAttribute(std::move(_value));
 }

 bool IDemoStubDefault::RemoteEventHandler::onRemoteSetAttribBoolAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value) {
     (void)_client;
     return onRemoteSetAttribBoolAttribute(_value);
 }


/*
 * description: 
 * Retrieve Attrib
 */
void IDemoStubDefault::GetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, GetAttribReply_t _reply) {
    (void)_client;
    IDemo::GenericErrors error;
    bool data = false;
    _reply(error, data);
}

/*
 * description: 
 * Set Attrib
 */
void IDemoStubDefault::SetAttrib(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value, SetAttribReply_t _reply) {
    (void)_client;
    (void)_value;
    IDemo::GenericErrors error;
    _reply(error);
}


/*
 * description: 
 * Broadcast for notifing client
 */
void IDemoStubDefault::fireStatusEvent(const std::string &_Message) {
    IDemoStub::fireStatusEvent(_Message);
}


IDemoStubDefault::RemoteEventHandler::RemoteEventHandler(IDemoStubDefault *_defaultStub)
    : 
      defaultStub_(_defaultStub) {
}

} // namespace microchip
} // namespace com
} // namespace v1