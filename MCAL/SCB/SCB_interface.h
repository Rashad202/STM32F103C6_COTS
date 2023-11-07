#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_




void DisableGlobalInterrupts(void); 


void SCB_SetPriorityGrouping (u32 Copy_PriorityGrouping);


void EnableGlobalInterrupts(void);


void SCB_EnableMemFault(void);


void SCB_EnableBusFault(void);


void SCB_EnableUsageFault(void);


void SCB_ClearMemFault(void);


void SCB_ClearBusFault(void);


void SCB_ClearUsageFault(void);



#endif /**< SCB_INTERFACE_H_ */
