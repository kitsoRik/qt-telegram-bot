#include "telegrampassportdata.h"

#include <QJsonArray>

TelegramPassportData::TelegramPassportData(const QJsonObject &json)
{
	m_credentials = (json.contains("credentials")) ? new TelegramEncryptedCredentials(json["credentials"].toObject()) : nullptr;

	QJsonArray dataArray = json["data"].toArray();

	for(auto dataObject : dataArray)
	{
		auto data = new TelegramEncryptedPassportElement(dataObject.toObject());
		m_data.append(data);
	}
}

QList<TelegramEncryptedPassportElement *> TelegramPassportData::data() const
{
	return m_data;
}

TelegramEncryptedCredentials *TelegramPassportData::credentials() const
{
	return m_credentials;
}
