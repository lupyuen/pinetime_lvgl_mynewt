/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
//  LVGL Interface for PineTime on Mynewt
#include <os/os.h>
#include <hal/hal_bsp.h>
#include <hal/hal_gpio.h>
#include <hal/hal_system.h>
#include <hal/hal_flash.h>
#include <console/console.h>
#include "lvgl.h"
#include "lv_port_disp.h"

/// Init the LVGL library. Called by sysinit() during startup, defined in pkg.yml.
void pinetime_lvgl_mynewt_init(void) {    
    console_printf("Init LVGL..."); console_flush();

    //  Init the LVGL display
    lv_init();
    lv_port_disp_init();
}

/// Render a Button Widget and a Label Widget
void pinetime_lvgl_mynewt_test(void) {
    puts("In C: Rendering widgets...");
    lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     //  Add a button the current screen
    lv_obj_set_pos(btn, 10, 10);                            //  Set its position
    lv_obj_set_size(btn, 120, 50);                          //  Set its size

    lv_obj_t * label = lv_label_create(btn, NULL);          //  Add a label to the button
    lv_label_set_text(label, "Button");                     //  Set the labels text
}

/// Render the LVGL display
void pinetime_lvgl_mynewt_render(void) {
    puts("In C: Rendering display...");
    //  Must tick at least 100 milliseconds to force LVGL to update display
    lv_tick_inc(100);
    //  LVGL will flush our display driver
    lv_task_handler();
}
