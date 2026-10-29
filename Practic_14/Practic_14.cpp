#include <iostream>
#include <random>
#include "Packet.h"

int Random(int min, int max) {
	static std::mt19937 x{ std::random_device{}() };
	std::uniform_int_distribution y{ min, max };
	int result = y(x);

	return result;
}

std::ostream& operator<<(std::ostream& out, const Packet& e) {
	out << "PACKET INFO\n" << "[PACKET NAME: " << e.name <<"]\n" << "[PACKET ID: " << e.id << "]\n" << "[PACKET SIZE: " << e.packetSize << "]\n";
	return out;
}

void CheckPacket(const Packet& e) {
	if (!e.isEncrypted) {
		std::cout << "PACKET CHECK ERROR: Encrypted packets not allowed on this port. Processing rejected.\n";
		return;
	}

	if (e.packetSize > 50) {
		std::cout << "PACKET CHECK ERROR: Packet size is too big. Server cannot process information.\n";
		return;
	}
	
	std::cout << "[OK] Packet verified: Payload decrypted and size within limits. Processing complete.";
}

int main() {
	Packet NetworkPacket{ Random(0, 10), "DATA", Random(10, 100), Random(0,1) };

	std::cout << NetworkPacket;

	CheckPacket(NetworkPacket);
}