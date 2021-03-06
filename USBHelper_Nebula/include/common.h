#pragma once
#include <stdint.h>

#define FILEVERSION "1.1.1.3"

#define NUM 60

#define NEBULA_VID		0x0483
#define P1_VID			0x0ED1

enum eDevicePid
{
	GATEWAY_PID	=	0x6001,
	T8A_PID		=	0x6002,
	T9A_PID		=	0x6003,
	X8_PID		=	0x600d,
	T7PL_PID	=   0x600e,
	T7E_TS_PID	=	0x600f,
	T9_J0_PID	=	0x6012,
	DONGLE_PID  =	0x5001,
	P1_PID		=   0x7806,
};

enum eDeviceType
{
	Unknow = 0,
	RobotPen_P7,
	Elite,
	Elite_Plus,
	RobotPen_P1,
	Elite_Plus_New,
	T8A,
	Elite_XY,
	J0_A5,
	Gateway,
	Dongle,
	J0_A4,
	T9A,
	X8,
	T7PL,
	T7E_TS,
	T7_TS,
	T7_XGL,
	T9_J0,
	J0_A4_P,
};
////////////////////////////////////////NEBULA///////////////////////////////////////
#pragma pack(1)
//状态
typedef struct node_status
{
	uint8_t	 device_status;
	uint8_t  battery_level;
	uint8_t  note_num;
}NODE_STATUS;
//报告
typedef struct robot_report
{
	uint8_t cmd_id;
	uint8_t reserved;
	uint8_t payload[60];
}ROBOT_REPORT;
//版本
typedef struct st_version
{
	uint8_t version;
	uint8_t version2;
	uint8_t version3;
	uint8_t version4;
}ST_VERSION;
//设备信息
typedef struct st_device_info
{
	ST_VERSION version;
	uint8_t  custom_num;
	uint8_t  class_num;
	uint8_t  device_num;
	uint8_t  mac[6];
	uint16_t  hardware_num;

}ST_DEVICE_INFO;
//设备版本号
typedef struct st_device_version
{
	uint16_t hard_version;
	ST_VERSION version;

}ST_DEVICE_VERSION;
//模组版本号
typedef struct st_module_version
{
	uint8_t  low_version;
	uint8_t  high_version;
	uint8_t  adjust;

}ST_MODULE_VERSION;

typedef struct st_option_packet
{
	uint8_t id;
	uint8_t option[6];

}ST_OPTION_PACKET;

typedef struct st_rtc_info
{
	uint8_t note_time_year;
	uint8_t note_time_month;
	uint8_t note_time_day;
	uint8_t note_time_hour;
	uint8_t note_time_min;

} ST_RTC_INFO;

typedef struct st_elite_header_info
{
	uint16_t note_identifier;
	uint8_t note_number;
	uint8_t flash_erase_flag;
	uint16_t note_start_sector;
	uint32_t note_len;
	ST_RTC_INFO note_time;

} ST_ELITE_HEADER_INFO;

typedef struct st_note_header_info
{
	uint16_t note_identifier;
	uint16_t note_number;
	uint8_t flash_erase_flag;
	uint8_t note_head_start;
	uint16_t note_start_sector;
	uint32_t note_len;
	ST_RTC_INFO note_time;

} ST_NOTE_HEADER_INFO;

#pragma pack()

enum eNebulaError
{
	ERROR_NONE,
	ERROR_FLOW_NUM,
	ERROR_FW_LEN,
	ERROR_FW_CHECKSUM,
	ERROR_STATUS,
	ERROR_VERSION,
	ERROR_NAME_CONTENT,
	ERROR_NO_NOTE,
};

enum eGatewayStatus
{
	NEBULA_STATUS_OFFLINE = 0,
	NEBULA_STATUS_STANDBY,
	NEBULA_STATUS_VOTE,
	NEBULA_STATUS_MASSDATA,
	NEBULA_STATUS_CONFIG,
	NEBULA_STATUS_DFU,
	NEBULA_STATUS_MULTI_VOTE,
	NEBULA_STATUS_VOTE_ANSWER,              
};

enum eNodeStatus
{
	DEVICE_POWER_OFF = 0,
	DEVICE_STANDBY,
	DEVICE_INIT_BTN,
	DEVICE_OFFLINE,
	DEVICE_ACTIVE,
	DEVICE_LOW_POWER_ACTIVE,
	DEVICE_OTA_MODE,//06
	DEVICE_OTA_WAIT_SWITCH,
	DEVICE_TRYING_POWER_OFF,
	DEVICE_FINISHED_PRODUCT_TEST,
	DEVICE_SYNC_MODE,
	DEVICE_DFU_MODE,
};

enum eNodeMode
{
	NODE_BLE = 0,
	NODE_2_4G,
	NODE_USB,
};

enum eRobotCmd
{
	ROBOT_GATEWAY_STATUS			= 0x00,		//获取状态
	ROBOT_NODE_STATUS,							//node状态
	ROBOT_ENTER_VOTE,							//进入投票模式
	ROBOT_EXIT_VOTE,							//退出投票模式
	ROBOT_EXIT_VOTE_MULIT,						//多选投票模式
	ROBOT_ENTER_BIG_DATA,						//进入大数据模式
	ROBOT_MASS_DATA,							//大数据上报
	ROBOT_EXIT_BIG_DATA,						//退出大数据模式
	ROBOT_GATEWAY_ERROR,						//错误
	ROBOT_NODE_MODE,							//设备服务模式
	ROBOT_SET_DEVICE_NUM,						//设置设备网络号
	ROBOT_ENTER_DFU,							//进入dfu模式
	ROBOT_FIRMWARE_LEN,							//获取固件长度
	ROBOT_FIRMWARE_DATA,						//获取固件信息
	ROBOT_FIRMWARE_CHECK_SUM,					//获取校验和
	ROBOT_RAW_RESULT,							//校验结果
	ROBOT_GATEWAY_REBOOT,						//设备重启
	ROBOT_EXIT_DFU,								//退出dfu模式
	ROBOT_GATEWAY_VERSION,						//设备版本号
	ROBOT_ONLINE_STATUS,						//在线状态
	ROBOT_DEVICE_CHANGE,						//设备改变
	ROBOT_NODE_INFO,							//设备信息
	ROBOT_NODE_ERROR,							//node错误
	ROBOT_ORIGINAL_PACKET,						//原始笔记数据包
	ROBOT_SET_RTC,								//设置RTC
	ROBOT_KEY_PRESS,							//按键按下
	ROBOT_SHOW_PAGE,							//显示页码		
	ROBOT_ENTER_SYNC,							//进入sync模式
	ROBOT_EXIT_SYNC,							//退出sync模式
	ROBOT_GET_SYNC_HEAD,						//获取存储笔记包头
	ROBOT_SYNC_TRANS_BEGIN,						//笔记传输命令开始
	ROBOT_SYNC_PACKET,							//上传坐标
	ROBOT_SYNC_TRANS_END,						//笔记传输命令结束
	ROBOT_VOTE_ANSWER,							//抢答模式
	ROBOT_OPTIMIZE_PACKET,						//优化笔记
	//////////////////////////Dongle/////////////////////////////
	ROBOT_DONGLE_STATUS,						//dongele状态
	ROBOT_DONGLE_VERSION,						//dongle版本
	ROBOT_DONGLE_SCAN_RES,						//扫描结果
	ROBOT_SET_NAME,								//设置名称
	ROBOT_SLAVE_ERROR,							//错误信息
	ROBOT_SLAVE_STATUS,							//slave状态
	ROBOT_SLAVE_VERSION,						//slave版本
	ROBOT_MODULE_VERSION,						//模组版本号
	ROBOT_ENTER_ADJUST_MODE,					//进入模组校准模式
	ROBOT_MODULE_ADJUST_RESULT,					//模组校准结果
	ROBOT_GET_X8_MAC,							//获取mac地址
};
// 笔数据信息
typedef struct pen_info
{
	uint8_t nStatus;		// 笔状态
	uint16_t nX;			// 笔x轴坐标
	uint16_t nY;			// 笔y轴坐标
	uint16_t nPress;		// 笔压力
}PEN_INFO;  
// 优化笔数据信息
typedef struct pen_infof
{
	uint8_t nStatus;		// 笔状态
	uint16_t nX;			// 笔x轴坐标8
	uint16_t nY;			// 笔y轴坐标
	float fWidth;			// 笔宽度
	float fSpeed;			// 速度
}PEN_INFOF;  

//页码信息
typedef struct page_info
{
	uint8_t page_num : 8;
	uint8_t note_num : 6;
	bool operator==(page_info &pageInfo) const
	{
		if (pageInfo.page_num == this->page_num
			&& pageInfo.note_num == this->note_num)
		{
			return true;
		}
		return false;
	}
}PAGE_INFO;

//设备信息
typedef struct usb_info
{
	char szDevPath[260];
	char szDevName[260];
	unsigned short nVendorNum;    
	unsigned short nProductNum;         
}USB_INFO;

enum eKeyPress
{
	CLICK = 1,
	DBCLICK,
	PAGEUP,
	PAGEDOWN,
	CREATEPAGE,
};

////////////////////////////DONGLE////////////////////////////////
#pragma pack(1)

typedef struct st_ble_device
{
	uint8_t num;
	uint8_t rssi;
	uint8_t match;
	uint8_t addr[6];
	uint8_t device_name[18];
	uint8_t device_type;
}ST_BLE_DEVICE;

#pragma pack()

//蓝牙状态
enum eDongleStatus
{
	BLE_STANDBY				= 0,
	BLE_SCANNING			= 1,	//正在扫描
	BLE_CONNECTING			= 2,	//连接中
	BLE_CONNECTED			= 3,	//连接成功
	BLE_ACTIVE_DISCONNECT	= 4,	//正在断开链接
	BLE_RECONNECTING		= 5,	//重新连接
	BLE_LINK_BREAKOUT		= 6,	//蓝牙正在升级中
	BLE_DFU_START			= 7,	//蓝牙dfu模式
};

enum eUpdateType
{
	DONGLE_BLE = 0,
	DONGLE_MCU,
	SLAVE_MCU,
	MODULE_MCU,
};

enum eSlaveError
{
	ERROR_SLAVE_NONE = 0,
	ERROR_OTA_FLOW_NUM,
	ERROR_OTA_LEN,
	ERROR_OTA_CHECKSUM,
	ERROR_OTA_STATUS,
	ERROR_OTA_VERSION,
	ERROR_SYNC_STATUS = 7,
};

enum eDeviceStatus
{
	DEVICE_IN	= 0,
	DEVICE_OUT,
};

enum eAdujstResult
{
	ADJUST_SUCCESSED = 0,
	ADJUST_FAILED,
	ADJUST_TIMEOUT,
};

#define WIDTH_T7P	22015
#define HEIGHT_T7P	15359

#define WIDTH_P1	17407
#define HEIGHT_P1	10751

#define WIDTH_A4	22600
#define HEIGHT_A4	16650

#define WIDTH_A5	14335
#define HEIGHT_A5	8191

#define WIDTH_X8	22100
#define HEIGHT_X8	14650