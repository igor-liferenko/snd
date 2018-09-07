
# Project name
PROJECT = EVK527-ATMega32U4-usbdevice_audio

# CPU architecture : {avr0|...|avr6}
# Parts :
MCU = atmega32u4

# Source files
CSRCS = \
  ../../../lib_mcu/util/start_boot.c\
  ../../../lib_mcu/usb/usb_drv.c\
  ../../../lib_mcu/power/power_drv.c\
  ../../../lib_mcu/adc/adc_drv.c\
  ../../../lib_board/evk_527/evk_527.c\
  ../../../modules/usb/device_chap9/usb_device_task.c\
  ../../../modules/usb/device_chap9/usb_standard_request.c\
  ../../../modules/usb/usb_task.c\
  ../../../modules/scheduler/scheduler.c\
  ../audio_task.c\
  ../usb_descriptors.c\
  ../usb_specific_request.c\
  ../main.c\

# Assembler source files
ASSRCS = \
  ../../../lib_mcu/flash/flash_drv.s\

