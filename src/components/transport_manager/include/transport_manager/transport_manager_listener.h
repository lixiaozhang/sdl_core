/**
 * \file transport_manager_listener.h
 * \brief interface for TransportManagerListener header file.
 *
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_TRANSPORT_MANAGERLISTENER
#define SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_TRANSPORT_MANAGERLISTENER

namespace transport_manager {

class TransportManagerListener {
public:
	virtual ~TransportManagerListener();

	virtual void onSearchDeviceDone(const DeviceHandle device, const ApplicationList app_list) = 0;
	virtual void onSearchDeviceFailed(const DeviceAdapter* device_adapter,
			const SearchDeviceError& error) = 0;

	virtual void onConnectDone(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id) = 0;
	virtual void onConnectFailed(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const ConnectError& error) = 0;

	virtual void onDisconnectDone(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id) = 0;
	virtual void onDisconnectFailed(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const DisconnectDeviceError& error) = 0;
	virtual void onDisconnectDeviceDone(const DeviceAdapter* device_adapter,
			const SessionID session_id);
	virtual void onDisconnectDeviceFailed(const DeviceAdapter* device_adapter,
			const SessionID session_id, const DisconnectDeviceError& error);

	virtual void onDataReceiveDone(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const RawMessageSptr data_container) = 0;
	virtual void onDataReceiveFailed(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const DataReceiveError& error) = 0;

	virtual void onDataSendDone(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const RawMessageSptr data_container) = 0;
	virtual void onDataSendFailed(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id,
			const DataSendError& error) = 0;

	virtual void onCommunicationError(const DeviceAdapter* device_adapter,
			const transport_manager::SessionID session_id) = 0;
};
} //namespace
#endif //SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_TRANSPORT_MANAGERLISTENER
