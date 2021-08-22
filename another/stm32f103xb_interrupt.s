.syntax     unified

.global     infinity
.extern     interrupt_reset

.section    .int

.word       stack_pointer
.word       interrupt_reset
.word       interrupt_nmi
.word       interrupt_fault_hard
.word       interrupt_fault_mem
.word       interrupt_fault_bus
.word       interrupt_fault_usage
.word       0x00000000
.word       0x00000000
.word       0x00000000
.word       0x00000000
.word       interrupt_sv_call
.word       interrupt_debug_monitor
.word       0x00000000
.word       interrupt_sv_pend
.word       interrupt_sys_tick
.word       interrupt_wwdg
.word       interrupt_pvd
.word       interrupt_tamper
.word       interrupt_rtc
.word       interrupt_flash
.word       interrupt_rcc
.word       interrupt_exti_0
.word       interrupt_exti_1
.word       interrupt_exti_2
.word       interrupt_exti_3
.word       interrupt_exti_4
.word       interrupt_dma_1_ch_1
.word       interrupt_dma_1_ch_2
.word       interrupt_dma_1_ch_3
.word       interrupt_dma_1_ch_4
.word       interrupt_dma_1_ch_5
.word       interrupt_dma_1_ch_6
.word       interrupt_dma_1_ch_7
.word       interrupt_adc_1_2
.word       interrupt_usb_hp_can_1_tx
.word       interrupt_usb_lp_can_1_rx_0
.word       interrupt_can_1_rx_1
.word       interrupt_can_1_sce
.word       interrupt_exti_5_9
.word       interrupt_tim_1_brk
.word       interrupt_tim_1_up
.word       interrupt_tim_1_trg_com
.word       interrupt_tim_1_cc
.word       interrupt_tim_2
.word       interrupt_tim_3
.word       interrupt_tim_4
.word       interrupt_i2c_1_ev
.word       interrupt_i2c_1_er
.word       interrupt_i2c_2_ev
.word       interrupt_i2c_2_er
.word       interrupt_spi_1
.word       interrupt_spi_2
.word       interrupt_usart_1
.word       interrupt_usart_2
.word       interrupt_usart_3
.word       interrupt_exti_10_15
.word       interrupt_rtc_alarm
.word       interrupt_usb_wake_up

.type       infinity,                           function

.weak       interrupt_nmi
.type       interrupt_nmi,                      function
.thumb_set  interrupt_nmi,                      infinity

.weak       interrupt_fault_hard
.type       interrupt_fault_hard,               function
.thumb_set  interrupt_fault_hard,               infinity

.weak       interrupt_fault_mem
.type       interrupt_fault_mem,                function
.thumb_set  interrupt_fault_mem,                infinity

.weak       interrupt_fault_bus
.type       interrupt_fault_bus,                function
.thumb_set  interrupt_fault_bus,                infinity

.weak       interrupt_fault_usage
.type       interrupt_fault_usage,              function
.thumb_set  interrupt_fault_usage,              infinity

.weak       interrupt_sv_call
.type       interrupt_sv_call,                  function
.thumb_set  interrupt_sv_call,                  infinity

.weak       interrupt_debug_monitor
.type       interrupt_debug_monitor,            function
.thumb_set  interrupt_debug_monitor,            infinity

.weak       interrupt_sv_pend
.type       interrupt_sv_pend,                  function
.thumb_set  interrupt_sv_pend,                  infinity

.weak       interrupt_sys_tick
.type       interrupt_sys_tick,                 function
.thumb_set  interrupt_sys_tick,                 infinity

.weak       interrupt_wwdg
.type       interrupt_wwdg,                     function
.thumb_set  interrupt_wwdg,                     infinity

.weak       interrupt_pvd
.type       interrupt_pvd,                      function
.thumb_set  interrupt_pvd,                      infinity

.weak       interrupt_tamper
.type       interrupt_tamper,                   function
.thumb_set  interrupt_tamper,                   infinity

.weak       interrupt_rtc
.type       interrupt_rtc,                      function
.thumb_set  interrupt_rtc,                      infinity

.weak       interrupt_flash
.type       interrupt_flash,                    function
.thumb_set  interrupt_flash,                    infinity

.weak       interrupt_rcc
.type       interrupt_rcc,                      function
.thumb_set  interrupt_rcc,                      infinity

.weak       interrupt_exti_0
.type       interrupt_exti_0,                   function
.thumb_set  interrupt_exti_0,                   infinity

.weak       interrupt_exti_1
.type       interrupt_exti_1,                   function
.thumb_set  interrupt_exti_1,                   infinity

.weak       interrupt_exti_2
.type       interrupt_exti_2,                   function
.thumb_set  interrupt_exti_2,                   infinity

.weak       interrupt_exti_3
.type       interrupt_exti_3,                   function
.thumb_set  interrupt_exti_3,                   infinity

.weak       interrupt_exti_4
.type       interrupt_exti_4,                   function
.thumb_set  interrupt_exti_4,                   infinity

.weak       interrupt_dma_1_ch_1
.type       interrupt_dma_1_ch_1,               function
.thumb_set  interrupt_dma_1_ch_1,               infinity

.weak       interrupt_dma_1_ch_2
.type       interrupt_dma_1_ch_2,               function
.thumb_set  interrupt_dma_1_ch_2,               infinity

.weak       interrupt_dma_1_ch_3
.type       interrupt_dma_1_ch_3,               function
.thumb_set  interrupt_dma_1_ch_3,               infinity

.weak       interrupt_dma_1_ch_4
.type       interrupt_dma_1_ch_4,               function
.thumb_set  interrupt_dma_1_ch_4,               infinity

.weak       interrupt_dma_1_ch_5
.type       interrupt_dma_1_ch_5,               function
.thumb_set  interrupt_dma_1_ch_5,               infinity

.weak       interrupt_dma_1_ch_6
.type       interrupt_dma_1_ch_6,               function
.thumb_set  interrupt_dma_1_ch_6,               infinity

.weak       interrupt_dma_1_ch_7
.type       interrupt_dma_1_ch_7,               function
.thumb_set  interrupt_dma_1_ch_7,               infinity

.weak       interrupt_adc_1_2
.type       interrupt_adc_1_2,                  function
.thumb_set  interrupt_adc_1_2,                  infinity

.weak       interrupt_usb_hp_can_1_tx
.type       interrupt_usb_hp_can_1_tx,          function
.thumb_set  interrupt_usb_hp_can_1_tx,          infinity

.weak       interrupt_usb_lp_can_1_rx_0
.type       interrupt_usb_lp_can_1_rx_0,        function
.thumb_set  interrupt_usb_lp_can_1_rx_0,        infinity

.weak       interrupt_can_1_rx_1
.type       interrupt_can_1_rx_1,               function
.thumb_set  interrupt_can_1_rx_1,               infinity

.weak       interrupt_can_1_sce
.type       interrupt_can_1_sce,                function
.thumb_set  interrupt_can_1_sce,                infinity

.weak       interrupt_exti_5_9
.type       interrupt_exti_5_9,                 function
.thumb_set  interrupt_exti_5_9,                 infinity

.weak       interrupt_tim_1_brk
.type       interrupt_tim_1_brk,                function
.thumb_set  interrupt_tim_1_brk,                infinity

.weak       interrupt_tim_1_up
.type       interrupt_tim_1_up,                 function
.thumb_set  interrupt_tim_1_up,                 infinity

.weak       interrupt_tim_1_trg_com
.type       interrupt_tim_1_trg_com,            function
.thumb_set  interrupt_tim_1_trg_com,            infinity

.weak       interrupt_tim_1_cc
.type       interrupt_tim_1_cc,                 function
.thumb_set  interrupt_tim_1_cc,                 infinity

.weak       interrupt_tim_2
.type       interrupt_tim_2,                    function
.thumb_set  interrupt_tim_2,                    infinity

.weak       interrupt_tim_3
.type       interrupt_tim_3,                    function
.thumb_set  interrupt_tim_3,                    infinity

.weak       interrupt_tim_4
.type       interrupt_tim_4,                    function
.thumb_set  interrupt_tim_4,                    infinity

.weak       interrupt_i2c_1_ev
.type       interrupt_i2c_1_ev,                 function
.thumb_set  interrupt_i2c_1_ev,                 infinity

.weak       interrupt_i2c_1_er
.type       interrupt_i2c_1_er,                 function
.thumb_set  interrupt_i2c_1_er,                 infinity

.weak       interrupt_i2c_2_ev
.type       interrupt_i2c_2_ev,                 function
.thumb_set  interrupt_i2c_2_ev,                 infinity

.weak       interrupt_i2c_2_er
.type       interrupt_i2c_2_er,                 function
.thumb_set  interrupt_i2c_2_er,                 infinity

.weak       interrupt_spi_1
.type       interrupt_spi_1,                    function
.thumb_set  interrupt_spi_1,                    infinity

.weak       interrupt_spi_2
.type       interrupt_spi_2,                    function
.thumb_set  interrupt_spi_2,                    infinity

.weak       interrupt_usart_1
.type       interrupt_usart_1,                  function
.thumb_set  interrupt_usart_1,                  infinity

.weak       interrupt_usart_2
.type       interrupt_usart_2,                  function
.thumb_set  interrupt_usart_2,                  infinity

.weak       interrupt_usart_3
.type       interrupt_usart_3,                  function
.thumb_set  interrupt_usart_3,                  infinity

.weak       interrupt_exti_10_15
.type       interrupt_exti_10_15,               function
.thumb_set  interrupt_exti_10_15,               infinity

.weak       interrupt_rtc_alarm
.type       interrupt_rtc_alarm,                function
.thumb_set  interrupt_rtc_alarm,                infinity

.weak       interrupt_usb_wake_up
.type       interrupt_usb_wake_up,              function
.thumb_set  interrupt_usb_wake_up,              infinity

.section    .text

infinity:
    b       infinity
