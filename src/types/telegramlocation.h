#ifndef TELEGRAMLOCATION_H
#define TELEGRAMLOCATION_H

#include "telegrambasetypes.h"

class TelegramLocation : public TelegramBaseTypes
{
public:
	TelegramLocation(const QJsonObject &json);

	/// Necessarily
	double longitute() const;
	/// Necessarily
	double latitude() const;

private:
	double m_longitute;
	double m_latitude;
};

#endif // TELEGRAMLOCATION_H
