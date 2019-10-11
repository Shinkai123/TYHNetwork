//
//  CameraStructGroup.h
//  IOTCamera
//
//  Created by lizhijian<lizhijian_21@163.com> on 2017/3/2.
//  Copyright © 2017年 concox. All rights reserved.
//

#ifndef CameraStructGroup_h
#define CameraStructGroup_h

typedef struct LAN_SEARCH
{
    char UID[21];
    char IP[17];
    unsigned short port;
    char DeviceName[24];
    char DevicePWD[24];
} LanSearch_t;

typedef struct CAMERA_NET_INFO_EX
{
    unsigned int size; //!< size of the structure
    unsigned char Mode; //!< 0: P2P mode, 1: Relay mode, 2: LAN mode
    char CorD; //!< 0: As a Client, 1: As a Device
    char UID[21]; //!< The UID of the device
    char RemoteIP[17]; //!< The IP address of remote site used during this IOTC session
    unsigned short RemotePort; //!< The port number of remote site used during this IOTC session
    unsigned int TX_Packetcount; //!< The total packets sent from the device and the client during this IOTC session
    unsigned int RX_Packetcount; //!< The total packets received in the device and the client during this IOTC session
    unsigned int IOTCVersion; //!< The IOTC version
    unsigned short VID; //!< The Vendor ID, part of VPG mechanism
    unsigned short PID; //!< The Product ID, part of VPG mechanism
    unsigned short GID; //!< The Group ID, part of VPG mechanism
    unsigned char isSecure; //!< 0: The IOTC session is in non-secure mode, 1: The IOTC session is in secure mode
    unsigned char LocalNatType; //!< The local NAT type, 0: Unknown type, 1: Type 1, 2: Type 2, 3: Type 3, 10: TCP only
    unsigned char RemoteNatType; //!< The remote NAT type, 0: Unknown type, 1: Type 1, 2: Type 2, 3: Type 3, 10: TCP only
    unsigned char RelayType; //!< 0: Not Relay, 1: UDP Relay, 2: TCP Relay
    unsigned int NetState; //!<If no UDP packet is ever received, the first bit of value is 1, otherwise 0
    char RemoteWANIP[17]; //!< The WAN IP address of remote site used during this IOTC session and it is only valid in P2P or Relay mode
    unsigned short RemoteWANPort; //!< The WAN port number of remote site used during this IOTC session and it is only valid in P2P or Relay mode
} CameraNetInfo_Ex;

#endif /* CameraStructGroup_h */
