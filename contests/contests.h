//
// Created by EGor on 16.02.2021.
//

#pragma once

#include "contest2/contest2.h"
#include "contest3/contest3.h"
#include "contest4/contest4.h"
#include "contest5/contest5.h"
#include "contest6_2020/contest6.h"
#include "contest7/contest7.h"
#include "control_test/control_test.h"
#include "control_test_2/contest_test_2.h"

#define WRONG_CONTEST_NUMBER 2

int contest_task( int num, char index ){
    switch (num) {
        case 2: return contest2::task(index);
        case 3: return contest3::task(index);
        case 4: return contest4::task(index);
        case 5: return contest5::task(index);
        case 6: return contest6::task(index);
        case 7: return contest7::task(index);
        case 10: return control::task(index);
        case 11: return control2::task(index);
        default: return WRONG_CONTEST_NUMBER;
    }
}