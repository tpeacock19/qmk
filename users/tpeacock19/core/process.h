#pragma once

#include QMK_KEYBOARD_H
#define _PROCESS_RECORD_RESULT_H

typedef enum
{
  PROCESS_RECORD_RETURN_TRUE,
  PROCESS_RECORD_RETURN_FALSE,
  PROCESS_RECORD_CONTINUE
} process_record_result_t;
