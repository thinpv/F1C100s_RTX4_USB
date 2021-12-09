// 本文件由洪旭耀设计，可以通过QQ联系作者：26750452
#include <efxinc.h>
#include <f1c100s-irq.h>
#include <tusb.h>
#include <ctype.h>

__task void usb_task() {
  for (;;) {
		tud_task();
	}
}


////////////////////////////////////////////////////////////////////////////////
//|          |
//| 函数名称 |: UserEntryInit
//| 功能描述 |: 应用程序初始化
//|          |:
//| 参数列表 |:
//|          |:
//| 返    回 |:
//|          |:
//| 备注信息 |:
//|          |:
////////////////////////////////////////////////////////////////////////////////
void UserEntryInit(void)
{
  target_wdt_feed();

  printf("DDR size: %uMB\n", (*(uint32_t*)0x5c) & 0xFFFFFF);
	tusb_init();
	os_tsk_create(usb_task, 10);
}

////////////////////////////////////////////////////////////////////////////////
//|          |
//| 函数名称 |: UserEntryLoop
//| 功能描述 |: 应用程序主循环
//|          |:
//| 参数列表 |:
//|          |:
//| 返    回 |:
//|          |:
//| 备注信息 |:
//|          |:
////////////////////////////////////////////////////////////////////////////////
void UserEntryLoop(void)
{
  for (;;) {
    target_wdt_feed();
		sys_delay(500);
#if 0
    // 串口驱动测试
    if (f1c100s_uart_isTxEnd(UART0_MID)) {
      rCnt = f1c100s_uart_readFifo(UART0_MID, rbuffer, sizeof(rbuffer));
      if (rCnt > 0) {
        f1c100s_uart_asyncTx(UART0_MID, rbuffer, rCnt);
      }
    }
#endif
  }
}


////////////////////////////////////////////////////////////////////////////////

