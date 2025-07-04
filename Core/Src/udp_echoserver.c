/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */


/* Includes ------------------------------------------------------------------*/
#include "lwip/opt.h"

#if LWIP_NETCONN

#include "lwip/api.h"
#include "lwip/sys.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define UDPECHO_THREAD_PRIO  ( tskIDLE_PRIORITY + 4 )
#define UDP_SERVER_PORT 7
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static struct netconn *conn;
static struct netbuf *buf;
static ip_addr_t *addr;
static unsigned short port;

/* Private function prototypes -----------------------------------------------*/
static void udpecho_thread(void *arg);
void udpecho_init(void);

/*-----------------------------------------------------------------------------------*/
static void udpecho_thread(void *arg)
{
  err_t err, recv_err;

  LWIP_UNUSED_ARG(arg);

  conn = netconn_new(NETCONN_UDP);
  if (conn!= NULL)
  {
    err = netconn_bind(conn, IP_ADDR_ANY, UDP_SERVER_PORT);
    if (err == ERR_OK)
    {
      while (1)
      {
        recv_err = netconn_recv(conn, &buf);
      
        if (recv_err == ERR_OK)
        {
          addr = netbuf_fromaddr(buf);
          port = netbuf_fromport(buf);
          netconn_connect(conn, addr, port);
          buf->addr.addr = 0;

          netconn_send(conn,buf);
          netbuf_delete(buf);
        }
      }
    }
    else
    {
      netconn_delete(conn);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void udpecho_init(void)
{
  sys_thread_new("udpecho_thread", udpecho_thread, NULL, DEFAULT_THREAD_STACKSIZE,UDPECHO_THREAD_PRIO );
}

#endif /* LWIP_NETCONN */
