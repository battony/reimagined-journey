#pragma once

#include "configuration.h"

#define DESC_DEVICE               (0x0100)
#define DESC_DEVICE_LEN           (0x12)

#define DESC_DEVICE_QUALFIFER     (0x0600)
#define DESC_DEVICE_QUALIFIER_LEN (0x0A)

#define DESC_CONFIGURATION        (0x0200)
#define DESC_CONFIGURATION_LEN    (0x22)

#define DESC_STRING               (0x0300)
#define DESC_STRING_LEN           (0x04)

#define DESC_STRING_MFR           (0x0301)
#define DESC_STRING_MFR_LEN       (0x1C)

#define DESC_STRING_PRD           (0x0302)
#define DESC_STRING_PRD_LEN       (0x12)

#define DESC_STRING_SNU           (0x0303)
#define DESC_STRING_SNU_LEN       (0x22)

#define DESC_STRING_CNF           (0x0304)
#define DESC_STRING_CNF_LEN       (0x08)

#define DESC_REPORT               (0x2200)
#define DESC_REPORT_LEN           (0x27)

extern const uint8_t descriptor_device[DESC_DEVICE_LEN];

extern const uint8_t descriptor_device_qualifier[DESC_DEVICE_QUALIFIER_LEN];

extern const uint8_t descriptor_configuration[DESC_CONFIGURATION_LEN];

extern const uint8_t descriptor_string[DESC_STRING_LEN];

extern const uint8_t descriptor_string_manufacturer[DESC_STRING_MFR_LEN];

extern const uint8_t descriptor_string_product[DESC_STRING_PRD_LEN];

extern const uint8_t descriptor_string_serial_number[DESC_STRING_SNU_LEN];

extern const uint8_t descriptor_string_configuration[DESC_STRING_CNF_LEN];

extern const uint8_t descriptor_report[DESC_REPORT_LEN];
