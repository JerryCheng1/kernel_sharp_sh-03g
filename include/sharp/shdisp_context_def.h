/* include/sharp/shdisp_context_def.h  (Display Driver)
 *
 * Copyright (C) 2011 SHARP CORPORATION
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef SHDISP_CONTEXT_DEF_H
#define SHDISP_CONTEXT_DEF_H

#define SHDISP_LCDC_EWB_TBL_SIZE                    (256)
#define SHDISP_NOOS_RESET_NUM                       (3)

#define SHDISP_ARGC_MBR_NUM                         (3)
#define SHDISP_ARGC_STAGE_NUM                       (16)
#define SHDISP_IGC_LUT_ENTRIES                      (256)

struct shdisp_dbg_error_code {
    unsigned char mode;
    unsigned char type;
    unsigned char code;
    unsigned char subcode;
};

struct shdisp_main_bkl_ctl {
    int mode;
    int param;
};

struct shdisp_main_bkl_auto {
    int mode;
    int param;
};

struct shdisp_tri_led {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    int ext_mode;
    int led_mode;
    int ontime;
    int interval;
    int count;
};

struct shdisp_als_adjust {
    unsigned short als_adj0;
    unsigned short als_adj1;
    unsigned char als_shift;
    unsigned char clear_offset;
    unsigned char ir_offset;
};

struct shdisp_photo_sensor_adj {
    unsigned char status;
    unsigned char key_backlight;
    unsigned int chksum;
    struct shdisp_als_adjust als_adjust[2];
};

struct shdisp_ledc_req {
    unsigned int red[2];
    unsigned int green[2];
    unsigned int blue[2];
    int led_mode;
    int on_count;
};

struct shdisp_ledc_status {
    int ledc_is_exist;
    int power_status;
    struct shdisp_ledc_req ledc_req;
};

struct shdisp_argc_lut {
    unsigned short  red[SHDISP_ARGC_STAGE_NUM][SHDISP_ARGC_MBR_NUM];
    unsigned short  green[SHDISP_ARGC_STAGE_NUM][SHDISP_ARGC_MBR_NUM];
    unsigned short  blue[SHDISP_ARGC_STAGE_NUM][SHDISP_ARGC_MBR_NUM];
};

struct shdisp_igc_lut {
    unsigned char   r_data[SHDISP_IGC_LUT_ENTRIES];
    unsigned char   g_data[SHDISP_IGC_LUT_ENTRIES];
    unsigned char   b_data[SHDISP_IGC_LUT_ENTRIES];
};

enum {
    SHDISP_MAIN_DISP_OFF,
    SHDISP_MAIN_DISP_ON,
    NUM_SHDISP_MAIN_DISP_STATUS
};

enum {
    SHDISP_MAIN_DISP_DRIVE_FREQ_DEFAULT,
    SHDISP_MAIN_DISP_DRIVE_FREQ_TYPE_A,
    SHDISP_MAIN_DISP_DRIVE_FREQ_TYPE_B,
    SHDISP_MAIN_DISP_DRIVE_FREQ_TYPE_C,
    NUM_SHDISP_MAIN_DISP_DRIVE_FREQ_TYPE
};

enum {
    SHDISP_UPPER_UNIT_IS_NOT_CONNECTED,
    SHDISP_UPPER_UNIT_IS_CONNECTED,
    NUM_UPPER_UNIT_STATUS
};

enum {
    SHDISP_BDIC_IS_NOT_EXIST,
    SHDISP_BDIC_IS_EXIST,
    NUM_BDIC_EXIST_STATUS
};

enum {
    SHDISP_MAIN_BKL_MODE_OFF,
    SHDISP_MAIN_BKL_MODE_FIX,
    SHDISP_MAIN_BKL_MODE_AUTO,
    SHDISP_MAIN_BKL_MODE_AUTO_ECO,
    SHDISP_MAIN_BKL_MODE_DTV_OFF,
    SHDISP_MAIN_BKL_MODE_DTV_FIX,
    SHDISP_MAIN_BKL_MODE_DTV_AUTO,
    NUM_SHDISP_MAIN_BKL_MODE
};

#define SHDISP_MAIN_BKL_PARAM_OFF           (0)
#define SHDISP_MAIN_BKL_PARAM_WEAK          (1)
#define SHDISP_MAIN_BKL_PARAM_DEFAULT       (115)
#define SHDISP_MAIN_BKL_PARAM_MIN           (0)
#define SHDISP_MAIN_BKL_PARAM_MAX           (255)
#define SHDISP_MAIN_BKL_PARAM_MIN_AUTO      (2)
#define SHDISP_MAIN_BKL_PARAM_MAX_AUTO      (255)

enum {
    SHDISP_MAIN_BKL_AUTO_OFF,
    SHDISP_MAIN_BKL_AUTO_ON,
    SHDISP_MAIN_BKL_AUTO_ECO_ON,
    NUM_SHDISP_MAIN_BKL_AUTO
};

enum {
    SHDISP_MAIN_BKL_DTV_OFF,
    SHDISP_MAIN_BKL_DTV_ON,
    NUM_SHDISP_MAIN_BKL_DTV
};

enum {
    SHDISP_MAIN_BKL_EMG_OFF,
    SHDISP_MAIN_BKL_EMG_ON,
    NUM_SHDISP_MAIN_BKL_EMG
};

enum {
    SHDISP_MAIN_DISP_ALS_RANGE_001 = 0,
    SHDISP_MAIN_DISP_ALS_RANGE_002,
    SHDISP_MAIN_DISP_ALS_RANGE_004,
    SHDISP_MAIN_DISP_ALS_RANGE_008,
    SHDISP_MAIN_DISP_ALS_RANGE_016,
    SHDISP_MAIN_DISP_ALS_RANGE_032,
    SHDISP_MAIN_DISP_ALS_RANGE_064,
    SHDISP_MAIN_DISP_ALS_RANGE_128,
    NUM_SHDISP_MAIN_DISP_ALS_RANGE
};

enum {
    SHDISP_PHOTO_SENSOR_DISABLE,
    SHDISP_PHOTO_SENSOR_ENABLE,
    NUM_SHDISP_PHOTO_SENSOR
};

enum {
    SHDISP_TRI_LED_EXT_MODE_DISABLE,
    SHDISP_TRI_LED_EXT_MODE_ENABLE,
    NUM_SHDISP_TRI_LED_EXT_MODE
};

enum {
    SHDISP_TRI_LED_MODE_NORMAL,
    SHDISP_TRI_LED_MODE_BLINK,
    SHDISP_TRI_LED_MODE_FIREFLY,
    SHDISP_TRI_LED_MODE_HISPEED,
    SHDISP_TRI_LED_MODE_STANDARD,
    SHDISP_TRI_LED_MODE_BREATH,
    SHDISP_TRI_LED_MODE_LONG_BREATH,
    SHDISP_TRI_LED_MODE_WAVE,
    SHDISP_TRI_LED_MODE_FLASH,
    SHDISP_TRI_LED_MODE_AURORA,
    SHDISP_TRI_LED_MODE_RAINBOW,
    SHDISP_TRI_LED_MODE_EMOPATTERN,
    SHDISP_TRI_LED_MODE_PATTERN1,
    SHDISP_TRI_LED_MODE_PATTERN2,
    NUM_SHDISP_TRI_LED_MODE
};

enum {
    SHDISP_TRI_LED_ONTIME_TYPE0,
    SHDISP_TRI_LED_ONTIME_TYPE1,
    SHDISP_TRI_LED_ONTIME_TYPE2,
    SHDISP_TRI_LED_ONTIME_TYPE3,
    SHDISP_TRI_LED_ONTIME_TYPE4,
    SHDISP_TRI_LED_ONTIME_TYPE5,
    SHDISP_TRI_LED_ONTIME_TYPE6,
    SHDISP_TRI_LED_ONTIME_TYPE7,
    SHDISP_TRI_LED_ONTIME_TYPE8,
    SHDISP_TRI_LED_ONTIME_TYPE9,
    SHDISP_TRI_LED_ONTIME_TYPE10,
    SHDISP_TRI_LED_ONTIME_TYPE11,
    SHDISP_TRI_LED_ONTIME_TYPE12,
    SHDISP_TRI_LED_ONTIME_TYPE13,
    NUM_SHDISP_TRI_LED_ONTIME
};

enum {
    SHDISP_TRI_LED_COUNT_NONE,
    SHDISP_TRI_LED_COUNT_1,
    SHDISP_TRI_LED_COUNT_2,
    SHDISP_TRI_LED_COUNT_3,
    SHDISP_TRI_LED_COUNT_4,
    SHDISP_TRI_LED_COUNT_5,
    SHDISP_TRI_LED_COUNT_6,
    SHDISP_TRI_LED_COUNT_7,
    NUM_SHDISP_TRI_LED_COUNT
};

enum {
    SHDISP_PHOTO_SENSOR_TYPE_APP,
    SHDISP_PHOTO_SENSOR_TYPE_LUX,
    SHDISP_PHOTO_SENSOR_TYPE_CAMERA,
    SHDISP_PHOTO_SENSOR_TYPE_KEYLED,
    SHDISP_PHOTO_SENSOR_TYPE_DIAG,
    SHDISP_PHOTO_SENSOR_TYPE_SENSORHUB,
    NUM_SHDISP_PHOTO_SENSOR_TYPE
};

enum {
    SHDISP_LEDC_ONCOUNT_REPEAT,
    SHDISP_LEDC_ONCOUNT_1SHOT,
    NUM_SHDISP_LEDC_ONCOUNT
};

enum {
    SHDISP_LEDC_IS_NOT_EXIST,
    SHDISP_LEDC_IS_EXIST,
    NUM_LEDC_EXIST_STATUS
};

enum {
    SHDISP_DIAG_COG_ID_NONE,
    SHDISP_DIAG_COG_ID_MASTER,
    SHDISP_DIAG_COG_ID_SLAVE,
    SHDISP_DIAG_COG_ID_BOTH,
    NUM_SHDISP_DIAG_COG_ID
};

struct shdisp_diag_bdic_reg {
    unsigned char reg;
    unsigned char val;
};

struct shdisp_diag_bdic_reg_multi {
    unsigned char reg;
    unsigned char val[8];
    unsigned char size;
};

#define SHDISP_LCDDR_BUF_MAX    (64)
struct shdisp_lcddr_reg {
    unsigned char address;
    unsigned char size;
    unsigned char buf[SHDISP_LCDDR_BUF_MAX];
    int      cog;
};

struct shdisp_photo_sensor_val {
    unsigned short value;
    unsigned int   lux;
    int mode;
    int result;
};

struct shdisp_photo_sensor_raw_val {
    unsigned short clear;
    unsigned short ir;
    int result;
};

struct shdisp_photo_sensor_power_ctl {
    int type;
    int power;
};

struct shdisp_pharaoh_reg {
    unsigned char address;
    unsigned char size;
    unsigned char buf[32];
};

struct shdisp_ledc_rgb {
    unsigned int mode;
    unsigned int red[2];
    unsigned int green[2];
    unsigned int blue[2];
};

struct shdisp_diag_ledc_reg {
    unsigned char reg;
    unsigned char val;
};

struct shdisp_ledc_mono {
    unsigned int led;
    int led_mode;
    int on_count;
};

struct shdisp_diag_flicker_param {
    unsigned short  request;
    unsigned short  master_alpha;
    unsigned short  slave_alpha;
};

struct shdisp_diag_lcdc_reg {
    unsigned short reg;
    unsigned int   value;
};

struct shdisp_diag_lcdc_i2c {
    unsigned char  slave_addr;
    unsigned char  buf[256];
    unsigned short size;
    unsigned int   timeout;
};

struct shdisp_diag_ewb_tbl {
    unsigned char   valR[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned char   valG[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned char   valB[SHDISP_LCDC_EWB_TBL_SIZE];
};

struct shdisp_diag_set_ewb {
    unsigned short  valR;
    unsigned short  valG;
    unsigned short  valB;
};

struct shdisp_diag_read_ewb {
    unsigned char   level;
    unsigned short  valR;
    unsigned short  valG;
    unsigned short  valB;
};

struct shdisp_ave_ado {
    unsigned char  als_range;
    unsigned short ave_als0;
    unsigned short ave_als1;
    unsigned short ave_ado;
};

#if (defined(CONFIG_USES_SHLCDC) || defined(FEATURE_SHLCDC))

#if defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI)
    #define SHDISP_PANEL_ANALOG_GAMMA_TBL_SIZE      (24)
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (18)

    #define SHDISP_LCDDR_PHY_ANALOG_GAMMA_BUF_MAX   SHDISP_PANEL_ANALOG_GAMMA_TBL_SIZE
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          (SHDISP_PANEL_GAMMA_TBL_SIZE * 3)
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       5
    struct shdisp_phy_gamma_sub {
        unsigned char analog_gamma[SHDISP_LCDDR_PHY_ANALOG_GAMMA_BUF_MAX];
        unsigned char applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    };
#else  /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (60)
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          (SHDISP_PANEL_GAMMA_TBL_SIZE * 3)
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       (9)
#endif /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */

enum {
    SHDISP_CLMR_IS_NOT_EXIST,
    SHDISP_CLMR_IS_EXIST,
    NUM_CLMR_EXIST_STATUS
};

struct shdisp_clmr_status {
    int clmr_is_exist;
    int power_status;
    unsigned int users;
};

struct shdisp_bdic_status {
    int power_status;
    unsigned int users;
};

struct shdisp_psals_status {
    int power_status;
    int sensor_state;
    int als_mode;
    unsigned int users;
};

struct shdisp_lcddr_phy_gamma_reg {
#if defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI)
    unsigned char  status;
    struct shdisp_phy_gamma_sub master;
    struct shdisp_phy_gamma_sub slave;
    unsigned short chksum;
#else  /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
    unsigned char  status;
    unsigned short buf[SHDISP_LCDDR_PHY_GAMMA_BUF_MAX];
    unsigned char  applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    unsigned int   chksum;
#endif /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
};

struct shdisp_clmr_ewb {
    unsigned char  valR[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned char  valG[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned char  valB[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned short red_chksum;
    unsigned short green_chksum;
    unsigned short blue_chksum;
    unsigned short ewb_lut_status;
};

enum {
    SHDISP_MAIN_BKL_ECO_OFF,
    SHDISP_MAIN_BKL_ECO_ON,
    NUM_SHDISP_MAIN_BKL_ECO
};

#if defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI)
struct shdisp_diag_gamma_info_sub {
    unsigned char   analog_gamma[SHDISP_PANEL_ANALOG_GAMMA_TBL_SIZE];
    unsigned char   vsps_vsns;
    unsigned char   vghs;
    unsigned char   vgls;
    unsigned char   vph_vpl;
    unsigned char   vnh_vnl;
};
#endif /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */

struct shdisp_diag_gamma_info {
#if defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI)
    struct shdisp_diag_gamma_info_sub   master_info;
    struct shdisp_diag_gamma_info_sub   slave_info;
#else  /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
    unsigned short  gammaR[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaG[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaB[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   vgh;
    unsigned char   vgl;
    unsigned char   gvddp;
    unsigned char   gvddn;
    unsigned char   gvddp2;
    unsigned char   vgho;
    unsigned char   vglo;
    unsigned char   avddr;
    unsigned char   aveer;
#endif /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
};

struct shdisp_diag_gamma {
#if defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI)
    unsigned char   level;
    unsigned char   master_gamma_p;
    unsigned char   master_gamma_n;
    unsigned char   slave_gamma_p;
    unsigned char   slave_gamma_n;
#else  /* defined(CONFIG_SHDISP_PANEL_GEMINI) || defined(USER_CONFIG_SHDISP_PANEL_GEMINI) */
    unsigned char   level;
    unsigned short  gammaR_p;
    unsigned short  gammaR_n;
    unsigned short  gammaG_p;
    unsigned short  gammaG_n;
    unsigned short  gammaB_p;
    unsigned short  gammaB_n;
#endif
};

#define CALI_LOGAREA_VAL            0x00007C68
#define CALI_END_VAL                0x00008000
#define SHDISP_CALI_EDRAM_DUMP_SIZE ((CALI_END_VAL - CALI_LOGAREA_VAL) * 7 * 16)
#define SHDISP_CALI_SRAM_DUMP_COUNT (4096)
#define SHDISP_CALI_SRAM_DUMP_SIZE  (SHDISP_CALI_SRAM_DUMP_COUNT * 4)

struct shdisp_clmr_ewb_accu {
    unsigned short valR[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned short valG[SHDISP_LCDC_EWB_TBL_SIZE];
    unsigned short valB[SHDISP_LCDC_EWB_TBL_SIZE];
};

#else /* (defined(CONFIG_USES_SHLCDC) || defined(FEATURE_SHLCDC)) */

#if defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY)
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (60)
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          (SHDISP_PANEL_GAMMA_TBL_SIZE * 3)
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       (9)
#elif defined(CONFIG_SHDISP_PANEL_ARIA) || defined(USER_CONFIG_SHDISP_PANEL_ARIA)
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (60)
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          (SHDISP_PANEL_GAMMA_TBL_SIZE * 3)
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       (11)
#elif defined(CONFIG_SHDISP_PANEL_CARIN) || defined(USER_CONFIG_SHDISP_PANEL_CARIN)
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (30)
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          SHDISP_PANEL_GAMMA_TBL_SIZE
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       (9)
#else   /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
    #define SHDISP_PANEL_GAMMA_TBL_SIZE             (24)
    #error "SHDISP SWITCH NOTHING!!"
    #define SHDISP_LCDDR_PHY_GAMMA_BUF_MAX          (SHDISP_PANEL_GAMMA_TBL_SIZE * 3)
    #define SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE       (9)
#endif  /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */

struct shdisp_bdic_status {
    int power_status;
    unsigned int users;
};

struct shdisp_psals_status {
    int power_status;
    unsigned int als_users;
    int ps_um_status;
    int als_um_status;
};

struct shdisp_lcddr_phy_gamma_reg {
#if defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY)
    unsigned char  status;
    unsigned short buf[SHDISP_LCDDR_PHY_GAMMA_BUF_MAX];
    unsigned char  applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    unsigned int   chksum;
#elif defined(CONFIG_SHDISP_PANEL_ARIA) || defined(USER_CONFIG_SHDISP_PANEL_ARIA)
    unsigned char  status;
    unsigned short buf[SHDISP_LCDDR_PHY_GAMMA_BUF_MAX];
    unsigned char  applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    unsigned int   chksum;
#elif defined(CONFIG_SHDISP_PANEL_CARIN) \
   || defined(USER_CONFIG_SHDISP_PANEL_CARIN)
    unsigned char  status;
    unsigned char  buf[SHDISP_LCDDR_PHY_GAMMA_BUF_MAX];
    unsigned char  applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    unsigned short chksum;
#else   /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
    unsigned char  status;
    unsigned char  buf[SHDISP_LCDDR_PHY_GAMMA_BUF_MAX];
    unsigned char  applied_voltage[SHDISP_LCDDR_APPLIED_VOLTAGE_SIZE];
    unsigned short chksum;
#endif  /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
};

struct shdisp_diag_gamma_info {
#if defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY)
    unsigned short  gammaR[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaG[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaB[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   vgh;
    unsigned char   vgl;
    unsigned char   gvddp;
    unsigned char   gvddn;
    unsigned char   gvddp2;
    unsigned char   vgho;
    unsigned char   vglo;
    unsigned char   avddr;
    unsigned char   aveer;
#elif defined(CONFIG_SHDISP_PANEL_ARIA) || defined(USER_CONFIG_SHDISP_PANEL_ARIA)
    unsigned short  gammaR[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaG[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned short  gammaB[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   dca;
    unsigned char   dcab;
    unsigned char   dcb;
    unsigned char   bta;
    unsigned char   vgh;
    unsigned char   vgl;
    unsigned char   vcl;
    unsigned char   gvddp;
    unsigned char   gvddn;
    unsigned char   vgho;
    unsigned char   vglo;
#elif defined(CONFIG_SHDISP_PANEL_CARIN) || defined(USER_CONFIG_SHDISP_PANEL_CARIN)
    unsigned char   gamma[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   vlm1;
    unsigned char   vlm2;
    unsigned char   vlm3;
    unsigned char   vc1;
    unsigned char   vc2;
    unsigned char   vc3;
    unsigned char   vpl;
    unsigned char   vnl;
    unsigned char   svss_svdd;
#else   /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
    unsigned char   gammaR[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   gammaG[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   gammaB[SHDISP_PANEL_GAMMA_TBL_SIZE];
    unsigned char   vlm1;
    unsigned char   vlm2;
    unsigned char   vlm3;
    unsigned char   vc1;
    unsigned char   vc2;
    unsigned char   vc3;
    unsigned char   vpl;
    unsigned char   vnl;
    unsigned char   svss_svdd;
#endif  /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
};

struct shdisp_diag_gamma {
#if defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY)
    unsigned char   level;
    unsigned short  gammaR_p;
    unsigned short  gammaR_n;
    unsigned short  gammaG_p;
    unsigned short  gammaG_n;
    unsigned short  gammaB_p;
    unsigned short  gammaB_n;
#elif defined(CONFIG_SHDISP_PANEL_ARIA) || defined(USER_CONFIG_SHDISP_PANEL_ARIA)
    unsigned char   level;
    unsigned short  gammaR_p;
    unsigned short  gammaR_n;
    unsigned short  gammaG_p;
    unsigned short  gammaG_n;
    unsigned short  gammaB_p;
    unsigned short  gammaB_n;
#elif defined(CONFIG_SHDISP_PANEL_CARIN) || defined(USER_CONFIG_SHDISP_PANEL_CARIN)
    unsigned char   level;
    unsigned char   gamma_p;
    unsigned char   gamma_n;
#else   /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
    unsigned char   level;
    unsigned char   gammaR_p;
    unsigned char   gammaR_n;
    unsigned char   gammaG_p;
    unsigned char   gammaG_n;
    unsigned char   gammaB_p;
    unsigned char   gammaB_n;
#endif  /* defined(CONFIG_SHDISP_PANEL_ANDY) || defined(USER_CONFIG_SHDISP_PANEL_ANDY) */
};

struct shdisp_photo_sensor_trigger {
    unsigned short level;
    unsigned short side;
    unsigned short en_hi_edge;
    unsigned short en_lo_edge;
    unsigned short enable;
};

struct shdisp_photo_sensor_int_trigger {
    struct shdisp_photo_sensor_trigger trigger1;
    struct shdisp_photo_sensor_trigger trigger2;
    int type;
    int result;
};

#define SHDISP_OPT_CHANGE_INT_1             (0x01)
#define SHDISP_OPT_CHANGE_INT_2             (0x02)

struct shdisp_light_info {
    unsigned int lux;
    unsigned short level;
    unsigned int clear_ir_rate;
    int result;
};

#endif /* (defined(CONFIG_USES_SHLCDC) || defined(FEATURE_SHLCDC)) */

#endif /* SHDISP_CONTEXT_DEF_H */