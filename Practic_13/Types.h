#pragma once

enum class HTTP {
	Get,
	Post,
	Delete
};

enum class UserNames {
	Guest,
	User,
	Admin
};

struct Session {
	int id;
	UserNames role;
	bool isBanned{ false };
	std::string password {"983256471"};
};

struct ApiRequest {
	int id;
	HTTP method;
	std::string endpoint;
	Session session;
};