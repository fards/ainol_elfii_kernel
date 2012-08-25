#ifndef _H_XD_SM
#define _H_XD_SM

#include "xd_protocol.h"
//#include "sm_protocol.h"
    
//Never change any sequence of following data variables
#pragma pack(1)
    
//XD status bit definitions
#define XD_SM_STATUS_PASS						0
#define XD_SM_STATUS_FAIL						1
#define XD_SM_STATUS_BUSY						0
#define XD_SM_STATUS_READY						1
#define XD_SM_STATUS_PROTECTED					0
#define XD_SM_STATUS_NOT_PROTECTED				1

	
	
	
	
	
	
	
	


	
	
	
	


#define CIS_FIELD1_OFFSET						0
#define IDI_FIELD1_OFFSET						128
#define CIS_FIELD2_OFFSET						256
#define IDI_FIELD2_OFFSET						384
#define STORING_AREA1_OFFSET					0
#define STORING_AREA2_OFFSET					256
    
#define DATA_STATUS_VALID						0xFF
#define DATA_STATUS_INVALID						0x00
//if four or more bits are "0", should be assumed to be synonymous with "00h"
    
#define BLOCK_STATUS_NORMAL						0xFF
#define BLOCK_STATUS_INITIALLY_DEFECTIVE		0x00
#define BLOCK_STATUS_MARKED_DEFECTIVE			0xF0
//if two or more bits are "0", should be judged to be a defective block
    
//D7  D6  D5  D4  D3  D2  D1  D0        512+16 Bytes/page
//0   0   0   1   0   BA9 BA8 BA7       518,523 Bytes
//BA6 BA5 BA4 BA3 BA2 BA1 BA0 P         519,524 Bytes
//P: Even parity bit

	
	
	
	
	
	
	



#define CIS_MANUFACTURE_NAME_OFFSET				0x59
#define CIS_PRODUCT_NAME_OFFSET					0x61
#define CIS_PRODUCT_VERSION_OFFSET				0x66
    
#pragma pack()
    
#define ZONE_NUMS_16MB							1
#define ZONE_NUMS_32MB							2
#define ZONE_NUMS_64MB							4
#define ZONE_NUMS_128MB							8
#define ZONE_NUMS_256MB							16
#define ZONE_NUMS_512MB							32
#define ZONE_NUMS_1GB							64
#define ZONE_NUMS_2GB							128
#define ZONE_NUMS_4GB							256
#define ZONE_NUMS_8GB							512
    
#define XD_SM_SECTOR_SIZE						512
#define MAX_REDUNDANT_SIZE						16
#define MAX_PAGES_PER_BLOCK						32
#define MAX_PHYSICAL_BLKS_PER_ZONE				1024
#define MAX_LOGICAL_BLKS_PER_ZONE				1000
#define MAX_SUPPORTED_ZONES						ZONE_NUMS_1GB
    
#define INVALID_BLOCK_ADDRESS					0xFFFF
    
#define XD_SM_WRITE_DISABLED					0
#define XD_SM_WRITE_ENABLED						1
    
#define ECC_NO_ERROR							0
#define ECC_ERROR_CORRECTED						1
#define ECC_ERROR_ECC							2
#define ECC_ERROR_UNCORRECTABLE					3
#define ECC_ERROR_UNKOWN	//
    
//Busy Intervals of 1MB to 256MB SM card
#define BUSY_TIME_PROG							(100*TIMER_1MS)	// xd: 1ms,   sm: 20ms
#define BUSY_TIME_BERASE						(400*TIMER_1MS)	// xd: 10ms,  sm: 400ms
#define BUSY_TIME_R								(10*TIMER_1MS)	// xd: 25us,  sm: 25us
#define BUSY_TIME_RST							(6*TIMER_1MS)	// xd: 0.5ms, sm: 6ms
#define BUSY_TIME_TCRY							(1*TIMER_1MS)
    
/* Error codes */ 
typedef enum XD_SM_Error_Status_t 
    { 
0, 
	
	
	
	
	
	
	
	
	
} XD_SM_Error_Status_t;

    { 
} XD_SM_Card_Type_t;

	
	    //unsigned long total_zones;
	    //unsigned long totoal_physical_blks;
	    //unsigned long totoal_logical_blks;
	    //unsigned short physical_blks_perzone;
	    //unsigned short logical_blks_perzone;
	    //unsigned short pages_per_blk;
	    //unsigned short page_size;
	    //unsigned short redundant_size;
	
	
	
	
	
	
	
	
#ifdef XD_SM_NUM_POINTER	
	unsigned short (*logical_physical_table)[MAX_LOGICAL_BLKS_PER_ZONE];
	
	
#else				/* 
	    unsigned short
	 logical_physical_table[MAX_SUPPORTED_ZONES]
	    [MAX_LOGICAL_BLKS_PER_ZONE];
	
	 free_block_table[MAX_SUPPORTED_ZONES][MAX_PHYSICAL_BLKS_PER_ZONE / 8];
	
#endif				/* 
} XD_SM_Card_Buffer_t;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


#define XD_Card_Info_t							XD_SM_Card_Info_t
#define SM_Card_Info_t							XD_SM_Card_Info_t

























						int enable_write);

						 int cycles);

						 unsigned long data_cnt,
						 unsigned char *redundant_buf,
						 unsigned long redundant_cnt);

						  unsigned long data_cnt,
						  unsigned char *redundant_buf,
						  unsigned long redundant_cnt);


//XD Operation Command Table                                    1st                       2nd                   Busy
#define XD_SM_SERIAL_DATA_INPUT					0x80
#define XD_SM_READ1								0x00
#define XD_SM_READ2								0x01
#define XD_SM_READ3								0x50
#define XD_SM_RESET								0xFF	//Yes
#define XD_SM_TRUE_PAGE_PROGRAM					0x10
#define XD_TRUE_DUMMY_PROGRAM					0x11
#define XD_MULTI_BLOCK_PROGRAM					0x15
#define XD_SM_BLOCK_ERASE_SETUP					0x60	//0xD0
#define XD_SM_BLOCK_ERASE_EXECUTE				0xD0
#define XD_SM_STATUS_READ1						0x70	//Yes
#define XD_STATUS_READ2							0x71	//Yes
#define XD_SM_ID_READ90							0x90
#define XD_SM_ID_READ91							0x91
#define XD_ID_READ9A							0x9A
    
#define XD_SM_INIT_RETRY						3
    
//Following functions are the API used for outside routine
    
//XD/SM Initialization...
int xd_sm_init(XD_Card_Info_t * card_info);



//Check if any card is inserted
//int xd_sm_check_insert();
    
//XD/SM Power on/off
void xd_sm_power_on(void);


#endif				//_H_XD_SM