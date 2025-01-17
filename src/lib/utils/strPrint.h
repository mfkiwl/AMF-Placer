/**
 * @file strPrint.h
 * @author Tingyuan LIANG (tliang@connect.ust.hk)
 * @brief
 * @version 0.1
 * @date 2021-10-02
 *
 * @copyright Copyright (c) 2021 Reconfiguration Computing Systems Lab, The Hong Kong University of Science and
 * Technology. All rights reserved.
 *
 */

#ifndef _STRPRINT
#define _STRPRINT

#include <chrono>
#include <ios>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/time.h>

extern std::chrono::time_point<std::chrono::steady_clock> oriTime;

void print_cmd(std::string tmp_string);
void print_info(std::string tmp_string);
void print_status(std::string tmp_string);
void print_error(std::string tmp_string);
void print_warning(std::string tmp_string);
void printProgress(double percentage);
std::string to_string_align3(int __val);

#endif
