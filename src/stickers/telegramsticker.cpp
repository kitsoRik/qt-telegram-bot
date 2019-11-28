#include "telegramsticker.h"
#include "types/telegramphotosize.h"
#include "telegrammaskposition.h"

TelegramSticker::TelegramSticker(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_isAnimated = json["is_animated"].toBool();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
	m_emoji = json["emoji"].toString();
	m_setName = json["set_name"].toString();
	m_maskPosition = (json.contains("mask_position")) ? new TelegramMaskPosition(json["mask_position"].toObject()) : nullptr;
	m_fileSize = json["file_size"].toInt(-1);
}

TelegramSticker::~TelegramSticker()
{
	if(m_thumb)
		delete m_thumb;
}

QString TelegramSticker::fileId() const
{
	return m_fileId;
}

int TelegramSticker::width() const
{
	return m_width;
}

int TelegramSticker::height() const
{
	return m_height;
}

bool TelegramSticker::isAnimated() const
{
	return m_isAnimated;
}

TelegramPhotoSize *TelegramSticker::thumb() const
{
	return m_thumb;
}

QString TelegramSticker::emoji() const
{
	return m_emoji;
}

QString TelegramSticker::setName() const
{
	return m_setName;
}

TelegramMaskPosition *TelegramSticker::maskPosition() const
{
	return m_maskPosition;
}

int TelegramSticker::fileSize() const
{
	return m_fileSize;
}
