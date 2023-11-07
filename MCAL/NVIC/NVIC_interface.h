 /*
 *							     NCIC_interface.h
 *
 *  Author  : Rashad
 *  Date    : 13 OCT 2023
 *  Layer   : MCAL
 *
 */
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Group 1 Interrupts */

#define NVIC_WWDG_IRQn              0   /* WWDG Window Watch-dog interrupt */
#define NVIC_PVD_IRQn               1   /* PVD PVD through EXTI Line detection interrupt */
#define NVIC_TAMPER_IRQn            2   /* TAMPER Tamper interrupt */
#define NVIC_RTC_IRQn               3   /* RTC RTC global interrupt */
#define NVIC_FLASH_IRQn             4   /* FLASH Flash global interrupt */
#define NVIC_RCC_IRQn               5   /* RCC RCC global interrupt */
#define NVIC_EXTI0_IRQn             6   /* EXTI0 EXTI Line0 interrupt */
#define NVIC_EXTI1_IRQn             7   /* EXTI1 EXTI Line1 interrupt */
#define NVIC_EXTI2_IRQn             8   /* EXTI2 EXTI Line2 interrupt */
#define NVIC_EXTI3_IRQn             9   /* EXTI3 EXTI Line3 interrupt */
#define NVIC_EXTI4_IRQn             10  /* EXTI4 EXTI Line4 interrupt */
#define NVIC_DMA1_Channel1_IRQn     11  /* DMA1_Channel1 DMA1 Channel1 global interrupt */
#define NVIC_DMA1_Channel2_IRQn     12  /* DMA1_Channel2 DMA1 Channel2 global interrupt */
#define NVIC_DMA1_Channel3_IRQn     13  /* DMA1_Channel3 DMA1 Channel3 global interrupt */
#define NVIC_DMA1_Channel4_IRQn     14  /* DMA1_Channel4 DMA1 Channel4 global interrupt */
#define NVIC_DMA1_Channel5_IRQn     15  /* DMA1_Channel5 DMA1 Channel5 global interrupt */
#define NVIC_DMA1_Channel6_IRQn     16  /* DMA1_Channel6 DMA1 Channel6 global interrupt */
#define NVIC_DMA1_Channel7_IRQn     17  /* DMA1_Channel7 DMA1 Channel7 global interrupt */
#define NVIC_ADC1_2_IRQn            18  /* ADC1_2 ADC1 and ADC2 global interrupt */
#define NVIC_USB_HP_CAN_TX_IRQn     19  /* USB_HP_CAN_TX USB High Priority or CAN TX interrupts */
#define NVIC_USB_LP_CAN_RX0_IRQn    20  /* USB_LP_CAN_RX0 USB Low Priority or CAN RX0 interrupts */
#define NVIC_CAN_RX1_IRQn           21  /* CAN_RX1 CAN RX1 interrupt */
#define NVIC_CAN_SCE_IRQn           22  /* CAN_SCE CAN SCE interrupt */
#define NVIC_EXTI9_5_IRQn           23  /* EXTI9_5 EXTI Line[9:5] interrupts */
#define NVIC_TIM1_BRK_IRQn          24  /* TIM1_BRK TIM1 Break interrupt */
#define NVIC_TIM1_UP_IRQn           25  /* TIM1_UP TIM1 Update interrupt */
#define NVIC_TIM1_TRG_COM_IRQn      26  /* TIM1_TRG_COM TIM1 Trigger and Commutation interrupts */
#define NVIC_TIM1_CC_IRQn           27  /* TIM1_CC TIM1 Capture Compare interrupt */

/* Group 2 Interrupts */
#define NVIC_TIM2_IRQn              28  /* TIM2 TIM2 global interrupt */
#define NVIC_TIM3_IRQn              29  /* TIM3 TIM3 global interrupt */
#define NVIC_TIM4_IRQn              30  /* TIM4 TIM4 global interrupt */
#define NVIC_I2C1_EV_IRQn           31  /* I2C1_EV I2C1 event interrupt */
#define NVIC_I2C1_ER_IRQn           32  /* I2C1_ER I2C1 error interrupt */
#define NVIC_I2C2_EV_IRQn           33  /* I2C2_EV I2C2 event interrupt */
#define NVIC_I2C2_ER_IRQn           34  /* I2C2_ER I2C2 error interrupt */
#define NVIC_SPI1_IRQn              35  /* SPI1 SPI1 global interrupt */
#define NVIC_SPI2_IRQn              36  /* SPI2 SPI2 global interrupt */
#define NVIC_USART1_IRQn            37  /* USART1 USART1 global interrupt */
#define NVIC_USART2_IRQn            38  /* USART2 USART2 global interrupt */
#define NVIC_USART3_IRQn            39  /* USART3 USART3 global interrupt */
#define NVIC_EXTI15_10_IRQn         40  /* EXTI15_10 EXTI Line[15:10] interrupts */
#define NVIC_RTCAlarm_IRQn          41  /* RTCAlarm RTC alarm through EXTI line interrupt */
#define NVIC_USBWakeup_IRQn         42  /* USBWakeup USB wakeup from suspend through EXTI line interrupt */
#define NVIC_TIM8_BRK_IRQn          43  /* TIM8_BRK TIM8 Break interrupt */
#define NVIC_TIM8_UP_IRQn           44  /* TIM8_UP TIM8 Update interrupt */
#define NVIC_TIM8_TRG_COM_IRQn      45  /* TIM8_TRG_COM TIM8 Trigger and Commutation interrupts */
#define NVIC_TIM8_CC_IRQn           46  /* TIM8_CC TIM8 Capture Compare interrupt */
#define NVIC_ADC3_IRQn              47  /* ADC3 ADC3 global interrupt */
#define NVIC_FSMC_IRQn              48  /* FSMC FSMC global interrupt */
#define NVIC_SDIO_IRQn              49  /* SDIO SDIO global interrupt */
#define NVIC_TIM5_IRQn              50  /* TIM5 TIM5 global interrupt */
#define NVIC_SPI3_IRQn              51  /* SPI3 SPI3 global interrupt */
#define NVIC_UART4_IRQn             52  /* UART4 UART4 global interrupt */
#define NVIC_UART5_IRQn             53  /* UART5 UART5 global interrupt */
#define NVIC_TIM6_IRQn              54  /* TIM6 TIM6 global interrupt */
#define NVIC_TIM7_IRQn              55  /* TIM7 TIM7 global interrupt */
#define NVIC_DMA2_Channel1_IRQn     56  /* DMA2_Channel1 DMA2 Channel1 global interrupt */
#define NVIC_DMA2_Channel2_IRQn     57  /* DMA2_Channel2 DMA2 Channel2 global interrupt */
#define NVIC_DMA2_Channel3_IRQn     58  /* DMA2_Channel3 DMA2 Channel3 global interrupt */
#define NVIC_DMA2_Channel4_5_IRQn   59  /* DMA2_Channel4_5 DMA2 Channel4 and DMA2 Channel5 global interrupts */




void NVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber                                                  );
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber                                                  );
void NVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber                                                  );
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber                                                  );
u8	 NVIC_u8GetActiveFlag      (u8 Copy_u8IntNumber                                                  );
void NVIC_voidSetPriority      (s8 Copy_s8INTID     , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority );
void NVIC_u8GetPriority        (u8 Copy_s8INTID     , u8 *Copy_Priority                              );
#endif
