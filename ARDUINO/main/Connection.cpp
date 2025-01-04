#include "Connection.h"

wro::Connection::Connection()
{
	Serial.begin(115200);
	while (!valid())
		continue;
}

wro::Connection::~Connection()
{
	Serial.end();
}

void wro::Connection::sendMessage(char* message) const
{
	Serial.write(message);
}

void wro::Connection::sendDebug(char* information) const
{
	Serial.write(information);
}

void wro::Connection::sendError(char* error) const
{
	Serial.write(error);
}

char* wro::Connection::getMessage() const
{
	const BYTE len = std::static_cast<BYTE>(Serial.read());
	char* result = new char[len];
	for (BYTE i = 0; i < len; i++)
		Serial.readBytes(result, len);
	return result;
}

bool wro::Connection::valid() const
{
	return Serial;
}

char* wro::Connection::toSerial(float f) const
{
	char* result = new char[sizeof(float)];
	memcpy(&f, result, sizeof(float));
	return result;
}