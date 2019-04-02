// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/node/inspector/protocol/NodeWorker.h"

#include "src/node/inspector/protocol/Protocol.h"

namespace node {
namespace inspector {
namespace protocol {
namespace NodeWorker {

// ------------- Enum values from types.

const char Metainfo::domainName[] = "NodeWorker";
const char Metainfo::commandPrefix[] = "NodeWorker.";
const char Metainfo::version[] = "1.0";

std::unique_ptr<WorkerInfo> WorkerInfo::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->addError("object expected");
        return nullptr;
    }

    std::unique_ptr<WorkerInfo> result(new WorkerInfo());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->push();
    protocol::Value* workerIdValue = object->get("workerId");
    errors->setName("workerId");
    result->m_workerId = ValueConversions<String>::fromValue(workerIdValue, errors);
    protocol::Value* typeValue = object->get("type");
    errors->setName("type");
    result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
    protocol::Value* titleValue = object->get("title");
    errors->setName("title");
    result->m_title = ValueConversions<String>::fromValue(titleValue, errors);
    protocol::Value* urlValue = object->get("url");
    errors->setName("url");
    result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
    errors->pop();
    if (errors->hasErrors())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> WorkerInfo::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("workerId", ValueConversions<String>::toValue(m_workerId));
    result->setValue("type", ValueConversions<String>::toValue(m_type));
    result->setValue("title", ValueConversions<String>::toValue(m_title));
    result->setValue("url", ValueConversions<String>::toValue(m_url));
    return result;
}

std::unique_ptr<WorkerInfo> WorkerInfo::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<AttachedToWorkerNotification> AttachedToWorkerNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->addError("object expected");
        return nullptr;
    }

    std::unique_ptr<AttachedToWorkerNotification> result(new AttachedToWorkerNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->push();
    protocol::Value* sessionIdValue = object->get("sessionId");
    errors->setName("sessionId");
    result->m_sessionId = ValueConversions<String>::fromValue(sessionIdValue, errors);
    protocol::Value* workerInfoValue = object->get("workerInfo");
    errors->setName("workerInfo");
    result->m_workerInfo = ValueConversions<protocol::NodeWorker::WorkerInfo>::fromValue(workerInfoValue, errors);
    protocol::Value* waitingForDebuggerValue = object->get("waitingForDebugger");
    errors->setName("waitingForDebugger");
    result->m_waitingForDebugger = ValueConversions<bool>::fromValue(waitingForDebuggerValue, errors);
    errors->pop();
    if (errors->hasErrors())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> AttachedToWorkerNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("sessionId", ValueConversions<String>::toValue(m_sessionId));
    result->setValue("workerInfo", ValueConversions<protocol::NodeWorker::WorkerInfo>::toValue(m_workerInfo.get()));
    result->setValue("waitingForDebugger", ValueConversions<bool>::toValue(m_waitingForDebugger));
    return result;
}

std::unique_ptr<AttachedToWorkerNotification> AttachedToWorkerNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<DetachedFromWorkerNotification> DetachedFromWorkerNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->addError("object expected");
        return nullptr;
    }

    std::unique_ptr<DetachedFromWorkerNotification> result(new DetachedFromWorkerNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->push();
    protocol::Value* sessionIdValue = object->get("sessionId");
    errors->setName("sessionId");
    result->m_sessionId = ValueConversions<String>::fromValue(sessionIdValue, errors);
    errors->pop();
    if (errors->hasErrors())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> DetachedFromWorkerNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("sessionId", ValueConversions<String>::toValue(m_sessionId));
    return result;
}

std::unique_ptr<DetachedFromWorkerNotification> DetachedFromWorkerNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<ReceivedMessageFromWorkerNotification> ReceivedMessageFromWorkerNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->addError("object expected");
        return nullptr;
    }

    std::unique_ptr<ReceivedMessageFromWorkerNotification> result(new ReceivedMessageFromWorkerNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->push();
    protocol::Value* sessionIdValue = object->get("sessionId");
    errors->setName("sessionId");
    result->m_sessionId = ValueConversions<String>::fromValue(sessionIdValue, errors);
    protocol::Value* messageValue = object->get("message");
    errors->setName("message");
    result->m_message = ValueConversions<String>::fromValue(messageValue, errors);
    errors->pop();
    if (errors->hasErrors())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> ReceivedMessageFromWorkerNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("sessionId", ValueConversions<String>::toValue(m_sessionId));
    result->setValue("message", ValueConversions<String>::toValue(m_message));
    return result;
}

std::unique_ptr<ReceivedMessageFromWorkerNotification> ReceivedMessageFromWorkerNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

// ------------- Enum values from params.


// ------------- Frontend notifications.

void Frontend::attachedToWorker(const String& sessionId, std::unique_ptr<protocol::NodeWorker::WorkerInfo> workerInfo, bool waitingForDebugger)
{
    if (!m_frontendChannel)
        return;
    std::unique_ptr<AttachedToWorkerNotification> messageData = AttachedToWorkerNotification::create()
        .setSessionId(sessionId)
        .setWorkerInfo(std::move(workerInfo))
        .setWaitingForDebugger(waitingForDebugger)
        .build();
    m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("NodeWorker.attachedToWorker", std::move(messageData)));
}

void Frontend::detachedFromWorker(const String& sessionId)
{
    if (!m_frontendChannel)
        return;
    std::unique_ptr<DetachedFromWorkerNotification> messageData = DetachedFromWorkerNotification::create()
        .setSessionId(sessionId)
        .build();
    m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("NodeWorker.detachedFromWorker", std::move(messageData)));
}

void Frontend::receivedMessageFromWorker(const String& sessionId, const String& message)
{
    if (!m_frontendChannel)
        return;
    std::unique_ptr<ReceivedMessageFromWorkerNotification> messageData = ReceivedMessageFromWorkerNotification::create()
        .setSessionId(sessionId)
        .setMessage(message)
        .build();
    m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("NodeWorker.receivedMessageFromWorker", std::move(messageData)));
}

void Frontend::flush()
{
    m_frontendChannel->flushProtocolNotifications();
}

void Frontend::sendRawNotification(const String& notification)
{
    m_frontendChannel->sendProtocolNotification(InternalRawNotification::create(notification));
}

// --------------------- Dispatcher.

class DispatcherImpl : public protocol::DispatcherBase {
public:
    DispatcherImpl(FrontendChannel* frontendChannel, Backend* backend, bool fallThroughForNotFound)
        : DispatcherBase(frontendChannel)
        , m_backend(backend)
        , m_fallThroughForNotFound(fallThroughForNotFound) {
        m_dispatchMap["NodeWorker.sendMessageToWorker"] = &DispatcherImpl::sendMessageToWorker;
        m_dispatchMap["NodeWorker.enable"] = &DispatcherImpl::enable;
        m_dispatchMap["NodeWorker.disable"] = &DispatcherImpl::disable;
    }
    ~DispatcherImpl() override { }
    DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
    HashMap<String, String>& redirects() { return m_redirects; }

protected:
    using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
    using DispatchMap = protocol::HashMap<String, CallHandler>;
    DispatchMap m_dispatchMap;
    HashMap<String, String> m_redirects;

    DispatchResponse::Status sendMessageToWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
    DispatchResponse::Status enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
    DispatchResponse::Status disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

    Backend* m_backend;
    bool m_fallThroughForNotFound;
};

DispatchResponse::Status DispatcherImpl::dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject)
{
    protocol::HashMap<String, CallHandler>::iterator it = m_dispatchMap.find(method);
    if (it == m_dispatchMap.end()) {
        if (m_fallThroughForNotFound)
            return DispatchResponse::kFallThrough;
        reportProtocolError(callId, DispatchResponse::kMethodNotFound, "'" + method + "' wasn't found", nullptr);
        return DispatchResponse::kError;
    }

    protocol::ErrorSupport errors;
    return (this->*(it->second))(callId, std::move(messageObject), &errors);
}


DispatchResponse::Status DispatcherImpl::sendMessageToWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
    errors->push();
    protocol::Value* messageValue = object ? object->get("message") : nullptr;
    errors->setName("message");
    String in_message = ValueConversions<String>::fromValue(messageValue, errors);
    protocol::Value* sessionIdValue = object ? object->get("sessionId") : nullptr;
    errors->setName("sessionId");
    String in_sessionId = ValueConversions<String>::fromValue(sessionIdValue, errors);
    errors->pop();
    if (errors->hasErrors()) {
        reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
        return DispatchResponse::kError;
    }

    std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->sendMessageToWorker(in_message, in_sessionId);
    if (response.status() == DispatchResponse::kFallThrough)
        return response.status();
    if (weak->get())
        weak->get()->sendResponse(callId, response);
    return response.status();
}

DispatchResponse::Status DispatcherImpl::enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
    errors->push();
    protocol::Value* waitForDebuggerOnStartValue = object ? object->get("waitForDebuggerOnStart") : nullptr;
    errors->setName("waitForDebuggerOnStart");
    bool in_waitForDebuggerOnStart = ValueConversions<bool>::fromValue(waitForDebuggerOnStartValue, errors);
    errors->pop();
    if (errors->hasErrors()) {
        reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
        return DispatchResponse::kError;
    }

    std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->enable(in_waitForDebuggerOnStart);
    if (response.status() == DispatchResponse::kFallThrough)
        return response.status();
    if (weak->get())
        weak->get()->sendResponse(callId, response);
    return response.status();
}

DispatchResponse::Status DispatcherImpl::disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
{

    std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->disable();
    if (response.status() == DispatchResponse::kFallThrough)
        return response.status();
    if (weak->get())
        weak->get()->sendResponse(callId, response);
    return response.status();
}

// static
void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
{
    std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
    uber->setupRedirects(dispatcher->redirects());
    uber->registerBackend("NodeWorker", std::move(dispatcher));
}

} // NodeWorker
} // namespace node
} // namespace inspector
} // namespace protocol
