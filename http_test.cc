/*
 * @Author: sunburst7 1064658281@qq.com
 * @Date: 2023-04-14 22:13:23
 * @LastEditors: sunburst7 1064658281@qq.com
 * @LastEditTime: 2023-04-14 22:19:55
 * @FilePath: /WebREST-test/http_test.cc
 * @Description: 
 * 
 * Copyright (c) 2023 by sunburst7 1064658281@qq.com, All Rights Reserved. 
 */
#include <iostream>

#include "eventloop.h"
#include "inet_address.h"
#include "http.h"
#include "http_request.h"
#include "http_response.h"

using namespace std;
using namespace WebREST;

int main()
{
    EventLoop loop;
    InetAddress listen_addr(54321);
    HttpServer server(&loop, listen_addr, false);

    server.Get("/test", [](const HttpRequest& req, HttpResponse& resp){
        printf("/test handler\n");
        resp.set_status_code(HttpResponse::k200OK);
        resp.set_status_message("OK");
        resp.set_body("test hello!\n");
    });
    
    server.start();
    loop.loop();
}


