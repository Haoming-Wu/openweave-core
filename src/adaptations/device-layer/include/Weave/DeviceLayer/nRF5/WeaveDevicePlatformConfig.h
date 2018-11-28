/*
 *
 *    Copyright (c) 2018 Nest Labs, Inc.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Platform-specific configuration overrides for the Weave Device Layer
 *          on nRF5* platforms using the Nordic SDK.
 */


#ifndef WEAVE_DEVICE_PLATFORM_CONFIG_H
#define WEAVE_DEVICE_PLATFORM_CONFIG_H

/* TODO: Map device configuration values onto the values generated by Kconfig.
 */
#define CONFIG_WEAVE_TASK_STACK_SIZE 4608
#define CONFIG_WEAVE_TASK_PRIORITY 1
#define CONFIG_MAX_EVENT_QUEUE_SIZE 100
#define CONFIG_DEVICE_VENDOR_ID 0x235A
#define CONFIG_DEVICE_PRODUCT_ID 0xFEFF
#define CONFIG_DEVICE_PRODUCT_REVISION 1
#define CONFIG_DEVICE_FIRMWARE_REVISION ""
#define CONFIG_ENABLE_WOBLE 0
#define CONFIG_BLE_DEVICE_NAME_PREFIX "NEST-"
#define CONFIG_BLE_FAST_ADVERTISING_INTERVAL 800
#define CONFIG_BLE_SLOW_ADVERTISING_INTERVAL 3200
#define CONFIG_ENABLE_WEAVE_TIME_SERVICE_TIME_SYNC 1
#define CONFIG_WEAVE_TIME_SERVICE_ENDPOINT_ID 0x18B4300200000005
#define CONFIG_DEFAULT_TIME_SYNC_INTERVAL 60
#define CONFIG_TIME_SYNC_TIMEOUT 10000
#define CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID 0x18B4300200000010
#define CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT 10000
#define CONFIG_ENABLE_TEST_DEVICE_IDENTITY 3
#define CONFIG_DISABLE_ACCOUNT_PAIRING 1

#define WEAVE_DEVICE_CONFIG_WEAVE_TASK_STACK_SIZE CONFIG_WEAVE_TASK_STACK_SIZE
#define WEAVE_DEVICE_CONFIG_WEAVE_TASK_PRIORITY CONFIG_WEAVE_TASK_PRIORITY
#define WEAVE_DEVICE_CONFIG_MAX_EVENT_QUEUE_SIZE CONFIG_MAX_EVENT_QUEUE_SIZE
#define WEAVE_DEVICE_CONFIG_DEVICE_VENDOR_ID CONFIG_DEVICE_VENDOR_ID
#define WEAVE_DEVICE_CONFIG_DEVICE_PRODUCT_ID CONFIG_DEVICE_PRODUCT_ID
#define WEAVE_DEVICE_CONFIG_DEVICE_PRODUCT_REVISION CONFIG_DEVICE_PRODUCT_REVISION
#define WEAVE_DEVICE_CONFIG_DEVICE_FIRMWARE_REVISION CONFIG_DEVICE_FIRMWARE_REVISION
#define WEAVE_DEVICE_CONFIG_ENABLE_WOBLE CONFIG_ENABLE_WOBLE
#define WEAVE_DEVICE_CONFIG_BLE_DEVICE_NAME_PREFIX CONFIG_BLE_DEVICE_NAME_PREFIX
#define WEAVE_DEVICE_CONFIG_BLE_FAST_ADVERTISING_INTERVAL CONFIG_BLE_FAST_ADVERTISING_INTERVAL
#define WEAVE_DEVICE_CONFIG_BLE_SLOW_ADVERTISING_INTERVAL CONFIG_BLE_SLOW_ADVERTISING_INTERVAL
#define WEAVE_DEVICE_CONFIG_ENABLE_WEAVE_TIME_SERVICE_TIME_SYNC CONFIG_ENABLE_WEAVE_TIME_SERVICE_TIME_SYNC
#define WEAVE_DEVICE_CONFIG_WEAVE_TIME_SERVICE_ENDPOINT_ID CONFIG_WEAVE_TIME_SERVICE_ENDPOINT_ID
#define WEAVE_DEVICE_CONFIG_DEFAULT_TIME_SYNC_INTERVAL CONFIG_DEFAULT_TIME_SYNC_INTERVAL
#define WEAVE_DEVICE_CONFIG_TIME_SYNC_TIMEOUT CONFIG_TIME_SYNC_TIMEOUT
#define WEAVE_DEVICE_CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID CONFIG_SERVICE_PROVISIONING_ENDPOINT_ID
#define WEAVE_DEVICE_CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT CONFIG_SERVICE_PROVISIONING_CONNECTIVITY_TIMEOUT
#define WEAVE_DEVICE_CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT CONFIG_SERVICE_PROVISIONING_REQUEST_TIMEOUT
#define WEAVE_DEVICE_CONFIG_ENABLE_TEST_DEVICE_IDENTITY CONFIG_ENABLE_TEST_DEVICE_IDENTITY
#define WEAVE_DEVICE_CONFIG_DISABLE_ACCOUNT_PAIRING CONFIG_DISABLE_ACCOUNT_PAIRING

#endif // WEAVE_DEVICE_PLATFORM_CONFIG_H