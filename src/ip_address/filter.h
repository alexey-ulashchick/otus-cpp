#ifndef TEMPLATE_SRC_IP_ADDRESS_FILTER_H
#define TEMPLATE_SRC_IP_ADDRESS_FILTER_H

#include "ip_address.h"
#include <vector>

std::vector<IpAddress> filter(const std::vector<IpAddress> &src, const unsigned char &oct1);
std::vector<IpAddress> filter(const std::vector<IpAddress> &src, const unsigned char &oct1, const unsigned char &oct2);
std::vector<IpAddress> filterAny(const std::vector<IpAddress> &src, const unsigned char &oct);

#endif
