mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/start_boot.o -MF default/dep/start_boot.o.d  -c ../../../lib_mcu/util/start_boot.c -o default/start_boot.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_drv.o -MF default/dep/usb_drv.o.d  -c ../../../lib_mcu/usb/usb_drv.c -o default/usb_drv.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/power_drv.o -MF default/dep/power_drv.o.d  -c ../../../lib_mcu/power/power_drv.c -o default/power_drv.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/adc_drv.o -MF default/dep/adc_drv.o.d  -c ../../../lib_mcu/adc/adc_drv.c -o default/adc_drv.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/evk_527.o -MF default/dep/evk_527.o.d  -c ../../../lib_board/evk_527/evk_527.c -o default/evk_527.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_device_task.o -MF default/dep/usb_device_task.o.d  -c ../../../modules/usb/device_chap9/usb_device_task.c -o default/usb_device_task.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_standard_request.o -MF default/dep/usb_standard_request.o.d  -c ../../../modules/usb/device_chap9/usb_standard_request.c -o default/usb_standard_request.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_task.o -MF default/dep/usb_task.o.d  -c ../../../modules/usb/usb_task.c -o default/usb_task.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/scheduler.o -MF default/dep/scheduler.o.d  -c ../../../modules/scheduler/scheduler.c -o default/scheduler.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/audio_task.o -MF default/dep/audio_task.o.d  -c ../audio_task.c -o default/audio_task.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_descriptors.o -MF default/dep/usb_descriptors.o.d  -c ../usb_descriptors.c -o default/usb_descriptors.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/usb_specific_request.o -MF default/dep/usb_specific_request.o.d  -c ../usb_specific_request.c -o default/usb_specific_request.o
mkdir -p default
mkdir -p default/dep
avr-gcc  -mmcu=atmega32u4 -Wall -gdwarf-2 -Os -fsigned-char -ffunction-sections -MD -MP -MT default/main.o -MF default/dep/main.o.d  -c ../main.c -o default/main.o
avr-gcc  -mmcu=atmega32u4 -x assembler-with-cpp -Wa,-gdwarf2 -c ../../../lib_mcu/flash/flash_drv.s -o default/flash_drv.o
avr-gcc -mmcu=atmega32u4 -Wl,-Map=EVK527-ATMega32U4-usbdevice_audio.map,--cref,--gc-sections,--relax default/start_boot.o default/usb_drv.o default/power_drv.o default/adc_drv.o default/evk_527.o default/usb_device_task.o default/usb_standard_request.o default/usb_task.o default/scheduler.o default/audio_task.o default/usb_descriptors.o default/usb_specific_request.o default/main.o default/flash_drv.o    -o EVK527-ATMega32U4-usbdevice_audio.elf
