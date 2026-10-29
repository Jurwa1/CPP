#pragma once
#include <string>

struct Packet {
	int id;
	std::string name;
	int packetSize;
	bool isEncrypted;
};